#include <iostream>
#include <vector>
//#include <random>
#include <sys/time.h>
#include <stdlib.h>

//#define DEBUG

double wtime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

typedef unsigned int u32;
typedef std::vector<u32> vectoru32;

//std::minstd_rand0 rnd(99);

u32 getrand(u32 min, u32 max) {
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void generateRandomVector(u32 n, vectoru32 &v) {
  v.resize(n);
  for ( u32 &val : v)
    //val = rnd();
    val = getrand(1, 1001);
}

void merge(vectoru32 &v, u32 begin, u32 mid, u32 end) {
  u32 n1 = mid - begin + 1;
  u32 n2 = end - mid;
  vectoru32 l(n1 + 1);
  vectoru32 r(n2 + 1);
  for ( u32 i = 0; i < n1; i++ )
    l[i] = v[begin + i];
  for ( u32 i = 0; i < n2; i++ )
    r[i] = v[mid + i + 1];
  l[n1] = (u32)-1;
  r[n2] = (u32)-1;
  u32 i = 0;
  u32 j = 0;
  for ( u32 k = begin; k <= end; k++ ) {
    /*if ( i == n1 ) {
      v[k] = r[j];
      j++;
      continue;
    }
    if ( j == n2 ) {
      v[k] = l[i];
      i++;
      continue;
    }*/
    if ( l[i] <= r[j] ) {
      v[k] = l[i];
      i++;
    } else {
      v[k] = r[j];
      j++;
    }
  }
}

void mergeSort(vectoru32 &v, u32 begin, u32 end) {
  if ( begin < end ) {
    u32 mid = begin + ((end - begin) >> 1);
    mergeSort(v, begin, mid);
    mergeSort(v, mid + 1, end);
    merge(v, begin, mid, end);
  }
}

void printVector(vectoru32 &v) {
  //  std::cout << "Vector of size " << v.size() << "\n\n";
  for (u32 &val : v)
    std::cout << val << " ";
  std::cout << "\n";
}

int main (int argc, char *argv[]) {

  double tis;
  u32 size = atoi(argv[1]);
  vectoru32 v;
  generateRandomVector(size, v);

#ifdef DEBUG
  std::cout << "Unsorted vector\n";
  printVector(v);
#endif

  tis = wtime();
  mergeSort(v, 0, v.size() - 1);
  tis = wtime() - tis;

#ifdef DEBUG
  std::cout << "\nSorted vector\n";
  printVector(v);
#endif
  //printf("[insertion sort] Size of vector : %lu. Elapsed time: %.6f sec.\n", v.size(), tis);
  printf("%lu %.6f\n", v.size(), tis);  
  return 0;
}
