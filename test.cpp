#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <map>
#include <x86intrin.h>
#include <chrono>
#include <sys/time.h>
#include <fcntl.h>
#include <pthread.h>
#include "extendibleHash/extendible_hash.h"

using namespace std;

#define TESTNUM 1000000

uint64_t *mykey;
extendible_hash *eh;
map<uint64_t, uint64_t> mm;


void correctnessTest() {
    mykey = new uint64_t[TESTNUM];
    rng r;
    rng_init(&r, 1, 2);
    for (int i = 0; i < TESTNUM; ++i) {
        mykey[i] = rand();
        mm[mykey[i]] = i + 1;
//        cout << hex << mykey[i] << endl;
    }

    for (int i = 0; i < TESTNUM; ++i) {
        eh->put(mykey[i], i + 1);
    }

    uint64_t res = 0;
    for (int i = 0; i < TESTNUM; ++i) {
        res = eh->get(mykey[i]);
        if (res != mm[mykey[i]]) {
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
    return;

}

int main() {
    init_fast_allocator();
    eh = new_extendible_hash(0, 32);
    correctnessTest();
    fast_free();
    return 0;
}
