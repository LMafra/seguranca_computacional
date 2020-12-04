#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#include "common.h"

using namespace std;

RSA *create_RSA(RSA *keypair, int pem_type, char *filename) {
  
  RSA *rsa = NULL;
  FILE *fp = NULL;

  if(pem_type == PUBLIC_KEY_PEM) {
    
    fp = fopen(filename, "w");
    PEM_write_RSAPublicKey(fp, keypair);
    fclose(fp);
    
    fp = fopen(filename, "rb");
    PEM_read_RSAPublicKey(fp, &rsa, NULL, NULL);
    fclose(fp);

  } else if(pem_type == PRIVATE_KEY_PEM) {
    
    fp = fopen(filename, "w");
    PEM_write_RSAPrivateKey(fp, keypair, NULL, NULL, NULL, NULL, NULL);
    fclose(fp);
    
    fp = fopen(filename, "rb");
    PEM_read_RSAPrivateKey(fp, &rsa, NULL, NULL);
    fclose(fp);

  }

  return rsa;
}


int public_encrypt(int flen, unsigned char* from, unsigned char *to, RSA* key, int padding) {

  int result = RSA_public_encrypt(flen, from, to, key, padding);

}

int private_decrypt(int flen, unsigned char* from, unsigned char *to, RSA* key, int padding) {

  int result = RSA_private_decrypt(flen, from, to, key, padding);

}

void create_encrypted_file(char* encrypted, RSA* key_pair) {

    FILE* encrypted_file = fopen("arquivo_criptografado.txt", "w");
    fwrite(encrypted, sizeof(*encrypted), RSA_size(key_pair), encrypted_file);
    fclose(encrypted_file);

}
