cmake_minimum_required(VERSION 3.23)
project(space_shooter C)

set(CMAKE_C_STANDARD 17)

add_executable(space_shooter src/spaceshooter.c src/structs.h src/init.c src/common.h src/init.h src/input.c src/input.h src/draw.c src/draw.h src/spaceshooter.h src/stage.c src/stage.h)
