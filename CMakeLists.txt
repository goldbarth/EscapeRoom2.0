cmake_minimum_required(VERSION 3.26)
project(EscapeRoom2_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(EscapeRoom2_0 main.cpp
        Game.cpp
        Game.h
        Exit.cpp
        Exit.h
        Player.cpp
        Player.h
        Key.cpp
        Key.h
        Room.cpp
        Room.h
        Application.cpp
        Application.h)
