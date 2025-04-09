#include <stdio.h>
#include <stdlib.h>
unsigned long long fibo(unsigned long long fiboNum) {return(fiboNum == 0 || fiboNum == 1) ? fiboNum : fibo(fiboNum - 1) + fibo(fiboNum - 2);}int main(int argc, char *argv[]){printf("fibo %lld\n\n", fibo(10));return 0;}