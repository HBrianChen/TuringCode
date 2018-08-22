# TuringCode
A simple solution for using number theory to encrypt messages at Turing's scheme. 

## Compile and Test
Compile:
```Bash
make TuringCode
```
Test:
```Bash
./TuringCode 11 "I'm a programmer."
```
11 is the encryption's key.

## Encrypt and Decrypt algorithm
### Encryption
*Suppose p is a prime and k is not a multiple of p. Then the sequence:*     
  (0 * k) rem p, (1 * k) rem p, (2 * k) rem p, ..., ((p - 1) * k) rem p     
*is a permutation of the sequence:*     
  0, 1, 2, ..., (p - 1)     
*This remains true if the first term is deleted from each sequence.*     
So I select 61 for the public key which is a prime. And I encode A-Z, a-z and some characters to range 1-60.      
This eqution use for encryption.        
*m' = m * k rem p*
### Decryption
First We compute the private key k's multiplicative inverses. Then we can decrypt the messages with this eqution.     
*m = m' * k^(-1) rem p*          
Fermat's Theorem suggests an efficient procedure for finding the multiplicative inverse of a number modulo a large prime.     
By Fermat's Theorem, we know that:           
*k^(p-2) * k = 1 (mod p)*        
Therefore, k^(p-2) must be a multiplicative inverse of k. We need to compute k^(p-2) rem p, which we can do by successive squaring.     

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
