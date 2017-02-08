#include <stdio.h>
#include <mpi.h>
#include <time.h> /* chronometrage */
#include <string.h> 
#include <sys/time.h> /* chronometrage */
#include <unistd.h> /* Sleep */

double my_gettimeofday(){
  struct timeval tmp_time;
  gettimeofday(&tmp_time, NULL);
  return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}

int main(int argc, char *argv[])
{
  const int ROOT = 0;
  char msg [20];
  int my_rank;
  int numtasks;
  int p;
  /* Chronometrage */
  double debut, fin;

  /* debut du chronometrage */
  debut = my_gettimeofday();

  MPI_Init(&argc, &argv); /*Initializes MPI calls*/
  
  MPI_Status status;

  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);  /* obtains the rank of current MPI process */
  MPI_Comm_size(MPI_COMM_WORLD, &numtasks); /* obtains the total number of MPI processes */

  if (my_rank != ROOT ) {
    strcpy(msg,"Hello World !");
    //sleep(1); // en s
    MPI_Send(msg, 20, MPI_CHAR, ROOT, 0, MPI_COMM_WORLD);
  }
  else 
    for ( p = 1; p < numtasks; p++ ) {
      MPI_Recv(msg, 20, MPI_CHAR, p, 0, MPI_COMM_WORLD, &status);
      printf("J'ai reçu : %s\n", msg);
  }

  MPI_Finalize();        /*Finalizes MPI calls */

   /* fin du chronometrage */
  fin = my_gettimeofday();
  fprintf( stderr, "Temps total de calcul : %g sec\n", 
     fin - debut);
  //fprintf( stdout, "%g\n", fin - debut);

  return 0;
}


