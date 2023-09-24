/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "uihotkeys.h"

UIHotKeys::UIHotKeys(QWidget *parent) : QDialog(parent),
    m_MainLayout(this),
    m_TitleBar  (this),
    m_SizeGrip  (NULL),
    //m_Cache     (NULL),
    background(NULL)
{
    connect(this       , SIGNAL(WindowTitleChanged()),
            &m_TitleBar, SLOT  (UpdateWindowTitle ()));

    resize(100, 120);

    setWindowTitle("Set HotKeys");
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose,true);

    m_MainLayout.setMargin (0); // No space between window's element and the window's border
    m_MainLayout.setSpacing(0); // No space between window's element

    m_TitleBar.setMinimumWidth(this->width());
    setLayout(&m_MainLayout);
    m_MainLayout.addWidget(&m_TitleBar, 0, 0, 1, 1);
    m_MainLayout.setRowStretch(1, 1); // Put the title bar at the top of the window

    m_mainLabel = new QLabel (this);
    m_mainLabel->setText("Click buttons to set Hotkeys");
    m_mainLabel->setAlignment(Qt::AlignCenter);

    m_labelZoomPlus = new QLabel (this);
    m_labelZoomPlus->setText("Plus");
    m_buttonZoomPlus = new QPushButton (this);
    m_zoomPlus->addWidget(m_labelZoomPlus);
    m_zoomPlus->addWidget(m_buttonZoomPlus);

    m_labelZoomMinus = new QLabel (this);
    m_labelZoomMinus->setText("Minus");
    m_buttonZoomMinus = new QPushButton (this);
    m_zoomMinus->addWidget(m_labelZoomMinus);
    m_zoomMinus->addWidget(m_buttonZoomMinus);

    m_layoutVZoom->addLayout(m_zoomPlus);
    m_layoutVZoom->addLayout(m_zoomMinus);

    QGroupBox *groupZoom = new QGroupBox ("Zoom", this);
    groupZoom->setLayout(m_layoutVZoom);

    m_labelSlowMoToggle = new QLabel (this);
    m_labelSlowMoToggle->setText("Toggle");
    m_buttonSlowMoToggle = new QPushButton (this);
    m_slowMoToggle->addWidget(m_labelSlowMoToggle);
    m_slowMoToggle->addWidget(m_buttonSlowMoToggle);

    m_labelSlowMoPlay = new QLabel (this);
    m_labelSlowMoPlay->setText("Play");
    m_buttonSlowMoPlay = new QPushButton (this);
    m_slowMoPlay->addWidget(m_labelSlowMoPlay);
    m_slowMoPlay->addWidget(m_buttonSlowMoPlay);

    m_labelSlowMoPlus = new QLabel (this);
    m_labelSlowMoPlus->setText("Plus");
    m_buttonSlowMoPlus = new QPushButton (this);
    m_slowMoPlus->addWidget(m_labelSlowMoPlus);
    m_slowMoPlus->addWidget(m_buttonSlowMoPlus);

    m_labelSlowMoMinus = new QLabel (this);
    m_labelSlowMoMinus->setText("Minus");
    m_buttonSlowMoMinus = new QPushButton (this);
    m_slowMoMinus->addWidget(m_labelSlowMoMinus);
    m_slowMoMinus->addWidget(m_buttonSlowMoMinus);

    m_layoutVSlowMo->addLayout(m_slowMoToggle);
    m_layoutVSlowMo->addLayout(m_slowMoPlay);
    m_layoutVSlowMo->addLayout(m_slowMoPlus);
    m_layoutVSlowMo->addLayout(m_slowMoMinus);

    QGroupBox *groupSlowMo = new QGroupBox ("Slow Motion", this);
    groupSlowMo->setLayout(m_layoutVSlowMo);

    m_labelSpectateModeToggle = new QLabel (this);
    m_labelSpectateModeToggle->setText("Toggle");
    m_buttonSpectateModeToggle = new QPushButton (this);
    m_spectateModeToggle->addWidget(m_labelSpectateModeToggle);
    m_spectateModeToggle->addWidget(m_buttonSpectateModeToggle);

    m_labelSpectateModeAdd = new QLabel (this);
    m_labelSpectateModeAdd->setText("Add");
    m_buttonSpectateModeAdd = new QPushButton (this);
    m_spectateModeAdd->addWidget(m_labelSpectateModeAdd);
    m_spectateModeAdd->addWidget(m_buttonSpectateModeAdd);

    m_labelSpectateModePlay = new QLabel (this);
    m_labelSpectateModePlay->setText("Play");
    m_buttonSpectateModePlay = new QPushButton (this);
    m_spectateModePlay->addWidget(m_labelSpectateModePlay);
    m_spectateModePlay->addWidget(m_buttonSpectateModePlay);

    m_labelSpectateModeStop = new QLabel (this);
    m_labelSpectateModeStop->setText("Stop");
    m_buttonSpectateModeStop = new QPushButton (this);
    m_spectateModeStop->addWidget(m_labelSpectateModeStop);
    m_spectateModeStop->addWidget(m_buttonSpectateModeStop);

    m_labelSpectateModeSpeedPlus = new QLabel (this);
    m_labelSpectateModeSpeedPlus->setText("Plus");
    m_buttonSpectateModeSpeedPlus = new QPushButton (this);
    m_spectateModeSpeedPlus->addWidget(m_labelSpectateModeSpeedPlus);
    m_spectateModeSpeedPlus->addWidget(m_buttonSpectateModeSpeedPlus);

    m_labelSpectateModeSpeedMinus = new QLabel (this);
    m_labelSpectateModeSpeedMinus->setText("Minus");
    m_buttonSpectateModeSpeedMinus = new QPushButton (this);
    m_spectateModeSpeedMinus->addWidget(m_labelSpectateModeSpeedMinus);
    m_spectateModeSpeedMinus->addWidget(m_buttonSpectateModeSpeedMinus);

    m_layoutVSpectateMode->addLayout(m_spectateModeToggle);
    m_layoutVSpectateMode->addLayout(m_spectateModeAdd);
    m_layoutVSpectateMode->addLayout(m_spectateModePlay);
    m_layoutVSpectateMode->addLayout(m_spectateModeStop);
    m_layoutVSpectateMode->addLayout(m_spectateModeSpeedPlus);
    m_layoutVSpectateMode->addLayout(m_spectateModeSpeedMinus);

    QGroupBox *groupSpectateMode = new QGroupBox ("Spectate Mode", this);
    groupSpectateMode->setLayout(m_layoutVSpectateMode);

    m_ButtonOK = new QPushButton (this);
    m_ButtonOK->setText("OK");
    m_ButtonOK->setMaximumWidth(100);
    m_layoutButtonOK->addWidget(m_ButtonOK);
    m_MainLayout.addWidget(m_mainLabel,1,0);
    m_MainLayout.addWidget(groupZoom,2,0);
    m_MainLayout.addWidget(groupSlowMo,3,0);
    m_MainLayout.addWidget(groupSpectateMode,4,0);
    m_MainLayout.addLayout(m_layoutButtonOK,5,0);
    this->setLayout(&m_MainLayout);

    setWindowModality(Qt::WindowModal);
    this->show();

    Design design;
    QString style = design.getStyle();
    this->setStyleSheet(style+"QWidget {background-color: #2F2F2F;}"
                        +"QPushButton {background-color:#2F2F2F;color :#AAAAAA;border: 1px solid #474747;}"
                        +"QPushButton::Disabled {background-color : #474747;border:none;color:#AAAAAA}"
                        +"QPushButton::hover {background-color:#201F1F;}"
                        +"QPushButton::pressed {background-color:#201F1F;color:#474747;}"
                        +"QLabel{margin-left:10px;margin-right:10px;}"
                        +"QGroupBox{margin:10px;}");


    QObject::connect(m_ButtonOK,SIGNAL(clicked()),this,SLOT(accept()));
}

UIHotKeys::~UIHotKeys()
{
if(background  != NULL) delete background ;
}


void UIHotKeys::setWindowTitle(const QString &title)
{
  QWidget::setWindowTitle(title);
  emit WindowTitleChanged();
}

void UIHotKeys::paintEvent(QPaintEvent *event)
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
