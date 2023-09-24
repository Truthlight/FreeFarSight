/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "uitablight.h"

Light WowLight;
dbcLightParams lightParams;

UItabLight::UItabLight(QWidget *parent):QWidget(parent)
{
    m_checkToogleLight = new QCheckBox(this);//desactivate wow functions writting constantly on light params.
    m_checkToogleLight->setText("Enable");
    m_light1->addWidget(m_checkToogleLight);

    QSpacerItem *spacerTabLight = new QSpacerItem(1, 5, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_light1->addItem(spacerTabLight);

    //FOG

    m_buttonFogColor = new QPushButton(this);
    m_buttonFogColor->setText("Color");
    m_labelFogColor = new QLabel (this);
    m_colorFogColor = new QColor (32,31,31);
    m_labelFogColor->setStyleSheet("QLabel {background-color:"+m_colorFogColor->name()+";}");
    m_labelFogColor->setMaximumSize(30,15);
    m_fogColor->addWidget(m_buttonFogColor);
    m_fogColor->addWidget(m_labelFogColor);

    m_labelFogNearClip = new QLabel(this);
    m_labelFogNearClip->setText("Near Clip");
    m_spinFogNearClip = new QDoubleSpinBox (this);
    m_spinFogNearClip->setMinimum(-2500);
    m_spinFogNearClip->setMaximum(2500);
    m_fogNearClip->addWidget(m_labelFogNearClip);
    m_fogNearClip->addWidget(m_spinFogNearClip);

    m_labelFogFarClip = new QLabel(this);
    m_labelFogFarClip->setText("Far Clip");
    m_spinFogFarClip = new QDoubleSpinBox (this);
    m_spinFogFarClip->setMinimum(-2500);
    m_spinFogFarClip->setMaximum(2500);
    m_fogFarClip->addWidget(m_labelFogFarClip);
    m_fogFarClip->addWidget(m_spinFogFarClip);

    m_labelFogDensity = new QLabel(this);
    m_labelFogDensity->setText("Density");
    m_spinFogDensity = new QDoubleSpinBox (this);
    m_spinFogDensity->setMaximum(30);
    m_fogDensity->addWidget(m_labelFogDensity);
    m_fogDensity->addWidget(m_spinFogDensity);

    layoutFog->addLayout(m_fogColor);
    layoutFog->addLayout(m_fogNearClip);
    layoutFog->addLayout(m_fogFarClip);
    layoutFog->addLayout(m_fogDensity);

    m_groupFog = new QGroupBox ("Fog",this);
    m_groupFog->setDisabled(true);
    m_groupFog->setLayout(layoutFog);
    //m_groupFog->setMaximumHeight(100);
    m_light1->addWidget(m_groupFog);

    //LIGHT (ambient and diffuse color)

    m_buttonDiffuseColor = new QPushButton(this);
    m_buttonDiffuseColor->setText("Diffuse Color");
    m_labelDiffuseColor = new QLabel(this);
    m_colorDiffuseColor = new QColor (32,31,31);
    m_labelDiffuseColor->setStyleSheet("QLabel {background-color:"+m_colorDiffuseColor->name()+";}");
    m_labelDiffuseColor->setMaximumSize(30,15);
    m_diffuseColor->addWidget(m_buttonDiffuseColor);
    m_diffuseColor->addWidget(m_labelDiffuseColor);

    m_buttonAmbientColor = new QPushButton(this);
    m_buttonAmbientColor->setText("Ambient Color");
    m_labelAmbientColor = new QLabel(this);
    m_colorAmbientColor = new QColor (32,31,31);
    m_labelAmbientColor->setStyleSheet("QLabel {background-color:"+m_colorAmbientColor->name()+";}");
    m_labelAmbientColor->setMaximumSize(30,15);
    m_ambientColor->addWidget(m_buttonAmbientColor);
    m_ambientColor->addWidget(m_labelAmbientColor);
    layoutLight->addLayout(m_diffuseColor);
    layoutLight->addLayout(m_ambientColor);

    m_groupLight = new QGroupBox ("Light",this);
    m_groupLight->setDisabled(true);
    m_groupLight->setLayout(layoutLight);
    m_light1->addWidget(m_groupLight);

    //ENVIRONMENT

    m_spinEnvironment = new QSpinBox(this);
    m_labelEnvironment = new QLabel(this);
    m_labelEnvironment->setText("= ?");
    m_spinEnvironment->setMinimum(1);
    m_spinEnvironment->setMaximum(lightParams.readSize());

    m_buttonEnvReset = new QPushButton(this);
    m_buttonEnvReset->setText("Reset");
    layoutEnvironment2->addWidget(m_spinEnvironment);
    layoutEnvironment2->addWidget(m_labelEnvironment);
    layoutEnvironment->addLayout(layoutEnvironment2);
    layoutEnvironment->addWidget(m_buttonEnvReset);

    m_groupEnvironment = new QGroupBox ("Environment",this);
    m_groupEnvironment->setLayout(layoutEnvironment);
    if (m_spinEnvironment->maximum()==1)
    {
        widgetMB* MB = new widgetMB ("FFS", "LightParams.dbc is missing.\nEnvironment group box will be disabled.\nPlease download the whole repack if you wan't to use it");
        MB->show();
        m_groupEnvironment->setDisabled(true);
        m_groupEnvironment->setToolTip("Disabled because 'LightParams.dbc' is missing");
    }
    m_light1->addWidget(m_groupEnvironment);

    //SKY

    m_buttonSunHaloColor = new QPushButton(this);
    m_buttonSunHaloColor->setText("Sun + Halo Color");
    m_labelSunHaloColor = new QLabel(this);
    m_colorSunHaloColor = new QColor (32,31,31);
    m_labelSunHaloColor->setStyleSheet("QLabel {background-color:"+m_colorSunHaloColor->name()+";}");
    m_labelSunHaloColor->setMaximumSize(30,15);
    m_SunHaloColor->addWidget(m_buttonSunHaloColor);
    m_SunHaloColor->addWidget(m_labelSunHaloColor);

    m_buttonSkyColor0 = new QPushButton(this);
    m_buttonSkyColor0->setText("Sky Color 0");
    m_labelSkyColor0 = new QLabel(this);
    m_colorSkyColor0 = new QColor (32,31,31);
    m_labelSkyColor0->setStyleSheet("QLabel {background-color:"+m_colorSkyColor0->name()+";}");
    m_labelSkyColor0->setMaximumSize(30,15);
    m_skyColor0->addWidget(m_buttonSkyColor0);
    m_skyColor0->addWidget(m_labelSkyColor0);

    m_buttonSkyColor1 = new QPushButton(this);
    m_buttonSkyColor1->setText("Sky Color 1");
    m_labelSkyColor1 = new QLabel(this);
    m_colorSkyColor1 = new QColor (32,31,31);
    m_labelSkyColor1->setStyleSheet("QLabel {background-color:"+m_colorSkyColor1->name()+";}");
    m_labelSkyColor1->setMaximumSize(30,15);
    m_skyColor1->addWidget(m_buttonSkyColor1);
    m_skyColor1->addWidget(m_labelSkyColor1);

    m_buttonSkyColor2 = new QPushButton(this);
    m_buttonSkyColor2->setText("Sky Color 2");
    m_labelSkyColor2 = new QLabel(this);
    m_colorSkyColor2 = new QColor (32,31,31);
    m_labelSkyColor2->setStyleSheet("QLabel {background-color:"+m_colorSkyColor2->name()+";}");
    m_labelSkyColor2->setMaximumSize(30,15);
    m_skyColor2->addWidget(m_buttonSkyColor2);
    m_skyColor2->addWidget(m_labelSkyColor2);

    m_buttonSkyColor3 = new QPushButton(this);
    m_buttonSkyColor3->setText("Sky Color 3");
    m_labelSkyColor3 = new QLabel(this);
    m_colorSkyColor3 = new QColor (32,31,31);
    m_labelSkyColor3->setStyleSheet("QLabel {background-color:"+m_colorSkyColor3->name()+";}");
    m_labelSkyColor3->setMaximumSize(30,15);
    m_skyColor3->addWidget(m_buttonSkyColor3);
    m_skyColor3->addWidget(m_labelSkyColor3);

    m_buttonSkyColor4 = new QPushButton(this);
    m_buttonSkyColor4->setText("Sky Color 4");
    m_labelSkyColor4 = new QLabel(this);
    m_colorSkyColor4 = new QColor (32,31,31);
    m_labelSkyColor4->setStyleSheet("QLabel {background-color:"+m_colorSkyColor4->name()+";}");
    m_labelSkyColor4->setMaximumSize(30,15);
    m_skyColor4->addWidget(m_buttonSkyColor4);
    m_skyColor4->addWidget(m_labelSkyColor4);

    m_buttonSkyColor5 = new QPushButton(this);
    m_buttonSkyColor5->setText("Sky Color 5");
    m_labelSkyColor5 = new QLabel(this);
    m_colorSkyColor5 = new QColor (32,31,31);
    m_labelSkyColor5->setStyleSheet("QLabel {background-color:"+m_colorSkyColor5->name()+";}");
    m_labelSkyColor5->setMaximumSize(30,15);
    m_skyColor5->addWidget(m_buttonSkyColor5);
    m_skyColor5->addWidget(m_labelSkyColor5);

    layoutSky->addLayout(m_SunHaloColor);
    layoutSky->addLayout(m_skyColor0);
    layoutSky->addLayout(m_skyColor1);
    layoutSky->addLayout(m_skyColor2);
    layoutSky->addLayout(m_skyColor3);
    layoutSky->addLayout(m_skyColor4);
    layoutSky->addLayout(m_skyColor5);

    m_groupSky = new QGroupBox ("Sky",this);
    m_groupSky->setDisabled(true);
    m_groupSky->setLayout(layoutSky);
    m_light2->addWidget(m_groupSky);

    //VIEW DIST

    m_spinboxViewDist = new QSpinBox (this);
    m_spinboxViewDist->setMaximum(2500);
    m_layoutHViewDist->addWidget(m_spinboxViewDist);

    QGroupBox *groupViewDist = new QGroupBox ("View Distance", this);
    groupViewDist->setMaximumHeight(53);
    groupViewDist->setLayout(m_layoutHViewDist);
    m_light2->addWidget(groupViewDist);

    //CLOUD

    m_buttonCloudColor1 = new QPushButton(this);
    m_buttonCloudColor1->setText("Cloud Color 1");
    m_labelCloudColor1 = new QLabel(this);
    m_colorCloudColor1 = new QColor (32,31,31);
    m_labelCloudColor1->setStyleSheet("QLabel {background-color:"+m_colorCloudColor1->name()+";}");
    m_labelCloudColor1->setMaximumSize(30,15);
    m_cloudColor1->addWidget(m_buttonCloudColor1);
    m_cloudColor1->addWidget(m_labelCloudColor1);

    m_buttonCloudColor2 = new QPushButton(this);
    m_buttonCloudColor2->setText("Cloud Color 2");
    m_labelCloudColor2 = new QLabel(this);
    m_colorCloudColor2 = new QColor (32,31,31);
    m_labelCloudColor2->setStyleSheet("QLabel {background-color:"+m_colorCloudColor2->name()+";}");
    m_labelCloudColor2->setMaximumSize(30,15);
    m_cloudColor2->addWidget(m_buttonCloudColor2);
    m_cloudColor2->addWidget(m_labelCloudColor2);

    m_buttonCloudColor3 = new QPushButton(this);
    m_buttonCloudColor3->setText("Cloud Color 3");
    m_labelCloudColor3 = new QLabel(this);
    m_colorCloudColor3 = new QColor (32,31,31);
    m_labelCloudColor3->setStyleSheet("QLabel {background-color:"+m_colorCloudColor3->name()+";}");
    m_labelCloudColor3->setMaximumSize(30,15);
    m_cloudColor3->addWidget(m_buttonCloudColor3);
    m_cloudColor3->addWidget(m_labelCloudColor3);

    //m_labelCloudDensity = new QLabel (this);
    //m_labelCloudDensity->setText("Density");
    //m_spinCloudDensity = new QDoubleSpinBox;
    //m_spinCloudDensity->setMaximum(10000);
    //m_cloudDensity->addWidget(m_labelCloudDensity);
    //m_cloudDensity->addWidget(m_spinCloudDensity);

    layoutCloud->addLayout(m_cloudColor1);
    layoutCloud->addLayout(m_cloudColor2);
    layoutCloud->addLayout(m_cloudColor3);
    //layoutCloud->addLayout(m_cloudDensity);

    m_groupCloud = new QGroupBox ("Cloud",this);
    m_groupCloud->setDisabled(true);
    m_groupCloud->setMaximumHeight(90);
    m_groupCloud->setLayout(layoutCloud);
    m_light3->addWidget(m_groupCloud);

    //WATER

    m_buttonLakeEdgeColor = new QPushButton(this);
    m_buttonLakeEdgeColor->setText("Lake Edge Color");
    m_labelLakeEdgeColor = new QLabel(this);
    m_colorLakeEdgeColor = new QColor (32,31,31);
    m_labelLakeEdgeColor->setStyleSheet("QLabel {background-color:"+m_colorLakeEdgeColor->name()+";}");
    m_labelLakeEdgeColor->setMaximumSize(30,15);
    m_lakeEdgeColor->addWidget(m_buttonLakeEdgeColor);
    m_lakeEdgeColor->addWidget(m_labelLakeEdgeColor);

    m_buttonLakeMidColor = new QPushButton(this);
    m_buttonLakeMidColor->setText("Lake Mid Color");
    m_labelLakeMidColor = new QLabel(this);
    m_colorLakeMidColor = new QColor (32,31,31);
    m_labelLakeMidColor->setStyleSheet("QLabel {background-color:"+m_colorLakeMidColor->name()+";}");
    m_labelLakeMidColor->setMaximumSize(30,15);
    m_lakeMidColor->addWidget(m_buttonLakeMidColor);
    m_lakeMidColor->addWidget(m_labelLakeMidColor);

    m_buttonSeaEdgeColor = new QPushButton(this);
    m_buttonSeaEdgeColor->setText("Sea Edge Color");
    m_labelSeaEdgeColor = new QLabel(this);
    m_colorSeaEdgeColor = new QColor (32,31,31);
    m_labelSeaEdgeColor->setStyleSheet("QLabel {background-color:"+m_colorSeaEdgeColor->name()+";}");
    m_labelSeaEdgeColor->setMaximumSize(30,15);
    m_seaEdgeColor->addWidget(m_buttonSeaEdgeColor);
    m_seaEdgeColor->addWidget(m_labelSeaEdgeColor);

    m_buttonSeaMidColor = new QPushButton(this);
    m_buttonSeaMidColor->setText("Sea Mid Color");
    m_labelSeaMidColor = new QLabel(this);
    m_colorSeaMidColor = new QColor (32,31,31);
    m_labelSeaMidColor->setStyleSheet("QLabel {background-color:"+m_colorSeaMidColor->name()+";}");
    m_labelSeaMidColor->setMaximumSize(30,15);
    m_seaMidColor->addWidget(m_buttonSeaMidColor);
    m_seaMidColor->addWidget(m_labelSeaMidColor);

    layoutWater->addLayout(m_lakeEdgeColor);
    layoutWater->addLayout(m_lakeMidColor);
    layoutWater->addLayout(m_seaEdgeColor);
    layoutWater->addLayout(m_seaMidColor);

    m_groupWater = new QGroupBox ("Water",this);
    m_groupWater->setDisabled(true);
    m_groupWater->setLayout(layoutWater);
    m_light3->addWidget(m_groupWater);

    //SAVE&LOAD

    m_buttonLoadList = new QPushButton(this);
    m_buttonLoadList->setText("Load");
    m_buttonLoadList->setFlat(true);

    m_buttonSaveList = new QPushButton(this);
    m_buttonSaveList->setText("Save");
    m_buttonSaveList->setFlat(true);

    layoutLoadSave->addWidget(m_buttonLoadList);
    layoutLoadSave->addWidget(m_buttonSaveList);

    m_groupLoadSave = new QGroupBox ("Load/Save", this);
    m_groupLoadSave->setMaximumHeight(53);
    m_groupLoadSave->setLayout(layoutLoadSave);
    m_groupLoadSave->setDisabled(true);

    m_light3->addWidget(m_groupLoadSave);

    m_light->addLayout(m_light1);
    m_light->addLayout(m_light2);
    m_light->addLayout(m_light3);

    QSpacerItem *spacerTabLight2 = new QSpacerItem(1, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);
    lightLayout->addItem(spacerTabLight2);
    lightLayout->addLayout(m_light);

    this->setLayout(lightLayout);

    QObject::connect (m_spinboxViewDist,SIGNAL(valueChanged(qint32)),this,SLOT(changeViewDist(qint32)));
    QObject::connect(m_checkToogleLight,SIGNAL(toggled(bool)),this,SLOT(reactToToogleTab(bool)));
    QObject::connect (m_buttonFogColor,SIGNAL(clicked()),this,SLOT(setFogColor()));
    QObject::connect (m_spinFogNearClip,SIGNAL(valueChanged(double)),this,SLOT(setFogNearClip(double)));
    QObject::connect (m_spinFogFarClip,SIGNAL(valueChanged(double)),this,SLOT(setFogFarClip(double)));
    QObject::connect (m_spinFogDensity,SIGNAL(valueChanged(double)),this,SLOT(setFogDensity(double)));
    QObject::connect (m_buttonDiffuseColor,SIGNAL(clicked()),this,SLOT(setDiffuseLight()));
    QObject::connect (m_buttonAmbientColor,SIGNAL(clicked()),this,SLOT(setAmbientLight()));
    QObject::connect (m_spinEnvironment,SIGNAL(valueChanged(qint32)),this,SLOT(setEnvironment(qint32)));
    QObject::connect (m_buttonEnvReset,SIGNAL(clicked()),this,SLOT(undoEnvironment()));
    QObject::connect (m_buttonSunHaloColor,SIGNAL(clicked()),this,SLOT(setSunColor()));
    QObject::connect (m_buttonSkyColor0,SIGNAL(clicked()),this,SLOT(setSkyColor0()));
    QObject::connect (m_buttonSkyColor1,SIGNAL(clicked()),this,SLOT(setSkyColor1()));
    QObject::connect (m_buttonSkyColor2,SIGNAL(clicked()),this,SLOT(setSkyColor2()));
    QObject::connect (m_buttonSkyColor3,SIGNAL(clicked()),this,SLOT(setSkyColor3()));
    QObject::connect (m_buttonSkyColor4,SIGNAL(clicked()),this,SLOT(setSkyColor4()));
    QObject::connect (m_buttonSkyColor5,SIGNAL(clicked()),this,SLOT(setSkyColor5()));
    QObject::connect (m_buttonCloudColor1,SIGNAL(clicked()),this,SLOT(setCloudColor1()));
    QObject::connect (m_buttonCloudColor2,SIGNAL(clicked()),this,SLOT(setCloudColor2()));
    QObject::connect (m_buttonCloudColor3,SIGNAL(clicked()),this,SLOT(setCloudColor3()));
    QObject::connect (m_buttonLakeEdgeColor,SIGNAL(clicked()),this,SLOT(setLakeEdgeColor()));
    QObject::connect (m_buttonLakeMidColor,SIGNAL(clicked()),this,SLOT(setLakeMidColor()));
    QObject::connect (m_buttonSeaEdgeColor,SIGNAL(clicked()),this,SLOT(setSeaEdgeColor()));
    QObject::connect (m_buttonSeaMidColor,SIGNAL(clicked()),this,SLOT(setSeaMidColor()));
    QObject::connect(m_buttonLoadList,SIGNAL(clicked()),this,SLOT(loadList()));
    QObject::connect(m_buttonSaveList,SIGNAL(clicked()),this,SLOT(saveList()));
}

UItabLight::~UItabLight()
{

}

void UItabLight::reactToToogleTab(bool checked)
{
    if (checked)
    {
        m_groupFog->setEnabled(true);
        m_groupLight->setEnabled(true);
        m_groupSky->setEnabled(true);
        m_groupCloud->setEnabled(true);
        m_groupWater->setEnabled(true);
        m_groupLoadSave->setEnabled(true);
        WowLight.EnableCustomEnv();
        QColor fogColor (WowLight.getFogColor());
        m_labelFogColor->setStyleSheet("QLabel {background-color:"+fogColor.name()+";}");
        m_spinFogNearClip->setValue(WowLight.getFogNearClip());
        m_spinFogFarClip->setValue(WowLight.getFogFarClip());
        m_spinFogDensity->setValue(WowLight.getFogDensity());
        QColor diffuseColor (WowLight.getDiffuseColor());
        m_labelDiffuseColor->setStyleSheet("QLabel {background-color:"+diffuseColor.name()+";}");
        QColor ambientColor (WowLight.getAmbientColor());
        m_labelAmbientColor->setStyleSheet("QLabel {background-color:"+ambientColor.name()+";}");
        QColor sunColor (WowLight.getSunHaloColor());
        m_labelSunHaloColor->setStyleSheet("QLabel {background-color:"+sunColor.name()+";}");
        QColor skyColor0 (WowLight.getSkyColor0());
        m_labelSkyColor0->setStyleSheet("QLabel {background-color:"+skyColor0.name()+";}");
        QColor skyColor1 (WowLight.getSkyColor1());
        m_labelSkyColor1->setStyleSheet("QLabel {background-color:"+skyColor1.name()+";}");
        QColor skyColor2 (WowLight.getSkyColor2());
        m_labelSkyColor2->setStyleSheet("QLabel {background-color:"+skyColor2.name()+";}");
        QColor skyColor3 (WowLight.getSkyColor3());
        m_labelSkyColor3->setStyleSheet("QLabel {background-color:"+skyColor3.name()+";}");
        QColor skyColor4 (WowLight.getSkyColor4());
        m_labelSkyColor4->setStyleSheet("QLabel {background-color:"+skyColor4.name()+";}");
        QColor skyColor5 (WowLight.getSkyColor5());
        m_labelSkyColor5->setStyleSheet("QLabel {background-color:"+skyColor5.name()+";}");
        QColor cloudColor1 (WowLight.getCloudColor1());
        m_labelCloudColor1->setStyleSheet("QLabel {background-color:"+cloudColor1.name()+";}");
        QColor cloudColor2 (WowLight.getCloudColor2());
        m_labelCloudColor2->setStyleSheet("QLabel {background-color:"+cloudColor2.name()+";}");
        QColor cloudColor3 (WowLight.getCloudColor3());
        m_labelCloudColor3->setStyleSheet("QLabel {background-color:"+cloudColor3.name()+";}");
        QColor lakeEdgeColor (WowLight.getLakeEdgeColor());
        m_labelLakeEdgeColor->setStyleSheet("QLabel {background-color:"+lakeEdgeColor.name()+";}");
        QColor lakeMidColor (WowLight.getLakeMidColor());
        m_labelLakeMidColor->setStyleSheet("QLabel {background-color:"+lakeMidColor.name()+";}");
        QColor seaEdgeColor (WowLight.getSeaEdgeColor());
        m_labelSeaEdgeColor->setStyleSheet("QLabel {background-color:"+seaEdgeColor.name()+";}");
        QColor seaMidColor (WowLight.getSeaMidColor());
        m_labelSeaMidColor->setStyleSheet("QLabel {background-color:"+seaMidColor.name()+";}");
    }
    else
    {
        m_groupFog->setDisabled(true);
        m_groupLight->setDisabled(true);
        m_groupSky->setDisabled(true);
        m_groupCloud->setDisabled(true);
        m_groupWater->setDisabled(true);
        m_groupLoadSave->setDisabled(true);
        WowLight.DisableCustomEnv();
        m_labelFogColor->setStyleSheet("QLabel {background-color:"+m_colorFogColor->name()+";}");
        m_labelDiffuseColor->setStyleSheet("QLabel {background-color:"+m_colorDiffuseColor->name()+";}");
        m_labelAmbientColor->setStyleSheet("QLabel {background-color:"+m_colorAmbientColor->name()+";}");
        m_labelSunHaloColor->setStyleSheet("QLabel {background-color:"+m_colorSunHaloColor->name()+";}");
        m_labelSkyColor0->setStyleSheet("QLabel {background-color:"+m_colorSkyColor0->name()+";}");
        m_labelSkyColor1->setStyleSheet("QLabel {background-color:"+m_colorSkyColor1->name()+";}");
        m_labelSkyColor2->setStyleSheet("QLabel {background-color:"+m_colorSkyColor2->name()+";}");
        m_labelSkyColor3->setStyleSheet("QLabel {background-color:"+m_colorSkyColor3->name()+";}");
        m_labelSkyColor4->setStyleSheet("QLabel {background-color:"+m_colorSkyColor4->name()+";}");
        m_labelSkyColor5->setStyleSheet("QLabel {background-color:"+m_colorSkyColor5->name()+";}");
        m_labelCloudColor1->setStyleSheet("QLabel {background-color:"+m_colorCloudColor1->name()+";}");
        m_labelCloudColor2->setStyleSheet("QLabel {background-color:"+m_colorCloudColor2->name()+";}");
        m_labelCloudColor3->setStyleSheet("QLabel {background-color:"+m_colorCloudColor3->name()+";}");
        m_labelLakeEdgeColor->setStyleSheet("QLabel {background-color:"+m_colorLakeEdgeColor->name()+";}");
        m_labelLakeMidColor->setStyleSheet("QLabel {background-color:"+m_colorLakeMidColor->name()+";}");
        m_labelSeaEdgeColor->setStyleSheet("QLabel {background-color:"+m_colorSeaEdgeColor->name()+";}");
        m_labelSeaMidColor->setStyleSheet("QLabel {background-color:"+m_colorSeaMidColor->name()+";}");
    }
}

void UItabLight::changeViewDist(qint32 ViewDist)
{
    qint32  baseAdr = MemoryWow.getBaseAdr();
    float ViewDistFloat = ViewDist;
    MemoryWow.MWrite <float>(baseAdr + Offsets::viewDistance, ViewDistFloat);
}

void UItabLight::setFogColor()
{
    QColor fogColor (WowLight.getFogColor());
    ColorPicker *m_dialogFogColor = new ColorPicker(fogColor,this);
    if (m_dialogFogColor->exec()==QDialog::Accepted)
    {
        QColor newFogColor = m_dialogFogColor->getColor();
        delete m_dialogFogColor;
        WowLight.setFogColor(newFogColor.rgb());
        m_labelFogColor->setStyleSheet("QLabel {background-color:"+newFogColor.name()+";}");
    }
    else
    {
        delete m_dialogFogColor;
        return;
    }
}

void UItabLight::setFogNearClip(double NearClip)
{
    float nearClip = NearClip;
    WowLight.setFogNearClip(nearClip);
}

void UItabLight::setFogFarClip(double FarClip)
{
    float farClip = FarClip;
    WowLight.setFogFarClip(farClip);
}

void UItabLight::setFogDensity(double Density)
{
    float density = Density;
    WowLight.setFogDensity(density);
}

void UItabLight::setDiffuseLight()
{
    QColor diffuseColor (WowLight.getDiffuseColor());
    ColorPicker *m_dialogDiffuseColor = new ColorPicker(diffuseColor,this);
    if (m_dialogDiffuseColor->exec()==QDialog::Accepted)
    {
        QColor newDiffuseColor = m_dialogDiffuseColor->getColor();
        delete m_dialogDiffuseColor;
        WowLight.setDiffuseColor(newDiffuseColor.rgb());
        m_labelDiffuseColor->setStyleSheet("QLabel {background-color:"+newDiffuseColor.name()+";}");
    }
    else
    {
        delete m_dialogDiffuseColor;
        return;
    }
}

void UItabLight::setAmbientLight()
{
    QColor ambientColor (WowLight.getAmbientColor());
    ColorPicker *m_dialogAmbientColor = new ColorPicker(ambientColor,this);
    if (m_dialogAmbientColor->exec()==QDialog::Accepted)
    {
        QColor newAmbientColor = m_dialogAmbientColor->getColor();
        delete m_dialogAmbientColor;
        WowLight.setAmbientColor(newAmbientColor.rgb());
        m_labelAmbientColor->setStyleSheet("QLabel {background-color:"+newAmbientColor.name()+";}");
    }
    else
    {
        delete m_dialogAmbientColor;
        return;
    }
}

void UItabLight::setEnvironment(qint32 env)
{
    QFile dbcLP ("LightParams.dbc");

    if (dbcLP.exists())
    {
        WowLight.setEnvironment(env);
        qint32 number = lightParams.readSkyNumber(env);
        QString s = QString::number(number);
        m_labelEnvironment->setText("= "+s);
    }
    else
    {
        widgetMB* MB = new widgetMB ("FFS", "LightParams.dbc is missing.\nEnvironment group box will be disabled.\nPlease download the whole repack if you wan't to use it",this);
        MB->show();
        m_groupEnvironment->setDisabled(true);
        m_groupEnvironment->setToolTip("Disabled because 'LightParams.dbc' is missing");
    }
}

void UItabLight::undoEnvironment()
{
    QFile dbcLP ("LightParams.dbc");

    if (dbcLP.exists())
    {
        WowLight.setEnvironmentUndo();
    }
    else
    {
        widgetMB* MB = new widgetMB ("FFS", "LightParams.dbc is missing.\nEnvironment group box will be disabled.\nPlease download the whole repack if you wan't to use it",this);
        MB->show();
        m_groupEnvironment->setDisabled(true);
        m_groupEnvironment->setToolTip("Disabled because 'LightParams.dbc' is missing");
    }
}

void UItabLight::setSunColor()
{
    QColor sunColor (WowLight.getSunHaloColor());
    ColorPicker *m_dialogSunColor = new ColorPicker(sunColor,this);
    if (m_dialogSunColor->exec()==QDialog::Accepted)
    {
        QColor newSunColor = m_dialogSunColor->getColor();
        delete m_dialogSunColor;
        WowLight.setSunHaloColor(newSunColor.rgb());
        m_labelSunHaloColor->setStyleSheet("QLabel {background-color:"+newSunColor.name()+";}");
    }
    else
    {
        delete m_dialogSunColor;
        return;
    }
}

void UItabLight::setSkyColor0()
{
    QColor skyColor (WowLight.getSkyColor0());
    ColorPicker *m_dialogSkyColor = new ColorPicker(skyColor,this);
    if (m_dialogSkyColor->exec()==QDialog::Accepted)
    {
        QColor newSkyColor = m_dialogSkyColor->getColor();
        delete m_dialogSkyColor;
        WowLight.setSkyColor0(newSkyColor.rgb());
        m_labelSkyColor0->setStyleSheet("QLabel {background-color:"+newSkyColor.name()+";}");
    }
    else
    {
        delete m_dialogSkyColor;
        return;
    }
}

void UItabLight::setSkyColor1()
{
    QColor skyColor (WowLight.getSkyColor1());
    ColorPicker *m_dialogSkyColor = new ColorPicker(skyColor,this);
    if (m_dialogSkyColor->exec()==QDialog::Accepted)
    {
        QColor newSkyColor = m_dialogSkyColor->getColor();
        delete m_dialogSkyColor;
        WowLight.setSkyColor1(newSkyColor.rgb());
        m_labelSkyColor1->setStyleSheet("QLabel {background-color:"+newSkyColor.name()+";}");
    }
    else
    {
        delete m_dialogSkyColor;
        return;
    }
}

void UItabLight::setSkyColor2()
{
    QColor skyColor (WowLight.getSkyColor2());
    ColorPicker *m_dialogSkyColor = new ColorPicker(skyColor,this);
    if (m_dialogSkyColor->exec()==QDialog::Accepted)
    {
        QColor newSkyColor = m_dialogSkyColor->getColor();
        delete m_dialogSkyColor;
        WowLight.setSkyColor2(newSkyColor.rgb());
        m_labelSkyColor2->setStyleSheet("QLabel {background-color:"+newSkyColor.name()+";}");
    }
    else
    {
        delete m_dialogSkyColor;
        return;
    }
}

void UItabLight::setSkyColor3()
{
    QColor skyColor (WowLight.getSkyColor3());
    ColorPicker *m_dialogSkyColor = new ColorPicker(skyColor,this);
    if (m_dialogSkyColor->exec()==QDialog::Accepted)
    {
        QColor newSkyColor = m_dialogSkyColor->getColor();
        delete m_dialogSkyColor;
        WowLight.setSkyColor3(newSkyColor.rgb());
        m_labelSkyColor3->setStyleSheet("QLabel {background-color:"+newSkyColor.name()+";}");
    }
    else
    {
        delete m_dialogSkyColor;
        return;
    }
}

void UItabLight::setSkyColor4()
{
    QColor skyColor (WowLight.getSkyColor4());
    ColorPicker *m_dialogSkyColor = new ColorPicker(skyColor,this);
    if (m_dialogSkyColor->exec()==QDialog::Accepted)
    {
        QColor newSkyColor = m_dialogSkyColor->getColor();
        delete m_dialogSkyColor;
        WowLight.setSkyColor4(newSkyColor.rgb());
        m_labelSkyColor4->setStyleSheet("QLabel {background-color:"+newSkyColor.name()+";}");
    }
    else
    {
        delete m_dialogSkyColor;
        return;
    }
}

void UItabLight::setSkyColor5()
{
    QColor skyColor (WowLight.getSkyColor5());
    ColorPicker *m_dialogSkyColor = new ColorPicker(skyColor,this);
    if (m_dialogSkyColor->exec()==QDialog::Accepted)
    {
        QColor newSkyColor = m_dialogSkyColor->getColor();
        delete m_dialogSkyColor;
        WowLight.setSkyColor5(newSkyColor.rgb());
        m_labelSkyColor5->setStyleSheet("QLabel {background-color:"+newSkyColor.name()+";}");
    }
    else
    {
        delete m_dialogSkyColor;
        return;
    }
}

void UItabLight::setCloudColor1()
{
    QColor cloudColor (WowLight.getCloudColor1());
    ColorPicker *m_dialogCloudColor = new ColorPicker(cloudColor,this);
    if (m_dialogCloudColor->exec()==QDialog::Accepted)
    {
        QColor newCloudColor = m_dialogCloudColor->getColor();
        delete m_dialogCloudColor;
        WowLight.setCloudColor1(newCloudColor.rgb());
        m_labelCloudColor1->setStyleSheet("QLabel {background-color:"+newCloudColor.name()+";}");
    }
    else
    {
        delete m_dialogCloudColor;
        return;
    }
}

void UItabLight::setCloudColor2()
{
    QColor cloudColor (WowLight.getCloudColor2());
    ColorPicker *m_dialogCloudColor = new ColorPicker(cloudColor,this);
    if (m_dialogCloudColor->exec()==QDialog::Accepted)
    {
        QColor newCloudColor = m_dialogCloudColor->getColor();
        delete m_dialogCloudColor;
        WowLight.setCloudColor2(newCloudColor.rgb());
        m_labelCloudColor2->setStyleSheet("QLabel {background-color:"+newCloudColor.name()+";}");
    }
    else
    {
        delete m_dialogCloudColor;
        return;
    }
}

void UItabLight::setCloudColor3()
{
    QColor cloudColor (WowLight.getCloudColor3());
    ColorPicker *m_dialogCloudColor = new ColorPicker(cloudColor,this);
    if (m_dialogCloudColor->exec()==QDialog::Accepted)
    {
        QColor newCloudColor = m_dialogCloudColor->getColor();
        delete m_dialogCloudColor;
        WowLight.setCloudColor3(newCloudColor.rgb());
        m_labelCloudColor3->setStyleSheet("QLabel {background-color:"+newCloudColor.name()+";}");
    }
    else
    {
        delete m_dialogCloudColor;
        return;
    }
}

void UItabLight::setCloudDensity(double CloudDensity)
{
    float cloudDensity = CloudDensity;
    WowLight.setCloudDensity(cloudDensity);
}

void UItabLight::setLakeEdgeColor()
{
    QColor lakeEdgeColor (WowLight.getLakeEdgeColor());
    ColorPicker *m_dialogLakeEdgeColor = new ColorPicker(lakeEdgeColor,this);
    if (m_dialogLakeEdgeColor->exec()==QDialog::Accepted)
    {
        QColor newLakeEdgeColor = m_dialogLakeEdgeColor->getColor();
        delete m_dialogLakeEdgeColor;
        WowLight.setLakeEdgeColor(newLakeEdgeColor.rgb());
        m_labelLakeEdgeColor->setStyleSheet("QLabel {background-color:"+newLakeEdgeColor.name()+";}");
    }
    else
    {
        delete m_dialogLakeEdgeColor;
        return;
    }
}

void UItabLight::setLakeMidColor()
{
    QColor lakeMidColor (WowLight.getLakeMidColor());
    ColorPicker *m_dialogLakeMidColor = new ColorPicker(lakeMidColor,this);
    if (m_dialogLakeMidColor->exec()==QDialog::Accepted)
    {
        QColor newLakeMidColor = m_dialogLakeMidColor->getColor();
        delete m_dialogLakeMidColor;
        WowLight.setLakeMidColor(newLakeMidColor.rgb());
        m_labelLakeMidColor->setStyleSheet("QLabel {background-color:"+newLakeMidColor.name()+";}");
    }
    else
    {
        delete m_dialogLakeMidColor;
        return;
    }
}

void UItabLight::setSeaEdgeColor()
{
    QColor seaEdgeColor (WowLight.getSeaEdgeColor());
    ColorPicker *m_dialogSeaEdgeColor = new ColorPicker(seaEdgeColor,this);
    if (m_dialogSeaEdgeColor->exec()==QDialog::Accepted)
    {
        QColor newSeaEdgeColor = m_dialogSeaEdgeColor->getColor();
        delete m_dialogSeaEdgeColor;
        WowLight.setSeaEdgeColor(newSeaEdgeColor.rgb());
        m_labelSeaEdgeColor->setStyleSheet("QLabel {background-color:"+newSeaEdgeColor.name()+";}");
    }
    else
    {
        delete m_dialogSeaEdgeColor;
        return;
    }
}

void UItabLight::setSeaMidColor()
{
    QColor seaMidColor (WowLight.getSeaMidColor());
    ColorPicker *m_dialogSeaMidColor = new ColorPicker(seaMidColor,this);
    if (m_dialogSeaMidColor->exec()==QDialog::Accepted)
    {
        QColor newSeaMidColor = m_dialogSeaMidColor->getColor();
        delete m_dialogSeaMidColor;
        WowLight.setSeaMidColor(newSeaMidColor.rgb());
        m_labelSeaMidColor->setStyleSheet("QLabel {background-color:"+newSeaMidColor.name()+";}");
    }
    else
    {
        delete m_dialogSeaMidColor;
        return;
    }
}

void UItabLight::saveList()
{
    QStringList filters;
    filters << "*.txt";
    m_dir = QDir(QDir::currentPath() + "/LightCustom");
    m_dir.setNameFilters(filters);
    m_list = m_dir.entryList();
    m_list.replaceInStrings(".txt","");
    widgetMBDialog2 *mb = new widgetMBDialog2 ("FFS","Select Light List", m_list,this);
    if (mb->exec() == QDialog::Accepted)
    {
        QString fileName = mb->getNameFile();
        delete mb;
        if (fileName == NULL)
        {
            widgetMB *mb = new widgetMB ("FFS","You didn't choose a filename, Light list has not been saved",this);
            mb->show();
            return;
        }
        QFile file ("LightCustom/"+fileName+".txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
        QTextStream fichier (&file);

        QByteArray buffer;

        fichier <<buffer.number(WowLight.getFogColor(),16).right(6)<<" "<<  //WTF? read color in memory -> convert in hex -> remove useless byte "FF" (more readable in .txt file)
              WowLight.getFogNearClip()<<" "<<
              WowLight.getFogFarClip()<<" "<<
              WowLight.getFogDensity()<<" "<<
              buffer.number(WowLight.getDiffuseColor(),16).right(6)<<" "<<
              buffer.number(WowLight.getAmbientColor(),16).right(6)<<" "<<
              buffer.number(WowLight.getSunHaloColor(),16).right(6)<<" "<<
              buffer.number(WowLight.getSkyColor0(),16).right(6)<<" "<<
              buffer.number(WowLight.getSkyColor1(),16).right(6)<<" "<<
              buffer.number(WowLight.getSkyColor2(),16).right(6)<<" "<<
              buffer.number(WowLight.getSkyColor3(),16).right(6)<<" "<<
              buffer.number(WowLight.getSkyColor4(),16).right(6)<<" "<<
              buffer.number(WowLight.getSkyColor5(),16).right(6)<<" "<<
              buffer.number(WowLight.getCloudColor1(),16).right(6)<<" "<<
              buffer.number(WowLight.getCloudColor2(),16).right(6)<<" "<<
              buffer.number(WowLight.getCloudColor3(),16).right(6)<<" "<<
              buffer.number(WowLight.getLakeEdgeColor(),16).right(6)<<" "<<
              buffer.number(WowLight.getLakeMidColor(),16).right(6)<<" "<<
              buffer.number(WowLight.getSeaEdgeColor(),16).right(6)<<" "<<
              buffer.number(WowLight.getSeaMidColor(),16).right(6);
        file.close();
    }
    else
    {
        delete mb;
        return;
    }
}

void UItabLight::loadList()
{
    QStringList filters;
    filters << "*.txt";
    m_dir = QDir(QDir::currentPath() + "/LightCustom");
    m_dir.setNameFilters(filters);
    m_list = m_dir.entryList();
    m_list.replaceInStrings(".txt","");
    widgetMBDialog *mb = new widgetMBDialog ("FFS","Select Light list", m_list, this);
    if (mb->exec() == QDialog::Accepted)
    {
        QString fileName = mb->getNameFile();
        delete mb;
        QFile file ("LightCustom/"+fileName+".txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
        QTextStream fichier (&file);
        QString ligne;
        QStringList lightList;
        while( !fichier.atEnd() )
        {
            //getline(fichier, ligne.toStdString());//lecture d'une ligne du fichier
            ligne=fichier.readLine();
            lightList = ligne.split(" ");

            WowLight.setFogColor(lightList.at(0).toInt(0,16));
            m_labelFogColor->setStyleSheet("QLabel {background-color:#"+lightList.at(0)+";}");

            WowLight.setFogNearClip(lightList.at(1).toDouble());
            m_spinFogNearClip->setValue(lightList.at(1).toDouble());

            WowLight.setFogFarClip(lightList.at(2).toDouble());
            m_spinFogFarClip->setValue(lightList.at(2).toDouble());

            WowLight.setFogDensity(lightList.at(3).toDouble());
            m_spinFogDensity->setValue(lightList.at(3).toDouble());

            WowLight.setDiffuseColor(lightList.at(4).toInt(0,16));
            m_labelDiffuseColor->setStyleSheet("QLabel {background-color:#"+lightList.at(4)+";}");

            WowLight.setAmbientColor(lightList.at(5).toInt(0,16));
            m_labelAmbientColor->setStyleSheet("QLabel {background-color:#"+lightList.at(5)+";}");

            WowLight.setSunHaloColor(lightList.at(6).toInt(0,16));
            m_labelSunHaloColor->setStyleSheet("QLabel {background-color:#"+lightList.at(6)+";}");

            WowLight.setSkyColor0(lightList.at(7).toInt(0,16));
            m_labelSkyColor0->setStyleSheet("QLabel {background-color:#"+lightList.at(7)+";}");

            WowLight.setSkyColor1(lightList.at(8).toInt(0,16));
            m_labelSkyColor1->setStyleSheet("QLabel {background-color:#"+lightList.at(8)+";}");

            WowLight.setSkyColor2(lightList.at(9).toInt(0,16));
            m_labelSkyColor2->setStyleSheet("QLabel {background-color:#"+lightList.at(9)+";}");

            WowLight.setSkyColor3(lightList.at(10).toInt(0,16));
            m_labelSkyColor3->setStyleSheet("QLabel {background-color:#"+lightList.at(10)+";}");

            WowLight.setSkyColor4(lightList.at(11).toInt(0,16));
            m_labelSkyColor4->setStyleSheet("QLabel {background-color:#"+lightList.at(11)+";}");

            WowLight.setSkyColor5(lightList.at(12).toInt(0,16));
            m_labelSkyColor5->setStyleSheet("QLabel {background-color:#"+lightList.at(12)+";}");

            WowLight.setCloudColor1(lightList.at(13).toInt(0,16));
            m_labelCloudColor1->setStyleSheet("QLabel {background-color:#"+lightList.at(13)+";}");

            WowLight.setCloudColor2(lightList.at(14).toInt(0,16));
            m_labelCloudColor2->setStyleSheet("QLabel {background-color:#"+lightList.at(14)+";}");

            WowLight.setCloudColor3(lightList.at(15).toInt(0,16));
            m_labelCloudColor3->setStyleSheet("QLabel {background-color:#"+lightList.at(15)+";}");

            WowLight.setLakeEdgeColor(lightList.at(16).toInt(0,16));
            m_labelLakeEdgeColor->setStyleSheet("QLabel {background-color:#"+lightList.at(16)+";}");

            WowLight.setLakeMidColor(lightList.at(17).toInt(0,16));
            m_labelLakeMidColor->setStyleSheet("QLabel {background-color:#"+lightList.at(17)+";}");

            WowLight.setSeaEdgeColor(lightList.at(18).toInt(0,16));
            m_labelSeaEdgeColor->setStyleSheet("QLabel {background-color:#"+lightList.at(18)+";}");

            WowLight.setSeaMidColor(lightList.at(19).toInt(0,16));
            m_labelSeaMidColor->setStyleSheet("QLabel {background-color:#"+lightList.at(19)+";}");
        }
        file.close();
    }
    else
    {
        delete mb;
        return;
    }
}
