/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "ffs_time.h"

Time::Time()
{
}

void Time::setHour(int Hour)
{
    baseAdr = MemoryWow.getBaseAdr();
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::timeHour,Hour);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::timeHourMinimap,Hour);
}

void Time::setMin(int Min)
{
    baseAdr = MemoryWow.getBaseAdr();
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::timeMin,Min);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::timeMinMinimap,Min);
}

void Time::setSpeed(double Speed)
{
    baseAdr = MemoryWow.getBaseAdr();
    float Speedfl = Speed;
    MemoryWow.MWrite<float>(baseAdr+Offsets::timeSpeed,Speedfl);
}
