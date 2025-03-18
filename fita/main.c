#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 2048

int main() {
    char line[MAX_MESSAGE_LENGTH + 1]; // Buffer para cada linha da entrada
    char message[MAX_MESSAGE_LENGTH + 1] = {0}; // Mensagem decodificada
    int msg_index = 0;

    while (fgets(line, sizeof(line), stdin)) {
        unsigned char byte = 0;
        int bit_count = 0;

        // Processar cada caractere da linha para extrair os bits
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == 'o') {
                byte = (byte << 1) | 1; // Adiciona o bit 1
                bit_count++;
            } else if (line[i] == ' ') {
                byte <<= 1; // Adiciona o bit 0
                bit_count++;
            }

            // Se acumulamos 8 bits, adicionar ao message e resetar
            if (bit_count == 8) {
                message[msg_index++] = byte;
                if (msg_index >= MAX_MESSAGE_LENGTH) {
                    break; // Prevenir overflow
                }
                byte = 0;
                bit_count = 0;
            }
        }
    }

    message[msg_index] = '\0'; // Terminar a string
    printf("%s\n", message);

    return 0;
}