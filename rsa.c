#include "rsa.h"

// implementation of rsa header file
// All the variables and function declared in header rsa.h is defined here
//

int select_prime_numbers(int n) {
	int isPrime = 0, m = 0;
	for(int i = 2; i < n; i++) {
		m = i / 2;
		for(int j = 2; j <= m; j++) {
			if(i % j == 0) {
				isPrime = 0;
			} else {
				isPrime = 1;
			}
		}
		if(isPrime == 1) {
		} else {
		}
	}
}

int gcd(int a, int b) {
	if(b == 0)
		return a;

	return gcd(b, a % b);
}

int generating_keys(struct PRIMES_AND_KEYS *keys) {
	int p, q, n, phi, privateKey = 0;
	p = keys->prime1;
	q = keys->prime2;
	
	// calculate their product and assign to ModuluN memeber of Keys struct
	n = p * q;
	keys->ModuluN = n;

	// calculate totient value using totient function or phi(n) and assign it to Phi memeber of Keys struct
	// this function helps us to find integers that are less than or equals to N that do not share common factors with N. 
	phi = (p - 1) * (q - 1);
	keys->Phi = phi;

	// choosing public key for encryption and assign it to PublicKey member of Keys struct for later use
	// their are some properties which must be satisfied, the first thing to choose public key the key you are about to choose must satisfy(1 <= e <= phi) this property where e is the public key and also e must be co-prime with phi or their gcd must be 1.
	// choosing public key and assign the last found publicKey to PublicKey member of Keys struct
	for(int publicKey = 2; publicKey < phi; publicKey++) { // 1 <= e <= phi
		if(gcd(publicKey, phi) == 1) {
			int i = 0;
			keys->PublicKeys[i] = publicKey;
			i++;
			break;
		}
	}

	// generating the decryption key(private key)
	// some rules must be satisfied such that d*e is congruent to 1 mod phi
	// or in simple way d-e (mod phi) = 0, if we deduct e from d then mod phi with it the result must be 0, or we can find PrivateKey just by using this formula( (1 + x * phi) / publicKey, where x is some positive integer), in this step congruece relation must be satisfied, means both numbers must return the same remainder, in our context they must return 0 remainder both.
	// after all the value must be assigned to PrivateKey which is member of Keys struct
	for(int x = 0; x < keys->ModuluN; x++) {
		if( ((1 + x * phi) % 5) == 0) {
			keys->PrivateKeys = (1 + x * phi) / keys->PublicKeys[0];
		}
	}
	printf("N: %d\nPHI: %d\nPublicKey: %d\nPrivateKey: %d\n", keys->ModuluN, keys->Phi, keys->PublicKeys[0], keys->PrivateKeys);
}
