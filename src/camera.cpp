/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "camera.h"

Camera CameraWow;

Camera::Camera(): camCoords (3), camOrientation (2)
{
}

void Camera::Initialize()
{
    baseAdr = MemoryWow.getBaseAdr();
    lvl1pointer = MemoryWow.MRead<unsigned int>(baseAdr+Offsets::Camptr);
    camera = MemoryWow.MRead<unsigned int>(lvl1pointer + Offsets::Camoffs);
}

std::vector<float> Camera::getCoords()
{
    camCoords.at(0) = MemoryWow.MRead<float>(camera + Offsets::Cam_X);
    camCoords.at(1) = MemoryWow.MRead<float>(camera + Offsets::Cam_Y);
    camCoords.at(2) = MemoryWow.MRead<float>(camera + Offsets::Cam_Z);
    return camCoords;
}

std::vector<float> Camera::getOrientation()
{
    camOrientation.at(0) = MemoryWow.MRead<float>(camera + Offsets::Yaw);
    camOrientation.at(1) = MemoryWow.MRead<float>(camera + Offsets::Pitch);
    //camOrientation.at(2) = MemoryWow.MRead<float>(camera + Offsets::Roll);
    return camOrientation;
}

float Camera::getFOV()
{
    return MemoryWow.MRead<float>(camera + Offsets::FOV);
}

float Camera::getZoom()
{
    return MemoryWow.MRead<float>(camera + Offsets::Zoom);
}

void Camera::SetOrientation(float orientationPlayer, std::vector<float> &orientation)
{
    MemoryWow.MWrite (camera + Offsets::Yaw,orientationPlayer + orientation.at(0));
}

void Camera::SetOrientation(std::vector<float> &orientation)
{
    MemoryWow.MWrite (camera + Offsets::Yaw,orientation.at(0));
    MemoryWow.MWrite (camera + Offsets::Pitch,orientation.at(1));
}

void Camera::setFOV(qint32 i)
{
    Initialize();
    float j = i;
    j/=100;
    MemoryWow.MWrite<float>(camera+Offsets::FOV, j);
}

void Camera::setZoom(qint32 i)
{
    Initialize();
    float j = i;
    j/=100;
    MemoryWow.MWrite<float>(camera+Offsets::Zoom, j);
}

void Camera::setZoom(float i)
{
    Initialize();
    MemoryWow.MWrite<float>(camera+Offsets::Zoom, i);
}

void Camera::setAttachX(qint32 i)
{
    Initialize();
    float j = i;
    j/=100;
    MemoryWow.MWrite<float>(camera+Offsets::AttachX, j);
}

void Camera::setAttachY(qint32 i)
{
    Initialize();
    float j = i;
    j/=100;
    MemoryWow.MWrite<float>(camera+Offsets::AttachY, j);
}

void Camera::setAttachZ(qint32 i)
{
    Initialize();
    float j = i;
    j/=100;
    MemoryWow.MWrite<float>(camera+Offsets::AttachZ, j);
}
