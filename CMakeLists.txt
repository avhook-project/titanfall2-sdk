project(titanfall2-sdk)
add_library(titanfall2-sdk STATIC source/BaseEntity.cpp)

add_subdirectory(extlibs)
add_subdirectory(source)

target_include_directories(titanfall2-sdk PUBLIC include)
target_link_libraries(titanfall2-sdk PUBLIC uml)
target_link_libraries(titanfall2-sdk PRIVATE signature_scanner)