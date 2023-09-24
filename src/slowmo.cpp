/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "slowmo.h"
#include <thread>

slowmo::slowmo() : QObject()
{
    m_terminate = false;
}

void slowmo::enableSlowMo()
{
    baseAdr = MemoryWow.getBaseAdr();
    lvl1pointer = MemoryWow.MRead<unsigned int>(baseAdr + Offsets::Camptr);
    camera = MemoryWow.MRead<unsigned int>(lvl1pointer + Offsets::Camoffs);
    MemoryWow.MWrite<unsigned int>(baseAdr + Offsets::slowMo+0x4, camera + Offsets::Roll);
    //use like Malu the RIP roll of the camera to write a new float for ths slowmo, tell wow to read on the roll, can probably do less ugly but it's ok like that
}

void slowmo::disableSlowMo()
{
    baseAdr = MemoryWow.getBaseAdr();
    MemoryWow.MWrite<unsigned int>(baseAdr + Offsets::slowMo+0x4, baseAdr + Offsets::SlowMoSpeed);
}

void slowmo::setSpeed(float slowMo)
{
    baseAdr = MemoryWow.getBaseAdr();
    lvl1pointer = MemoryWow.MRead<unsigned int>(baseAdr + Offsets::Camptr);
    camera = MemoryWow.MRead<unsigned int>(lvl1pointer + Offsets::Camoffs);
    MemoryWow.MWrite<float>(camera + Offsets::Roll, slowMo);
}

void slowmo::setValue(double SlowMoA, double SlowMoB, int Time)
{
    slowMoA = SlowMoA/1000;
    slowMoB = SlowMoB/1000;
    slowMoC = SlowMoA/1000;
    time = Time;
}

void slowmo::run()
{
    baseAdr = MemoryWow.getBaseAdr();
    lvl1pointer = MemoryWow.MRead<unsigned int>(baseAdr + Offsets::Camptr);
    camera = MemoryWow.MRead<unsigned int>(lvl1pointer + Offsets::Camoffs);

    for (int i =0;i<time*100;i++)
    {
        slowMoC = slowMoC - (slowMoA - slowMoB)/(time*100); //took same as Malu's.
        MemoryWow.MWrite<float>(camera + Offsets::Roll,slowMoC);
        emitValue(slowMoC);
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
        if (m_terminate == true)
        {
            break;
        }
    }
    emit end();
}

void slowmo::stop()
{
    m_terminate=true;
}
