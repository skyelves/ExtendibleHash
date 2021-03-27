set(EXTENDIBLEHASH_SOURCES extendible_hash.cpp extendible_hash.h)

add_library(extendible_hash STATIC ${EXTENDIBLEHASH_SOURCES})
target_compile_features(extendible_hash PUBLIC c_std_11 cxx_std_17)

target_link_libraries(extendible_hash PUBLIC fastalloc)