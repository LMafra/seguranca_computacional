#include <iostream>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#include "common.h"

/*
 * Trabalho de Segurança Computacional: 01/2020
 *
 * Lucas Mafra Chagas - 12/0126443
 *
 */

using namespace std;

int main() {

  std::cout << MSG_START_OPENSSL;

  RSA *private_key;
  RSA *public_key;

  char message[KEY_SIZE / 4];
  char *encrypt = NULL;
  char *decrypt = NULL;

  char private_key_pem[12] = "private_key";
  char public_key_pem[11] = "public_key";

  std::cout << MSG_START_KEY;
  std::cout << KEY_SIZE <<endl;

  std::cout << MSG_START_RSA;
  std::cout << PUBLIC_EXPONENT <<endl;

  std::cout << MSG_INPUT_MESSAGE;
  cin.getline(message,sizeof(message));

  RSA *keypair = RSA_generate_key(KEY_SIZE, PUBLIC_EXPONENT, NULL, NULL);
  std::cout << MSG_GENERATE_KEY;

  private_key = create_RSA(keypair, PRIVATE_KEY_PEM, private_key_pem);
  
  std::cout << MSG_PRIVATE_KEY;

  public_key = create_RSA(keypair, PUBLIC_KEY_PEM, public_key_pem);
  
  std::cout << MSG_PUBLIC_KEY;

  encrypt = (char*)malloc(RSA_size(public_key));
  int encrypt_length = public_encrypt(strlen(message) + 1, (unsigned char*)message, (unsigned char*)encrypt, public_key, RSA_PKCS1_OAEP_PADDING);
  if(encrypt_length == -1) {
    std::cout << ERR_PUBLIC_ENCRYPT;
  }
  std::cout << MSG_DATA_ENCRYPT;

  create_encrypted_file(encrypt, public_key);

  std::cout << MSG_FILE_ENCRYPT;

  decrypt = (char *)malloc(encrypt_length);
  int decrypt_length = private_decrypt(encrypt_length, (unsigned char*)encrypt, (unsigned char*)decrypt, private_key, RSA_PKCS1_OAEP_PADDING);
  if(decrypt_length == -1) {
    std::cout << ERR_PRIVATE_DECRYPT;
  }

  std::cout << MSG_DATA_DECRYPT;
  std::cout << decrypt <<endl;

  FILE *decrypted_file = fopen("arquivo_decifrado.txt", "w");
  fwrite(decrypt, sizeof(*decrypt), decrypt_length -1, decrypted_file);
  fclose(decrypted_file);
  std::cout << MSG_FILE_DECRYPT;

  RSA_free(keypair);
  free(private_key);
  free(public_key);
  free(encrypt);
  free(decrypt);
  std::cout << MSG_END_OPENSSL;

  return 0;
}