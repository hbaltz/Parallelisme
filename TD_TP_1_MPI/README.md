# TD/TP1 : Ensemble de Mandelbrot

## Calcul séquentiel

### Question 1 

### Question 2

#### 2.1
```
gcc -o mandel mandel.c -lm  
./mandel  
Temps total de calcul : 5.49344 sec
```

![Resutlat code original](mandel_base.ras)

#### 2.2 && 2.3
```
./mandel 800 800 0.35 0.355 0.353 0.358 200  
Temps total de calcul : 0.449191 sec
```

![Resultat calcul changement xmin ymin xmax ymax prof](mandel_800_800_0.35_0.355_0.353_0.358_200.ras)

```
./mandel 800 800 -0.736 -0.184 -0.735 -0.183 500  
Temps total de calcul : 1.48156 sec
```

![](mandel_800_800_-0.736_-0.184_-0.735_-0.183_500.ras)