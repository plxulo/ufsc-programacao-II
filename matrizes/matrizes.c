#include <stdio.h>
#include <string.h>

#define MAX_N 10 // N < 10
#define MAX_T 50 // T < 50

// Permutar linha da matriz:
void row(int matrix[MAX_N][MAX_N], int N, int a, int b) {
  for (int i = 0; i < N; i++) {
    int temp = matrix[a][i];
    matrix[a][i] = matrix[b][i];
    matrix[b][i] = temp;
  }
}

// Permutar coluna da matriz:
void col(int matrix[MAX_N][MAX_N], int N, int a, int b) {
  for (int i = 0; i < N; i++) {
    int temp = matrix[i][a];
    matrix[i][a] = matrix[i][b];
    matrix[i][b] = temp;
  }
}

// Incrementa uma entrada da matriz em 1 % 10
void inc(int matrix[MAX_N][MAX_N], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      matrix[i][j] = (matrix[i][j] + 1) % 10;
    }
  }
}

// Decrementa uma entrada da matriz em 1 % 10
void dec(int matrix[MAX_N][MAX_N], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      matrix[i][j] = (matrix[i][j] - 1 + 10) % 10;
    }
  }
}

// Transpõe a matriz linha <-> coluna
void transpose(int matrix[MAX_N][MAX_N], int N) {
  for (int i = 0; i < N; i++)
  for (int j = i + 1; j < N; j++) {
    int temp = matrix[i][j];
    matrix[i][j] = matrix[j][i];
    matrix[j][i] = temp;
  }
}

// Exibe a matriz formato: Case #1 ... Case #2
void print(int matrix[MAX_N][MAX_N], int N, int case_number) {
  printf("Case #%d\n", case_number);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    int N, M, matrix[MAX_N][MAX_N];
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%1d", &matrix[i][j]);
      }
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
      char operation[10];
      int a, b;

      scanf("%s", operation);
      if (strcmp(operation, "row") == 0) {
        scanf("%d %d", &a, &b);
        row(matrix, N, a - 1, b - 1);
      } else if (strcmp(operation, "col") == 0) {
        scanf("%d %d", &a, &b);
        row(matrix, N, a - 1, b - 1);
      } else if (strcmp(operation, "inc") == 0) {
        inc(matrix, N);
      } else if (strcmp(operation, "dec") == 0) {
        dec(matrix, N);
      } else if (strcmp(operation, "transpose") == 0) {
        transpose(matrix, N);
      }
    }
    print(matrix, N, t);
  }
  return 0;
}