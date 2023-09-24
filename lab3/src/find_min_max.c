#include "find_min_max.h"

#include <limits.h>

struct MinMax GetMinMax(int *array, unsigned int begin, unsigned int end) {
  struct MinMax min_max;
  min_max.min = INT_MAX;
  min_max.max = INT_MIN;

  for(int ind = begin; ind < end; ind++) {
    if(array[ind] < min_max.min)
	min_max.min = array[ind];
    if(array[ind] > min_max.max)
	min_max.max = array[ind];
  }  

return min_max;
}
