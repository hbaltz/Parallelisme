# TD/TP1 : Ensemble de Mandelbrot

## Calcul séquentiel

### Question 1 

Dans le code deux boucles for imbriquées permettent de parcourir l'ensemble des pixels de l'images et d'en calculer la valeur
  j va de 0 à W-1 (largueur image)
  i va de 0 à H-1 (hauteur image) 

Utilisation pour les pixels d'unsigned char codés sur 8 bits

Puisque l'ensemble est discret alors que le plan complexe est continu, nous calculons l'incrémént xinc, yinc entre les coordonnées de pixels contigus

  * x(i) = xmin + xinc * i
  * y(j) = ymin + yinc * j

Avec :

  * xinc = (xmax - xmin) / (w - 1)
  * yinc = (ymax - ymin) / (h - 1)

### Question 2

#### 2.1
```
gcc -o mandel mandel.c -lm  
./mandel  
Temps total de calcul : 5.49344 sec
```

![Resultat code original](mandel_base.ras)

#### 2.2 && 2.3
```
./mandel 800 800 0.35 0.355 0.353 0.358 200  
Temps total de calcul : 0.449191 sec
```

![Resultat calcul changement xmin ymin xmax ymax](mandel_800_800_0.35_0.355_0.353_0.358_200.ras)

Commentaires : changement du domaine a calculer dans le plan complexe. On remarque un déplacement de la zone de calcul

```
./mandel 800 800 -0.736 -0.184 -0.735 -0.183 500  
Temps total de calcul : 1.48156 sec
```

![Resultat calcul changement prof](mandel_800_800_-0.736_-0.184_-0.735_-0.183_500.ras)

Commentaires : changement du domaine a calculer dans le plan complexe et profondeur


```
./mandel 800 800 -0.736 -0.184 -0.735 -0.183 300  
Temps total de calcul : 1.24605 sec
```

![Resultat calcul changement prof](mandel_800_800_-0.736_-0.184_-0.735_-0.183_300.ras)

Commentaires : changement de profondeur (nombre maximale d'iteration) par rapport à l'image précédente, on remarque un nombre de formes plus important.

## Calcul parallèle

### Question 3

#### 3.1

Le calcul de l'ensemble de Mandelbrot nécéssite de connnaître la position en 2D (en x et en y) simultanément, c'est cela qui rend difficile la parallélisation.