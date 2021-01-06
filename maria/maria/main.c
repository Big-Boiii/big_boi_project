#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "datatools.h"	
#include "matmult_nat.h"
#define mytimer clock
#define delta_t(a,b) (1e3 * (b - a) / CLOCKS_PER_SEC)


int main(int argc, char *argv[]){
 
    double **A, **B, **C;
    int m,k,n;
    int blkSize;
    clock_t t1, t2;
    double tcpu1; 

    if ( argc >= 5 ) {
        m = atoi(argv[1]);
        k = atoi(argv[2]);
        n = atoi(argv[3]);
        blkSize = atoi(argv[4]);
        }
    else {
         m = 1;
         k = 1;
         n = 1;
         blkSize = 1;
         }
    if ( argc == 4 ) {
         m = atoi(argv[1]);
         k = atoi(argv[2]);
         n = atoi(argv[3]);
    }
    if ( argc == 3 ) {
         m = atoi(argv[1]);
         k = atoi(argv[2]);
    }
     if ( argc == 2 ) {
         m = atoi(argv[1]);
    }

    /* Allocate memory */
    A = malloc_2d(m, k);
    B = malloc_2d(k, n);
    C = malloc_2d(m, n);
    
    if (A == NULL || B == NULL | C == NULL) {
	    fprintf(stderr, "Memory allocation error...\n");
	    exit(EXIT_FAILURE);
	}

    /* initialize with useful data - last argument is reference */
    init_data(m,k,A);
    init_data(k,n,B);

    t1 = mytimer();

    matmult_nat(m,k, n, A, B, C);
    t2 = mytimer();
//    tcpu1 = delta_t(t1, t2) / N;


    /*printing matrises*/
    int i1, i2;
    printf("A MATRIX ");
    for(i1 = 0; i1< m; i1++){
        printf("\n ");
	for(i2 = 0; i2< k; i2++){
	   printf("%lf ", A[i1][i2]);
	 }
    }
    printf("\nB MATRIX ");
    for(i1 = 0; i1< k; i1++){
	printf("\n ");
	for(i2 = 0; i2< n; i2++){
	    printf("%lf ", B[i1][i2]);
	}
     }
     printf("\nC MATRIX ");
     for(i1 = 0; i1< m; i1++){
	 printf("\n ");
	 for(i2 = 0; i2< n; i2++){
	     printf("%lf ", C[i1][i2]);
	 }
      }

    /* Free memory */
    free_2d(A);
    free_2d(B);
    free_2d(C);


    return EXIT_SUCCESS;
}




