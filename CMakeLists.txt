cmake_minimum_required(VERSION 3.16)
project(leetcode_practice)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode_practice miscellaneous/main.cpp)
add_executable(28-strStr miscellaneous/28-strStr.cpp)
add_executable(test miscellaneous/test.cpp)
add_executable(78-subset miscellaneous/78-subset.cpp)

add_subdirectory(DataStructure)
add_subdirectory(LeetcodeCard)
add_subdirectory(InterviewProblem)
add_subdirectory(BasicAlgorithm)
add_subdirectory(KnowledgePlayGround)
add_subdirectory(CodingInterview)

add_executable(test1 test1.cpp)