#include "rsa.h"

int main() {
	fillAlphabets();
	struct PRIMES_AND_KEYS *keys;
       	keys = (struct PRIMES_AND_KEYS*)malloc(sizeof(struct PRIMES_AND_KEYS));
	keys->prime1 = 5;
	keys->prime2 = 23;
	encrypt("hello", keys);
	printf("Original Message: %s\n", keys->message);
	printf("Cipher Text: %s\n", keys->cipher);
}
