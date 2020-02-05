#include <stdlib.h>
#include "sha256.h"

static void SHAInit(byte* digest);

sha256* SHA256(byte* msg, int len)
{
    word a, b, c, d, e, f, g, h;
    word H[8];
    word W[64];



    sha256* sha_obj = (sha256*)malloc(sizeof(sha256));

    return sha_obj;
}

/*
 *
 * Initializes the digest as per RFC 4634 section 6.1
 * Assuming little endian
 * TODO: Test this assumption
 *
 */
static void SHAInit(byte* digest)
{
    // H(0)0 = 6a09e667
    *(unsigned int*)digest = 0x6a09e667;

    // H(0)1 = bb67ae85
    *(unsigned int*)(digest+4) = 0xbb67ae85;

    // H(0)2 = 3c6ef372
    *(unsigned int*)(digest+8) = 0x3c6ef372;

    // H(0)3 = a54ff53a
    *(unsigned int*)(digest+12) = 0xa54ff53a;

    // H(0)4 = 510e527f
    *(unsigned int*)(digest+16) = 0x510e527f;

    // H(0)5 = 9b05688c
    *(unsigned int*)(digest+20) = 0x9b05688c;

    // H(0)6 = 1f83d9ab
    *(unsigned int*)(digest+24) = 0x1f83d9ab;

    // H(0)7 = 5be0cd19
    *(unsigned int*)(digest+28) = 0x5be0cd19;
}