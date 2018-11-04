#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
  
int main(int argc, char **argv) 
{ 
    setuid(0);
    char buffer[256];
    gets(buffer); 
    return 0; 
} 
