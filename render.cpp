/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "render.h"

Render::Render()
{
}

void Render::enableM2()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag+Offsets::renderM2);
}

void Render::enableFarM2()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag-Offsets::renderFarM2);
}

void Render::enableGroundDoodads()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag+Offsets::renderGroundDoodads);
}

void Render::enableTerrain()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag+Offsets::renderTerrain);
}

void Render::enableWmo()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag+Offsets::renderWmo);
}

void Render::enableLiquid()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag+Offsets::renderLiquid);
}

void Render::enableWdl()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag+Offsets::renderWDL);
}

/*void Render::enableWireframe()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag+Offsets::renderWireframe);
}*/

void Render::disableM2()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag-Offsets::renderM2);
}

void Render::disableFarM2()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag+Offsets::renderFarM2);
}

void Render::disableGroundDoodads()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag-Offsets::renderGroundDoodads);
}

void Render::disableTerrain()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag-Offsets::renderTerrain);
}

void Render::disableWmo()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag-Offsets::renderWmo);
}

void Render::disableLiquid()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag-Offsets::renderLiquid);
}

void Render::disableWdl()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag-Offsets::renderWDL);
}

/*void Render::disableWireframe()
{
    baseAdr = MemoryWow.getBaseAdr();
    unsigned int renderFlag = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::renderAdr);
    MemoryWow.MWrite<unsigned int>(baseAdr+Offsets::renderAdr,renderFlag-Offsets::renderWireframe);
}*/

/*renderM2 = 0x1,
renderTerrain = 0x2,
renderWmo = 0x20,
renderLiquid = 0x200,
renderWireframe = 0x08000000,
renderCollision = 0x04000000*/
