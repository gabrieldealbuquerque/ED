#include <stdio.h>
#include <stdlib.h>

int main ( void ) { 
   int a, b, *p;
   p = calloc(1, sizeof(int)); 
   a = 2; 
   *p = 3; 
   b = a + (*p); 
   printf(" %d ", b); 
   return 0; 
}   