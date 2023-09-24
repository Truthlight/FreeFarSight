/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef SLOWMO_H
#define SLOWMO_H

#include "memory.h"
#include "Offsets.h"
//#include <unistd.h>
#include <QThread>

class slowmo : public QObject
{
    Q_OBJECT
public:
    slowmo();
    void enableSlowMo();
    void disableSlowMo();
    void setSpeed(float slowMo);
    void setValue(double SlowMoA, double SlowMoB, int Time);
public slots:
    void run();
    void stop();

Q_SIGNALS:
    void finished();
    void end();
    void emitValue(float value);

private:
    DWORD baseAdr;
    unsigned int lvl1pointer;
    unsigned int camera;
    float slowMoA,slowMoB,slowMoC;
    unsigned int time;
    bool m_terminate;
};

#endif // SLOWMO_H
