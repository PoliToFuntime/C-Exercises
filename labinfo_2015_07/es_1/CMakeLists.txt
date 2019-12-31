project(labinfo_07_es_1 C)

add_executable(labinfo_07_es_1 main.c)
if (NOT WIN32)
    target_link_libraries(labinfo_07_es_1 m) # link math.h for linux
endif()
