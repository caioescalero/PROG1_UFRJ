/*
------------------------------------------------------------
Programa: Cifra de Letras (Substituição ROT13 adaptada)
Autor: Caio Escalero
Descrição:
  Este programa lê 3 letras digitadas pelo usuário e exibe
  suas respectivas cifras (letras substituídas por outras
  de acordo com uma lógica baseada na posição no alfabeto).

  - Se a letra estiver entre 'A' e 'N' ou 'a' e 'n', soma-se 13.
  - Se estiver entre 'N' e 'Z' (ou 'n' e 'z'), a lógica usa o
    resto da divisão para circular dentro do alfabeto.
  - Caso o caractere não seja uma letra, o programa exibe
    "Caractere inválido" e encerra.

Entrada:
  Letras fornecidas pelo usuário (uma por vez).

Saída:
  A letra original e sua respectiva cifra.

Exemplo de execução:
  Digite uma letra: A
  A cifra de A eh N
------------------------------------------------------------
*/

#include <stdio.h>

int main() {
    int aux, cont = 1; // Variável auxiliar e contador
    char letra;        // Letra digitada
    char cifra;        // Letra cifrada

    // Loop que roda 3 vezes
    while (cont < 4) {
        printf("Digite uma letra: ");
        letra = getchar();            // Lê o caractere digitado
        while (getchar() != '\n');    // Limpa o buffer de entrada

        // Verifica se é uma letra válida
        if (!((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z'))) {
            printf("Caractere invalido");
            break;
        }

        // Cálculo da cifra
        if (letra > 'N' && letra <= 'Z') {
            aux = letra % 26;
            cifra = 64 + aux;  // Ajuste para circular no alfabeto maiúsculo
        }
        else if (letra > 'n' && letra <= 'z') {
            aux = (letra - 'a' + 12) % 26;
            cifra = 'a' + aux; // Ajuste para circular no alfabeto minúsculo
        }
        else {
            cifra = letra + 13; // Caso padrão (A–N ou a–n)
        }

        // Exibe o resultado
        printf("A cifra de %c eh %c", letra, cifra);
        cont++;
        printf("\n");
    }

    return 0;
}