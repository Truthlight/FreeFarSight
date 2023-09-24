/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "player.h"


Player::Player() : ObjectManager()
{
}

void Player::Readflag()
{
    objMgr.Initialize();
    PlayerBase = objMgr.FindMe();
    descriptor = MemoryWow.MRead<quint32>(PlayerBase+Offsets::DescriptorOffset);
    flag = MemoryWow.MRead<quint32>(descriptor + Offsets::PLAYER_FLAGS*4);
}

quint64 Player::ReadTargetGUID()
{
    targetGUID = MemoryWow.MRead<quint64>(descriptor + Offsets::UNIT_FIELD_TARGET*4);
    return targetGUID;
}

quint64 Player::ReadTargetGUID2()
{
    targetGUID = MemoryWow.MRead<quint64>(descriptor + (Offsets::UNIT_FIELD_TARGET+2)*4);
    return targetGUID;
}

void Player::EnableComm()
{
    CameraWow.Initialize();
    std::vector <float> coords = CameraWow.getCoords();
    orientation = CameraWow.getOrientation();
    quint32 baseAdr = MemoryWow.getBaseAdr();
    MemoryWow.MWrite<float>(baseAdr + Offsets::Com_X, coords.at(0));
    MemoryWow.MWrite<float>(baseAdr + Offsets::Com_Y, coords.at(1));
    MemoryWow.MWrite<float>(baseAdr + Offsets::Com_Z, coords.at(2));

    MemoryWow.MWrite<quint32>(descriptor + Offsets::PLAYER_FLAGS*4, flag+0x480000);
    orientationPlayer = getOrientation();
    CameraWow.SetOrientation(orientationPlayer, orientation);
    MemoryWow.MWrite<byte>(baseAdr + Offsets::viewPlayer, 0x00);
}

void Player::DisableCom()
{
    CameraWow.SetOrientation(orientation);
    MemoryWow.MWrite<quint32>(descriptor + Offsets::PLAYER_FLAGS*4, flag);
}

float Player::getOrientation()
{
    return MemoryWow.MRead<float>(PlayerBase + Offsets::RotationOffset);
}
