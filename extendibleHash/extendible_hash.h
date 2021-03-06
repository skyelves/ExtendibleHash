//
// Created by Ke Wang on 2021-03-16.
//

#ifndef NVMKV_EXTENDIBLE_HASH_H
#define NVMKV_EXTENDIBLE_HASH_H

#include <math.h>
#include <cstdint>
#include "../fastalloc/fastalloc.h"

#define likely(x)   (__builtin_expect(!!(x), 1))
#define unlikely(x) (__builtin_expect(!!(x), 0))

#define BUCKET_SIZE 4

class key_value {
public:
    bool type = 1;
    uint64_t key = 0;// indeed only need uint8 or uint16
    uint64_t value = 0;// value or pointer
};

key_value *new_key_value(int key=0, int value=0);

class bucket {
public:
    int depth = 0;
    int cnt = 0;
    key_value counter[BUCKET_SIZE];

    bucket();

    bucket(int _depth);

    void init(int _depth);

    void set_depth(int _depth);

    int64_t get(uint64_t key);

    int find_place(uint64_t key);
};

bucket *new_bucket(int _depth = 0);

class extendible_hash {
private:
    bool type = 0;
    uint64_t global_depth = 0;
    uint64_t dir_size = 1;
    int key_len = 16;
    bucket **dir = NULL;
public:
    extendible_hash();

    extendible_hash(uint32_t _global_depth);

    extendible_hash(uint32_t _global_depth, int _key_len);

    void init(uint32_t _global_depth, int _key_len);

    void set_key_len(int _key_len);

    void put(uint64_t key,
             uint64_t value);//value is limited to non-zero number, zero is used to define empty counter in bucket

    int64_t get(uint64_t key);
};

extendible_hash *new_extendible_hash(uint32_t _global_depth, int _key_len);


#endif //NVMKV_EXTENDIBLE_HASH_H
