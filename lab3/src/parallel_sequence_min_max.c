#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s seed arraysize\n", argv[0]);
    return 1;
  }

  int seed = atoi(argv[1]);
  if (seed <= 0) {
    printf("seed is a positive number\n");
    return 1;
  }

  int array_size = atoi(argv[2]);
  if (array_size <= 0) {
    printf("array_size is a positive number\n");
    return 1;
  }

  if (fork() == 0) {
    // Child process
    execlp("./sequential_min_max", "./sequential_min_max", argv[1], argv[2], NULL);
    perror("execlp");
    return 1;
  } else {
    // Parent process
   printf("Parent process");
  }

  return 0;
}
