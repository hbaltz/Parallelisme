# Configuration des rapsberry pi

Inspireé par [lleksah](https://lleksah.wordpress.com/2016/04/11/configuring-a-raspberry-cluster-with-mpi/)

## Obtenir fortran

```
sudo apt-get install gfortran
```

## Obtenir mpi

Sur une pi, la plus performante de préférence

```
mkdir /home/pi/mpich3
cd mpich3
mkdir build install
wget http://mpich.org/static/downloads/3.0.4/mpich-3.0.4.tar.gz
tar -xvf mpich-3.0.4.tar.gz
cd build 
/home/pi/mpich3/mpich-3.0.4/configure -prefix=/home/pi/mpich3/install
make
make install
```

Suppresion (rm) des fichiers inutiles (par exemple le tar.gz)

## Copie sur les autres pi

```
scp autre pi 
scp -r mpich3 piensg005:
```

## Exporter le chemin

```
export PATH="$PATH:/home/pi/mpich3/install/bin"
```

## Exporter le chemin au démarrage

```
sudo nano /home/pi/.profile
export PATH="$PATH:/home/pi/mpich3/install/bin"
```

## Ajouter les pi aux clusters

Exemple sur la piensg017

Modifier /etc/hosts voir [hosts](hosts)

```
127.0.0.1       piensg017
172.31.57.156   piensg015
172.31.57.70    piensg011
172.31.57.64    piensg005
```

Et /home/pi/pifile

pifile017 

```
172.31.57.156
172.31.57.70
172.31.57.64
127.0.0.1
```

```
mpiexec -f pifile hostname
```

