#include <stdio.h>
#include "strlib.h"

int main() {
  char *palavra = "Paulo";
  char *palavra_null = NULL;

  printf("Tamanho da palavra: %s = %d\n\n", palavra, str_length(palavra));
  printf("Aqui é pra aparecer -1: %s = %d\n\n", palavra_null, str_length(palavra_null));

  return 0;
}