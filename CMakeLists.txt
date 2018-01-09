cmake_minimum_required(VERSION 3.7)
project(cc3k)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        1.txt
        2.txt
        BaseObject.cpp
        BaseObject.h
        Cell.cpp
        Cell.h
        Chamber.cpp
        Chamber.h
        Character.cpp
        Character.h
        Display.cpp
        Display.h
        Enemy.cpp
        Enemy.h
        Floor.cpp
        Floor.h
        GameObject.cpp
        GameObject.h
        Helpers.cpp
        Helpers.h
        Hero.cpp
        Hero.h
        Item.cpp
        Item.h
        main.cpp
        potion.cpp
        potion.h
        Treasure.cpp
        Treasure.h)

add_executable(cc3k ${SOURCE_FILES})