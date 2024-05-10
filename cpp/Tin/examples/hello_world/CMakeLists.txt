# Define the example project
PROJECT(HELLO_WORLD)

# Set paths
SET(INCS_PATH ${TIN_ROOT_DIR}/include)
SET(SRCS_PATH ${TIN_ROOT_DIR}/examples/hello_world)

# Add source files
SET(SRCS
    ${SRCS_PATH}/main.cpp
)

# Create an executable
ADD_EXECUTABLE(HELLO_WORLD ${SRCS})
TARGET_LINK_LIBRARIES(HELLO_WORLD TINLIB)

# Set output names for the project binary
SET_TARGET_PROPERTIES(
    HELLO_WORLD
    PROPERTIES
    OUTPUT_NAME HelloWorld
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
