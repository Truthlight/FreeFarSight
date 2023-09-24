/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <windows.h>
#include <stdio.h>

#include <QApplication>
#include <QGridLayout>
#include <QSizeGrip>
#include <QDesktopWidget>
#include <QWidget>
#include <QTabWidget>

#include "widgettitlebar.h"
#include "design.h"
#include "widgetmb.h"
#include "qlabelclickable.h"

#include "uitabspectate.h"
#include "uitabgeneral.h"
#include "uitablight.h"
#include "uitababout.h"

#include "hotkeysthread.h"

class UItabGeneral;
class UItabSpectate;

class HotKeysThread;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    ~MainWidget();
    MainWidget(DWORD processID);
    void setWindowTitle(const QString &title);
    void enableHotKeys();
    void disableHotKeys();


signals:
    void WindowTitleChanged();

Q_SIGNALS:
    void end();

protected:
    void paintEvent (QPaintEvent *event);
private:
    QGridLayout m_MainLayout;
    WidgetTitleBar m_TitleBar;
    QSizeGrip m_SizeGrip;
    //QPixmap *m_Cache;

    QTabWidget *onglets;

    DWORD processID;
    DWORD baseaddr;

    UItabGeneral *tabGeneral;
    UItabSpectate *tabSpectate;
    UItabLight *tabLight;
    UITabAbout *tabAbout;

    HotKeysThread *hk ;
    QThread *thread;
};

#endif // MAINWIDGET_H

