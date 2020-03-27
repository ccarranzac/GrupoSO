#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXIMA_LONGITUD 32

int randNum(int max);

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

int generateData(void *ap, char names[][MAXIMA_LONGITUD], char breeds[][MAXIMA_LONGITUD])
{
  struct dogType *dog;
  dog = ap;
  int randomNumber = 0;
  char generos[] = {'M', 'F'};
  printf("INICIO ESTRUCTURA\n");

  //Data
  randomNumber = randNum(1731);
  char name[MAXIMA_LONGITUD];
  strcpy(name, names[randomNumber]);
  //printf("Nombre: %s\n", name);

  char type[MAXIMA_LONGITUD] = "Perro";
  //printf("Tipo: %s\n", type);

  randomNumber = randNum(15);
  int age = randomNumber;
  //printf("Edad: %d\n", age);

  randomNumber = randNum(7);
  char breed[MAXIMA_LONGITUD];
  strcpy(breed, breeds[randomNumber]);
  //printf("Raza: %s\n", breed);

  randomNumber = randNum(10);
  float height = (float)randomNumber;
  //printf("Altura: %f\n", height);

  randomNumber = randNum(15);
  float weight = (float)randomNumber;
  //printf("Peso: %f\n", weight);

  randomNumber = randNum(2);
  char gender = generos[randomNumber];
  //printf("Genero: %c\n", gender);

  //Llenar dog
  strcpy(dog->nombre, name);
  strcpy(dog->tipo, type);
  dog->edad = age;
  strcpy(dog->raza, breed);
  dog->estatura = height;
  dog->peso = weight;
  dog->genero = gender;

  return 0;
}

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
  int rant = (int) ( rand() % max );

  return rant;
}


/*char[][MAXIMA_LONGITUD] generarArreglo(char[MAXIMA_LONGITUD] nombre)
{
  //Archivo
  FILE *apFile;
  apFile = fopen(nombre, "r");

  //Variables
  char buffer[32] = ""; //Variable
  char nombres[1730][32]; //Arreglo de char[] para guardar nombres: [NUMERO_STRINGS][LONGITUD_MAXIMA]
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
  //Retornar arreglo lleno
  return nombres;
}*/


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
  char buffer[MAXIMA_LONGITUD] = ""; //Variable
  char nombres[1730][MAXIMA_LONGITUD]; //Arreglo de char[] para guardar nombres: [NUMERO_STRINGS][LONGITUD_MAXIMA]
  char razas [6][MAXIMA_LONGITUD]; // = {"Criollo", "Pitbull", "Huskee", "Chihuahua", "Puddle", "Pug"};
  int indice = 0; //Índice para recorrer arreglo de char[]

  //Recorrer archivo hasta que encunetre 'End of File'
  while( (fscanf(apFile, "%s\n", buffer)) != EOF)
  {
    strcpy(nombres[indice], buffer); //Asignar al arreglo lo leido en buffer
    //printf("names array: %s, i: %i\n", nombres[indice], indice); //Impresión para comprobar
    indice++; //Aumentar índice
  }

  //Recorrer archivo hasta que encunetre 'End of File'
  apFile = fopen("breeds.txt", "r");
  indice = 0;
  while( (fscanf(apFile, "%s\n", buffer)) != EOF)
  {
    strcpy(razas[indice], buffer); //Asignar al arreglo lo leido en buffer
    //printf("names array: %s, i: %i\n", razas[indice], indice); //Impresión para comprobar
    indice++; //Aumentar índice
  }

  //Cerrar archivo
  r = fclose(apFile);
  if(r != 0)
  {
    perror("fclose error: ");
    exit(-1);
  }

  //Generar estructura
  r = generateData(dato, nombres, razas);
  if(r != 0)
  {
    perror("error generateDato: ");
    exit(-1);
  }

  //Imprimir estructura guardada
  printStruct(dato);

  //Liberar memoria del dato
  free(dato);
  //Prueba de función que imprime 5 números aleatorios
  randNum(1000);
	return 0;
}
