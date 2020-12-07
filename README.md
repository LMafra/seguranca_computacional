![alt text](http://www.unb.br/images/Imagens/logo_unb.png)

# Segurança Computacional - 1/2020

## Membro
* Lucas Mafra Chagas - 12/0126443

## Introdução

#### Gerador/Verificador de Assinaturas

Como atividade de implementação, deve-se implementar um gerador e verificador de assinaturas RSA em arquivos. Assim, deve-se implementar um programa com as seguintes funcionalidades:

* Geração de chaves (mínimo de 1024 bits)
* Assinatura
1. Cálculo de hashes (função de hash SHA-3)
2. Assinatura da mensagem (cifração do hash)
3. Formatação do resultado (caracteres especiais e informações para verificação)

* Verificação
1. Parsing do documento assinado (de acordo com a formatação usada)
2. Decifração da assinatura (decifração do hash)
3. Verificação (cálculo e comparação do hash do arquivo)

## Fundamentação Teórica

### RSA

#### O que é RSA?

RSA é um sistema de criptografia de chave pública e é bastante utilizado para transmissão segura de dados. Neste sistema de criptografia, a chave de encriptação é pública e é diferente da chave de decifração, que é privada. Essa assimetria é baseada na fatorização do produto de dois números primos grandes, conhecido como "Problema de Fatoração".
## Funcionamento do Projeto

### Descrição das Funções

#### Funções construídas
* create_RSA: Função responsável pela criação das chaves públicas e privadas.
* public_encrypt: Função responsável pela criptografia da mensagem utilizando a chave pública criada.
* private_decrypt: Função responsável pela decifração da mensagem utilizando a chave privada criada.
* create_encrypted_file: Função responsável pela criação do arquivo criptografado .bin
### Compilação do Código

Para compilar o código, basta executar:
```c
   make all
```
Caso queira limpar o diretório, basta executar:
```c
   make clean
```
Caso queira limpar o diretório e remover os arquivos gerados, basta executar:
```c
   make deep_clean
```
## Limitações e Bugs

* As chaves pública e privada são geradas em arquivos, mas não aparecem no terminal.

## Extra

Código adaptado de: [bavlayan/Encrypt-Decrypt-with-OpenSSL---RSA](https://github.com/bavlayan/Encrypt-Decrypt-with-OpenSSL---RSA)