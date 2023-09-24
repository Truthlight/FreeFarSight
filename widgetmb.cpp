/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "widgetmb.h"

widgetMB::widgetMB(QString title, QString message,QWidget *parent) : QDialog(parent),
    m_MainLayout(this),
    m_TitleBar  (this),
    m_SizeGrip  (NULL),
    m_Cache     (NULL),
    background(NULL)
{
    connect(this       , SIGNAL(WindowTitleChanged()),
            &m_TitleBar, SLOT  (UpdateWindowTitle ()));

    resize(100, 120);

    setWindowTitle(title);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose,true);

    m_MainLayout.setMargin (0); // No space between window's element and the window's border
    m_MainLayout.setSpacing(0); // No space between window's element

    m_TitleBar.setMinimumWidth(this->width());
    setLayout(&m_MainLayout);
    m_MainLayout.addWidget(&m_TitleBar, 0, 0, 1, 1);
    m_MainLayout.setRowStretch(1, 1); // Put the title bar at the top of the window

    m_message = new QLabel (this);
    m_message->setText(message);
    m_message->setAlignment(Qt::AlignCenter);
    m_ButtonOK = new QPushButton (this);
    m_ButtonOK->setText("OK");
    m_ButtonOK->setMaximumWidth(100);
    m_layoutButtonOK->addWidget(m_ButtonOK);
    m_MainLayout.addWidget(m_message,1,0);
    m_MainLayout.addLayout(m_layoutButtonOK,2,0);
    this->setLayout(&m_MainLayout);

    setWindowModality(Qt::WindowModal);
    this->show();

    Design design;
    QString style = design.getStyle();
    this->setStyleSheet(style+"QWidget {background-color: #2F2F2F;}"
                        +"QPushButton {background-color:#2F2F2F;color :#AAAAAA;border: 1px solid #474747;margin-bottom:10px;}"
                        +"QPushButton::Disabled {background-color : #474747;border:none;color:#AAAAAA}"
                        +"QPushButton::hover {background-color:#201F1F;}"
                        +"QPushButton::pressed {background-color:#201F1F;color:#474747;}");
    m_message->setStyleSheet("QLabel{margin-left:10px;margin-right:10px;}");

    QObject::connect(m_ButtonOK,SIGNAL(clicked()),this,SLOT(accept()));
}

widgetMB::~widgetMB()
{
if(background  != NULL) delete background ;
}


void widgetMB::setWindowTitle(const QString &title)
{
  QWidget::setWindowTitle(title);
  emit WindowTitleChanged();
}

void widgetMB::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

  QPolygon border;
  border << QPoint(0,0)//haut gauche
         << QPoint(width(),0)//haut droit
         << QPoint(width(), height())
         << QPoint(0, height());

  QPainter painter (this);

  background  = new QPixmap(size());
  background ->fill(Qt::transparent);

  painter.setPen(QPen(QBrush(0x201F1F),2));
  painter.setBrush(QBrush(0x2F2F2F));

  painter.drawPolygon(border);
  painter.end();
  painter.drawPixmap(0, 0, *background );

}
