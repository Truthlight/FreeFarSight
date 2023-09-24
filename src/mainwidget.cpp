/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "mainwidget.h"

MainWidget::~MainWidget()
{
//if(m_Cache != NULL) delete m_Cache;
if(thread) thread->deleteLater();
}

MainWidget::MainWidget(DWORD processID) : QWidget(),
    m_MainLayout(this),
    m_TitleBar  (this),
    m_SizeGrip  (NULL)
    //m_Cache     (NULL)
{
    connect(this       , SIGNAL(WindowTitleChanged()),
            &m_TitleBar, SLOT  (UpdateWindowTitle ()));

    resize(480, 350);

    setWindowTitle("Free Far Sight");
    setWindowFlags(Qt::FramelessWindowHint);//remove ugly windows frame
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose,true);

    m_MainLayout.setMargin (0); // No space between window's element and the window's border
    m_MainLayout.setSpacing(0); // No space between window's element

    setLayout(&m_MainLayout);
    m_MainLayout.addWidget(&m_TitleBar, 0, 0, 1, 1);
    m_MainLayout.setRowStretch(1, 1); // Put the title bar at the top of the window

    //
    MemoryWow.Initialize(processID);

    //UI
    onglets = new QTabWidget (this);//onglet is the french word for tab
    onglets->setGeometry(0, 0, 480, 350);

    tabGeneral = new UItabGeneral (this);
    tabSpectate = new UItabSpectate (this);
    tabLight = new UItabLight;
    tabAbout = new UITabAbout;

    onglets->addTab(tabGeneral, "General");
    onglets->addTab(tabSpectate, "Spectate");
    onglets->addTab(tabLight,"Light");
    onglets->addTab(tabAbout, "About");
    m_MainLayout.addWidget(onglets);

    //style
    Design design;
    QString style = design.getStyle();
    this->setStyleSheet(style);
}

void MainWidget::setWindowTitle(const QString &title)
{
  QWidget::setWindowTitle(title);
  emit WindowTitleChanged();
}

void MainWidget::paintEvent(QPaintEvent *event)//ok
{
  QPainter painter(this);
  QBrush background(QColor(32, 31, 31));
  painter.setBrush(background); //background color
  painter.drawRect(0, 0, width(), height()); //draw window
}

void MainWidget::enableHotKeys()
{
    //création QThread
    //qui active les différents hotkeys

    hk = new HotKeysThread (tabSpectate);
    thread = new QThread (this);
    hk->moveToThread(thread);

    connect (thread,SIGNAL(started()),hk,SLOT(run()));
    connect (hk,SIGNAL(finished()),thread,SLOT(quit()));
    connect (hk,SIGNAL(finished()),hk,SLOT(deleteLater()));
    connect (hk,SIGNAL(finished()),thread,SLOT(deleteLater()));

    thread->start();
}

void MainWidget::disableHotKeys()
{

    tabSpectate->disableHotKeys();

    //thread->finished();
    //thread->quit();
    //thread->exit();
    //thread->deleteLater();
}
