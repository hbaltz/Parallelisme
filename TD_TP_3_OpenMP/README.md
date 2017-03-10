# TD/TP2 : OpenMP

## Question 1

```
cat /proc/cpuinfo  
cpu cores	: 4
```

## Question 2

```
export OMP_NUM_THREADS=4

gcc -fopenmp -o omp_hello omp_hello.c 
```

## Question 3

Voir [mandel_openMP.c](src/mandel_openMP.c)

```
gcc -fopenmp -o mandel_openMP mandel_openMP.c -lm
```

