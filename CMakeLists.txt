cmake_minimum_required(VERSION 3.2)

# Creates source groups for a target
function(create_source_groups TARGET)
  get_property(SOURCES TARGET ${TARGET} PROPERTY SOURCES)
  foreach(FILE ${SOURCES}) 
    get_filename_component(PARENT_DIR "${FILE}" PATH)

    # skip src or include and changes /'s to \\'s
    string(REGEX REPLACE "(\\./)?(src|include)/?" "" GROUP "${PARENT_DIR}")
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    # group into "Source Files" and "Header Files"
    if ("${FILE}" MATCHES "\\.c(pp)?$")
      set(GROUP "Source Files\\${GROUP}")
    elseif("${FILE}" MATCHES "\\.h(pp)?$")
      set(GROUP "Header Files\\${GROUP}")
    endif()

    source_group("${GROUP}" FILES "${FILE}")
  endforeach()

  # Create a solution folder for the target based on the directory this
  # function was called from

  # There doesn't seem to be a function to convert an absolute path to a
  # relative one, so hack around it by getting the length of the root directory
  # and chopping it off of the beginning of the target's directory
  string(LENGTH "${CMAKE_SOURCE_DIR}" SOURCE_DIR_LENGTH)
  string(SUBSTRING "${CMAKE_CURRENT_SOURCE_DIR}" ${SOURCE_DIR_LENGTH} -1 FOLDER_NAME)
  set_target_properties(${TARGET} PROPERTIES FOLDER "${FOLDER_NAME}")
endfunction()

# Statically link MSVC++ runtime to output
set(CMAKE_USER_MAKE_RULES_OVERRIDE
   ${CMAKE_CURRENT_SOURCE_DIR}/c_flag_overrides.cmake)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX
   ${CMAKE_CURRENT_SOURCE_DIR}/cxx_flag_overrides.cmake)

# Project name is DarkCore
project(DarkCore)

# Add CXX flags
if(NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

# Enable solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Library directories
link_directories($ENV{DXSDK_DIR}/Lib/x86)
link_directories(${CMAKE_SOURCE_DIR}/libs/detours/lib.X86)
link_directories(${CMAKE_SOURCE_DIR}/libs/openssl-1.0.2c/lib)
link_directories(${CMAKE_SOURCE_DIR}/libs/libwebsockets/lib)
link_directories(${CMAKE_SOURCE_DIR}/libs/python35/lib)

# Create main target
add_library(DarkCore SHARED
    src/Logging/Debug.cpp
    src/Logging/Debug.hpp
    src/Python/Python.cpp
    src/Python/Python.hpp
    src/WebSockets/WebSockets.cpp
    src/WebSockets/WebSockets.hpp
    src/DarkCore.hpp
    src/DarkCore.rc
    src/Main.cpp
    src/resource.h)

create_source_groups(DarkCore)

# Include directories
target_include_directories(DarkCore PRIVATE
  $ENV{DXSDK_DIR}/Include
  ${CMAKE_SOURCE_DIR}/libs/detours/include
  ${CMAKE_SOURCE_DIR}/libs/openssl-1.0.2c/include
  ${CMAKE_SOURCE_DIR}/libs/libwebsockets/include
  ${CMAKE_SOURCE_DIR}/libs/python35/include
  ${CMAKE_SOURCE_DIR}/src)

# Link lib files
target_link_libraries(DarkCore
  d3d9
  d3dx9
  Version
  ws2_32
  detours
  libeay32MT
  ZLib
  libwebsocketswin32
  python35)

target_compile_definitions(DarkCore PRIVATE NOMINMAX) # Prevent windows.h from defining min() and max()