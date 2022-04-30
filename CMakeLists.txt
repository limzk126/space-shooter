cmake_minimum_required(VERSION 3.23)
project(space_shooter C)

set(CMAKE_C_STANDARD 17)

add_executable(space_shooter spaceshooter.c structs.h init.c common.h init.h input.c input.h draw.c draw.h spaceshooter.h)
