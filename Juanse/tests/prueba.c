#include <stdio.h>
#include <stdlib.h>

int main()
{
  char buffer[32]; // Buffer to store data
  FILE * stream;
  stream = fopen("file.txt", "r");
  printf("Size of file: %lu \n", sizeof(stream));
  //int count = fread(&buffer, sizeof(char), 3, stream);
  fscanf(stream, "%s\n", buffer);
  printf("Data read from file: %s \n", buffer);

  fscanf(stream, "%s\n", buffer);
  printf("Data read from file: %s \n", buffer);

  fclose(stream);
  // Printing data to check validity

  //printf("Elements read: %d", count);
  return 0;
}
