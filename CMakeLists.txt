cmake_minimum_required(VERSION 3.10)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main project files (exclude main.cpp for tests later)
file(GLOB SRC_FILES src/*.cpp)
# Remove main.cpp from SRC_FILES for the test executable
list(FILTER SRC_FILES EXCLUDE REGEX ".*main\\.cpp$")

# Main executable
add_executable(algorithms src/main.cpp ${SRC_FILES})
target_include_directories(algorithms PRIVATE src/include)

# Test files
file(GLOB TEST_FILES tests/*.cpp)

# Debug: Print the TEST_FILES to verify
message("TEST_FILES: ${TEST_FILES}")

if (TEST_FILES)
  # Test executable (include test files, source files, and catch_amalgamated.cpp)
  add_executable(tests ${TEST_FILES} ${SRC_FILES} external/catch_amalgamated.cpp)
  target_include_directories(tests PRIVATE src/include external)
else()
  message(WARNING "No test files found in tests/ directory. Test executable will not be built.")
endif()
