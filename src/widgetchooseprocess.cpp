/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "widgetchooseprocess.h"

WidgetChooseProcess::~WidgetChooseProcess()
{

}

WidgetChooseProcess::WidgetChooseProcess(std::vector <DWORD> &m_processIDHandle) : QWidget(),
    m_MainLayout(this),
    m_TitleBar  (this),
    m_SizeGrip  (NULL),
    m_Cache     (NULL)
{
    if (m_processIDHandle.size() == 0) // if no handle wow.exe
    {
        widgetMB* MB = new widgetMB ("FFS", "Wow Process not found\n\nMake sure you\'re running a 32 bits version of WoW"
                                     "To run the 32-bit version :\nEnable the checkbox \"Launch 32-bit client (instead of 64-bit)\"\non the battlenet launcher (Settings -> Game Settings)\n");
        MB->show();
    }
    else if (m_processIDHandle.size() ==1) //if 1 handle found
    {
        MainWidget* m_mainWidget = new MainWidget(m_processIDHandle.at(0));// display mainwidget
        m_mainWidget->show();
    }
    else // if >1 handle
    {
        for (int i=0;i<m_processIDHandle.size();i++)
        {
            std::ostringstream stream;
            stream <<"World of Warcraft  ";
            stream << m_processIDHandle.at(i);
            std::string str = stream.str();
            m_listProcess.append(str.c_str());
        }
        connect(this       , SIGNAL(WindowTitleChanged()),
                &m_TitleBar, SLOT  (UpdateWindowTitle ()));

        resize(260, 200);

        setWindowTitle("Free Far Sight");
        setWindowFlags(Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);

        m_MainLayout.setMargin (0); // No space between window's element and the window's border
        m_MainLayout.setSpacing(0); // No space between window's element

        m_TitleBar.setMinimumWidth(this->width());
        setLayout(&m_MainLayout);
        m_MainLayout.addWidget(&m_TitleBar, 0, 0, 1, 1);
        m_MainLayout.setRowStretch(1, 1); // Put the title bar at the top of the window

        QStringListModel *modele = new QStringListModel(m_listProcess);

        m_listview = new QListView (this);
        m_listview->setEditTriggers(0); //Content list uneditable
        m_label = new QLabel;
        m_buttonOK = new QPushButton ("OK",this);
        m_buttonSelect = new QPushButton ("Show Selected",this);
        m_label->setText("\nSelect wow process :");
        m_label->setAlignment(Qt::AlignCenter);
        m_label->setStyleSheet("font-size:12px;");
        //m_listview->setMaximumWidth(100);

        m_listview->setModel(modele);

        layoutV->addWidget(m_label);
        layoutV->addWidget (m_listview);
        layoutV->addLayout(layoutH);
        layoutH->addWidget(m_buttonSelect);
        layoutH->addWidget(m_buttonOK);
        m_MainLayout.addLayout(layoutV,1,0);
        this->setLayout(&m_MainLayout);
        this->show();

        //Design
        Design design;
        QString style = design.getStyle();
        this->setStyleSheet(style+"QWidget {background-color: #2F2F2F;}"
                            +"QPushButton {background-color:#2F2F2F;color :#AAAAAA;border: 1px solid #474747;margin-bottom:10px;max-width:100px;}"
                            +"QPushButton::Disabled {background-color : #474747;border:none;color:#AAAAAA}"
                            +"QPushButton::hover {background-color:#201F1F;}"
                            +"QPushButton::pressed {background-color:#201F1F;color:#474747;}"
                            +"QListView {color: #AAAAAA;background-color: #2F2F2F;border: 1px solid #474747;margin:10px;}");

        connect (m_buttonSelect, SIGNAL(clicked()), this ,SLOT(WindowSelected()));
        connect (m_buttonOK, SIGNAL(clicked()),this, SLOT (ChooseProcess()));
    }
}

void WidgetChooseProcess::setWindowTitle(const QString &title)
{
  QWidget::setWindowTitle(title);
  emit WindowTitleChanged();
}

void WidgetChooseProcess::paintEvent(QPaintEvent *event)//ok
{
  QPainter painter(this);
  QBrush background(QColor(47, 47, 47));
  painter.setBrush(background); //background color
  painter.drawRect(0, 0, width(), height()); //dessine fenetre
}

void WidgetChooseProcess::SetProcessIDVector (std::vector <DWORD> &processIDHandle)
{
    m_processIDHandle = processIDHandle;
}

void WidgetChooseProcess::WindowSelected()
{
    if (!m_listview->selectionModel()->hasSelection())
    {
        widgetMB *MB = new widgetMB("FFS","You must select a process",this);
        MB->show();
    }
    else
    {
        QItemSelectionModel *selection = m_listview->selectionModel();
        QModelIndex indexSelectedElement = selection->currentIndex();
        int row = indexSelectedElement.row();
        processWOW.FindHWNDProcess(m_processIDHandle.at(row), "World of Warcraft");
    }
}

void WidgetChooseProcess::ChooseProcess()
{
    if (!m_listview->selectionModel()->hasSelection())
    {
        widgetMB *MB = new widgetMB("FFS","You must select a process",this);
        MB->show();
    }
    else
    {
        QItemSelectionModel *selection = m_listview->selectionModel();
        QModelIndex indexSelectedElement = selection->currentIndex();
        int row = indexSelectedElement.row();
        DWORD HandleIDSelected = m_processIDHandle.at(row);
        MainWidget* m_mainWidget = new MainWidget(HandleIDSelected);
        m_mainWidget->show();
        this->close();
    }
}
