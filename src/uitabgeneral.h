/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef UITABGENERAL_H
#define UITABGENERAL_H

//#include "mainwidget.h"
#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QCheckBox>
#include <QSpinBox>
#include <QTextEdit>
#include <QPushButton>
#include <QTimeEdit>
#include <QTime>

#include "mainwidget.h"
#include "qlabelclickable.h"
#include "render.h"
#include "ffs_time.h"
#include "memory.h"
#include "camera.h"
#include "slowmo.h"
#include "uihotkeys.h"

class UItabGeneral : public QWidget
{
    Q_OBJECT
public:
    UItabGeneral(QWidget *parent=0);
    ~UItabGeneral();
private slots:
    void resetFOV();
    void setFOV (qint32 i);
    void resetZoom();
    void setZoom (qint32 i);
    void setZoom (double i);
    void setAttachX (qint32 i);
    void setAttachX (double i);
    void resetAttachX ();
    void setAttachY (qint32 i);
    void setAttachY (double i);
    void resetAttachY ();
    void setAttachZ (qint32 i);
    void setAttachZ (double i);
    void resetAttachZ ();
    void reactToToggleM2(bool checked);
    void reactToToggleFarM2(bool checked);
    void reactToToggleGroundDoodads(bool checked);
    void reactToToggleTerrain(bool checked);
    void reactToToggleWMO(bool checked);
    void reactToToggleLiquid(bool checked);
    void reactToToggleWdl(bool checked);
    //void reactToToggleWireframe(bool checked);
    void changeTime(QTime Time);
    void changeTimeSpeed(double Speed);
    void resetTimeSpeed();
    void toggleSlowMo(bool checked);
    void changeSlowMo();
    void threadInit();
    void threadFinished();
    void changeSlowMo(qint32 SlowMo);
    void changeSlowMo(float SlowMo);
    void toggleOnTop(bool checked);
    void toggleShortCut (bool checked);
    void changeShortCut ();


protected:
    QWidget *m_parent;

    QHBoxLayout *generalLayout = new QHBoxLayout;
    QVBoxLayout *generalVLayout = new QVBoxLayout;
    QVBoxLayout *generalV2Layout = new QVBoxLayout;

    QGroupBox *groupCamera;
    QGroupBox *groupRender;

    QHBoxLayout *m_layoutHCamera = new QHBoxLayout;
    QVBoxLayout *m_layoutVCamera = new QVBoxLayout;
    QVBoxLayout *m_layoutVCamera2 = new QVBoxLayout;

    QHBoxLayout *m_FOV = new QHBoxLayout;
    QLabelClickable *m_labelFOV = new QLabelClickable;
    QSlider *m_sliderFOV = new QSlider;
    QDoubleSpinBox *m_spinFOV = new QDoubleSpinBox;

    QHBoxLayout *m_Zoom = new QHBoxLayout;
    QLabelClickable *m_labelZoom = new QLabelClickable;
    QSlider *m_sliderZoom = new QSlider;
    QDoubleSpinBox *m_spinZoom = new QDoubleSpinBox;

    QLabelClickable *m_labelAttachX = new QLabelClickable;
    QHBoxLayout *m_AttachX = new QHBoxLayout;
    QSlider *m_sliderAttachX = new QSlider;
    QDoubleSpinBox *m_spinAttachX = new QDoubleSpinBox;

    QHBoxLayout *m_AttachY = new QHBoxLayout;
    QLabelClickable *m_labelAttachY = new QLabelClickable;
    QSlider *m_sliderAttachY = new QSlider;
    QDoubleSpinBox *m_spinAttachY = new QDoubleSpinBox;

    QHBoxLayout *m_AttachZ = new QHBoxLayout;
    QLabelClickable *m_labelAttachZ = new QLabelClickable;
    QSlider *m_sliderAttachZ = new QSlider;
    QDoubleSpinBox *m_spinAttachZ = new QDoubleSpinBox;

    //QCheckBox *m_checkXProtec = new QCheckBox;
    //QCheckBox *m_checkYProtec = new QCheckBox;
    //QCheckBox *m_checkZProtec = new QCheckBox;
    //QCheckBox *m_checkZoomProtec = new QCheckBox;

    QCheckBox *m_checkOnTop;
    QVBoxLayout *m_layoutVShortCut = new QVBoxLayout;
    QCheckBox *m_checkShortCut;
    QPushButton *m_buttonShortCut;

    QVBoxLayout *m_layoutVRender = new QVBoxLayout;
    QCheckBox *m_checkRenderM2;
    QCheckBox *m_checkRenderTerrain;
    QCheckBox *m_checkRenderWMO;
    QCheckBox *m_checkRenderLiquid;
    //QCheckBox *m_checkRenderWireframe;
    QCheckBox *m_checkRenderFarM2;
    QCheckBox *m_checkRenderWdl;
    QCheckBox *m_checkRenderGroundDoodads;

    QLabel *m_labelSlowMotion;
    QLabel *m_labelSlowMotion2;
    QLabel *m_labelSlowMotion3;
    QPushButton *m_buttonPlay;
    QCheckBox *m_checkSlowMo;
    QDoubleSpinBox *m_spinboxSlowMotion;
    QDoubleSpinBox *m_spinboxSlowMotion2;
    QSpinBox *m_spinboxSlowMotion3;
    QSlider *m_sliderSlowMo;
    QThread *thread;
    slowmo *WowSlowMo2;

    QVBoxLayout *m_layoutVSlowMotion = new QVBoxLayout;
    QHBoxLayout *m_layoutHSlowMotion = new QHBoxLayout;
    QHBoxLayout *m_layoutHSlowMotion2 = new QHBoxLayout;

    //QLabel *m_labelTimeHour;
    //QLabel *m_labelTimeMin;
    QLabelClickable *m_labelTimeSpeed;
    //QSpinBox *m_spinboxTimeHour;
    //QSpinBox *m_spinboxTimeMin;
    QTimeEdit *m_timeEdit;
    QDoubleSpinBox *m_spinboxTimeSpeed;
    QHBoxLayout *m_layoutHTimeEdit = new QHBoxLayout;
    QHBoxLayout *m_layoutHTimeSpeed = new QHBoxLayout;
    QHBoxLayout *m_layoutHTimeSpeed2 = new QHBoxLayout;

    QHBoxLayout *m_layoutHTime = new QHBoxLayout;
    QVBoxLayout *m_layoutVTime = new QVBoxLayout;

    double threadRunning;
};

#endif // UITABGENERAL_H
