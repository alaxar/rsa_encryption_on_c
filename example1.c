#include "rsa.h"

int main() {
	fillAlphabets();
	struct PRIMES_AND_KEYS *keys;
       	keys = (struct PRIMES_AND_KEYS*)malloc(sizeof(struct PRIMES_AND_KEYS));
	keys->prime1 = 5;
	keys->prime2 = 23;
	printf("Power: %d\n", raise_to_pow(2, 3));
	encrypt("hello", keys);
	printf("%s", keys->cipher);
}
