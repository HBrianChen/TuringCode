//
//  TuringCode.c
//  TuringCode
//
//  Created by BrianChen on 2018/8/21.
//  Copyright © 2018 BrianChen. All rights reserved.
//

#include "TuringCode.h"
#include <string.h>
#include <stdlib.h>

static const char table[128] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    // space 32 ! 33 " 34 ' 39 , 44 - 45 . 46 ? 63
    1, 2, 3, 0, 0, 0, 0, 4,
    0, 0, 0, 0, 5, 6, 7, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 8,
    
    // A-Z a-z
    0, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 0, 0, 0, 0, 0,
    0, 35, 36, 37, 38, 39, 40, 41,
    42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57,
    58, 59, 60, 0, 0, 0, 0, 0
};

static const char tableInverse[PUBLIC_KEY] = {
    0, ' ', '!', '"', '\'', ',', '-', '.', '?',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'k', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

static const int prime = PUBLIC_KEY;

char * encryptString(const char *str, int key)
{
    unsigned long len = strlen(str);
    if (len == 0)
    {
        return NULL;
    }
    char *encryption = (char *)calloc(len + 1, sizeof(char));
    for (int i = 0; i < len; i++)
    {
        int index = str[i];
        encryption[i] = table[index] * key % prime;
    }
    return encryption;
}

char * decryptString(const char *str, int key)
{
    unsigned long len = strlen(str);
    if (len == 0)
    {
        return NULL;
    }
    char *decryption = (char *)calloc(len + 1, sizeof(char));
    // find inverses with Fermat's Theorem. k^(p - 2) * k = 1 (mod p)
    // compute k^(61 - 2) rem 61
    // k^59 = k^(32 + 16 + 8 + 2 + 1)
    int key2 = key * key % prime;
    int key4 = key2 * key2 % prime;
    int key8 = key4 * key4 % prime;
    int key16 = key8 * key8 % prime;
    int key32 = key16 * key16 % prime;
    int keyInverse = key32 * key16 * key8 * key2 * key % prime;
    // decrypt string with eqution m' * keyInverse rem p
    for (int i = 0; i < len; i++) {
        int index = str[i] * keyInverse % prime;
        decryption[i] = tableInverse[index];
    }
    return decryption;
}
