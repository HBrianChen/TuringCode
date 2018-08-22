//
//  TuringCode.h
//  TuringCode
//
//  Created by BrianChen on 2018/8/21.
//  Copyright © 2018 BrianChen. All rights reserved.
//

#ifndef TuringCode_h
#define TuringCode_h

#include <stdio.h>

#define PUBLIC_KEY 61

/**
 Encrypt a string with eqution m * k rem p.
 P equal 61 which is a prime.

 @param str String will be encrypted, should only contain characters a-z, A-Z, '.', ',', ''', ' ', '?', '!', '-', """.
 @param key Key must be not a multiple of p(61).
 
 @return return a encrypted string, should free memory by yourself.
 */
char * encryptString(const char *str, int key);

/**
 Decrypt a string with key.

 @param str String will be decrypted.
 @param key Key equal encryption's key.
 
 @return return a decrypted string, should free memory by yourself.
 */
char * decryptString(const char *str, int key);

#endif /* TuringCode_h */
