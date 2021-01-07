#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>

void matmult_lib(int m, int n, int k, double **A, double **B, double **C) {
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1., &A[0][0], k, &B[0][0], n, 0., &C[0][0], n);
}


void matmult_nat(int m, int n, int k, double **A, double **B, double **C) {
    
    int i1, i2, i3;
    for(i1 = 0; i1 < m; i1++){
		for(i2 = 0; i2 < n; i2++){
	    	C[i1][i2] = 0;
	 	}
    }
  
    for(i1 = 0; i1< m; i1++){
    	for(i2 = 0; i2 < n; i2++){
	    	for(i3 = 0; i3 < k; i3++){
				C[i1][i2]+=A[i1][i3]*B[i3][i2];
	    	}
        }
    }
}

void printMatrix(double **arr, int m, int n){
	int i, j;
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%f \t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

double ** malloc_2d(int m, int n){
	// initializes a matrix of size mxn. It is needed in order to make the matrix passable as an argument to other functions. DINAMICALLY ALLOCATED.
	int i, j;
	double **A;

	A = malloc(m * sizeof(double *));
	A[0] = malloc(m * n * sizeof(double));
	for(i = 1; i < m; i++){
		A[i] = A[0] + i*n;
	}
	
	return A;
}


void initMatrix(double **arr, int m, int n){
	int i, j;

	/* setting the seed */
    srand((unsigned)time(NULL));

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
			// arr[i][j] = i*j;
            arr[i][j] = rand() % 20;
		}
	}
}


int main(){
	int m = 5, n = 2, k = 4, i;
	double **A, **B, **C;

	A = malloc_2d(m, k);
	initMatrix(A, m, k);

	B = malloc_2d(k,n);
	initMatrix(B, k, n);
	
	C = malloc_2d(m,n);

	printf("With our function:\n");

	matmult_nat(m, n, k, A, B, C);

	printMatrix(A, m, k);
	printMatrix(B, k, n);
	printMatrix(C, m, n);

	printf("With CBLAS function:\n");

	matmult_lib(m, n, k, A, B, C);

	printMatrix(A, m, k);
	printMatrix(B, k, n);
	printMatrix(C, m, n);


	return 0;
}

