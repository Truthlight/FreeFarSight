/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

This is the source code of FFS. FFS is a machinima tool for World of Warcraft.

Offsets have to be changed at every patch of wow.

I made a new version with the roll but the code is unreachable for the moment. The code changed the camera matrix directly with this code if you want to add this in a new version :

MemoryWow.MWrite<float>(camera+Offsets::Matrix_1_1,cos(yaw)*cos(pitch));
MemoryWow.MWrite<float>(camera+Offsets::Matrix_1_2,sin(yaw)*cos(pitch));
MemoryWow.MWrite<float>(camera+Offsets::Matrix_1_3,-sin(pitch));
MemoryWow.MWrite<float>(camera+Offsets::Matrix_2_1,cos(yaw)*sin(pitch)*sin(roll)-sin(yaw)*cos(roll));
MemoryWow.MWrite<float>(camera+Offsets::Matrix_2_2,sin(yaw)*sin(pitch)*sin(roll)+cos(yaw)*cos(roll));
MemoryWow.MWrite<float>(camera+Offsets::Matrix_2_3,cos(pitch)*sin(roll));
MemoryWow.MWrite<float>(camera+Offsets::Matrix_3_1,cos(yaw)*sin(pitch)*cos(roll)+sin(yaw)*sin(roll));
MemoryWow.MWrite<float>(camera+Offsets::Matrix_3_2,sin(yaw)*sin(pitch)*cos(roll)-cos(yaw)*sin(roll));
MemoryWow.MWrite<float>(camera+Offsets::Matrix_3_3,cos(pitch)*cos(roll));
    
float matrix_2_3 = MemoryWow.MRead<float>(camera+Offsets::Matrix_2_3);
float matrix_3_3 = MemoryWow.MRead<float>(camera+Offsets::Matrix_3_3);
float roll = atan2 (matrix_2_3,matrix_3_3);