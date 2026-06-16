# ===================================================================
# Makefile - Analisador de DNA
# Fatec Ourinhos - Linguagem C
#
# Comandos:
#   make           - compila o programa
#   make run       - compila e executa
#   make clean     - remove arquivos gerados
#   make valgrind  - executa com verificacao de memoria (opcional)
# ===================================================================

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -g
TARGET  = analisador_dna

# Lista dos arquivos-fonte
SRC = main.c cadastro.c analise.c ordenacao.c arquivo.c comparacao.c

# Arquivos-objeto (.o) gerados a partir dos .c
OBJ = $(SRC:.c=.o)

# Regra principal: gera o executavel
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
	@echo ""
	@echo ">> Compilacao concluida: ./$(TARGET)"

# Regra generica: como compilar cada .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compila e roda
run: $(TARGET)
	./$(TARGET)

# Remove os arquivos gerados pela compilacao
clean:
	rm -f $(OBJ) $(TARGET) sequencias.txt
	@echo ">> Arquivos limpos."

# Verificacao de memory leaks (requer Valgrind instalado)
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

.PHONY: run clean valgrind
