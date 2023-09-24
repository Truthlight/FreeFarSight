/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "objectmanager.h"

ObjectManager objMgr;

ObjectManager::ObjectManager()
{

}

void ObjectManager::Initialize()
{
    baseAdr = MemoryWow.getBaseAdr();
    //2 ways to get object manager :
    //pre_ObjectManager = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::ClientConnection);
    //objectManager = MemoryWow.MRead<unsigned int>(pre_ObjectManager + Offsets::CurrMgrOffset);
    //objectManager = MemoryWow.MRead<unsigned int>(baseAdr + Offsets::objMgrAdr);

    //LocalGUID = MemoryWow.MRead<unsigned long long>(objectManager + Offsets::LocalGUIDOffset);
}

unsigned int ObjectManager::FindMe()
{
    /*CurrentObject = MemoryWow.MRead<unsigned int>(objectManager+Offsets::FirstObjectOffset);
    Type = MemoryWow.MRead<unsigned int>(CurrentObject+Offsets::TypeOffset);
    while (CurrentObject != 0 && (CurrentObject & 1) == 0)
    {
        switch (Type)
        {
        case 4:
            Guid = MemoryWow.MRead<unsigned long long>(CurrentObject+Offsets::GuidOffset);
            if (Guid == LocalGUID)
            {
                PlayerBase = CurrentObject;
                return PlayerBase;
                break;
            }
        }
        CurrentObject = MemoryWow.MRead<unsigned int>(CurrentObject+Offsets::NextObjectOffset);;
        Type = MemoryWow.MRead<unsigned int>(CurrentObject+Offsets::TypeOffset);;
    }*/
    return MemoryWow.MRead<unsigned int>(baseAdr + Offsets::playerAdr);//unstead of using object manager, finally used the direct pointer of player//todo : change file name :D
    CloseHandle(handle_proc);
}
