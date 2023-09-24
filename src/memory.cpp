/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "memory.h"
#include <TlHelp32.h>

Memory MemoryWow;


Memory::Memory()
{
}

void Memory::Initialize(DWORD Process_ID)
{
    ProcessID = Process_ID; // A CHANGER PARCE QUE C TROP MOCHE
    getAccess (Process_ID);
    baseAdr = GetProcessBaseAddress(Process_ID);
}

HANDLE Memory::getHANDLE ()
{
    return handle_proc;
}

HANDLE Memory::getAccess(DWORD process_ID)  // get an access to this thread
{
    handle_proc = OpenProcess(PROCESS_ALL_ACCESS,
                                     FALSE,
                                     process_ID);

    if (handle_proc == NULL)
    {
        QMessageBox::critical(0,"Error","Can't open its process. Try with admin access");
        exit(-1);
    }
    else
    {
        return handle_proc;
    }
}

DWORD Memory::GetProcessBaseAddress(DWORD process_ID) // return base address //frost source code
{
    HANDLE hSnapshot;
    MODULEENTRY32 me32;
    me32.dwSize = sizeof(MODULEENTRY32);
    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, process_ID);
    if(Module32First(hSnapshot, &me32) != TRUE)
        return 0;
    do
    {
        if(strcmp(me32.szModule, "WoW.exe") == 0 || strcmp(me32.szModule, "Wow.exe") == 0)
            return (DWORD)me32.modBaseAddr;
    } while(Module32Next(hSnapshot, &me32) != FALSE);
    CloseHandle(hSnapshot);
    return 0;
}

DWORD Memory::getBaseAdr()
{
    return baseAdr;
}

void Memory::MWriteArray(unsigned int addr, unsigned long long array, int size)
{
    WriteProcessMemory(handle_proc, (LPVOID)addr, &array, size, 0);
}

DWORD Memory::getProcessID()
{
    return ProcessID;
}
