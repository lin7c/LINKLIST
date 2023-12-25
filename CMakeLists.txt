cmake_minimum_required(VERSION 3.0)
project(LINKLIST)
include_directories(./include)

set (SRC_DIR "./src")
set (LIB_DIR "../lib")
set (BIN_DIR "../bin")
set (EXM_DIR "./example")
# do the lib 
add_library(F_LINK STATIC
    ${SRC_DIR}/Travel.c
    ${SRC_DIR}/Sort.c 
    ${SRC_DIR}/LinkList.c 
    ${SRC_DIR}/Length.c 
    ${SRC_DIR}/Insert.c
    ${SRC_DIR}/MakeEmpty.c
    ${SRC_DIR}/Remove.c
    ${SRC_DIR}/Delete.c
    ${SRC_DIR}/Find.c
)

# do the executable 
add_executable(main main.c)
add_executable(Wmain WIN32 ${EXM_DIR}/Wmain.c)
set_target_properties(F_LINK PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR})
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
set_target_properties(Wmain PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
target_link_libraries(main ${LIB_DIR}/F_LINK)
target_link_libraries(Wmain ${LIB_DIR}/F_LINK legacy_stdio_definitions.lib)