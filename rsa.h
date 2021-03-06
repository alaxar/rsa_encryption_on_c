#ifndef	_RSA_HEADER_HH
#define _RSA_HEADER_HH

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// I used struct to store both generated prime number, it help a function to return both numbers at once for another function

typedef struct PRIMES_AND_KEYS{
	int prime1, prime2, PrivateKeys, PublicKeys[20], ModuluN, Phi;
       	char cipher[1024], message[1024];
}PRIMES_AND_KEYS;


// function prototypes
int raise_to_pow(int base, int expo);
int select_prime_numbers(int n);
struct PRIMES_AND_KEYS *generating_keys(struct PRIMES_AND_KEYS *keys);
int phi_of_n();
int encrypt(char *message, struct PRIMES_AND_KEYS *keys);
int decrypt(struct PRIMES_AND_KEYS *keys);
int fillAlphabets();	// fill the array with alphabets.

// variable declaration
extern char alphabets[94];
extern int index_position_by_cipher, last_index;
#endif
