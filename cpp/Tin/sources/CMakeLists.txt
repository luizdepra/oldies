# Add a project name with version and lang
PROJECT(TINLIB)

# Set paths
SET(INCS_PATH ${TIN_ROOT_DIR}/include)
SET(SRCS_PATH ${TIN_ROOT_DIR}/sources)

# Add source files
SET(INCS
    ${INCS_PATH}/version.h
    ${INCS_PATH}/common.h
    ${INCS_PATH}/application.h
    ${SRCS_PATH}/internal/_base_internal_application.h
    ${SRCS_PATH}/internal/_window.h
    ${SRCS_PATH}/internal/platform/windows/_internal_application.h
)

SET(SRCS
    ${SRCS_PATH}/application.cpp
    ${SRCS_PATH}/internal/_base_internal_application.cpp
    ${SRCS_PATH}/internal/_window.cpp
    ${SRCS_PATH}/internal/platform/windows/_internal_application.cpp)

# Create a shared library target to the project using those files
ADD_LIBRARY(TINLIB STATIC ${SRCS} ${INCS})

# Link the target with SDL2 lib
TARGET_LINK_LIBRARIES(TINLIB ${SDL2_LIBRARY})

# Set output names for the project binary
SET_TARGET_PROPERTIES(
    TINLIB
    PROPERTIES
    OUTPUT_NAME tin
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
