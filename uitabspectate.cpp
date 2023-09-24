/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "uitabspectate.h"

Player WowPlayer;
Commentator WowCommentator;

UItabSpectate::UItabSpectate(QWidget *parent):QWidget(parent)
{
    m_checkSpectateToggle = new QCheckBox (this);
    m_checkSpectateToggle->setText("Toggle Spectate Mode");

    m_checkSpectateCollisionToggle = new QCheckBox (this);
    m_checkSpectateCollisionToggle->setText("Disable Collisions");
    m_checkSpectateCollisionToggle->setDisabled(true);

    m_checkLookAtTarget = new QCheckBox (this);
    m_checkLookAtTarget->setText("Look at target");
    m_checkLookAtTarget->setDisabled(true);

    m_checkFollowTarget = new QCheckBox (this);
    m_checkFollowTarget->setText("Follow target");
    m_checkFollowTarget->setDisabled(true);

    m_labelSpectateSpeed = new QLabel (this);
    m_labelSpectateSpeed->setText("Speed (<1000)");
    m_labelSpectateSpeed->setDisabled(true);

    m_spinboxSpectateSpeed = new QDoubleSpinBox (this);
    m_spinboxSpectateSpeed->setMaximum(1000);
    m_spinboxSpectateSpeed->setValue(10);
    m_spinboxSpectateSpeed->setDecimals(1);
    m_spinboxSpectateSpeed->setSingleStep(0.1);
    m_spinboxSpectateSpeed->setDisabled(true);

    m_labelZoomspe = new QLabelClickable (this);
    m_labelZoomspe->setText("Zoom");
    m_labelZoomspe->setDisabled(true);
    m_sliderZoomspe = new QSlider(Qt::Horizontal, this);
    m_sliderZoomspe->setRange(-147,147);
    m_sliderZoomspe->setValue(0);
    m_sliderZoomspe->setDisabled(true);

    QSpacerItem *spacerSpectate = new QSpacerItem(1, 5, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_layoutVSpectate->addItem(spacerSpectate);
    m_layoutVSpectate->addWidget(m_checkSpectateToggle);
    m_layoutVSpectate->addWidget(m_checkSpectateCollisionToggle);
    m_layoutVSpectate->addWidget(m_checkLookAtTarget);
    m_layoutVSpectate->addWidget(m_checkFollowTarget);
    m_SpecSpeed->addWidget(m_labelSpectateSpeed);
    m_SpecSpeed->addWidget(m_spinboxSpectateSpeed);
    m_layoutVSpectate->addLayout(m_SpecSpeed);
    m_Zoomspe->addWidget(m_labelZoomspe);
    m_Zoomspe->addWidget(m_sliderZoomspe);
    m_layoutVSpectate->addLayout(m_Zoomspe);

    QGroupBox *groupSpectate = new QGroupBox ("Spectate Mode", this);
    groupSpectate->setLayout(m_layoutVSpectate);

    m_labelAutoPanX = new QLabelClickable (this);
    m_labelAutoPanX->setText("Pan X");
    m_labelAutoPanX->setDisabled(true);
    m_sliderAutoPanX = new QSlider (Qt::Horizontal, this);
    m_sliderAutoPanX->setRange(-50,50);
    m_sliderAutoPanX->setDisabled(true);

    m_labelAutoPanY = new QLabelClickable (this);
    m_labelAutoPanY->setText("Pan Y");
    m_labelAutoPanY->setDisabled(true);
    m_sliderAutoPanY = new QSlider (Qt::Horizontal, this);
    m_sliderAutoPanY->setRange(-50,50);
    m_sliderAutoPanY->setDisabled(true);

    m_labelAutoPanZ = new QLabelClickable (this);
    m_labelAutoPanZ->setText("Pan Z");
    m_labelAutoPanZ->setDisabled(true);
    m_sliderAutoPanZ = new QSlider (Qt::Horizontal, this);
    m_sliderAutoPanZ->setRange(-50,50);
    m_sliderAutoPanZ->setDisabled(true);

    m_labelAutoRotate = new QLabelClickable (this);
    m_labelAutoRotate->setText("Rot.  ");
    m_labelAutoRotate->setDisabled(true);
    m_sliderAutoRotate = new QSlider (Qt::Horizontal, this);
    m_sliderAutoRotate->setRange(-50,50);
    m_sliderAutoRotate->setDisabled(true);

    m_autoPanX->addWidget(m_labelAutoPanX);
    m_autoPanX->addWidget(m_sliderAutoPanX);
    m_layoutVAuto->addLayout(m_autoPanX);

    m_autoPanY->addWidget(m_labelAutoPanY);
    m_autoPanY->addWidget(m_sliderAutoPanY);
    m_layoutVAuto->addLayout(m_autoPanY);

    m_autoPanZ->addWidget(m_labelAutoPanZ);
    m_autoPanZ->addWidget(m_sliderAutoPanZ);
    m_layoutVAuto->addLayout(m_autoPanZ);

    m_autoRotate->addWidget(m_labelAutoRotate);
    m_autoRotate->addWidget(m_sliderAutoRotate);
    m_layoutVAuto->addLayout(m_autoRotate);

    m_layoutHAuto->addLayout(m_layoutVAuto);

    QGroupBox *groupAuto = new QGroupBox ("Auto", this);
    groupAuto->setMaximumHeight(130);
    groupAuto->setLayout(m_layoutHAuto);

    m_layoutV->addWidget(groupSpectate);
    m_layoutV->addWidget(groupAuto);

    QSpacerItem *spacerSpectate2 = new QSpacerItem(1, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

    m_buttonAdd = new QPushButton (this);
    m_buttonAdd->setToolTip("Add");
    m_buttonAdd->setFlat(true);
    m_buttonAdd->setStyleSheet("QPushButton{background-image: url(:/images/add_base.png);padding:0;margin:0;border:none;width: 18px;height: 18px;background-color:#2F2F2F}"
                               "QPushButton::hover{background-image: url(:/images/add_hover.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}"
                               "QPushButton::pressed{background-image: url(:/images/add_pressed.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}");
    m_layoutButton->addWidget(m_buttonAdd);

    m_buttonReplace = new QPushButton (this);
    m_buttonReplace->setToolTip("Replace");
    m_buttonReplace->setFlat(true);
    m_buttonReplace->setStyleSheet("QPushButton{background-image: url(:/images/replace_base.png);padding:0;margin:0;border:none;width: 18px;height: 18px;background-color:#2F2F2F}"
                                   "QPushButton::hover{background-image: url(:/images/replace_hover.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}"
                                   "QPushButton::pressed{background-image: url(:/images/replace_pressed.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}");
    m_layoutButton->addWidget(m_buttonReplace);

    m_buttonClear = new QPushButton (this);
    m_buttonClear->setToolTip("Delete Point(s)");
    m_buttonClear->setFlat(true);
    m_buttonClear->setStyleSheet("QPushButton{background-image: url(:/images/delete_base.png);padding:0;margin:0;border:none;width: 18px;height: 18px;background-color:#2F2F2F}"
                                 "QPushButton::hover{background-image: url(:/images/delete_hover.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}"
                                 "QPushButton::pressed{background-image: url(:/images/delete_pressed.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}");
    m_layoutButton->addWidget(m_buttonClear);

    m_buttonView = new QPushButton (this);
    m_buttonView->setToolTip("View");
    m_buttonView->setFlat(true);
    m_buttonView->setStyleSheet("QPushButton{background-image: url(:/images/view_base.png);padding:0;margin:0;border:none;width: 18px;height: 18px;background-color:#2F2F2F}"
                                "QPushButton::hover{background-image: url(:/images/view_hover.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}"
                                "QPushButton::pressed{background-image: url(:/images/view_pressed.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}");
    m_layoutButton->addWidget(m_buttonView);

    m_buttonPlay = new QPushButton (this);
    m_buttonPlay->setToolTip("Play");
    m_buttonPlay->setFlat(true);
    m_buttonPlay->setStyleSheet("QPushButton{background-image: url(:/images/play_base.png);padding:0;margin:0;border:none;width: 18px;height: 18px;background-color:#2F2F2F}"
                                "QPushButton::hover{background-image: url(:/images/play_hover.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}"
                                "QPushButton::pressed{background-image: url(:/images/play_pressed.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}");
    m_layoutButton->addWidget(m_buttonPlay);

    m_buttonStop = new QPushButton (this);
    m_buttonStop->setToolTip("Stop");
    m_buttonStop->setFlat(true);
    m_buttonStop->setStyleSheet("QPushButton{background-image: url(:/images/stop_base.png);padding:0;margin:0;border:none;width: 18px;height: 18px;background-color:#2F2F2F}"
                                "QPushButton::hover{background-image: url(:/images/stop_hover.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}"
                                "QPushButton::pressed{background-image: url(:/images/stop_pressed.png);padding:0;margin:0;border:none;width: 18px;height: 18px;}");
    m_layoutButton->addWidget(m_buttonStop);

    //**********************************************************************
    m_buttonLoadList = new QPushButton (this);
    m_buttonLoadList->setText("Load");
    //m_buttonLoadList->setToolTip("Load list");
    m_buttonLoadList->setFlat(true);
    //m_layoutButton->addWidget(m_buttonLoadList);

    m_buttonSaveList = new QPushButton (this);
    m_buttonSaveList->setText("Save");
    //m_buttonSaveList->setToolTip("Save list");
    m_buttonSaveList->setFlat(true);
    //m_layoutButton->addWidget(m_buttonSaveList);
    //**********************************************************************

    QSpacerItem *spacerRender = new QSpacerItem(95, 5, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_layoutButton->addItem(spacerRender);

    QStandardItemModel* model=new QStandardItemModel(0,6);
    m_tableView = new QTableView (this);
    listeHeader << "X" << "Y" << "Z" << "Zoom" << "Yaw" << "Pitch" ;
    model->setHorizontalHeaderLabels(listeHeader);
    m_tableView->setEditTriggers(0); //Content list uneditable
    //m_tableView->setShowGrid(false);//remove border
    m_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableView->setModel(model);
    m_tableView->resizeColumnsToContents();

    m_labelSpeedMachinima = new QLabel(this);
    m_labelSpeedMachinima->setText("Speed");

    m_spinboxSpeedMachinima = new QDoubleSpinBox (this);
    m_spinboxSpeedMachinima->setMaximum(20);
    m_spinboxSpeedMachinima->setValue(1);
    m_spinboxSpeedMachinima->setSingleStep(0.01);

    m_speedMachinima->addWidget(m_labelSpeedMachinima);
    m_speedMachinima->addWidget(m_spinboxSpeedMachinima);

    m_360 = new QCheckBox (this);
    m_360->setText("360");
    m_speedMachinima->addWidget(m_360);


    QSpacerItem *spacerSpeedMachinima = new QSpacerItem(30, 5, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_speedMachinima->addItem(spacerSpeedMachinima);

    m_speedMachinima->addWidget(m_buttonLoadList);
    m_speedMachinima->addWidget(m_buttonSaveList);

    m_layoutVWaypoints->addItem(spacerSpectate2);
    m_layoutVWaypoints->addLayout(m_layoutButton);
    m_layoutVWaypoints->addWidget(m_tableView);
    m_layoutVWaypoints->addLayout(m_speedMachinima);

    QGroupBox *groupWaypoints = new QGroupBox ("Waypoints", this);
    groupWaypoints->setLayout(m_layoutVWaypoints);

    m_layoutV2->addWidget(groupWaypoints);

    m_layoutH->addLayout(m_layoutV);
    m_layoutH->addLayout(m_layoutV2);

    QSpacerItem *spacerTabSpectate = new QSpacerItem(1, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);
    spectateLayout->addItem(spacerTabSpectate);

    spectateLayout->addLayout(m_layoutH);

    this->setLayout(spectateLayout);

    QObject::connect (m_checkSpectateToggle,SIGNAL(toggled(bool)),this,SLOT(reactToSpectateToggle(bool)));
    QObject::connect (m_checkSpectateCollisionToggle, SIGNAL(toggled(bool)),this,SLOT(reactToSpectateCollisionToggle(bool)));
    QObject::connect (m_spinboxSpectateSpeed,SIGNAL(valueChanged(double)),this,SLOT(SetSpeed(double)));
    QObject::connect (m_checkLookAtTarget,SIGNAL(toggled(bool)),this,SLOT(reactToLookAtTarget(bool)));
    QObject::connect (m_checkFollowTarget,SIGNAL(toggled(bool)),this,SLOT(reactToFollowTarget(bool)));
    QObject::connect (m_sliderAutoPanX,SIGNAL(valueChanged(qint32)),this,SLOT(setAutoPanX(qint32)));
    QObject::connect (m_labelAutoPanX,SIGNAL(clicked()),this,SLOT(resetAutoPanX()));
    QObject::connect (m_sliderAutoPanY,SIGNAL(valueChanged(qint32)),this,SLOT(setAutoPanY(qint32)));
    QObject::connect (m_labelAutoPanY,SIGNAL(clicked()),this,SLOT(resetAutoPanY()));
    QObject::connect (m_sliderAutoPanZ,SIGNAL(valueChanged(qint32)),this,SLOT(setAutoPanZ(qint32)));
    QObject::connect (m_labelAutoPanZ,SIGNAL(clicked()),this,SLOT(resetAutoPanZ()));
    QObject::connect (m_sliderAutoRotate,SIGNAL(valueChanged(qint32)),this,SLOT(setAutoRotate(qint32)));
    QObject::connect (m_labelAutoRotate,SIGNAL(clicked()),this,SLOT(resetAutoRotate()));
    QObject::connect (m_sliderZoomspe,SIGNAL(valueChanged(qint32)),this,SLOT(setZoomspe(qint32)));
    QObject::connect (m_labelZoomspe,SIGNAL(clicked()),this,SLOT(resetZoom()));
    QObject::connect (m_buttonAdd, SIGNAL(clicked()),this,SLOT(addPoint()));
    QObject::connect (m_buttonReplace, SIGNAL(clicked()),this,SLOT(replacePoint()));
    QObject::connect (m_buttonClear, SIGNAL(clicked()),this,SLOT(clearPoint()));
    QObject::connect (m_buttonView, SIGNAL(clicked()),this,SLOT(viewPoint()));
    QObject::connect (m_buttonPlay, SIGNAL(clicked()),this,SLOT(playPoint()));
    //
    QObject::connect (m_buttonLoadList, SIGNAL(clicked()),this,SLOT(loadList()));
    QObject::connect (m_buttonSaveList, SIGNAL(clicked()),this,SLOT(saveList()));
    //QObject::connect (m_buttonStop, SIGNAL(clicked()),this,SLOT(stopPoint()));
}

UItabSpectate::~UItabSpectate()
{

}

void UItabSpectate::reactToSpectateToggle(bool checked) //toggle spectate mode
 {
    if (checked)
    {
        m_checkSpectateCollisionToggle->setEnabled(true);
        m_labelSpectateSpeed->setEnabled(true);
        m_spinboxSpectateSpeed->setEnabled(true);
        m_checkLookAtTarget->setEnabled(true);
        m_checkFollowTarget->setEnabled(true);
        //m_labelAuto->setEnabled(true);
        m_sliderAutoPanX->setEnabled(true);
        m_labelAutoPanX->setEnabled(true);
        m_sliderAutoPanY->setEnabled(true);
        m_labelAutoPanY->setEnabled(true);
        m_sliderAutoPanZ->setEnabled(true);
        m_labelAutoPanZ->setEnabled(true);
        m_sliderAutoRotate->setEnabled(true);
        m_labelAutoRotate->setEnabled(true);
        m_labelZoomspe->setEnabled(true);
        m_sliderZoomspe->setEnabled(true);

        WowPlayer.Readflag();
        WowPlayer.EnableComm();
    }
    else
    {
        m_checkSpectateCollisionToggle->setDisabled(true);
        m_spinboxSpectateSpeed->setDisabled(true);
        m_labelSpectateSpeed->setDisabled(true);
        m_checkLookAtTarget->setDisabled(true);
        m_checkFollowTarget->setDisabled(true);
        //m_labelAuto->setDisabled(true);
        m_sliderAutoPanX->setDisabled(true);
        m_labelAutoPanX->setDisabled(true);
        m_sliderAutoPanY->setDisabled(true);
        m_labelAutoPanY->setDisabled(true);
        m_sliderAutoPanZ->setDisabled(true);
        m_labelAutoPanZ->setDisabled(true);
        m_sliderAutoRotate->setDisabled(true);
        m_labelAutoRotate->setDisabled(true);
        m_labelZoomspe->setDisabled(true);
        m_sliderZoomspe->setDisabled(true);

        WowPlayer.DisableCom();
    }
 }

void UItabSpectate::reactToSpectateCollisionToggle(bool checked)
 {
    if (checked)
    {
       WowCommentator.DisableCollision();
    }
    else
    {
        WowCommentator.EnableCollision();
    }
 }

void UItabSpectate::SetSpeed(double i)
{
    WowCommentator.SetSpeed(i);
}

void UItabSpectate::reactToLookAtTarget(bool checked)
{
    if (checked)
    {
        unsigned long long targetGUID = WowPlayer.ReadTargetGUID();
        unsigned long long targetGUID2 = WowPlayer.ReadTargetGUID2();
        WowCommentator.LookAtTarget(targetGUID,targetGUID2);
    }
    else
    {
        WowCommentator.LookAtTargetDisable();
    }
}

void UItabSpectate::reactToFollowTarget(bool checked)
{
    if (checked)
    {
        unsigned long long targetGUID = WowPlayer.ReadTargetGUID();
        unsigned long long targetGUID2 = WowPlayer.ReadTargetGUID2();
        WowCommentator.FollowTarget(targetGUID,targetGUID2);
    }
    else
    {
        WowCommentator.FollowTargetDisable();
    }
}

void UItabSpectate::setAutoPanX (qint32 i)
{
    WowCommentator.SetAutoPanX(i);
}

void UItabSpectate::setAutoPanY (qint32 i)
{
    WowCommentator.SetAutoPanY(i);
}

void UItabSpectate::setAutoPanZ (qint32 i)
{
    WowCommentator.SetAutoPanZ(i);
}

void UItabSpectate::setAutoRotate (qint32 i)
{
    WowCommentator.SetAutoRotate(i);
}

void UItabSpectate::setZoomspe (qint32 i)
{
    CameraWow.setZoom(i);
    //WowCommentator.SetZoom(i);
}

void UItabSpectate::resetAutoPanX()
{
    WowCommentator.SetAutoPanX(0);
    m_sliderAutoPanX->setValue(0);
}

void UItabSpectate::resetAutoPanY()
{
    WowCommentator.SetAutoPanY(0);
    m_sliderAutoPanY->setValue(0);
}

void UItabSpectate::resetAutoPanZ()
{
    WowCommentator.SetAutoPanZ(0);
    m_sliderAutoPanZ->setValue(0);
}

void UItabSpectate::resetAutoRotate()
{
    WowCommentator.SetAutoRotate(0);
    m_sliderAutoRotate->setValue(0);
}

void UItabSpectate::resetZoom()
{
    CameraWow.setZoom(0);
    m_sliderZoomspe->setValue(0);
}

void UItabSpectate::addPoint()
{
    if (model->rowCount()==63)
    {
        widgetMB* MB = new widgetMB ("FFS", "You can't add more than 63 waypoints",this);
        MB->show();
    }
    else
    {
        CameraWow.Initialize();
        std::vector <float> CamXYZ;
        CamXYZ = CameraWow.getCoords();
        qint32 row = model->rowCount();
        model->setHorizontalHeaderLabels(listeHeader);//c'est moche de le redéclarer à revoir.
        QStandardItem* ItemX = new QStandardItem();
        ItemX->setData(CamXYZ.at(0), Qt::DisplayRole);
        model->setItem(row, 0, ItemX);
        QStandardItem* ItemY = new QStandardItem();
        ItemY->setData(CamXYZ.at(1), Qt::DisplayRole);
        model->setItem(row, 1, ItemY);
        QStandardItem* ItemZ = new QStandardItem();
        ItemZ->setData(CamXYZ.at(2), Qt::DisplayRole);
        model->setItem(row, 2, ItemZ);

        QStandardItem* ItemZoom = new QStandardItem();
        ItemZoom->setData(CameraWow.getZoom(), Qt::DisplayRole);
        model->setItem(row, 3, ItemZoom);

        std::vector <float> CamOrientation;
        CamOrientation = CameraWow.getOrientation();
        QStandardItem* ItemYaw = new QStandardItem();
        ItemYaw->setData(CamOrientation.at(0), Qt::DisplayRole);
        model->setItem(row, 4, ItemYaw);
        QStandardItem* ItemPitch = new QStandardItem();
        ItemPitch->setData(CamOrientation.at(1), Qt::DisplayRole);
        model->setItem(row, 5, ItemPitch);

        m_tableView->setModel(model);
        m_tableView->resizeColumnsToContents();
    }
}

void UItabSpectate::replacePoint()
{
    if (m_tableView->selectionModel()->hasSelection())
    {
        QModelIndexList indexes = m_tableView->selectionModel()->selectedIndexes();

        CameraWow.Initialize();
        std::vector <float> CamXYZ;
        CamXYZ = CameraWow.getCoords();

        QStandardItem* ItemX = new QStandardItem();
        ItemX->setData(CamXYZ.at(0), Qt::DisplayRole);
        model->setItem(indexes.first().row(), 0, ItemX);
        QStandardItem* ItemY = new QStandardItem();
        ItemY->setData(CamXYZ.at(1), Qt::DisplayRole);
        model->setItem(indexes.first().row(), 1, ItemY);
        QStandardItem* ItemZ = new QStandardItem();
        ItemZ->setData(CamXYZ.at(2), Qt::DisplayRole);
        model->setItem(indexes.first().row(), 2, ItemZ);

        QStandardItem* ItemZoom = new QStandardItem();
        ItemZoom->setData(CameraWow.getZoom(), Qt::DisplayRole);
        model->setItem(indexes.first().row(), 3, ItemZoom);

        std::vector <float> CamOrientation;
        CamOrientation = CameraWow.getOrientation();
        QStandardItem* ItemYaw = new QStandardItem();
        ItemYaw->setData(CamOrientation.at(0), Qt::DisplayRole);
        model->setItem(indexes.first().row(), 4, ItemYaw);
        QStandardItem* ItemPitch = new QStandardItem();
        ItemPitch->setData(CamOrientation.at(1), Qt::DisplayRole);
        model->setItem(indexes.first().row(), 5, ItemPitch);
        //QStandardItem* ItemRoll = new QStandardItem();
        //ItemRoll->setData(CamOrientation.at(2), Qt::DisplayRole);
        //model->setItem(indexes.first().row(), 6, ItemRoll);

        m_tableView->setModel(model);
        m_tableView->resizeColumnsToContents();
    }
    else
    {
        widgetMB* MB = new widgetMB ("FFS", "You must select a waypoint",this);
        MB->show();
    }
}

void UItabSpectate::clearPoint()
{
    if (m_tableView->selectionModel()->hasSelection())
    {
        QModelIndexList indexes = m_tableView->selectionModel()->selectedIndexes();
        model->removeRow(indexes.first().row());
        m_tableView->setModel(model);
    }
    else
    {
        model->clear();
        model->setHorizontalHeaderLabels(listeHeader);
        m_tableView->setModel(model);
        m_tableView->resizeColumnsToContents();
    }
}

void UItabSpectate::viewPoint()
{
    if (m_tableView->selectionModel()->hasSelection())
    {
        std::vector <float> xyzLocation (3);
        std::vector <float> xyzOrientation (2);
        float zoom ;
        QItemSelectionModel *selection = m_tableView->selectionModel();
        QModelIndexList listeSelections = selection->selectedIndexes();
        QVariant xVar = model->data(listeSelections[0]);
        QVariant yVar = model->data(listeSelections[1]);
        QVariant zVar = model->data(listeSelections[2]);
        xyzLocation.at(0) = xVar.toFloat();
        xyzLocation.at(1) = yVar.toFloat();
        xyzLocation.at(2) = zVar.toFloat();

        QVariant zoomVar = model->data(listeSelections[3]);
        zoom = zoomVar.toFloat();

        QVariant YawVar = model->data(listeSelections[4]);
        QVariant PitchVar = model->data(listeSelections[5]);
        //QVariant RollVar = model->data(listeSelections[6]);
        xyzOrientation.at(0) = YawVar.toFloat();
        xyzOrientation.at(1) = PitchVar.toFloat();
        //xyzOrientation.at(2) = RollVar.toFloat();

        WowCommentator.viewPoint(xyzLocation);
        CameraWow.setZoom(zoom);
        CameraWow.SetOrientation(xyzOrientation);
    }
    else
    {
        widgetMB* MB = new widgetMB ("FFS", "You must select a waypoint",this);
        MB->show();
    }
}


void UItabSpectate::playPoint()
{
    qint32 row = model->rowCount();
    if (row<=1)
    {
        widgetMB* MB = new widgetMB ("FFS", "You must have at least 2 points",this);
        MB->show();
    }
    else
    {
        std::vector < std::vector < float > > P ;
        P.resize( row , std::vector<float>( 6 ) );
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<6;j++)
            {
                QVariant Var = model->data(model->index(i,j), Qt::DisplayRole).toFloat();
                P.at(i).at(j) = Var.toFloat();
            }
        }
        double speedMachinima = m_spinboxSpeedMachinima->value();
        if (threadRunning == true)
        {
            movie->stop();
        }

        movie = new Movie(speedMachinima);
        movie->setVectorP(P);
        thread = new QThread ;
        movie -> moveToThread(thread);
        connect (thread,SIGNAL(started()),this,SLOT(threadInit()));
        if (m_360->isChecked())
        {
            connect(thread, SIGNAL(started()), movie, SLOT(run360()));
        }
        else
        {
            connect(thread, SIGNAL(started()), movie, SLOT(run()));
        }
        connect(movie, SIGNAL(finished()), thread, SLOT(quit()));
        connect(movie, SIGNAL(finished()), movie, SLOT(deleteLater()));
        connect(movie, SIGNAL(finished()), thread, SLOT(deleteLater()));
        connect(movie, SIGNAL(end()), this, SLOT(threadFinished())); // probably ugly... didn't know how to do better.

           thread->start();
           connect (m_buttonStop,SIGNAL(clicked()),this,SLOT(stopPoint()));
    }
}

void UItabSpectate::threadInit()
{
    threadRunning = true;
    m_sliderAutoPanX->setDisabled(true);
    m_sliderAutoPanY->setDisabled(true);
    m_sliderAutoPanZ->setDisabled(true);
    m_sliderAutoRotate->setDisabled(true);
    m_sliderZoomspe->setDisabled(true);
}

void UItabSpectate::threadFinished()
{
    threadRunning = false;
    m_sliderAutoPanX->setEnabled(true);
    m_sliderAutoPanY->setEnabled(true);
    m_sliderAutoPanZ->setEnabled(true);
    m_sliderAutoRotate->setEnabled(true);
    m_sliderZoomspe->setEnabled(true);
}

void UItabSpectate::stopPoint()
{
    movie->stop();
}

void UItabSpectate::loadList()
{
    //m_model = new QDirModel (this);
    //m_model = new QStringListModel (this);
    //m_list = new QStringList (this);
    QStringList filters;
    filters << "*.txt";
    m_dir = QDir(QDir::currentPath() + "/WaypointsCustom");
    m_dir.setNameFilters(filters);
    m_list = m_dir.entryList();
    m_list.replaceInStrings(".txt","");
    widgetMBDialog *mb = new widgetMBDialog ("FFS","Select Waypoints list", m_list,this);
    if (mb->exec() == QDialog::Accepted)
    {
        QString fileName = mb->getNameFile();
        delete mb;
        QFile file ("WaypointsCustom/"+fileName+".txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
        QTextStream fichier (&file);
        QString ligne;
        QStringList Waypoints;
        model->clear();
        while( !fichier.atEnd() )
        {
            //getline(fichier, ligne.toStdString());//lecture d'une ligne du fichier
            ligne=fichier.readLine();
            Waypoints = ligne.split(" ");
            qint32 row = model->rowCount();
            model->setHorizontalHeaderLabels(listeHeader);
            QStandardItem* ItemX = new QStandardItem();
            ItemX->setData(Waypoints.at(0), Qt::DisplayRole);
            model->setItem(row, 0, ItemX);
            QStandardItem* ItemY = new QStandardItem();
            ItemY->setData(Waypoints.at(1), Qt::DisplayRole);
            model->setItem(row, 1, ItemY);
            QStandardItem* ItemZ = new QStandardItem();
            ItemZ->setData(Waypoints.at(2), Qt::DisplayRole);
            model->setItem(row, 2, ItemZ);
            QStandardItem* ItemZoom = new QStandardItem();
            ItemZoom->setData(Waypoints.at(3), Qt::DisplayRole);
            model->setItem(row, 3, ItemZoom);
            QStandardItem* ItemYaw = new QStandardItem();
            ItemYaw->setData(Waypoints.at(4), Qt::DisplayRole);
            model->setItem(row, 4, ItemYaw);
            QStandardItem* ItemPitch = new QStandardItem();
            ItemPitch->setData(Waypoints.at(5), Qt::DisplayRole);
            model->setItem(row, 5, ItemPitch);
            m_tableView->setModel(model);
            m_tableView->resizeColumnsToContents();
        }
    }
    else
    {
        delete mb;
        return;
    }
}

void UItabSpectate::saveList()
{
    qint32 row = model->rowCount();
    if (row==0)
    {
        widgetMB* MB = new widgetMB ("FFS", "You must have at least one point",this);
        MB->show();
        return;
    }
    QStringList filters;
    filters << "*.txt";
    m_dir = QDir(QDir::currentPath() + "/WaypointsCustom");
    m_dir.setNameFilters(filters);
    m_list = m_dir.entryList();
    m_list.replaceInStrings(".txt","");
    widgetMBDialog2 *mb = new widgetMBDialog2 ("FFS","Select Waypoints List", m_list,this);
    if (mb->exec() == QDialog::Accepted)
    {
        QString fileName = mb->getNameFile();
        delete mb;
        if (fileName == NULL)
        {
            widgetMB *mb = new widgetMB ("FFS","You didn't choose a filename, Waypoints list has not been saved",this);
            mb->show();
            return;
        }
        QFile file ("WaypointsCustom/"+fileName+".txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream fichier (&file);
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<6;j++)
            {
                QVariant Var = model->data(model->index(i,j), Qt::DisplayRole).toFloat();
                fichier<<Var.toString()<<" ";
            }
            fichier<<"\n";
        }
    }
    else
    {
        delete mb;
        return;
    }
}

void UItabSpectate::activateHKThread()
{
    while (threadHKRunning == true)
    {
        if(GetAsyncKeyState(VK_F2) & 0x0001)
        {
            m_checkSpectateToggle->toggle();
        }
    }
    Sleep(1);
}



void UItabSpectate::enableHotKeys()
{
    threadHKRunning = true;
}

void UItabSpectate::disableHotKeys()
{
    threadHKRunning = false;
}
