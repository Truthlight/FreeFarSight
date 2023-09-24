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
