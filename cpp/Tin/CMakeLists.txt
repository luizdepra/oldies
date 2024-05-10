# Check minimum CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# Name the project
PROJECT(TIN)

# Set project root dir
SET(TIN_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Add project's CMake to the module path
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")

# Check compiler and set extra compilation flags
IF (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
ELSEIF (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	IF (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		STRING(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	ELSE()
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	ENDIF()
ENDIF()

# Find Boost, check for BOOST_ROOT variable on Windows
FIND_PACKAGE(Boost 1.55.0 REQUIRED)
# Add Boost (header only) to include dirs
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

# Find SDL2, check for SDL2 variable on Windows
FIND_PACKAGE(SDL2 2.0.3 REQUIRED)
# Add SDL2 to include dirs
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR})

# Add project's include files
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add extra directories (witch need a CMakeLists.txt file) for building steps
# Tin files
ADD_SUBDIRECTORY(sources)
# Examples:
ADD_SUBDIRECTORY(examples)
