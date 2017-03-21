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

./mandel_openMP
```

TODO : ajouter tableaux et courbes

## Question 4

Voir [convol_openMP.c](src/convol_openMP.c)

```
gcc -fopenmp -o convol_openMP convol_openMP.c -lm

./convol_openMP Sukhothai_4080x6132.ras 0 100
```

TODO : ajouter tableaux et courbes