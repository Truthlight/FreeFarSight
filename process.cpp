/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "process.h"

#include <QApplication>
#include <QMessageBox>

process processWOW;

process::process()
{
}

std::vector<DWORD> process::FindHANDLEProcess (std::string nameHandle)
{
    PROCESSENTRY32   pe32;
    HANDLE         hSnapshot = NULL;
    pe32.dwSize = sizeof( PROCESSENTRY32 );
    hSnapshot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
    if( Process32First( hSnapshot, &pe32 ) )
    {
        do //seek for all handle
        {
            if( strcmp(pe32.szExeFile, nameHandle.c_str() ) == 0 ) //the ones named "Wow.exe"
            {
                processIDHandle.push_back (pe32.th32ProcessID); //add all handle "Wow.exe" on a vector
                Handle.push_back (hSnapshot);
            }
        }
        while( Process32Next( hSnapshot, &pe32 ) );
    }
    return processIDHandle;
}

void process::FindHWNDProcess (DWORD HandleID, std::string nameHwnd)
{
    HWND h = GetTopWindow(0);
    while (h) //seek for all windows
    {
        TCHAR szBuf[80];
        GetWindowText (h,szBuf,80);//find windows'name
        if (strcmp(szBuf , nameHwnd.c_str()) ==0)//the ones names "World of warcraft"
        {
            GetWindowThreadProcessId(h, &process_ID); //get his processID
            if (process_ID == HandleID) //compare to the one found by handle
            {
                flashWindowProcess(h); //flash window
                break;
            }
        }
        h = ::GetNextWindow( h , GW_HWNDNEXT);
    }
}

HWND process::getHWND (DWORD processID, std::string nameHwnd)
{
    HWND h = GetTopWindow(0);
    while (h) //seek for all windows
    {
        TCHAR szBuf[80];
        GetWindowText (h,szBuf,80);//find windows'name
        if (strcmp(szBuf , nameHwnd.c_str()) ==0)//the ones names "World of warcraft"
        {
            GetWindowThreadProcessId(h, &process_ID); //get his processID
            if (process_ID == processID) //compare to the one found by handle
            {
                HwndWow = h;
                return h;
            }
        }
        h = ::GetNextWindow( h , GW_HWNDNEXT);
    }
}

HWND process::getWowHWND()
{
    return HwndWow;
}


void process::flashWindowProcess(HWND handle)  //flash window
{
    FLASHWINFO info;

    info.cbSize = sizeof(info);
    info.hwnd = handle;
    info.dwFlags = FLASHW_ALL;
    info.dwTimeout = 0;
    info.uCount = 3;
    ::FlashWindowEx(&info);
}

void process::getVersion()
{
/*
    //Presque OK je pense !!
    DWORD dwHandle;
    //LPVOID ptr;
    //UINT uLength;
    std::string targetNameProcess = "World of Warcraft";
    DWORD dwVersionInfoSize = GetFileVersionInfoSizeA(targetNameProcess.c_str(), &dwHandle);
    LPVOID pFileInfo = (LPVOID) HeapAlloc(Handle.at(0), HEAP_ZERO_MEMORY, dwVersionInfoSize);
    GetFileVersionInfoA(targetNameProcess.c_str(), dwHandle, dwVersionInfoSize, pFileInfo);
*/
}


