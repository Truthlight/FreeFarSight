/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef OFFSETS_H
#define OFFSETS_H


namespace Offsets
{
enum ObjectManager
{
    //playerAdr = 0xDC0BC8,//F21C00,//
    //playerAdr = 0xE2AD40,//6.2//
    playerAdr = 0xD2E4C0,//E379B0,//E37930, //6.2.2//
    //FirstObjectOffset = 0xCC,
    //NextObjectOffset = 0x34,
    //LocalGUIDOffset = 0xE8,
    //GuidOffset = 0x0,
    //TypeOffset = 0xC,
    DescriptorOffset = 0x4//ok
};

enum Player
{
    XOffset = 0xAC0,//A90,
    YOffset = 0xAC4,//A94,
    ZOffset = 0xAC8,//A98,
    RotationOffset = 0xAD0,//AA0
};


enum CommentatorMode
{
    Com_Yaw = 0xE1C150,//F25968,//F258E0,//F18B98,//FBB508,
    Com_Pitch = Com_Yaw + 0x04,
    Com_AutoRotate = Com_Yaw + 0x08,
    Com_X = Com_Yaw + 0x0C,
    Com_Y = Com_Yaw + 0x10,
    Com_Z = Com_Yaw + 0x14,
    Com_X2 = Com_Yaw + 0x18,
    Com_Y2 = Com_Yaw + 0x1C,
    Com_Z2 = Com_Yaw + 0x20,
    //Com_Unknown1 = Com_Yaw + 0x24,
    //Com_Unknown2 = Com_Yaw + 0x28,
    //Com_Unknown3 = Com_Yaw + 0x2C,

    Com_autoPanX = Com_Yaw + 0x30,
    Com_autoPanY = Com_Yaw + 0x34,
    Com_autoPanZ = Com_Yaw + 0x38,
    //Com_Unknown4 = Com_Yaw + 0x3C,
    Com_GUIDrelative1 = Com_Yaw + 0x40,//28, //look at GUID
    Com_GUIDrelative2 = Com_Yaw + 0x48,//30, //look at GUID
    Com_GUIDFree1 = Com_Yaw + 0x60,//38, //follow GUID
    Com_GUIDFree2 = Com_Yaw + 0x68,//40, //follow GUID
    Com_Unknown6 = Com_Yaw + 0x60,// Zoom related 48,
    Com_Zoom1 = Com_Yaw + 0x64,//4C,
    Com_Zoom2 = Com_Yaw + 0x68,//50,
    Com_Speed = Com_Yaw + 0x7C,//54,//
    Com_Collision = Com_Yaw + 0x80//58
};

enum Cameraoffs
{
    //Camptr = 0xE362A8,//F972C8,//
    //Camptr = 0xEA24E0,//6.2//
    Camptr = 0xDA5D58,//EAF270,//EAF1F0, //6.2.2//
    Camoffs = 0x7610,

    Unknown1 = 0x00,
    Unknown2 = 0x04,
    Cam_X = 0x08,
    Cam_Y = 0x0C,
    Cam_Z = 0x10,
    Matrix_1_1 = 0x14,
    Matrix_1_2 = 0x18,
    Matrix_1_3 = 0x1C,
    Matrix_2_1 = 0x20,
    Matrix_2_2 = 0x24,
    Matrix_2_3 = 0x28,
    Matrix_3_1 = 0x2C,
    Matrix_3_2 = 0x30,
    Matrix_3_3 = 0x34,
    FOV = 0x38,
    Distance = 0x124,
    Yaw = 0x128,
    Pitch = 0x12C,
    Roll = 0x130,
    Zoom = 0x144, //-1.47 to  1.47
    AttachX = 0x14c,
    AttachY = 0x150,
    AttachZ = 0x154
    /*Distance = 0x118,//124
    Yaw = 0x11C,//128
    Pitch = 0x120,//12C
    Roll = 0x124,//130
    Zoom = 0x138,//144 -1.47 to  1.47
    AttachX = 0x140,//14c
    AttachY = 0x144,//150
    AttachZ = 0x148//154*/
};

enum Render
{
    //renderAdr = 0xEB9650,//101A5C0,//
    renderAdr = 0xE7ABB8,//F84230,//F84A20,//F77C78,//6.2
    renderM2 = 0x1,
    renderTerrain = 0x2,
    renderWmo = 0x20,
    renderLiquid = 0x200,
    //renderWireframe = 0x08000000,
    //renderCollision = 0x04000000,
    renderWDL = 0x100,
    renderGroundDoodads = 0x80,
    renderFarM2 = 0x2000
};

enum ViewDistance
{
    //viewDistance = 0xEB963C//101A5AC//
    //viewDistance = 0xF77C64//6.2
    viewDistance = 0xE7ABA4,//F8421C,//F84A0C,//F77C64//6.2.
};

enum Time
{
    //timeMin = 0xD13CD0,
    timeMin = 0xC751F8,//D7D5D0,//D7D550,//D70CD8,//6.2
    timeHour = timeMin + 0x4,
    timeSpeed = timeMin + 0x30,
    timeStamp = timeMin + 0x34,//change to 0.99 to instant change of the time
    timeMinMinimap = timeMin + 0x80,
    timeHourMinimap = timeMin + 0x84
};

enum Light
{
    //lightPtr = 0xC921CC,//DDFDF4,//
    lightPtr = 0xBEDF80,//CF6580,//CF6500,//CEA2A0,//6.2
    lightOffs1 = 0,
    lightOffs2 = 0x88,
    fogColor = 0x0,
    fogNearClip = 0x4,
    fogFarClip = 0x8,
    fogDensity = 0xC,
    //...
    diffuseLight = 0xD8,//160 ok
    ambientLight = 0xDC,
    //...
    skyColor0 = 0xE4,//16c ok
    skyColor1 = 0xE8,
    skyColor2 = 0xEC,
    skyColor3 = 0xF0,
    skyColor4 = 0xF4,
    skyColor5 = 0xF8,
    sunColor = 0xFC,//184
    cloudColor1 = 0x100,
    cloudColor2 = 0x104,
    cloudColor3 = 0x108,
    //...
    seaEdgeColor = 0x110,//198 ok
    seaMidColor = 0x114,
    lakeEdgeColor = 0x118,
    lakeMidColor = 0x11C,
    //
    cloudDensity = 0x138,// /!\ error 134

    //fogColorProtecAdr = 0x8282B4,
    fogColorProtecAdr = 0x843F82,//87871A,//878630,//878628,//8781FA,//87823B,//877F2D,//86E76B,//6.2
    fogColorProtec = 0x000000888E89,//6.0.2
    fogColorProtecPatch = 0x909090909090,

    //fogNearClipProtecAdr = 0x8282AC,
    fogNearClipProtecAdr = 0x843F7A,//878712,//878628,//878620,//8781F2,//878233,//877F25,//86E763,//6.2
    fogNearClipProtec = 0x0000008C8E110FF3,//6.0.2
    fogNearClipProtecPatch = 0x9090909090909090,

    //fogFarClipProtecAdr = 0x8282A4,
    fogFarClipProtecAdr = 0x843F72,//87870A,//878620,//878618,//8781EA,//87822B,//877F1D,//86E75B,//6.2
    fogFarClipProtec = 0x0000009086110FF3,//6.0.2
    fogFarClipProtecPatch = 0x9090909090909090,

    //fogDensityProtecAdr = 0x82829A,
    fogDensityProtecAdr = 0x843F68,//878700,//878616,//87860E,//8781E0,//878221,//877F13,//86E751,//6.2
    fogDensityProtec = 0x000000949ED9,//6.0.2
    fogDensityProtecPatch = 0x909090909090,

    //diffuseLightProtecAdr = 0x827F0C,
    diffuseLightProtecAdr = 0x843BDA,//878372,//878288,//878280,//877E52,//877E93,//877B84,//86E3C3,//6.2
    diffuseLightProtec = 0x0889,//6.0.2
    diffuseLightProtecPatch = 0x9090,

    //ambientLightProtecAdr = 0x827F12,
    ambientLightProtecAdr = 0x843BE0,//878378,//87828E,//878286,//877E58,//877E99,//877B8A,//86E3C9,//6.2
    ambientLightProtec = 0x044889,//6.0.2
    ambientLightProtecPatch = 0x909090,

    //skyColorProtecAdr = 0x827F2F,
    skyColorProtecAdr = 0x843BFD,//878395,//8782AB,//8782A3,//877E75,//877EB6,//877BA7,//86E3E6,//6.2
    skyColorProtec = 0x1189,//6.0.2
    skyColorProtecPatch = 0x9090,

    //sunColorProtecAdr = 0x827F45,//+cloud
    sunColorProtecAdr = 0x843C13,//8783AB,//8782C1,//8782B9,//877E8B,//877ECC,//877BBD,//86E3FC,//6.2
    sunColorProtec = 0x1189,//6.0.2
    sunColorProtecPatch = 0x9090,

    //waterColorProtecAdr = 0x827F57,
    waterColorProtecAdr = 0x843C25,//8783BD,//8782D3,//8782CB,//877E9D,//877EDE,//877BCF,//86E40E,//6.2
    waterColorProtec = 0x1189,//6.0.2
    waterColorProtecPatch = 0x9090,

    cloudDensityProtecAdr = 0x7CA633,//5.4.8 18414
    cloudDensityProtec = 0x1ED9,
    cloudDensityProtecPatch = 0x9090,

    //environment = 0xD135A4
    environment = 0xC74ACC,//D7CEA4,//D7CE24,//D705AC//6.2
};

enum SlowMo
{
    //slowMo = 0x1D287,//0259D3,//
    slowMo = 0x01FFD4,//01FF3D,//01F65E,//01F67E,//01F506,//01F5E2,//1F43C,//6.2
    //SlowMoSpeed = 0x9A2208//AA160C//
    SlowMoSpeed = 0x97F87C,//9F1208,//9E7208//6.2
};

enum viewPlayer
{
    //viewPlayer = 0x51D064//5D8F4E//
    //viewPlayer = 0x55EA45//6.2
    viewPlayer = 0x565F58//566153,//568900,//56892F,//568922,//56887E,//568887,//5685B9,//55EA58//6.2
};

enum CGUnitData //not multiplied *4
{
    UNIT_FIELD_TARGET = 0x28  //WOD
};

enum CGPlayerData //not multiplied *4
{
    PLAYER_FLAGS = 0xE0//
};

}
#endif // OFFSETS_H
