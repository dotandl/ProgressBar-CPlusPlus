cmake_minimum_required(VERSION 3.8.0)
project(ProgressBarCPP)

add_library(ProgressBarCPP STATIC ProgressBarManager.cpp)
set_target_properties(
  ProgressBarCPP
  PROPERTIES
  PROGRESS_BAR_CPP_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}
)

set_property(TARGET ProgressBarCPP PROPERTY CXX_STANDARD 11)
