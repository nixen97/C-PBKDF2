#include <stdio.h>
#include "pbkdf2.h"
#include "sha256.h"

int main(int argc, char const *argv[])
{
    byte msg[4];

    *(word*)msg = 0xdeadbeef;

    sha256* hash = SHA256(msg, sizeof(msg));

    for (int i; i < SHA_SIZE; i++)
    {
        printf("%02X", hash->digest[i]);
    }

    printf("\n");

    return 0;
}
