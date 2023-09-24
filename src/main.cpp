/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include <QApplication>
#include <QMessageBox>

#include "process.h"
#include "widgetchooseprocess.h"

std::vector<DWORD>processIDHandle;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    processIDHandle = processWOW.FindHANDLEProcess ("Wow.exe");// search handle -> vector
    WidgetChooseProcess WChooseProcess (processIDHandle);
    WChooseProcess.SetProcessIDVector (processIDHandle);
    return a.exec();
}
