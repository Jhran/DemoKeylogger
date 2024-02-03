file(GLOB_RECURSE IMAGE_SOURCES *.c)

idf_component_register(SRCS ${IMAGE_SOURCES}
                        INCLUDE_DIRS ".")
                        
add_definitions(-w)

#set_target_properties(${COMPONENT_LIB} PROPERTIES COMPILE_FLAGS -Wno-restrict)
#set_target_properties(${COMPONENT_LIB} PROPERTIES COMPILE_FLAGS -Wno-format-overflow)