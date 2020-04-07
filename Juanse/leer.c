#include <stdio.h>
#include <stdlib.h>
#define NUMERO_DATOS 10e06

//Estructura
struct dogType
{
  char nombre[32];
  char tipo[32];
  int edad;
  char raza[32];
  float estatura;
  float peso;
  char genero;
};

//Imprimir estructura dogType
int printStruct(void *ap)
{
    struct dogType *data;
    data = ap;
    printf("\nDATO LEIDO\nNombre: %s", data->nombre);
    printf("\nTipo: %s", data->tipo);
    printf("\nEdad: %i", data->edad);
    printf("\nRaza: %s", data->raza);
    printf("\nEstatura: %f", data->estatura);
    printf("\nPeso: %f", data->peso);
    printf("\nGenero: %c", data->genero);
    return 0;
}

int main()
{
  FILE *apFile;
  struct dogType *datoLeido;
  datoLeido = malloc(sizeof( struct dogType ));
  if(datoLeido == NULL)
  {
    perror("error malloc: ");
    exit(-1);
  }

  int r;

  apFile = fopen("dogsData.dat", "r");


  for (size_t i = 0; i < NUMERO_DATOS; i++) {
    r = fread(datoLeido, sizeof(struct dogType), 1, apFile);
    if(r < 0)
    {
      perror("error fread");
      exit(-1);
    }
    printStruct(datoLeido);
    printf("\n");
  }

  fclose(apFile);
  free(datoLeido);
	return 0;
}
