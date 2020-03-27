#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

/*int generateData(void *ap, char names[][], char breeds[])
{
  struct dogType *dog;
  dog = ap;
  int randomNumber;
  char generos[] = {'M', 'F'};

  //Data
  randomNumber = randNum(1000);
  char name[32] = names[randomNumber];

  char type[32] = "Perro";

  randomNumber = randNum(15);
  int age = randomNumber;

  randomNumber = randNum(20);
  char breed[32] = breeds[randomNumber];

  randomNumber = randNum(10);
  float height = (float)randomNumber;

  randomNumber = randNum(15);
  float weight = (float)randomNumber;

  randomNumber = randNum(2);
  char gender = generos[randomNumber];

  //Llenar dog
  sprintf(dog->nombre, name);
  sprintf(dog->tipo, type);
  dog->edad = age;
  sprintf(dog->raza, breed);
  dog->estatura = height;
  dog->peso = weight;
  dog->genero = gender;

  return 0;
}*/

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

int randNum(int max)
{
  srand(time(0));

  for(int i = 0; i<5; i++)
    printf(" %d ", rand() % max);

  return 0;
}


int main()
{
  //Estructura
  struct dogType *dato;
  dato = malloc(sizeof( struct dogType ));
  int r;
  if(dato == NULL)
  {
    perror("error malloc: ");
    exit(-1);
  }

  //Archivo
  FILE *apFile;
  apFile = fopen("nombresMascotas.txt", "r");

  //Variables
  char buffer[32] = ""; //Variable
  char nombres[1729][32]; //Arreglo de char[] para guardar nombres: [NUMERO_STRINGS][LONGITUD_MAXIMA]
  int indice = 0; //Índice para recorrer arreglo de char[]

  //Recorrer archivo hasta que encunetre 'End of File'
  while( (fscanf(apFile, "%s\n", buffer)) != EOF)
  {
    strcpy(nombres[indice], buffer); //Asignar al arreglo lo leido en buffer
    printf("names array: %s, i: %i\n", nombres[indice], indice); //Impresión para comprobar
    indice++; //Aumentar índice
  }
  //Cerrar archivo
  r = fclose(apFile);
  if(r != 0)
  {
    perror("fclose error: ");
    exit(-1);
  }
  //Liberar memoria del dato
  free(dato);
  //Prueba de función que imprime 5 números aleatorios
  randNum(1000);
	return 0;
}
