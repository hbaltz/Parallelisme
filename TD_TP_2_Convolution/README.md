# TD/TP2 : Convolution

## Test code

```
gcc -o convol convol.c -lm
```

TODO insérer imade départ et résultat

```
./convol femme10.ras 0 100
Temps total de calcul : 0.2132 seconde(s) 

./convol femme10.ras 0 1000
Temps total de calcul : 2.11188 seconde(s) 

./convol femme10.ras 1 100
Temps total de calcul : 0.209322 seconde(s) 

./convol femme10.ras 1 1000
Temps total de calcul : 2.12449 seconde(s) 

./convol femme10.ras 2 100
Temps total de calcul : 0.185408 seconde(s) 

./convol femme10.ras 3 100
Temps total de calcul : 0.178958 seconde(s) 

./convol femme10.ras 4 100
Temps total de calcul : 2.37874 seconde(s) 
```

```
./convol Sukhothai_4080x6132.ras 0 100
Temps total de calcul : 83.2444 seconde(s)

./convol Sukhothai_4080x6132.ras 2 100
Temps total de calcul : 72.2662 seconde(s) 

./convol Sukhothai_4080x6132.ras 4 100
Temps total de calcul : 778.2 seconde(s) 
```

## Question 1

Dans la fonction convolution(), on prépare un tampon intermédiaire pour ne pas avoir à modifier l'image originale, car nous avons besoin des 9 pixels les plus proche d'un pixel pour effectuer le calcul, or si nous modifons directement les pixels d'une ligne par exmple, pour la ligne suivante 3 des pixels les plus proches auront une valeur déjjà transformé, ce qui ne nous permet pas d'effectuer le calcul de conolution correct.

## Question 2

La fonction convolution() qui dépend uniquement du x,y du pixel peut être paralléliser, cependant l'enchaînement des convolutions elle ne pas l'être, car pour effectuer la convolution n, nous avons besoin de l'ensemble de l'image qui a subit la convolution n-1.

## Question 3

9 multplications et 8 additions : Complexité de o(9+8)~o(7)~o(1), donc une complexité constante. Dans ce cas une charge statique est plus efficace car le maître peux effectuer des calculs.

## Question 4

Le découpage naturel est de prendre des formes géométriques constantes tels que des carrés, rectangles, triangles. Par exemple on peux travailler par ligne ou par colonne de plusieurs pixels.

## Question 5

Lignes/colonnes non traitées entre blocs, nécéssite une communication entre les ouvriers (entre les blocs voisins)

Alternative : image origine à tous les ouvriers, peut-être moins efficace si l'image est grosse

## Question 6