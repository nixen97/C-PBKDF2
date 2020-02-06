#include "types.h"

#define SHA_SIZE 32

typedef struct {
    // TODO: Make this a Union of byte[] and word[]
    union
    {
        byte digest[SHA_SIZE];
        word digestInt[SHA_SIZE/4];
    };
} sha256;


sha256* SHA256(byte* msg, word len);
