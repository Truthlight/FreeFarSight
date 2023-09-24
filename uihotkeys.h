/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef UIHOTKEYS_H
#define UIHOTKEYS_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QSizeGrip>
#include <QGroupBox>
#include "widgettitlebar2.h"
#include "design.h"

class UIHotKeys:public QDialog
{
    Q_OBJECT
public:
    UIHotKeys(QWidget *parent);
    ~UIHotKeys();
    void setWindowTitle(const QString &title);
    void paintEvent(QPaintEvent *event);
private:
    QGridLayout m_MainLayout;
    WidgetTitleBar2 m_TitleBar;
    QSizeGrip m_SizeGrip;
    //QPixmap *m_Cache;
    QPushButton *m_ButtonOK;
    QHBoxLayout *m_layoutButtonOK = new QHBoxLayout;
    QPixmap *background ;

    QLabel *m_mainLabel;

    QLabel *m_labelZoomPlus;
    QPushButton *m_buttonZoomPlus;
    QHBoxLayout *m_zoomPlus = new QHBoxLayout;
    QLabel *m_labelZoomMinus;
    QPushButton *m_buttonZoomMinus;
    QHBoxLayout *m_zoomMinus = new QHBoxLayout;

    QVBoxLayout *m_layoutVZoom = new QVBoxLayout;

    QLabel *m_labelSlowMoToggle;
    QPushButton *m_buttonSlowMoToggle;
    QHBoxLayout *m_slowMoToggle = new QHBoxLayout;
    QLabel *m_labelSlowMoPlay;
    QPushButton *m_buttonSlowMoPlay;
    QHBoxLayout *m_slowMoPlay = new QHBoxLayout;
    QLabel *m_labelSlowMoPlus;
    QPushButton *m_buttonSlowMoPlus;
    QHBoxLayout *m_slowMoPlus = new QHBoxLayout;
    QLabel *m_labelSlowMoMinus;
    QPushButton *m_buttonSlowMoMinus;
    QHBoxLayout *m_slowMoMinus = new QHBoxLayout;

    QVBoxLayout *m_layoutVSlowMo = new QVBoxLayout;

    QLabel *m_labelSpectateModeToggle;
    QPushButton *m_buttonSpectateModeToggle;
    QHBoxLayout *m_spectateModeToggle = new QHBoxLayout;
    QLabel *m_labelSpectateModeAdd;
    QPushButton *m_buttonSpectateModeAdd;
    QHBoxLayout *m_spectateModeAdd = new QHBoxLayout;
    QLabel *m_labelSpectateModePlay;
    QPushButton *m_buttonSpectateModePlay;
    QHBoxLayout *m_spectateModePlay = new QHBoxLayout;
    QLabel *m_labelSpectateModeStop;
    QPushButton *m_buttonSpectateModeStop;
    QHBoxLayout *m_spectateModeStop = new QHBoxLayout;
    QLabel *m_labelSpectateModeSpeedPlus;
    QPushButton *m_buttonSpectateModeSpeedPlus;
    QHBoxLayout *m_spectateModeSpeedPlus = new QHBoxLayout;
    QLabel *m_labelSpectateModeSpeedMinus;
    QPushButton *m_buttonSpectateModeSpeedMinus;
    QHBoxLayout *m_spectateModeSpeedMinus = new QHBoxLayout;

    QVBoxLayout *m_layoutVSpectateMode = new QVBoxLayout;

signals:
    void WindowTitleChanged();
};

#endif // UIHOTKEYS_H
