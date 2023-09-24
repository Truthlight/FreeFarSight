/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef COMMENTATOR_H
#define COMMENTATOR_H

#include "memory.h"
#include "Offsets.h"

#include <sstream>
#include <QtGlobal>

class Commentator
{
public:
    Commentator();
    void EnableCollision();
    void DisableCollision();
    void SetSpeed(double Speed);
    void LookAtTarget(quint64 TargetGUID, quint64 TargetGUID2);
    void LookAtTargetDisable();
    void FollowTarget(quint64 TargetGUID, quint64 TargetGUID2);
    void FollowTargetDisable();
    void SetAutoPanX(qint32 i);
    void SetAutoPanY(qint32 i);
    void SetAutoPanZ(qint32 i);
    void SetAutoRotate(qint32 i);
    void SetZoom(qint32 i);
    void SetZoom(float i);
    float getZoom ();
    void viewPoint(std::vector <float> &xyzLocation);
private:
    DWORD baseAdr;
    unsigned long long TargetGUID;
};

#endif // COMMENTATOR_H
