/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

//#include <QMessageBox>
//#include <sstream>
//#include <string>
#include "Offsets.h"
#include "windows.h"
#include "memory.h"

class ObjectManager
{
public:
    ObjectManager();
    void Initialize();
    unsigned int FindMe();
private:
    HANDLE handle_proc;
    unsigned int objectManager;
    unsigned int pre_ObjectManager;
    unsigned long long LocalGUID;
    unsigned int CurrentObject;
    unsigned int Type;
    unsigned long long Guid;
    DWORD baseAdr;

protected:
    DWORD processID;
    unsigned int PlayerBase;

};

extern ObjectManager objMgr;

#endif // OBJECTMANAGER_H
