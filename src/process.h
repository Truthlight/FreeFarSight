/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef PROCESS_H
#define PROCESS_H

#include <vector>
#include <string>
#include <windows.h>
#include <tlhelp32.h>


class process
{
public:
    process();
    std::vector<DWORD> FindHANDLEProcess(std::string nameHandle);
    void FindHWNDProcess (DWORD HandleID, std::string nameHwnd);
    HWND getHWND (DWORD processID,std::string nameHwnd);
    HWND getWowHWND();
    void flashWindowProcess(HWND handle);
    void getVersion();

private:
    std::vector <DWORD> processIDHandle ;
    std::vector <HANDLE> Handle;
    std::vector <HWND> HwndW;
    std::vector <HWND> Hwndexe;
    DWORD process_ID;
    HWND HwndWow;
};

extern process processWOW;

#endif // PROCESS_H
