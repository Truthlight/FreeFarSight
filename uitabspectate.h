/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef UITABSPECTATE_H
#define UITABSPECTATE_H

#include <QWidget>
#include <QGroupBox>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QPushButton>
#include <QTableView>
#include <QStandardItemModel>
#include <vector>
#include <fstream>
#include <QTextStream>
//#include <QxtGlobalShortcut>
#include <QShortcut>
#include "windows.h"

#include "objectmanager.h"
#include "player.h"
#include "commentator.h"
#include "movie.h"
#include "qlabelclickable.h"
#include "widgetmbdialog.h"
#include "widgetmbdialog2.h"
#include "process.h"




class UItabSpectate: public QWidget
{
    Q_OBJECT
public:
    UItabSpectate(QWidget *parent=0);
    ~UItabSpectate();
    void activateHKThread();
    void enableHotKeys();
    void disableHotKeys();
private slots:
    void reactToSpectateToggle(bool checked);
    void reactToSpectateCollisionToggle(bool checked);
    void SetSpeed(double i);
    void reactToLookAtTarget(bool checked);
    void reactToFollowTarget(bool checked);
    void setAutoPanX (qint32 i);
    void setAutoPanY (qint32 i);
    void setAutoPanZ (qint32 i);
    void setAutoRotate (qint32 i);
    void setZoomspe (qint32 i);
    void addPoint();
    void replacePoint();
    void clearPoint();
    void viewPoint();
    void playPoint();
    void threadInit();
    void threadFinished();
    void stopPoint();
    void resetAutoPanX();
    void resetAutoPanY();
    void resetAutoPanZ();
    void resetAutoRotate();
    void resetZoom();
    void loadList();
    void saveList();


private:
    QVBoxLayout *spectateLayout = new QVBoxLayout;

    QGroupBox *groupSpectate;
    QGroupBox *groupAuto;
    QGroupBox *groupWaypoints;
    QCheckBox *m_checkSpectateToggle;
    QCheckBox *m_checkSpectateCollisionToggle;
    QLabel *m_labelSpectateSpeed;
    QDoubleSpinBox *m_spinboxSpectateSpeed;

    QVBoxLayout *m_layoutVSpectate = new QVBoxLayout;
    QVBoxLayout *m_layoutVAuto = new QVBoxLayout;
    //QVBoxLayout *m_layoutVAuto2 = new QVBoxLayout;
    QHBoxLayout *m_layoutHAuto = new QHBoxLayout;
    QVBoxLayout *m_layoutVWaypoints = new QVBoxLayout;
    QVBoxLayout *m_layoutV = new QVBoxLayout;
    QVBoxLayout *m_layoutV2 = new QVBoxLayout;
    QHBoxLayout *m_layoutH = new QHBoxLayout;

    QCheckBox *m_checkLookAtTarget;
    QCheckBox *m_checkFollowTarget;
    //QLabel *m_labelAuto = new QLabel;
    QLabelClickable *m_labelAutoPanX;
    QSlider *m_sliderAutoPanX;
    QLabelClickable *m_labelAutoPanY;
    QSlider *m_sliderAutoPanY;
    QLabelClickable *m_labelAutoPanZ;
    QSlider *m_sliderAutoPanZ;
    QLabelClickable *m_labelAutoRotate;
    QSlider *m_sliderAutoRotate;
    QLabelClickable *m_labelZoomspe;
    QSlider *m_sliderZoomspe;

    QPushButton *m_buttonPlay;
    QPushButton *m_buttonView;
    QPushButton *m_buttonReplace;
    QPushButton *m_buttonAdd;
    QPushButton *m_buttonStop;
    QPushButton *m_buttonClear;
    QTableView *m_tableView = new QTableView;
    QStandardItemModel *model = new QStandardItemModel;
    QStringList listeHeader;
    QLabel *m_labelSpeedMachinima;
    QDoubleSpinBox *m_spinboxSpeedMachinima;
    QCheckBox *m_360;

    QHBoxLayout *m_SpecSpeed = new QHBoxLayout;
    QHBoxLayout *m_autoPanX = new QHBoxLayout;
    QHBoxLayout *m_autoPanY = new QHBoxLayout;
    QHBoxLayout *m_autoPanZ = new QHBoxLayout;
    QHBoxLayout *m_autoRotate = new QHBoxLayout;
    QHBoxLayout *m_Zoomspe = new QHBoxLayout;
    //QHBoxLayout *m_Roll = new QHBoxLayout;
    QHBoxLayout *m_layoutButton = new QHBoxLayout;
    QHBoxLayout *m_speedMachinima = new QHBoxLayout;
    QThread *thread;
    Movie *movie;
    double threadRunning;
    QPushButton *m_buttonLoadList;
    QPushButton *m_buttonSaveList;
    QStringListModel *m_model;
    QStringList m_list;
    QDir m_dir;
    bool threadHKRunning;
};

#endif // UITABSPECTATE_H
