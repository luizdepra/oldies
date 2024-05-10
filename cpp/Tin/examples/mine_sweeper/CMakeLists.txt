# Add source files
FILE(GLOB_RECURSE incs "*.h")
FILE(GLOB_RECURSE srcs "*.cpp")

# Create an executable
ADD_EXECUTABLE(TinMineSweeper ${srcs} ${incs})
TARGET_LINK_LIBRARIES(TinMineSweeper TinLib)

# Set output names for the project binary
SET_TARGET_PROPERTIES(
    TinMineSweeper
    PROPERTIES
    OUTPUT_NAME MineSweeper
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
