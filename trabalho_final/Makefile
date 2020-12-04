OBJECTS += \
		main.o \
		opensslRSA.o \

TERGET = trabalho_final

LIB += -lcrypto

CFLAG += -c -fPIC -w

EXTRA_GEN_FILE += \
	arquivo_criptografado.txt \
	arquivo_decifrado.txt \
	private_key \
	public_key \

all: ${OBJECTS}
	g++ ${OBJECTS} -o ${TERGET} ${LIB}

%.o:%.cpp
	g++ ${CFLAG} $< -o $@ $(LIB)

clean:
	rm -rf ${OBJECTS} ${TERGET}

deep_clean:
	rm -rf ${OBJECTS} ${TERGET} ${EXTRA_GEN_FILE}