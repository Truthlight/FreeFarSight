/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef HOTKEYSTHREAD_H
#define HOTKEYSTHREAD_H

#include "windows.h"
#include <QObject>
#include <QThread>
#include <QMessageBox>

#include "uitabspectate.h"

class UItabSpectate;

class HotKeysThread : public QObject
{
    Q_OBJECT

public:
    HotKeysThread(UItabSpectate *UItabS);
    ~HotKeysThread();
public slots:
    void run();
    //void stop();
private:
    UItabSpectate *tabSpectate;
Q_SIGNALS:
    void finished();
    void end();
};

#endif // HOTKEYSTHREAD_H
