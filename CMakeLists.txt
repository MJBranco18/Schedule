cmake_minimum_required(VERSION 3.23)
project(Schedule)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Schedule
        src/ClassUc.cpp
        src/ClassUc.h
        src/main.cpp
        src/ScheduleManager.cpp
        src/ScheduleManager.h
        src/ScheduleUc.cpp
        src/ScheduleUc.h
        src/Slot.cpp
        src/Slot.h
        src/Student.cpp
        src/Student.h src/Order.h src/Order.cpp)
