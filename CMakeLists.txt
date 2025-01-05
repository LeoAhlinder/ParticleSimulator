cmake_minimum_required(VERSION 3.16)
project(ParticleSimulator LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE source_files "src/*.cpp")

if(NOT source_files)
    message(FATAL_ERROR "No source files found in src/*.cpp")
endif()

add_executable(${PROJECT_NAME} ${source_files})
target_include_directories(${PROJECT_NAME} PRIVATE "src")
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${_SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying SFML dependencies to output directory"
    )
endif()
