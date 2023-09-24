/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef LIGHT_H
#define LIGHT_H

#include <QString>
#include <QVector>
#include <QTextStream>
#include "memory.h"
#include "Offsets.h"
#include "dbclightparams.h"
#include "widgetmb.h"

class Light
{
public:
    Light();
    //void DisableFog();
    //void EnableFog();
    void DisableCustomEnv();
    void EnableCustomEnv();
    int getFogColor();
    void setFogColor(int fogColor);
    float getFogNearClip();
    void setFogNearClip(float fogNearClip);
    float getFogFarClip();
    void setFogFarClip(float fogFarClip);
    float getFogDensity();
    void setFogDensity(float fogDensity);
    int getDiffuseColor();
    void setDiffuseColor(int diffuseColor);
    int getAmbientColor();
    void setAmbientColor(int ambientColor);
    int getSunHaloColor();
    void setSunHaloColor(int sunHaloColor);
    int getSkyColor0();
    void setSkyColor0(int skyColor0);
    int getSkyColor1();
    void setSkyColor1(int skyColor1);
    int getSkyColor2();
    void setSkyColor2(int skyColor2);
    int getSkyColor3();
    void setSkyColor3(int skyColor3);
    int getSkyColor4();
    void setSkyColor4(int skyColor4);
    int getSkyColor5();
    void setSkyColor5(int skyColor5);
    int getCloudColor1();
    void setCloudColor1(int cloudColor1);
    int getCloudColor2();
    void setCloudColor2(int cloudColor2);
    int getCloudColor3();
    void setCloudColor3(int cloudColor3);
    float getCloudDensity();
    void setCloudDensity(float cloudDensity);
    int getLakeEdgeColor();
    void setLakeEdgeColor(int lakeEdgeColor);
    int getLakeMidColor();
    void setLakeMidColor(int lakeMidColor);
    int getSeaEdgeColor();
    void setSeaEdgeColor(int seaEdgeColor);
    int getSeaMidColor();
    void setSeaMidColor(int seaMidColor);
    void setEnvironment (int env);
    void setEnvironmentUndo ();
    void saveLight(QString fileName);
    void loadLight(QString fileName);


private:
    DWORD baseAdr;
};

#endif // LIGHT_H
