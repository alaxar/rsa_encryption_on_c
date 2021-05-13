#include "rsa.h"


int main() {
	struct PRIMES_AND_KEYS *keys;
       	keys = (struct PRIMES_AND_KEYS*)malloc(sizeof(struct PRIMES_AND_KEYS));
	keys->prime1 = 7;
	keys->prime2 = 19;
	generating_keys(keys);
}
