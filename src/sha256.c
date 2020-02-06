#include <stdlib.h>
#include <memory.h>
#include "sha256.h"

#include <stdio.h>

static void SHAInit(word* digest);
static int PadMsg(byte* msg, word len, byte* buffer, word bLen);

sha256* SHA256(byte* msg, word len)
{
    // word a, b, c, d, e, f, g, h;
    sha256* sha_obj = (sha256*)malloc(sizeof(sha256));
    // word W[64];

    SHAInit(sha_obj->digestInt);

    unsigned int bLen = (((len + 8) + 63) / 64) * 64;

    byte* msg_buffer = (byte*)malloc(bLen);

    int N = PadMsg(msg, len, msg_buffer, bLen);

    printf("%d\n", N);

    for (int i = 0; i < len; i++)
    {
        printf("%02X", *(msg++));
    }

    printf("\n");

    for (int i = 0; i < bLen; i++)
    {
        printf("%02X", *(msg_buffer++));
    }

    printf("\n");

    for (int i = 1; i <= N; i++)
    {
        // Do the thing
    }


    return sha_obj;
}

/*
 *
 * Message padding according to RFC 4634 section 4.1
 *
 */
static int PadMsg(byte* msg, word len, byte* buffer, word bLen)
{
    // L + 1 + K = 56 mod 64
    unsigned long long L = len*8;

    unsigned int K;

    for (int i = 0; i < 56; i++ )
    {
        if ((len + 1 + i) % 64 == 56)
        {
            K = i;
            break;
        }
    }

    unsigned int N = len + 1 + K + sizeof(L);

    byte* ptr = buffer;

    for (int i = 0; i < len; i++)
    {
        *ptr++ = msg[i];
    }

    *ptr++ = 0b10000000;

    for (int i = len+1; i < len+1+K; i++)
    {
        *ptr++ = 0x00;
    }

    // Big endian ordering
    for (int i = sizeof(L)-1; i >= 0; i--)
    {
        *ptr++ = ((L >> (8*i)) & 0xFF);
    }

    return N/64;
}

/*
 *
 * Initializes the digest as per RFC 4634 section 6.1
 * Assuming little endian
 * TODO: Test this assumption
 * Usually RFC's specify everything in big endian
 *
 */
static void SHAInit(word* digest)
{
    // H(0)0 = 6a09e667
    digest[0] = 0x6a09e667;

    // H(0)1 = bb67ae85
    digest[1] = 0xbb67ae85;

    // H(0)2 = 3c6ef372
    digest[2] = 0x3c6ef372;

    // H(0)3 = a54ff53a
    digest[3] = 0xa54ff53a;

    // H(0)4 = 510e527f
    digest[4] = 0x510e527f;

    // H(0)5 = 9b05688c
    digest[5] = 0x9b05688c;

    // H(0)6 = 1f83d9ab
    digest[6] = 0x1f83d9ab;

    // H(0)7 = 5be0cd19
    digest[7] = 0x5be0cd19;
}