/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "light.h"

dbcLightParams dbcLP;

Light::Light()
{
}

/*void Light::DisableFog()
{
    baseAdr = MemoryWow.getBaseAdr();
    MemoryWow.MWrite<UINT16>(baseAdr+Offsets::fogDensityM2Protec,Offsets::fogDensityProtectPatch);
    MemoryWow.MWrite<UINT16>(baseAdr+Offsets::fogDensityWmoProtec,Offsets::fogDensityProtectPatch);
    MemoryWow.MWrite<UINT16>(baseAdr+Offsets::fogDensityTerrainProtec,Offsets::fogDensityProtectPatch);
    MemoryWow.MWrite<float>(baseAdr+Offsets::fogDensityM2,0);
    MemoryWow.MWrite<float>(baseAdr+Offsets::fogDensityWmo,0);
    MemoryWow.MWrite<float>(baseAdr+Offsets::fogDensityTerrain,0);
}

void Light::EnableFog()
{
    baseAdr = MemoryWow.getBaseAdr();
    MemoryWow.MWrite<UINT16>(baseAdr+Offsets::fogDensityM2Protec,Offsets::fogDensityProtect);
    MemoryWow.MWrite<UINT16>(baseAdr+Offsets::fogDensityWmoProtec,Offsets::fogDensityProtect);
    MemoryWow.MWrite<UINT16>(baseAdr+Offsets::fogDensityTerrainProtec,Offsets::fogDensityProtect);
}*/

void Light::DisableCustomEnv()
{
    baseAdr = MemoryWow.getBaseAdr();
    MemoryWow.MWriteArray(baseAdr+Offsets::fogColorProtecAdr,Offsets::fogColorProtec,6);
    MemoryWow.MWriteArray(baseAdr+Offsets::fogNearClipProtecAdr,Offsets::fogNearClipProtec,8);
    MemoryWow.MWriteArray(baseAdr+Offsets::fogFarClipProtecAdr,Offsets::fogFarClipProtec,8);
    MemoryWow.MWriteArray(baseAdr+Offsets::fogDensityProtecAdr,Offsets::fogDensityProtec,6);
    MemoryWow.MWriteArray(baseAdr+Offsets::skyColorProtecAdr,Offsets::skyColorProtec,2);
    MemoryWow.MWriteArray(baseAdr+Offsets::sunColorProtecAdr,Offsets::sunColorProtec,2);
    MemoryWow.MWriteArray(baseAdr+Offsets::waterColorProtecAdr,Offsets::waterColorProtec,2);
    MemoryWow.MWriteArray(baseAdr+Offsets::diffuseLightProtecAdr,Offsets::diffuseLightProtec,2);
    MemoryWow.MWriteArray(baseAdr+Offsets::ambientLightProtecAdr,Offsets::ambientLightProtec,3);
    //MemoryWow.MWriteArray(baseAdr+Offsets::cloudDensityProtecAdr,Offsets::cloudDensityProtec,2);
}

void Light::EnableCustomEnv()
{
    baseAdr = MemoryWow.getBaseAdr();
    MemoryWow.MWriteArray(baseAdr+Offsets::fogColorProtecAdr,Offsets::fogColorProtecPatch,6);
    MemoryWow.MWriteArray(baseAdr+Offsets::fogNearClipProtecAdr,Offsets::fogNearClipProtecPatch,8);
    MemoryWow.MWriteArray(baseAdr+Offsets::fogFarClipProtecAdr,Offsets::fogFarClipProtecPatch,8);
    MemoryWow.MWriteArray(baseAdr+Offsets::fogDensityProtecAdr,Offsets::fogDensityProtecPatch,6);
    MemoryWow.MWriteArray(baseAdr+Offsets::skyColorProtecAdr,Offsets::skyColorProtecPatch,2);
    MemoryWow.MWriteArray(baseAdr+Offsets::sunColorProtecAdr,Offsets::sunColorProtecPatch,2);
    MemoryWow.MWriteArray(baseAdr+Offsets::waterColorProtecAdr,Offsets::waterColorProtecPatch,2);
    MemoryWow.MWriteArray(baseAdr+Offsets::diffuseLightProtecAdr,Offsets::diffuseLightProtecPatch,2);
    MemoryWow.MWriteArray(baseAdr+Offsets::ambientLightProtecAdr,Offsets::ambientLightProtecPatch,3);
    //MemoryWow.MWriteArray(baseAdr+Offsets::cloudDensityProtecAdr,Offsets::cloudDensityProtecPatch,2);//doesn't work/remove all skys :(
}

int Light::getFogColor()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::fogColor);
}

void Light::setFogColor(int fogColor)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::fogColor,fogColor);
}

float Light::getFogNearClip()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<float>(lvl2ptr+Offsets::lightOffs2+Offsets::fogNearClip);
}

void Light::setFogNearClip(float fogNearClip)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<float>(lvl2ptr+Offsets::lightOffs2+Offsets::fogNearClip,fogNearClip);
}

float Light::getFogFarClip()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<float>(lvl2ptr+Offsets::lightOffs2+Offsets::fogFarClip);
}

void Light::setFogFarClip(float fogFarClip)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<float>(lvl2ptr+Offsets::lightOffs2+Offsets::fogFarClip,fogFarClip);
}

float Light::getFogDensity()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<float>(lvl2ptr+Offsets::lightOffs2+Offsets::fogDensity);
}

void Light::setFogDensity(float fogDensity)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<float>(lvl2ptr+Offsets::lightOffs2+Offsets::fogDensity,fogDensity);
}

int Light::getDiffuseColor()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::diffuseLight);
}

void Light::setDiffuseColor(int diffuseColor)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::diffuseLight,diffuseColor);
}

int Light::getAmbientColor()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::ambientLight);
}

void Light::setAmbientColor(int ambientColor)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::ambientLight,ambientColor);
}

int Light::getSunHaloColor()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::sunColor);
}

void Light::setSunHaloColor(int sunHaloColor)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::sunColor,sunHaloColor);
}

int Light::getSkyColor0()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor0);
}

void Light::setSkyColor0(int skyColor0)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor0,skyColor0);
}

int Light::getSkyColor1()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor1);
}

void Light::setSkyColor1(int skyColor1)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor1,skyColor1);
}

int Light::getSkyColor2()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor2);
}

void Light::setSkyColor2(int skyColor2)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor2,skyColor2);
}

int Light::getSkyColor3()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor3);
}

void Light::setSkyColor3(int skyColor3)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor3,skyColor3);
}

int Light::getSkyColor4()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor4);
}

void Light::setSkyColor4(int skyColor4)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor4,skyColor4);
}

int Light::getSkyColor5()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor5);
}

void Light::setSkyColor5(int skyColor5)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::skyColor5,skyColor5);
}

int Light::getCloudColor1()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::cloudColor1);
}

void Light::setCloudColor1(int cloudColor1)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::cloudColor1,cloudColor1);
}

int Light::getCloudColor2()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::cloudColor2);
}

void Light::setCloudColor2(int cloudColor2)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::cloudColor2,cloudColor2);
}

int Light::getCloudColor3()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::cloudColor3);
}

void Light::setCloudColor3(int cloudColor3)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::cloudColor3,cloudColor3);
}

float Light::getCloudDensity()
{
    return 1.0f; // TODO
}

void Light::setCloudDensity(float cloudDensity)
{

}

int Light::getLakeEdgeColor()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::lakeEdgeColor);
}

void Light::setLakeEdgeColor(int lakeEdgeColor)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::lakeEdgeColor,lakeEdgeColor);
}

int Light::getLakeMidColor()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::lakeMidColor);
}

void Light::setLakeMidColor(int lakeMidColor)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::lakeMidColor,lakeMidColor);
}

int Light::getSeaEdgeColor()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::seaEdgeColor);
}

void Light::setSeaEdgeColor(int seaEdgeColor)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::seaEdgeColor,seaEdgeColor);
}

int Light::getSeaMidColor()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    return MemoryWow.MRead<int>(lvl2ptr+Offsets::lightOffs2+Offsets::seaMidColor);
}

void Light::setSeaMidColor(int seaMidColor)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::lightPtr);
    int lvl2ptr = MemoryWow.MRead<int>(lvl1ptr+Offsets::lightOffs1);
    MemoryWow.MWrite<int>(lvl2ptr+Offsets::lightOffs2+Offsets::seaMidColor,seaMidColor);
}

void Light::setEnvironment(int env)
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::environment);
    dbcLightParams::sky sky;
    sky = dbcLP.readSkyUndo(env);
    for (int i=0; i<dbcLP.readSize() ;i++)
    {
        MemoryWow.MWrite<int>(lvl1ptr+i*40,sky.ID);
        MemoryWow.MWrite<int>(lvl1ptr+i*40+0x4,sky.highlightSky);
        MemoryWow.MWrite<int>(lvl1ptr+i*40+0x8,sky.lightSkyboxID);
        MemoryWow.MWrite<int>(lvl1ptr+i*40+0xC,sky.cloudTypeID);
        MemoryWow.MWrite<float>(lvl1ptr+i*40+0x10,sky.glow);
        MemoryWow.MWrite<float>(lvl1ptr+i*40+0x14,sky.waterShallowAlpha);
        MemoryWow.MWrite<float>(lvl1ptr+i*40+0x18,sky.waterDeepAlpha);
        MemoryWow.MWrite<float>(lvl1ptr+i*40+0x1C,sky.oceanShallowAlpha);
        MemoryWow.MWrite<float>(lvl1ptr+i*40+0x20,sky.oceanDeepAlpha);
        MemoryWow.MWrite<int>(lvl1ptr+i*40+0x24,sky.flag);
    }
}

void Light::setEnvironmentUndo()
{
    baseAdr = MemoryWow.getBaseAdr();
    int lvl1ptr = MemoryWow.MRead<int>(baseAdr+Offsets::environment);
    dbcLightParams::sky sky;
    for (int i=0; i<dbcLP.readSize() ;i++)
    {
        sky = dbcLP.readSkyUndo(i);
        MemoryWow.MWrite<int>(lvl1ptr+i*40,sky.ID);
        MemoryWow.MWrite<int>(lvl1ptr+i*40+0x4,sky.highlightSky);
        MemoryWow.MWrite<int>(lvl1ptr+i*40+0x8,sky.lightSkyboxID);
        MemoryWow.MWrite<int>(lvl1ptr+i*40+0xC,sky.cloudTypeID);
        MemoryWow.MWrite<float>(lvl1ptr+i*40+0x10,sky.glow);
        MemoryWow.MWrite<float>(lvl1ptr+i*40+0x14,sky.waterShallowAlpha);
        MemoryWow.MWrite<float>(lvl1ptr+i*40+0x18,sky.waterDeepAlpha);
        MemoryWow.MWrite<float>(lvl1ptr+i*40+0x1C,sky.oceanShallowAlpha);
        MemoryWow.MWrite<float>(lvl1ptr+i*40+0x20,sky.oceanDeepAlpha);
        MemoryWow.MWrite<int>(lvl1ptr+i*40+0x24,sky.flag);
    }
}

void Light::saveLight(QString fileName)
{
    QFile file ("LightCustom/"+fileName+".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;
    QTextStream fichier (&file);

    QByteArray buffer;

    fichier <<buffer.number(getFogColor(),16).right(6)<<" "<<  //WTF? read color in memory -> convert in hex -> remove useless byte "FF" (more readable in .txt file)
          getFogNearClip()<<" "<<
          getFogFarClip()<<" "<<
          getFogDensity()<<" "<<
          buffer.number(getDiffuseColor(),16).right(6)<<" "<<
          buffer.number(getAmbientColor(),16).right(6)<<" "<<
          buffer.number(getSunHaloColor(),16).right(6)<<" "<<
          buffer.number(getSkyColor0(),16).right(6)<<" "<<
          buffer.number(getSkyColor1(),16).right(6)<<" "<<
          buffer.number(getSkyColor2(),16).right(6)<<" "<<
          buffer.number(getSkyColor3(),16).right(6)<<" "<<
          buffer.number(getSkyColor4(),16).right(6)<<" "<<
          buffer.number(getSkyColor5(),16).right(6)<<" "<<
          buffer.number(getCloudColor1(),16).right(6)<<" "<<
          buffer.number(getCloudColor2(),16).right(6)<<" "<<
          buffer.number(getCloudColor3(),16).right(6)<<" "<<
          buffer.number(getLakeEdgeColor(),16).right(6)<<" "<<
          buffer.number(getLakeMidColor(),16).right(6)<<" "<<
          buffer.number(getSeaEdgeColor(),16).right(6)<<" "<<
          buffer.number(getSeaMidColor(),16).right(6);
    file.close();
}

void Light::loadLight(QString fileName)
{
    QFile file ("LightCustom/"+fileName+".txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;
    QTextStream fichier (&file);
    QString ligne;
    QStringList lightList;
    while( !fichier.atEnd() )
    {
        //getline(fichier, ligne.toStdString());//lecture d'une ligne du fichier
        ligne=fichier.readLine();
        lightList = ligne.split(" ");
        setFogColor(lightList.at(0).toInt(0,16));
        setFogNearClip(lightList.at(1).toDouble());
        setFogFarClip(lightList.at(2).toDouble());
        setFogDensity(lightList.at(3).toDouble());
        setDiffuseColor(lightList.at(4).toInt(0,16));
        setAmbientColor(lightList.at(5).toInt(0,16));
        setSunHaloColor(lightList.at(6).toInt(0,16));
        setSkyColor0(lightList.at(7).toInt(0,16));
        setSkyColor1(lightList.at(8).toInt(0,16));
        setSkyColor2(lightList.at(9).toInt(0,16));
        setSkyColor3(lightList.at(10).toInt(0,16));
        setSkyColor4(lightList.at(11).toInt(0,16));
        setSkyColor5(lightList.at(12).toInt(0,16));
        setCloudColor1(lightList.at(13).toInt(0,16));
        setCloudColor2(lightList.at(14).toInt(0,16));
        setCloudColor3(lightList.at(15).toInt(0,16));
        setLakeEdgeColor(lightList.at(16).toInt(0,16));
        setLakeMidColor(lightList.at(17).toInt(0,16));
        setSeaEdgeColor(lightList.at(18).toInt(0,16));
        setSeaMidColor(lightList.at(19).toInt(0,16));
    }
    file.close();
}
