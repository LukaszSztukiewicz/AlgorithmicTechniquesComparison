cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# Set the name of the project as THIS variable
set(THIS AlgorithmicTechniquesComparison)
project(${THIS})

#source headers
include_directories(src)

#dependencies
add_subdirectory(lib/googletest)

#our subdirectories (goes into subdirectory and searches for CMakeLists.txt there)
add_subdirectory(src)
add_subdirectory(test)

enable_testing()
