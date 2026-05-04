cmake_minimum_required(VERSION 3.16)
project(ant_bridge_stub C)

add_library(ANT_WrappedLib SHARED ant_bridge_stub.c)
set_target_properties(ANT_WrappedLib PROPERTIES
    OUTPUT_NAME "ANT_WrappedLib"
    PREFIX ""
)

# Use exports from generated .def file so ordinals/names are stable.
set_property(TARGET ANT_WrappedLib PROPERTY LINK_FLAGS "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/ant_bridge.def")
