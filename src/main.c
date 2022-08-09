#include <stdio.h>
#include <string.h>

#include "ed25519-donna/ed25519.h"

char *stringToHex(char source[], char *dest, int dlen)
{

	for (size_t count = 0; count < dlen; count++)
	{
		sscanf(source, "%2hhx", &dest[count]);
		source += 2;
	}
	return dest;
}

void hexToString(const unsigned int array[], int len)
{

	unsigned int orig = 0;
	unsigned int new = 0;
	int ilen = sizeof orig;

	for (int i = 0; i < len / 4; i++)
	{
		orig = array[i];
		new = htonl(orig);
		printf("%08x", new);
	}
	printf("\n");
}

void printRaw(const unsigned char array[], int len)
{

	printf("[");
	for (int i = 0; i < len; i++)
	{
		printf("%02x", array[i]);
		printf(",");
	}
	printf("]");
}

int main()
{

	const char *pass[4] = {"", ""};
	int passes = sizeof(pass)/sizeof(char*);

	const char *encrypted_secret = "";


	unsigned char esk[128] = {0};
	stringToHex(encrypted_secret, esk, 128);

	for ( int i = 0; i < passes; i++)
	{
		unsigned char sk[128] = {0};
		unencrypt_start(pass[i], strlen(pass[i]), esk, sk);

		ed25519_public_key pk;
		ed25519_publickey(sk, pk);

		printf("\nTrying to decrypt with: \"%s\" password\n", pass[i]);
		printf("Ori Priv:");
		hexToString(esk, 64);
		printf("New Priv:");
		hexToString(sk, 64);

		printf("Orig Pub:");
		hexToString(&esk[64], 32);
		printf("New Pub :");
		hexToString(pk, 32);

	}
	/*

	 wallet_encrypted_derive_private(
		 tsk,
		 passPhrase, 0,
		 2147483648,
		 etsk,
		 1);

	 wallet_encrypted_derive_private(
		 etsk,
		 passPhrase, 0,
		 2147483648,
		 tsk,
		 1);

	 hexToString(tsk, 128);
 */
	return;
}
