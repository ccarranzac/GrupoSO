#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXIMA_LONGITUD 32
#define NUMERO_DATOS 10e06
#define NUMERO_NOMBRES 1730
#define NUMERO_RAZAS 6



//Funciones (Signatures)
int randNum(int max);

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

//Generar estructura con todos los datos
int generateData(void *ap, char names[][MAXIMA_LONGITUD], char breeds[][MAXIMA_LONGITUD], int i)
{
  struct dogType *dog;
  dog = ap;
  int randomNumber = 0;
  char generos[] = {'M', 'F'};
  printf("\nINICIO ESTRUCTURA\n");

  //Data
  randomNumber = randNum(1731);
  char name[MAXIMA_LONGITUD];
  strcpy(name, names[i % 1730]);

  char type[MAXIMA_LONGITUD] = "Perro";

  randomNumber = randNum(15);
  int age = randomNumber;

  randomNumber = randNum(7);
  char breed[MAXIMA_LONGITUD];
  strcpy(breed, breeds[i % 6]);

  randomNumber = randNum(10);
  float height = (float)randomNumber;

  randomNumber = randNum(15);
  float weight = (float)randomNumber;

  randomNumber = randNum(2);
  char gender = generos[randomNumber];

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

//Guardar (escribir) estructura en el archivo
int guardar(void *ap, char nombre[])
{
  struct dogType *data;
  data = ap;

  FILE *apFile;
  int r;

  apFile = fopen(nombre, "a+");
  if(apFile == NULL)
  {
    perror("error fopen");
    exit(-1);
  }

  r = fwrite((void *)ap, sizeof(struct dogType), 1, apFile);
  if(r < 0)
  {
    perror("error fwrite");
    exit(-1);
  }

  r = fclose(apFile);
  if(r < 0)
  {
    perror("error fclose");
    exit(-1);
  }

  return 0;
}

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

//Función para generar número aleatorio
int randNum(int max)
{
  srand(time(0));
  int rant = (int) ( rand() % max );
  return rant;
}

//Función para llenar arreglos
int llenarArreglo(char arreglo[][MAXIMA_LONGITUD], char nombreArchivo[MAXIMA_LONGITUD])
{
  //Variables
  FILE *apFile;
  apFile = fopen(nombreArchivo, "r");
  char buffer[MAXIMA_LONGITUD] = "";
  int indice = 0;
  int r;

  //Recorrer archivo hasta que encunetre 'End of File'
  while( (fscanf(apFile, "%s\n", buffer)) != EOF)
  {
    strcpy(arreglo[indice], buffer); //Asignar al arreglo lo leido en buffer
    indice++; //Aumentar índice
  }

  //Cerrar archivo
  r = fclose(apFile);
  if(r != 0)
  {
    perror("fclose error: ");
    exit(-1);
  }
  return 0;
}

//Función que escribe un cantidad de datos a partir de dos arreglos char [] y datos aleatorios
int escribirDatos(void *ap, char names[][MAXIMA_LONGITUD], char breeds[][MAXIMA_LONGITUD], int cantidad, char nombreArchivo[MAXIMA_LONGITUD])
{
  struct dogType *dog;
  dog = ap;
  int r;

  //Writing all the data needed (10'000'000)
  for(int i = 0; i < cantidad; i++)
  {
    generateData((void *)ap, names, breeds, i);
    r = guardar((void *)ap, nombreArchivo);
    printf("i: %d\n", i); //Prueba
    if(r != 0)
    {
      perror("error guardar");
      exit(-1);
    }
  }
  return 0;
}

int main()
{
  //Estructura
  struct dogType *dato;
  dato = malloc(sizeof( struct dogType ));
  if(dato == NULL)
  {
    perror("error malloc: ");
    exit(-1);
  }

  //Variables
  char nombres[NUMERO_NOMBRES][MAXIMA_LONGITUD]; //Nombres de perros [cantidad][maxima_long_caracteres]
  char razas [NUMERO_RAZAS][MAXIMA_LONGITUD]; //Razas de perros
  int r; //Variable para resultados

  //Llenar arreglo de nombres y razas a partir de archivos
  llenarArreglo(nombres, "nombresMascotas.txt");
  llenarArreglo(razas, "razas.txt");

  /*Escribir datos a partir de arreglo
  1. Dato: estructura (apuntador) dogType a guardar en dogsData.dat
  2. Nombres: Arreglo de nombres de perros
  3. Razas: Arreglo de razas de perros
  4. Número de datos a escribir: 10e06
  5. Nombre del archivo para escribir datos
  */
  r = escribirDatos(dato, nombres, razas, NUMERO_DATOS, "dogsData.dat");
  if(r != 0)
  {
    perror("error escribirDatos() ");
    exit(-1);
  }
  //Liberar memoria del dato
  free(dato);
	return 0;
}
