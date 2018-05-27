#include <stdio.h>
#include "ed25519.h"


char *stringToHex(char source[], char *dest, int dlen) {

    for (size_t count = 0; count < dlen; count++) {
        sscanf(source, "%2hhx", &dest[count]);
        source += 2;
    }
	return dest;
}
 
void hexToString(const unsigned int array[], int len) {

	unsigned int orig = 0;
	unsigned int new = 0;
	int ilen = sizeof orig;

	for(int i = 0; i < len / 4; i++) {
		orig = array[i];
		new = htonl(orig);
		printf("%08x", new);
  		//printf("%08x", htonl(array[i]));
	}
	printf("\n");
}

void printRaw(const unsigned char array[], int len) {
	
	printf("[");
	for(int i = 0; i < len; i++) {
		printf("%02x", array[i]);
		printf(",");
	}
	printf("]");
}

int main()
{
	const char hexString[] = "700a53bc1ef246ba3e93f1f65d6581fc6e3907e087a1b47d8e3df4ce5690ab6c";
    //ed25519_public_key iL = { 112,10,83,188,30,242,70,186,62,147,241,246,93,101,129,252,110,57,7,224,135,161,180,125,142,61,244,206,86,144,171,108};
    //ed25519_public_key iR = { 1,64,159,184,142,255,146,33,22,19,173,105,126,82,126,198,129,193,193,123,103,203,244,185,239,227,190,105,71,2,139,65};
	
	//ed25519_public_key iL = { 143,72,48,21,43,117,216,49,49,158,249,154,39,127,169,28,224,93,203,185,99,173,21,237,228,14,17,160,222,103,156,23};
	//ed25519_public_key iR = { 76,95,233,19,45,40,247,206,48,145,223,69,167,231,96,131,7,43,199,50,3,44,219,156,131,249,124,88,53,95,253,223};
	
	ed25519_public_key iL = { 194,145,232,132,188,66,229,74,48,83,103,173,0,246,239,236,207,80,112,111,131,30,173,1,54,187,233,255,2,236,148,200 };
	ed25519_public_key iR = { 115,159,75,60,172,164,201,173,79,205,75,220,46,244,44,134,1,175,141,105,70,153,158,248,94,246,174,132,246,110,114,235};

	const char * passPhrase = "";
	//ed25519_secret_key sk;


	//printRaw(esk, sizeof esk);
	printf("iL & iR: ");
	hexToString(iL, sizeof iL);
	hexToString(iR, sizeof iR);

	//ed25519_randombytes_unsafe(sk, sizeof(ed25519_secret_key));
	unsigned char esk[128] = {0};
	wallet_encrypted_from_secret(passPhrase, 0, iL, iR, esk);

	printf("SK/PUB\n");
	hexToString(esk, 64);
	hexToString(&esk[64], 32);
	hexToString(&esk[96], 32);
	//ed25519_public_key pk;
	//ed25519_publickey(iL, pk);
	// printf() displays the string inside quotation
	//int n = sizeof(hexString);
	//printf("ESK: %d\n", sizeof esk);
	//hexToString(esk, sizeof esk);
    
	unsigned char firstAccount[128] = {0};
	unsigned char origAccount[128] = {192,61,168,132,192,165,111,73,239,203,72,170,192,155,213,67,66,53,245,198,120,13,74,80,82,51,230,34,47,108,183,77,40,241,107,224,95,67,29,133,233,204,248,160,190,32,118,225,220,39,131,159,168,247,182,105,177,97,37,160,241,0,241,107,109,9,151,97,58,206,111,150,235,158,26,239,199,223,135,172,119,112,214,70,218,39,35,157,3,15,88,233,31,203,135,72,1,64,159,184,142,255,146,33,22,19,173,105,126,82,126,198,129,193,193,123,103,203,244,185,239,227,190,105,71,2,139,65};
    
//	wallet_encrypted_derive_private
 //   (esk,
  //   "", 0,
//    2147483648,
 //   firstAccount,
  //  1);

	//printf("ORIG: %d\n", sizeof origAccount);
	//hexToString(origAccount, sizeof origAccount);
	//printf("NEWA: %d\n", sizeof firstAccount);
	//hexToString(firstAccount, sizeof firstAccount);
	return;
}
