cmake_minimum_required(VERSION 3.23)
project(18_homework)

set(CMAKE_CXX_STANDARD 17)

add_executable(18_homework main.cpp Models/User.h Models/Message.h Utils/UsersCSV.h Utils/MessagesCSV.h)
