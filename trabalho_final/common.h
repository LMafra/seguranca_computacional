#ifndef COMMON_H
#define COMMON_H

/*
 * Header que define os protótipos de funções e estruturas que serão utilizadas
 * por todo o projeto.
 *
 * Trabalho de Segurança Computacional: 01/2020
 *
 * Lucas Mafra Chagas - 12/0126443
 *
 */

/*
 * ================== Constantes ==================
 */

#define KEY_SIZE 1024
#define PUBLIC_EXPONENT 65537
#define PUBLIC_KEY_PEM 1
#define PRIVATE_KEY_PEM 0

#define MSG_START_OPENSSL "Iniciando programa...\n"
#define MSG_START_KEY "Tamanho da chave: "
#define MSG_START_RSA "Expoente RSA: "
#define MSG_INPUT_MESSAGE "Digite a mensagem a ser criptografada:\n"
#define MSG_GENERATE_KEY  "RSA foi criada.\n"
#define MSG_PRIVATE_KEY  "Chave privada foi criada.\n"
#define MSG_PUBLIC_KEY  "Chave publica foi criada.\n"

#define ERR_PUBLIC_ENCRYPT "ERRO: Não foi possível criptografar. \n"
#define ERR_PRIVATE_DECRYPT "ERRO: Não foi possível decifrar. \n"

#define MSG_DATA_ENCRYPT "A mensagem foi criptografada. \n"
#define MSG_FILE_ENCRYPT "O arquivo criptografado foi criado.\n"

#define MSG_DATA_DECRYPT "A mensagem foi decifrada: "
#define MSG_FILE_DECRYPT "O arquivo decifrado foi criado.\n"

#define MSG_END_OPENSSL "Fechando programa..."

/*
* Criando arquivos das chaves públicas e as chaves privadas.
*/

RSA *create_RSA(RSA *keypair, int pem_type, char *filename);

/*
* Função que criptografa o dado.
*/

int public_encrypt(int flen, unsigned char* from, unsigned char *to, RSA* key, int padding);

/*
* Função que decifra o dado.
*/

int private_decrypt(int flen, unsigned char* from, unsigned char *to, RSA* key, int padding);

/*
* Criando arquivos .bin. Contém o dado criptografado.
*/

void create_encrypted_file(char* encrypted, RSA *key_pair);

#endif