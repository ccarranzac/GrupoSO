#include <stdio.h>
#include <stdlib.h>

int main()
{
    char entrada[32] = "";
    printf("Escribe un caracter: ");
    while ((scanf("%s%*c", entrada)) != EOF)
    {
        printf("La entrada no ha sido EOF, fue %s\n", entrada);
        printf("Escribe un caracter:\n");
    }
    printf("\nEOF");
    return 0; // Ejemplo aprenderaprogramar.com
}
