/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef DBCLIGHTPARAMS_H
#define DBCLIGHTPARAMS_H

#include <QByteArray>
#include <QFile>
#include <QVector>
//#include <QDataStream>
#include "widgetmb.h"
//#include <QMessageBox>
#include<sstream>

class dbcLightParams
{
private:

public:
    struct sky
    {
        qint32 ID;
        qint32 highlightSky;//it's a bool... but don't know why it writted 7bytes...
        qint32 lightSkyboxID;
        qint32 cloudTypeID;
        float glow;
        float waterShallowAlpha;
        float waterDeepAlpha;
        float oceanShallowAlpha;
        float oceanDeepAlpha;
        qint32 flag;
    };
    dbcLightParams();
    sky readSky(quint32 skyNumber);
    sky readSkyUndo(quint32 skyNumber);
    quint32 readSize();
    std::vector<qint32> readSkyNumbers();
    qint32 readSkyNumber(qint32 env);
    quint32 getMaxValue();
};

#endif // DBCLIGHTPARAMS_H
