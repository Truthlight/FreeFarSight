/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "dbclightparams.h"

dbcLightParams::dbcLightParams()
{
}

dbcLightParams::sky dbcLightParams::readSky(quint32 skyNumber)
{
    QFile dbcLP ("LightParams.dbc");
    QDataStream in (&dbcLP);
    in.setByteOrder(QDataStream::LittleEndian);
    in.setFloatingPointPrecision(QDataStream::SinglePrecision);
    if (dbcLP.open(QIODevice::ReadOnly))
    {
        std::vector<int>skyNumbers = readSkyNumbers();
        for (int i=0;i<readSize();i++)
        {
            if (skyNumber==skyNumbers.at(i))
            {
                skyNumber=i;
                break;
            }
        }
        dbcLP.seek(0x14+0x28*(skyNumber));
        sky m_sky;
        in>>m_sky.ID;
        in>>m_sky.highlightSky;
        in>>m_sky.lightSkyboxID;
        in>>m_sky.cloudTypeID;
        in>>m_sky.glow;
        in>>m_sky.waterShallowAlpha;
        in>>m_sky.waterDeepAlpha;
        in>>m_sky.oceanShallowAlpha;
        in>>m_sky.oceanDeepAlpha;
        in>>m_sky.flag;
        dbcLP.close();
        return m_sky;
    }
}

dbcLightParams::sky dbcLightParams::readSkyUndo(quint32 skyNumber)
{
    QFile dbcLP ("LightParams.dbc");
    QDataStream in (&dbcLP);
    in.setByteOrder(QDataStream::LittleEndian);
    in.setFloatingPointPrecision(QDataStream::SinglePrecision);
    if (dbcLP.open(QIODevice::ReadOnly))
    {
        dbcLP.seek(0x14+0x28*(skyNumber));
        sky m_sky;
        in>>m_sky.ID;
        in>>m_sky.highlightSky;
        in>>m_sky.lightSkyboxID;
        in>>m_sky.cloudTypeID;
        in>>m_sky.glow;
        in>>m_sky.waterShallowAlpha;
        in>>m_sky.waterDeepAlpha;
        in>>m_sky.oceanShallowAlpha;
        in>>m_sky.oceanDeepAlpha;
        in>>m_sky.flag;
        dbcLP.close();
        return m_sky;
    }
}

quint32 dbcLightParams::readSize()
{
    QFile dbcLP("LightParams.dbc");
    if (dbcLP.exists())
    {
        dbcLP.open(QIODevice::ReadOnly);
        dbcLP.seek(4);
        QDataStream in (&dbcLP);
        in.setByteOrder(QDataStream::LittleEndian);
        qint32 buffer;
        in>>buffer;
        dbcLP.close();
        return buffer;
    }
}

std::vector<qint32> dbcLightParams::readSkyNumbers()
{
    QFile dbcLP ("LightParams.dbc");

    if (dbcLP.exists())
    {
        dbcLP.open(QIODevice::ReadOnly);
        std::vector <int> skyNumbers;
        //dbcLP.seek(20);
        QDataStream in (&dbcLP);
        in.setByteOrder(QDataStream::LittleEndian);
        for (int i=0;i<readSize();i++)
        {
            qint32 buffer;
            dbcLP.seek(20+40*i);
            in>>buffer;
            skyNumbers.push_back(buffer);
        }
        dbcLP.close();
        return skyNumbers;
    }
}

qint32 dbcLightParams::readSkyNumber(qint32 env)
{
    QFile dbcLP ("LightParams.dbc");

    if (dbcLP.exists())
    {
        dbcLP.open(QIODevice::ReadOnly);
        QDataStream in (&dbcLP);
        in.setByteOrder(QDataStream::LittleEndian);
        qint32 buffer;
        dbcLP.seek(20+(env-1)*40);
        in>>buffer;
        dbcLP.close();
        return buffer;
    }
}

quint32 dbcLightParams::getMaxValue()
{
    QFile dbcLP ("LightParams.dbc");
    if (dbcLP.exists())
    {
        dbcLP.open(QIODevice::ReadOnly);
        QDataStream in (&dbcLP);
        qint32 buffer;
        in.setByteOrder(QDataStream::LittleEndian);
        dbcLP.seek((readSize()-1)*40+20);
        in>>buffer;
        dbcLP.close();
        return buffer;
    }
}
