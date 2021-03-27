set(FASTALLOC_SOURCES fastalloc.cpp fastalloc.h)

add_library (fastalloc STATIC ${FASTALLOC_SOURCES})
target_compile_features(fastalloc PUBLIC c_std_11 cxx_std_17)
