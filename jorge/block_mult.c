#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>

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

void matmult_blk(int m, int n, int k, int bs, double **A, double **B, double **C){
    int i1, i2, i3;

    for(i1 = 0; i1 < m/bs; i1 += bs){
		for(i2 = 0; i2 < n; i2++){
	    	C[i1][i2] = 0;
	 	}
    }
}





void printMatrix(double **arr, int m, int n){
	int i, j;
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%.0f \t", arr[i][j]);
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

void pointBlock(int row, int col, int bs, double **A, double **Z){
    // This functions takes Z, which is a matrix bs*bs and makes the pointers stored at Z[0], Z[1] to point at the locations &A[row][col].
    // In this way we make Z point at the values of A we want for the block.
    // Z needs to be initialized with: Z = malloc(bs * sizeof(double *)); before being used.

    int i;
    for(i = 0; i < bs; i++){
        Z[i] = &A[row+i][col];
    }
}

void getBlock(int row, int col, int bs, double **A, double **Z){
    // This functions copies the values from A we want for the block into a matrix Z of size bs x bs.
    // Z needs to be initialized with: Z = malloc_2d(bs, bs); before being used.
    
    int i, j;

    for(i = 0; i < bs; i++){
        for(j = 0; j < bs; j++){
            Z[i][j] = A[row + i][col + j];
        }
    }
}


int main(){
	int m = 6, n = 6, bs = 2;
	double **A;
    double **Z;

	A = malloc_2d(m, n);
	initMatrix(A, m, n);
	printMatrix(A, m, n);
    
    // Z = malloc(bs * sizeof(double *));
    // pointBlock(2, 2, bs, A, Z);
 
    Z = malloc_2d(bs, bs);
    getBlock(2, 2, bs, A, Z);
    
    printMatrix(Z, bs, bs);    

	return 0;
}

