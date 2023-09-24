/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef CAMERA_H
#define CAMERA_H

#include "Offsets.h"
#include "memory.h"

#include <sstream>

class Camera
{
public:
    Camera();
    void Initialize();
    std::vector<float> getCoords();
    std::vector <float> getOrientation();
    float getFOV();
    float getZoom();
    void SetOrientation(float orientationPlayer, std::vector<float> &orientation);
    void SetOrientation(std::vector<float> &orientation);
    void setFOV(qint32 i);
    void setZoom(qint32 i);
    void setZoom(float i);
    void setAttachX (qint32 i);
    void setAttachY (qint32 i);
    void setAttachZ (qint32 i);
private:
    DWORD baseAdr;
    quint32 lvl1pointer;
    quint32 camera;
    std::vector <float> camCoords;
    std::vector <float> camOrientation;
};

extern Camera CameraWow;

#endif // CAMERA_H
