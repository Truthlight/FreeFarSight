/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "uitabgeneral.h"

Render WowRender;
Time WowTime;
slowmo WowSlowMo;

UItabGeneral::UItabGeneral(QWidget *parent):QWidget(parent),
    m_parent (parent)
{
    /*m_labelFOV = new QLabelClickable (this);
    m_labelFOV->setText("FOV          ");
    m_sliderFOV = new QSlider(Qt::Horizontal, this);
    m_sliderFOV->setRange(0,300);
    m_sliderFOV->setValue(150);
    m_spinFOV->setValue(1.50);
    m_spinFOV->setSingleStep(0.01);
    m_spinFOV->setStyleSheet("QDoubleSpinBox {min-height: 15px; min-width:57px;}");
    m_spinFOV->setReadOnly(true);
    m_FOV->addWidget(m_labelFOV);
    m_FOV->addWidget(m_sliderFOV);
    m_FOV->addWidget(m_spinFOV);*/

    m_labelZoom = new QLabelClickable (this);
    m_labelZoom->setText("Zoom        ");
    m_sliderZoom = new QSlider(Qt::Horizontal,this);
    m_sliderZoom->setRange(-147,147);
    m_sliderZoom->setValue(0);
    m_spinZoom->setValue(0.00);
    m_spinZoom->setSingleStep(0.01);
    //m_spinZoom->setMinimum(-1.47);
    m_spinZoom->setRange(-1.47,1.47);
    m_spinZoom->setStyleSheet("QDoubleSpinBox {min-height: 15px; min-width:57px;}");
    //m_spinZoom->setReadOnly(true);
    m_Zoom->addWidget(m_labelZoom);
    m_Zoom->addWidget(m_sliderZoom);
    m_Zoom->addWidget(m_spinZoom);

    m_labelAttachX = new QLabelClickable (this);
    m_labelAttachX->setText("Attach X   ");
    m_sliderAttachX = new QSlider(Qt::Horizontal,this);
    m_sliderAttachX->setRange(-10000,10000);                   // à changer++
    m_sliderAttachX->setValue(0);
    m_spinAttachX->setValue(0.00);
    m_spinAttachX->setSingleStep(0.01);
    m_spinAttachX->setRange(-100,100);
    //m_spinAttachX->setMinimum(-1000);
    m_spinAttachX->setStyleSheet("QDoubleSpinBox {min-height: 15px; min-width:57px;}");
    //m_spinAttachX->setReadOnly(true);
    m_AttachX->addWidget(m_labelAttachX);
    m_AttachX->addWidget(m_sliderAttachX);
    m_AttachX->addWidget(m_spinAttachX);
    //m_checkXProtec->setText("Unplug");
    //m_AttachX->addWidget(m_checkXProtec);

    //QGroupBox *groupX = new QGroupBox ("X Attach", this);
    //groupX->setLayout(m_AttachX);
    //m_Attach->addWidget(groupX);

    m_labelAttachY = new QLabelClickable (this);
    m_labelAttachY->setText("Attach Y   ");
    m_sliderAttachY = new QSlider(Qt::Horizontal,this);
    m_sliderAttachY->setRange(-10000,10000);                   // à changer++
    m_sliderAttachY->setValue(0);
    m_spinAttachY->setValue(0.00);
    m_spinAttachY->setSingleStep(0.01);
    m_spinAttachY->setRange(-100,100);
    //m_spinAttachY->setMinimum(-1000);
    m_spinAttachY->setStyleSheet("QDoubleSpinBox {min-height: 15px; min-width:57px;}");
    //m_spinAttachY->setReadOnly(true);
    m_AttachY->addWidget(m_labelAttachY);
    m_AttachY->addWidget(m_sliderAttachY);
    m_AttachY->addWidget(m_spinAttachY);
    //m_checkYProtec->setText("Unplug");
    //m_AttachY->addWidget(m_checkYProtec);

    //QGroupBox *groupY = new QGroupBox ("Y Attach", this);
    //groupY->setLayout(m_AttachY);
    //m_Attach->addWidget(groupY);

    m_labelAttachZ = new QLabelClickable (this);
    m_labelAttachZ->setText("Attach Z   ");
    m_sliderAttachZ = new QSlider(Qt::Horizontal,this);
    m_sliderAttachZ->setRange(-10000,10000);                   // à changer++
    m_sliderAttachZ->setValue(0);
    m_spinAttachZ->setValue(0.00);
    m_spinAttachZ->setSingleStep(0.01);
    m_spinAttachZ->setRange(-100,100);
    //m_spinAttachZ->setMinimum(-1000);
    m_spinAttachZ->setStyleSheet("QDoubleSpinBox {min-height: 15px; min-width:57px;}");
    //m_spinAttachZ->setReadOnly(true);
    m_AttachZ->addWidget(m_labelAttachZ);
    m_AttachZ->addWidget(m_sliderAttachZ);
    m_AttachZ->addWidget(m_spinAttachZ);
    //m_checkZProtec->setText("Unplug");
    //m_AttachZ->addWidget(m_checkZProtec);

    //QGroupBox *groupZ = new QGroupBox ("Z Attach", this);
    //groupZ->setLayout(m_AttachZ);
    //m_Attach->addWidget(groupZ);


    //m_layoutVCamera->addLayout(m_FOV);
    m_layoutVCamera->addLayout(m_Zoom);
    m_layoutVCamera->addLayout(m_AttachX);
    m_layoutVCamera->addLayout(m_AttachY);
    m_layoutVCamera->addLayout(m_AttachZ);
    QGroupBox *groupCamera = new QGroupBox ("Camera Settings", this);
    groupCamera->setLayout(m_layoutVCamera);
    m_layoutVCamera2->addWidget(groupCamera);
    //m_layoutVCamera2->addLayout(m_Attach);

    m_checkOnTop = new QCheckBox (this);
    m_checkOnTop->setText("Always On Top");
    /*m_checkShortCut = new QCheckBox (this);
    m_checkShortCut->setText("Enable");
    m_buttonShortCut = new QPushButton (this);
    m_buttonShortCut->setText("Change");
    m_buttonShortCut->setDisabled(true);
    m_layoutVShortCut->addWidget(m_checkShortCut);
    m_layoutVShortCut->addWidget(m_buttonShortCut);
    QGroupBox *groupShortCut = new QGroupBox ("HotKeys", this);
    groupShortCut->setDisabled(true);// +++++++++++++++++++++++++++++++++++++++à réactiver quand ok
    groupShortCut->setLayout(m_layoutVShortCut);*/

    m_checkRenderM2 = new QCheckBox (this);
    m_checkRenderM2->setText("M2");
    m_checkRenderM2->setChecked(true);
    m_checkRenderFarM2 = new QCheckBox (this);
    m_checkRenderFarM2->setText("Far M2");
    m_checkRenderFarM2->setChecked(true);
    m_checkRenderGroundDoodads = new QCheckBox (this);
    m_checkRenderGroundDoodads->setText("Details");
    m_checkRenderGroundDoodads->setChecked(true);
    m_checkRenderTerrain = new QCheckBox (this);
    m_checkRenderTerrain->setText("Terrain");
    m_checkRenderTerrain->setChecked(true);
    m_checkRenderWMO = new QCheckBox (this);
    m_checkRenderWMO->setText("WMO");
    m_checkRenderWMO->setChecked(true);
    m_checkRenderLiquid = new QCheckBox (this);
    m_checkRenderLiquid->setText("Liquid");
    m_checkRenderLiquid->setChecked(true);
    //m_checkRenderWireframe = new QCheckBox (this);
    //m_checkRenderWireframe->setText("Wireframe");
    m_checkRenderWdl = new QCheckBox (this);
    m_checkRenderWdl->setText("Mountains");
    m_checkRenderWdl->setChecked(true);
    QSpacerItem *spacerRender = new QSpacerItem(1, 5, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_layoutVRender->addItem(spacerRender);
    m_layoutVRender->addWidget(m_checkRenderM2);
    m_layoutVRender->addWidget(m_checkRenderFarM2);
    m_layoutVRender->addWidget(m_checkRenderGroundDoodads);
    m_layoutVRender->addWidget(m_checkRenderTerrain);
    m_layoutVRender->addWidget(m_checkRenderWMO);
    m_layoutVRender->addWidget(m_checkRenderLiquid);
    m_layoutVRender->addWidget(m_checkRenderWdl);

    //m_layoutVRender->addWidget(m_checkRenderWireframe);

    QGroupBox *groupRender = new QGroupBox ("Render", this);
    groupRender->setLayout(m_layoutVRender);

    m_checkSlowMo = new QCheckBox (this);
    m_checkSlowMo->setText("Enable");
    m_buttonPlay = new QPushButton (this);
    m_buttonPlay->setToolTip("Play");
    m_buttonPlay->setFlat(true);
    m_buttonPlay->setStyleSheet("QPushButton{background-image: url(:/images/play_base.png);padding:0;margin:0;border:none;width: 8px;height: 18px;background-color:#2F2F2F}"
                                "QPushButton::hover{background-image: url(:/images/play_hover.png);padding:0;margin:0;border:none;width: 8px;height: 18px;}"
                                "QPushButton::pressed{background-image: url(:/images/play_pressed.png);padding:0;margin:0;border:none;width: 8px;height: 18px;}"
                                "QPushButton::disabled{background-image: url(:/images/play_pressed.png);padding:0;margin:0;border:none;width: 8px;height: 18px;}");
    m_buttonPlay->setDisabled(true);
    m_labelSlowMotion = new QLabel(this);
    m_labelSlowMotion->setText("Speed :");
    m_labelSlowMotion->setFixedWidth(36);
    m_labelSlowMotion->setDisabled(true);
    m_spinboxSlowMotion = new QDoubleSpinBox (this);
    m_spinboxSlowMotion->setDecimals(2);
    m_spinboxSlowMotion->setValue(0);
    m_spinboxSlowMotion->setMaximum(2);
    m_spinboxSlowMotion->setSingleStep(0.01);
    m_spinboxSlowMotion->setDisabled(true);
    m_labelSlowMotion2 = new QLabel(this);
    m_labelSlowMotion2->setText("to ");
    m_labelSlowMotion2->setFixedWidth(9);
    m_labelSlowMotion2->setDisabled(true);
    m_spinboxSlowMotion2 = new QDoubleSpinBox (this);
    m_spinboxSlowMotion2->setDecimals(2);
    m_spinboxSlowMotion2->setValue(2);
    m_spinboxSlowMotion2->setMaximum(2);
    m_spinboxSlowMotion2->setSingleStep(0.01);
    m_spinboxSlowMotion2->setDisabled(true);
    m_labelSlowMotion3 = new QLabel(this);
    m_labelSlowMotion3->setText("time(s) :");
    m_labelSlowMotion3->setFixedWidth(38);
    m_labelSlowMotion3->setDisabled(true);
    m_spinboxSlowMotion3 = new QSpinBox (this);
    m_spinboxSlowMotion3->setValue(10);
    m_spinboxSlowMotion3->setMaximum(10);
    m_spinboxSlowMotion3->setDisabled(true);
    m_layoutHSlowMotion2->addWidget(m_labelSlowMotion);
    m_layoutHSlowMotion2->addWidget(m_spinboxSlowMotion);
    m_layoutHSlowMotion2->addWidget(m_labelSlowMotion2);
    m_layoutHSlowMotion2->addWidget(m_spinboxSlowMotion2);
    m_layoutHSlowMotion2->addWidget(m_labelSlowMotion3);
    m_layoutHSlowMotion2->addWidget(m_spinboxSlowMotion3);
    QSpacerItem *spacerSlowMo = new QSpacerItem(249, 1, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_layoutHSlowMotion->addWidget(m_checkSlowMo);
    m_layoutHSlowMotion->addItem(spacerSlowMo);
    m_layoutHSlowMotion->addWidget(m_buttonPlay);
    //m_layoutVSlowMotion->addWidget(m_checkSlowMo);
    m_sliderSlowMo = new QSlider (Qt::Horizontal,this);
    m_sliderSlowMo->setRange(0,200);
    m_sliderSlowMo->setValue(0);
    m_sliderSlowMo->setDisabled(true);
    m_layoutVSlowMotion->addLayout(m_layoutHSlowMotion);
    m_layoutVSlowMotion->addLayout(m_layoutHSlowMotion2);
    m_layoutVSlowMotion->addWidget(m_sliderSlowMo);

    QGroupBox *groupSlowMotion = new QGroupBox ("Slow Motion", this);
    groupSlowMotion->setMaximumHeight(120);
    groupSlowMotion->setMinimumHeight(120);
    groupSlowMotion->setLayout(m_layoutVSlowMotion);

    m_timeEdit = new QTimeEdit (QTime::currentTime(),this);
    m_timeEdit->setDisplayFormat("hh:mm");
    m_layoutHTimeEdit->addWidget(m_timeEdit);
    m_labelTimeSpeed = new QLabelClickable (this);
    m_labelTimeSpeed->setText("Speed : ");
    m_spinboxTimeSpeed = new QDoubleSpinBox (this);
    m_spinboxTimeSpeed->setMaximum(1000.00);
    m_layoutHTimeSpeed->addWidget(m_labelTimeSpeed);
    m_layoutHTimeSpeed2->addWidget(m_spinboxTimeSpeed);

    QSpacerItem *spacerTime = new QSpacerItem(1, 5, QSizePolicy::Minimum, QSizePolicy::Maximum);

    m_layoutVTime->addItem(spacerTime);
    m_layoutVTime->addLayout(m_layoutHTimeEdit);
    m_layoutVTime->addLayout(m_layoutHTimeSpeed);
    m_layoutVTime->addLayout(m_layoutHTimeSpeed2);

    QGroupBox *groupTime = new QGroupBox ("Time", this);
    groupTime->setMaximumHeight(90);
    groupTime->setLayout(m_layoutVTime);

    m_layoutVCamera2->addWidget(groupSlowMotion);

    generalLayout->addLayout(m_layoutVCamera2);
    generalVLayout->addWidget(m_checkOnTop);
    QSpacerItem *spacerCheckOnTop = new QSpacerItem(1, 15, QSizePolicy::Minimum, QSizePolicy::Maximum);
    generalVLayout->addItem(spacerCheckOnTop);
    //generalVLayout->addWidget(groupShortCut);
    generalVLayout->addWidget(groupRender);
    generalVLayout->addWidget(groupTime);

    generalLayout->addLayout(generalVLayout);

    QSpacerItem *spacerTabGeneral = new QSpacerItem(1, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);
    generalV2Layout->addItem(spacerTabGeneral);

    generalV2Layout->addLayout(generalLayout);

    this->setLayout(generalV2Layout);

    //QObject::connect (m_labelFOV,SIGNAL(clicked()),this,SLOT(resetFOV()));
    //QObject::connect (m_sliderFOV,SIGNAL(valueChanged(qint32)),this,SLOT(setFOV(qint32)));
    QObject::connect (m_labelZoom,SIGNAL(clicked()),this,SLOT(resetZoom()));
    QObject::connect (m_sliderZoom,SIGNAL(valueChanged(qint32)),this,SLOT(setZoom(qint32)));
    QObject::connect (m_spinZoom,SIGNAL(valueChanged(double)),this,SLOT(setZoom(double)));
    QObject::connect (m_sliderAttachX,SIGNAL(valueChanged(qint32)),this,SLOT(setAttachX(qint32)));
    QObject::connect (m_spinAttachX,SIGNAL(valueChanged(double)),this,SLOT(setAttachX(double)));
    QObject::connect (m_sliderAttachY,SIGNAL(valueChanged(qint32)),this,SLOT(setAttachY(qint32)));
    QObject::connect (m_spinAttachY,SIGNAL(valueChanged(double)),this,SLOT(setAttachY(double)));
    QObject::connect (m_sliderAttachZ,SIGNAL(valueChanged(qint32)),this,SLOT(setAttachZ(qint32)));
    QObject::connect (m_spinAttachZ,SIGNAL(valueChanged(double)),this,SLOT(setAttachZ(double)));
    QObject::connect (m_labelAttachX,SIGNAL(clicked()),this,SLOT(resetAttachX()));
    QObject::connect (m_labelAttachY,SIGNAL(clicked()),this,SLOT(resetAttachY()));
    QObject::connect (m_labelAttachZ,SIGNAL(clicked()),this,SLOT(resetAttachZ()));
    QObject::connect (m_checkRenderM2, SIGNAL(toggled(bool)),this,SLOT(reactToToggleM2(bool)));
    //QObject::connect (m_checkRenderFarM2, SIGNAL(toggled(bool)),this,SLOT(reactToToggleFarM2(bool)));
    QObject::connect (m_checkRenderGroundDoodads, SIGNAL(toggled(bool)),this,SLOT(reactToToggleGroundDoodads(bool)));
    QObject::connect (m_checkRenderTerrain, SIGNAL(toggled(bool)),this,SLOT(reactToToggleTerrain(bool)));
    QObject::connect (m_checkRenderWMO, SIGNAL(toggled(bool)),this,SLOT(reactToToggleWMO(bool)));
    QObject::connect (m_checkRenderLiquid, SIGNAL(toggled(bool)),this,SLOT(reactToToggleLiquid(bool)));
    QObject::connect (m_checkRenderWdl, SIGNAL(toggled(bool)),this,SLOT(reactToToggleWdl(bool)));
    //QObject::connect (m_checkRenderWireframe, SIGNAL(toggled(bool)),this,SLOT(reactToToggleWireframe(bool)));
    QObject::connect (m_timeEdit,SIGNAL(timeChanged(QTime)),this,SLOT(changeTime(QTime)));
    QObject::connect (m_spinboxTimeSpeed,SIGNAL(valueChanged(double)), this,SLOT(changeTimeSpeed(double)));
    QObject::connect (m_labelTimeSpeed,SIGNAL(clicked()),this,SLOT(resetTimeSpeed()));

    QObject::connect (m_checkSlowMo,SIGNAL(toggled(bool)),this,SLOT(toggleSlowMo(bool)));
    //QObject::connect (m_spinboxSlowMotion,SIGNAL(valueChanged(double)),this,SLOT(changeSlowMo(double)));
    QObject::connect (m_sliderSlowMo,SIGNAL(valueChanged(qint32)),this,SLOT(changeSlowMo(qint32)));
    QObject::connect (m_buttonPlay,SIGNAL(clicked()),this,SLOT(changeSlowMo()));
    QObject::connect (m_checkOnTop,SIGNAL(toggled(bool)),this,SLOT(toggleOnTop(bool)));
    //QObject::connect (m_checkShortCut,SIGNAL(toggled(bool)),this,SLOT(toggleShortCut(bool)));
    //QObject::connect (m_buttonShortCut,SIGNAL(clicked()),this,SLOT(changeShortCut()));
}

UItabGeneral::~UItabGeneral()
{

}

void UItabGeneral::toggleOnTop(bool checked)
{
    if (checked)
    {
        m_parent->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    }
    else
    {
        m_parent->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
    }
    m_parent->show();
}

void UItabGeneral::toggleShortCut(bool checked)
{
    MainWidget* b = static_cast<MainWidget*>(m_parent);
    if (checked)
    {
        m_buttonShortCut->setEnabled(true);
        QFile fileHotKeys ("Hotkeys.txt");
        if (!fileHotKeys.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;// add error message!
        }
        else
        {
            b->enableHotKeys();
        }
    }
    else
    {
        m_buttonShortCut->setDisabled(true);
        b->disableHotKeys();
    }
}

void UItabGeneral::changeShortCut()
{
    UIHotKeys *uiHK = new UIHotKeys(this);
    uiHK->show();
}

void UItabGeneral::setFOV (qint32 i)
{
    CameraWow.setFOV(i);
    float j = i;
    j/=100;
    m_spinFOV->setValue(j);
}

void UItabGeneral::resetFOV()
{
    CameraWow.setFOV(150);
    m_sliderFOV->setValue(150);
}
void UItabGeneral::setZoom (qint32 i)
{
    CameraWow.setZoom(i);
    float j = i;
    j/=100;
    QObject::disconnect (m_spinZoom,SIGNAL(valueChanged(double)),this,SLOT(setZoom(double)));
    m_spinZoom->setValue(j);
    QObject::connect (m_spinZoom,SIGNAL(valueChanged(double)),this,SLOT(setZoom(double)));
}

void UItabGeneral::setZoom (double i)
{
    i*=100;
    qint32 j = i;
    CameraWow.setZoom(j);
    QObject::disconnect (m_sliderZoom,SIGNAL(valueChanged(qint32)),this,SLOT(setZoom(qint32)));
    m_sliderZoom->setValue(j);
    QObject::connect (m_sliderZoom,SIGNAL(valueChanged(qint32)),this,SLOT(setZoom(qint32)));
}

void UItabGeneral::resetZoom()
{
    CameraWow.setZoom(0);
    m_sliderZoom->setValue(0);
}

void UItabGeneral::setAttachX (qint32 i)
{
    CameraWow.setAttachX(i);
    float j = i;
    j/=100;
    QObject::disconnect (m_spinAttachX,SIGNAL(valueChanged(double)),this,SLOT(setAttachX(double)));
    m_spinAttachX->setValue(j);
    QObject::connect (m_spinAttachX,SIGNAL(valueChanged(double)),this,SLOT(setAttachX(double)));
}
void UItabGeneral::setAttachX (double i)
{
    i*=100;
    qint32 j = i;
    CameraWow.setAttachX(j);
    QObject::disconnect (m_sliderAttachX,SIGNAL(valueChanged(qint32)),this,SLOT(setAttachX(qint32)));
    m_sliderAttachX->setValue(j);
    QObject::connect (m_sliderAttachX,SIGNAL(valueChanged(qint32)),this,SLOT(setAttachX(qint32)));
}

void UItabGeneral::resetAttachX()
{
    CameraWow.setAttachX(0);
    m_sliderAttachX->setValue(0);
}

void UItabGeneral::setAttachY (qint32 i)
{
    CameraWow.setAttachY(i);
    float j = i;
    j/=100;
    QObject::disconnect (m_spinAttachY,SIGNAL(valueChanged(double)),this,SLOT(setAttachY(double)));
    m_spinAttachY->setValue(j);
    QObject::connect (m_spinAttachY,SIGNAL(valueChanged(double)),this,SLOT(setAttachY(double)));
}

void UItabGeneral::setAttachY (double i)
{
    i*=100;
    qint32 j = i;
    CameraWow.setAttachY(j);
    QObject::disconnect (m_sliderAttachY,SIGNAL(valueChanged(qint32)),this,SLOT(setAttachY(qint32)));
    m_sliderAttachY->setValue(j);
    QObject::connect (m_sliderAttachY,SIGNAL(valueChanged(qint32)),this,SLOT(setAttachY(qint32)));
}

void UItabGeneral::resetAttachY()
{
    CameraWow.setAttachY(0);
    m_sliderAttachY->setValue(0);
}

void UItabGeneral::setAttachZ (qint32 i)
{
    CameraWow.setAttachZ(i);
    float j = i;
    j/=100;
    QObject::connect (m_spinAttachZ,SIGNAL(valueChanged(double)),this,SLOT(setAttachZ(double)));
    m_spinAttachZ->setValue(j);
    QObject::connect (m_spinAttachZ,SIGNAL(valueChanged(double)),this,SLOT(setAttachZ(double)));
}

void UItabGeneral::setAttachZ (double i)
{
    i*=100;
    qint32 j = i;
    CameraWow.setAttachZ(j);
    QObject::disconnect (m_sliderAttachZ,SIGNAL(valueChanged(qint32)),this,SLOT(setAttachZ(qint32)));
    m_sliderAttachZ->setValue(j);
    QObject::connect (m_sliderAttachZ,SIGNAL(valueChanged(qint32)),this,SLOT(setAttachZ(qint32)));
}

void UItabGeneral::resetAttachZ()
{
    CameraWow.setAttachZ(0);
    m_sliderAttachZ->setValue(0);
}

void UItabGeneral::reactToToggleM2(bool checked)
{
    if (checked)
    {
        WowRender.enableM2();
    }
    else
    {
        WowRender.disableM2();
    }
}

void UItabGeneral::reactToToggleFarM2(bool checked)
{
    if (checked)
    {
        WowRender.enableFarM2();
    }
    else
    {
        WowRender.disableFarM2();
    }
}

void UItabGeneral::reactToToggleGroundDoodads(bool checked)
{
    if (checked)
    {
        WowRender.enableGroundDoodads();
    }
    else
    {
        WowRender.disableGroundDoodads();
    }
}

void UItabGeneral::reactToToggleTerrain(bool checked)
{
    if (checked)
    {
        WowRender.enableTerrain();
    }
    else
    {
        WowRender.disableTerrain();
    }
}
void UItabGeneral::reactToToggleWMO(bool checked)
{
    if (checked)
    {
        WowRender.enableWmo();
    }
    else
    {
        WowRender.disableWmo();
    }
}
void UItabGeneral::reactToToggleLiquid(bool checked)
{
    if (checked)
    {
        WowRender.enableLiquid();
    }
    else
    {
        WowRender.disableLiquid();
    }
}

void UItabGeneral::reactToToggleWdl(bool checked)
{
    if (checked)
    {
        WowRender.enableWdl();
    }
    else
    {
        WowRender.disableWdl();
    }
}
/*void UItabGeneral::reactToToggleWireframe(bool checked)
{
    if (checked)
    {
        WowRender.enableWireframe();
    }
    else
    {
        WowRender.disableWireframe();
    }
}*/

void UItabGeneral::changeTime(QTime Time)
{
    WowTime.setMin(m_timeEdit->time().minute());
    WowTime.setHour(m_timeEdit->time().hour());
}

void UItabGeneral::changeTimeSpeed(double Speed)
{
    WowTime.setSpeed(Speed);
}

void UItabGeneral::resetTimeSpeed()
{
    WowTime.setSpeed(0.01);//à vérifier++
    m_spinboxTimeSpeed->setValue(0.01);
}

void UItabGeneral::toggleSlowMo(bool checked)
{
    if (checked)
    {
        WowSlowMo.enableSlowMo();
        m_buttonPlay->setEnabled(true);
        m_labelSlowMotion->setEnabled(true);
        m_spinboxSlowMotion->setEnabled(true);
        m_labelSlowMotion2->setEnabled(true);
        m_spinboxSlowMotion2->setEnabled(true);
        m_labelSlowMotion3->setEnabled(true);
        m_spinboxSlowMotion3->setEnabled(true);
        m_sliderSlowMo->setEnabled(true);
    }
    else
    {
        WowSlowMo.disableSlowMo();
        m_buttonPlay->setDisabled(true);
        m_labelSlowMotion->setDisabled(true);
        m_spinboxSlowMotion->setDisabled(true);
        m_labelSlowMotion2->setDisabled(true);
        m_spinboxSlowMotion2->setDisabled(true);
        m_labelSlowMotion3->setDisabled(true);
        m_spinboxSlowMotion3->setDisabled(true);
        m_sliderSlowMo->setDisabled(true);
    }
}

void UItabGeneral::changeSlowMo()
{
    if (threadRunning == true)
    {
        WowSlowMo2->stop();
    }
    threadRunning = true;
    WowSlowMo2 = new slowmo();
    WowSlowMo2->setValue(m_spinboxSlowMotion->value(),m_spinboxSlowMotion2->value(),m_spinboxSlowMotion3->value());
    thread = new QThread ;
    WowSlowMo2 -> moveToThread(thread);
    connect (thread,SIGNAL(started()),this,SLOT(threadInit()));
    connect(thread, SIGNAL(started()), WowSlowMo2, SLOT(run()));
    connect(WowSlowMo2,SIGNAL(emitValue(float)),this,SLOT(changeSlowMo(float)));
    connect(WowSlowMo2, SIGNAL(finished()), thread, SLOT(quit()));
    connect(WowSlowMo2, SIGNAL(finished()), WowSlowMo2, SLOT(deleteLater()));
    connect(WowSlowMo2, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(WowSlowMo2, SIGNAL(end()), this, SLOT(threadFinished())); // probably ugly... didn't know how to do better.

       thread->start();
}

void UItabGeneral::threadInit()
{
    threadRunning = true;
    m_sliderSlowMo->setDisabled(true);
}

void UItabGeneral::threadFinished()
{
    threadRunning = false;
    m_sliderSlowMo->setEnabled(true);
}

void UItabGeneral::changeSlowMo(qint32 SlowMo)
{
    float SlowMoFl = SlowMo;
    SlowMoFl/=100000;
    WowSlowMo.setSpeed(SlowMoFl);
}

void UItabGeneral::changeSlowMo(float SlowMo)
{
    int SlowMoInt;
    SlowMoInt = SlowMo*100000;
    m_sliderSlowMo->setValue(SlowMoInt);
}
