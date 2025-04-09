#include <stdio.h>
#include "strlib.h"

int main() {
  char *palavra = "Teste";
  char *palavra_legal = "Teste";
  char *palavra_null = NULL;
  char *copia_palavra = str_duplicate(palavra);

  printf("Tamanho da palavra: %s = %d\n\n", palavra, str_length(palavra));
  printf("Aqui é pra aparecer -1: %s = %d\n\n", palavra_null, str_length(palavra_null));

  printf("Cópia da palavra - original: %s - cópia: %s\n\n",palavra,copia_palavra);
  printf("Paulo vs UFSC: %d\n", str_compare("Paulo", "UFSC"));

  char lower[] = "Paulo";
  printf("lower: %s\n\n", lower);

  int upper = str_upper(lower);
  printf("upper count: %d\n\n", upper);

  return 0;
}