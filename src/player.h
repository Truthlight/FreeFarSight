/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef PLAYER_H
#define PLAYER_H

#include "objectmanager.h"
#include "mainwidget.h"
#include "camera.h"
#include "memory.h"
//#include <sstream>

class Player : public ObjectManager
{
public:
    Player();
    void Readflag();
    quint64 ReadTargetGUID();
    quint64 ReadTargetGUID2();
    void EnableComm();
    void DisableCom();
    float getOrientation();
private:
    quint32 descriptor;
    quint32 flag;
    quint64 targetGUID;
    quint64 targetGUID2;
    DWORD processID;
    float orientationPlayer;
    std::vector <float> orientation;

};

//extern Player WowPlayer;

#endif // PLAYER_H
