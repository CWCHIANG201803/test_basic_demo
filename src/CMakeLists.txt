add_library(foo "")

target_sources(
    foo
    PRIVATE
        foo.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/foo.h
    )

target_include_directories(
    foo
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
