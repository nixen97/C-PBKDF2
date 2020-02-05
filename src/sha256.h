#include "types.h"

#define SHA_SIZE 32

typedef struct {
    // TODO: Make this a Union of byte[] and word[]
    byte digest[SHA_SIZE];
} sha256;


sha256* SHA256(byte* msg, int len);
