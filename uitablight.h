/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef UITABLIGHT_H
#define UITABLIGHT_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QSpinBox>
#include <QColorDialog>
#include <QDir>
#include <QStandardItem>
#include <QTextStream>
//#include <iostream>
//#include <iomanip>

#include "light.h"
#include "dbclightparams.h"
//#include "qspinboxbis.h"         //++++++++++++++++++++++++++++++++++++++++++++++++++
#include "colorpicker.h"
#include "widgetmb.h"
#include "widgetmbdialog.h"
#include "widgetmbdialog2.h"

class UItabLight : public QWidget
{
    Q_OBJECT
public:
    UItabLight(QWidget *parent=0);
    ~UItabLight();
private slots:
    //void reactToToggleFog(bool checked);
    void reactToToogleTab(bool checked);
    void changeViewDist(qint32 ViewDist);
    void setFogColor();
    //void setFogColor(QColor newFogColor);
    void setFogNearClip(double NearClip);
    void setFogFarClip(double FarClip);
    void setFogDensity(double Density);
    void setDiffuseLight();
    void setAmbientLight();
    void setEnvironment(qint32 env);
    void undoEnvironment();
    void setSunColor();
    void setSkyColor0();
    void setSkyColor1();
    void setSkyColor2();
    void setSkyColor3();
    void setSkyColor4();
    void setSkyColor5();
    void setCloudColor1();
    void setCloudColor2();
    void setCloudColor3();
    void setCloudDensity(double CloudDensity);
    void setSeaEdgeColor();
    void setSeaMidColor();
    void setLakeEdgeColor();
    void setLakeMidColor();
    void loadList();
    void saveList();
private:
    QGroupBox *m_groupFog;
    QGroupBox *m_groupLight;
    QGroupBox *m_groupEnvironment;
    QGroupBox *m_groupSky;
    QGroupBox *m_groupCloud;
    QGroupBox *m_groupWater;
    QGroupBox *m_groupLoadSave;


    QVBoxLayout *lightLayout = new QVBoxLayout;
    QHBoxLayout *m_light = new QHBoxLayout;
    QVBoxLayout *m_light1 = new QVBoxLayout;
    QVBoxLayout *m_light2 = new QVBoxLayout;
    QVBoxLayout *m_light3 = new QVBoxLayout;
    QCheckBox *m_checkFog;
    QColor *m_color;
    QLabel *m_label;

    QCheckBox *m_checkToogleLight;

    QVBoxLayout *layoutFog = new QVBoxLayout;
    QHBoxLayout *m_fogColor = new QHBoxLayout;
    QPushButton *m_buttonFogColor;
    QLabel *m_labelFogColor;
    QColor *m_colorFogColor;
    QHBoxLayout *m_fogNearClip = new QHBoxLayout;
    QLabel *m_labelFogNearClip;
    QDoubleSpinBox *m_spinFogNearClip;
    QHBoxLayout *m_fogFarClip = new QHBoxLayout;
    QLabel *m_labelFogFarClip;
    QDoubleSpinBox *m_spinFogFarClip;
    QHBoxLayout *m_fogDensity = new QHBoxLayout;
    QLabel *m_labelFogDensity;
    QDoubleSpinBox *m_spinFogDensity;

    QVBoxLayout *layoutLight = new QVBoxLayout;
    QHBoxLayout *m_diffuseColor = new QHBoxLayout;
    QHBoxLayout *m_ambientColor = new QHBoxLayout;
    QPushButton *m_buttonDiffuseColor;
    QLabel *m_labelDiffuseColor;
    QColor *m_colorDiffuseColor;
    QPushButton *m_buttonAmbientColor;
    QLabel *m_labelAmbientColor;
    QColor *m_colorAmbientColor;

    QVBoxLayout *layoutEnvironment = new QVBoxLayout;
    QHBoxLayout *layoutEnvironment2 = new QHBoxLayout;
    QLabel *m_labelEnvironment;
    QSpinBox *m_spinEnvironment;
    QPushButton *m_buttonEnvReset;

    QVBoxLayout *layoutSky = new QVBoxLayout;
    QHBoxLayout *m_SunHaloColor = new QHBoxLayout;
    QHBoxLayout *m_skyColor0 = new QHBoxLayout;
    QHBoxLayout *m_skyColor1 = new QHBoxLayout;
    QHBoxLayout *m_skyColor2 = new QHBoxLayout;
    QHBoxLayout *m_skyColor3 = new QHBoxLayout;
    QHBoxLayout *m_skyColor4 = new QHBoxLayout;
    QHBoxLayout *m_skyColor5 = new QHBoxLayout;
    QPushButton *m_buttonSunHaloColor;
    QLabel *m_labelSunHaloColor;
    QColor *m_colorSunHaloColor;
    QPushButton *m_buttonSkyColor0;
    QLabel *m_labelSkyColor0;
    QColor *m_colorSkyColor0;
    QPushButton *m_buttonSkyColor1;
    QLabel *m_labelSkyColor1;
    QColor *m_colorSkyColor1;
    QPushButton *m_buttonSkyColor2;
    QLabel *m_labelSkyColor2;
    QColor *m_colorSkyColor2;
    QPushButton *m_buttonSkyColor3;
    QLabel *m_labelSkyColor3;
    QColor *m_colorSkyColor3;
    QPushButton *m_buttonSkyColor4;
    QLabel *m_labelSkyColor4;
    QColor *m_colorSkyColor4;
    QPushButton *m_buttonSkyColor5;
    QLabel *m_labelSkyColor5;
    QColor *m_colorSkyColor5;

    //QLabel *m_labelViewDist;
    QSpinBox *m_spinboxViewDist;
    QHBoxLayout *m_layoutHViewDist = new QHBoxLayout;

    QVBoxLayout *layoutCloud = new QVBoxLayout;
    QHBoxLayout *m_cloudColor1 = new QHBoxLayout;
    QHBoxLayout *m_cloudColor2 = new QHBoxLayout;
    QHBoxLayout *m_cloudColor3 = new QHBoxLayout;
    QHBoxLayout *m_cloudDensity = new QHBoxLayout;
    QPushButton *m_buttonCloudColor1;
    QLabel *m_labelCloudColor1;
    QColor *m_colorCloudColor1;
    QPushButton *m_buttonCloudColor2;
    QLabel *m_labelCloudColor2;
    QColor *m_colorCloudColor2;
    QPushButton *m_buttonCloudColor3;
    QLabel *m_labelCloudColor3;
    QColor *m_colorCloudColor3;
    //QPushButton *m_buttonCloudDensity;
    QLabel *m_labelCloudDensity;
    QDoubleSpinBox *m_spinCloudDensity;

    QVBoxLayout *layoutWater = new QVBoxLayout;
    QHBoxLayout *m_lakeEdgeColor = new QHBoxLayout;
    QHBoxLayout *m_lakeMidColor = new QHBoxLayout;
    QHBoxLayout *m_seaEdgeColor = new QHBoxLayout;
    QHBoxLayout *m_seaMidColor = new QHBoxLayout;
    QPushButton *m_buttonLakeEdgeColor;
    QLabel *m_labelLakeEdgeColor;
    QColor *m_colorLakeEdgeColor;
    QPushButton *m_buttonLakeMidColor;
    QLabel *m_labelLakeMidColor;
    QColor *m_colorLakeMidColor;
    QPushButton *m_buttonSeaEdgeColor;
    QLabel *m_labelSeaEdgeColor;
    QColor *m_colorSeaEdgeColor;
    QPushButton *m_buttonSeaMidColor;
    QLabel *m_labelSeaMidColor;
    QColor *m_colorSeaMidColor;

    QPushButton *m_buttonLoadList;
    QPushButton *m_buttonSaveList;
    QHBoxLayout *layoutLoadSave = new QHBoxLayout;

    QStringList m_list;
    QDir m_dir;
};

#endif // UITABLIGHT_H
