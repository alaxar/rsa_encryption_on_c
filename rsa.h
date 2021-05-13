#ifndef	_RSA_HEADER_HH
#define _RSA_HEADER_HH

#include <stdio.h>
#include <stdlib.h>

// I used struct to store both generated prime number, it help a function to return both numbers at once for another function

typedef struct PRIMES_AND_KEYS{
	int prime1, prime2, PrivateKeys, PublicKeys[20], ModuluN, Phi;
}PRIMES_AND_KEYS;

// function prototypes
int select_prime_numbers(int n);
int generating_keys(struct PRIMES_AND_KEYS *keys);
int phi_of_n();
int encrypt(char *message);
int decrypt(char *cipher);

// variable declaration


#endif
