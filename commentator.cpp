/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "commentator.h"

Commentator::Commentator()
{

}

void Commentator::EnableCollision()
{
    baseAdr = MemoryWow.getBaseAdr();//*A voir pour ne dÃ©clarer qu'une fois.
    MemoryWow.MWrite<quint32>(baseAdr+Offsets::Com_Collision,1);
}

void Commentator::DisableCollision()
{
    baseAdr = MemoryWow.getBaseAdr();//*
    MemoryWow.MWrite<quint32>(baseAdr+Offsets::Com_Collision,0);
}

void Commentator::SetSpeed(double Speed)
{
    baseAdr = MemoryWow.getBaseAdr();//*
    MemoryWow.MWrite<float>(baseAdr+Offsets::Com_Speed,Speed);
}

void Commentator::LookAtTarget(quint64 TargetGUID,quint64 TargetGUID2)
{
    baseAdr = MemoryWow.getBaseAdr();//*
    MemoryWow.MWrite<quint64>(baseAdr+Offsets::Com_GUIDrelative1, TargetGUID);
    MemoryWow.MWrite<quint64>(baseAdr+Offsets::Com_GUIDrelative2, TargetGUID2);
}

void Commentator::LookAtTargetDisable()
{
    MemoryWow.MWrite<quint64>(baseAdr+Offsets::Com_GUIDrelative1,NULL);
    MemoryWow.MWrite<quint64>(baseAdr+Offsets::Com_GUIDrelative2,NULL);
}

void Commentator::FollowTarget(quint64 TargetGUID, quint64 TargetGUID2)
{
    baseAdr = MemoryWow.getBaseAdr();//*
    MemoryWow.MWrite<quint64>(baseAdr+Offsets::Com_GUIDFree1, TargetGUID);
    MemoryWow.MWrite<quint64>(baseAdr+Offsets::Com_GUIDFree2, TargetGUID2);
}

void Commentator::FollowTargetDisable()
{
    MemoryWow.MWrite<quint64>(baseAdr+Offsets::Com_GUIDFree1, NULL);
    MemoryWow.MWrite<quint64>(baseAdr+Offsets::Com_GUIDFree2, NULL);
}

void Commentator::SetAutoPanX(qint32 i)
{
    baseAdr = MemoryWow.getBaseAdr();//*
    float j = i;
    j/=100;
    MemoryWow.MWrite<float>(baseAdr+Offsets::Com_autoPanX, j);
}

void Commentator::SetAutoPanY(qint32 i)
{
    baseAdr = MemoryWow.getBaseAdr();//*
    float j = i;
    j/=100;
    MemoryWow.MWrite<float>(baseAdr+Offsets::Com_autoPanY, j);
}

void Commentator::SetAutoPanZ(qint32 i)
{
    baseAdr = MemoryWow.getBaseAdr();//*
    float j = i;
    j/=100;
    MemoryWow.MWrite<float>(baseAdr+Offsets::Com_autoPanZ, j);
}

void Commentator::SetAutoRotate(qint32 i)
{
    baseAdr = MemoryWow.getBaseAdr();//*
    float j = i;
    j/=1000;
    MemoryWow.MWrite<float>(baseAdr+Offsets::Com_AutoRotate, j);
}

void Commentator::viewPoint(std::vector <float> &xyzLocation)
{
    baseAdr = MemoryWow.getBaseAdr();//*
    MemoryWow.MWrite<float>(baseAdr + Offsets::Com_X, xyzLocation.at(0));
    MemoryWow.MWrite<float>(baseAdr + Offsets::Com_Y, xyzLocation.at(1));
    MemoryWow.MWrite<float>(baseAdr + Offsets::Com_Z, xyzLocation.at(2));
}

float Commentator::getZoom ()
{
    baseAdr = MemoryWow.getBaseAdr();//*
    return MemoryWow.MRead<float>(baseAdr+Offsets::Com_Zoom2);
}

void Commentator::SetZoom(qint32 i)
{
    baseAdr = MemoryWow.getBaseAdr();//*
    float j = i;
    j/=100;
    MemoryWow.MWrite<float>(baseAdr+Offsets::Com_Zoom2, j);
}

void Commentator::SetZoom(float i)
{
    MemoryWow.MWrite<float>(baseAdr+Offsets::Com_Zoom2, i);
}
