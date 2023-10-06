#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <sys/time.h>
#include "utils.h"

struct SumArgs {
  int *array;
  int begin;
  int end;
};

int Sum(const struct SumArgs *args) {
  int sum = 0;
  for (int i = args->begin; i < args->end; ++i) {
    sum += args->array[i];
  }
  return sum;
}

void *ThreadSum(void *args) {
  struct SumArgs *sum_args = (struct SumArgs *)args;
  return (void *)(size_t)Sum(sum_args);
}

int main(int argc, char **argv) {
  uint32_t threads_num = 0;
  uint32_t array_size = 0;
  uint32_t seed = 0;

  if (argc != 4) {
    printf("Usage: %s threads_num array_size seed\n", argv[0]);
    return 1;
  }

  threads_num = atoi(argv[1]);
  array_size = atoi(argv[2]);
  seed = atoi(argv[3]);

  pthread_t threads[threads_num];
  struct SumArgs args[threads_num];
  int *array = malloc(sizeof(int) * array_size);
  GenerateArray(array, array_size, seed);

  struct timeval start_time, end_time;
  gettimeofday(&start_time, NULL);

  for (int i = 0; i < threads_num; ++i) {
    args[i].array = array;
    args[i].begin = i * array_size / threads_num;
    args[i].end = (i + 1) * array_size / threads_num;
    if (pthread_create(&threads[i], NULL, ThreadSum, &args[i])) {
      printf("Error: pthread_create failed!\n");
      return 1;
    }
  }

  int total_sum = 0;
  for (int i = 0; i < threads_num; ++i) {
    int thread_sum = 0;
    pthread_join(threads[i], (void **)&thread_sum);
    total_sum += thread_sum;
  }

  gettimeofday(&end_time, NULL);
  double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

  free(array);

  printf("Total: %d\n", total_sum);
  printf("Elapsed time: %.6f seconds\n", elapsed_time);

  return 0;
}

