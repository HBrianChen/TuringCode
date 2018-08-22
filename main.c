//
//  main.c
//  TuringCode
//
//  Created by BrianChen on 2018/8/21.
//  Copyright © 2018 BrianChen. All rights reserved.
//

#include <stdio.h>
#include "TuringCode.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    if (argc != 3)
    {
        printf("Usage: TuringCode key string\n");
        return -1;
    }
    
    int key = atoi(argv[1]);
    if (key % 61 == 0)
    {
        printf("Error: key must be not a multiply of 61.\n");
        return -1;
    }
    
    const char *str = argv[2];
    char *encryption = encryptString(str, key);
    printf("Encrypted String:\n");
    for (int i = 0; encryption[i] != 0; i++) {
        printf("%d ", encryption[i]);
    }
    printf("\n");
    
    char *decryption = decryptString(encryption, key);
    printf("Decrypted String:\n");
    printf("%s\n", decryption);
    
    free(encryption);
    free(decryption);
    return 0;
}
