cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(kubridge)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-q -Wall -O3 -nostdlib")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fno-exceptions")

add_executable(kubridge
  main.c
)

target_link_libraries(kubridge
  taihenForKernel_stub
  taihenModuleUtils_stub
  SceSysclibForDriver_stub
  SceSysmemForDriver_stub
  SceThreadmgrForDriver_stub
)

vita_create_self(kubridge.skprx kubridge CONFIG exports.yml UNSAFE)

vita_create_stubs(stubs kubridge ${CMAKE_CURRENT_SOURCE_DIR}/exports.yml KERNEL)

add_custom_target(kubridge_all
  ALL
  DEPENDS libkubridge_stub.a
  DEPENDS libkubridge_stub_weak.a
)

install(DIRECTORY ${CMAKE_BINARY_DIR}/stubs/
  DESTINATION lib
  FILES_MATCHING PATTERN "*.a"
)

install(FILES kubridge.h
  DESTINATION include
)
