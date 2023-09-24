/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef MEMORY_H
#define MEMORY_H

#include <QMessageBox>
#include <windows.h>

class Memory
{
public:
    Memory();
    void Initialize(DWORD Process_ID);
    HANDLE getHANDLE ();
    HANDLE getAccess(DWORD process_ID);
    DWORD GetProcessBaseAddress(DWORD process_ID);
    DWORD getBaseAdr();
    DWORD getProcessID();

    template<class T>
    T MRead(unsigned int addr)
    {
        T value;
        int result;
        result = ReadProcessMemory(handle_proc, (LPCVOID)addr, &value, sizeof(value), 0);
        if(result == 0) // failed
            return (T)0;
        return value; // Success
    };
    template<class S>
    void MWrite(unsigned int addr, S value)
    {
        WriteProcessMemory(handle_proc, (LPVOID)addr, &value, sizeof(value), 0);
    };
    void MWriteArray(unsigned int addr, unsigned long long array, int size);

private:
    HANDLE handle_proc;
    DWORD baseAdr;
    DWORD ProcessID;
};


extern Memory MemoryWow;

#endif // MEMORY_H
