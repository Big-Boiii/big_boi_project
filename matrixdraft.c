#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>

void
matmult_nat(int m, int n, int k, double **A, double **B, double **C) {
    for(int i1 = 0; i1< m; i1++){
        for(int i2 = 0; i2 < n; i2++){
            for(int i3 = 0; i3 < k; i3++){
                C[i1][i2]+=A[i1][i3]*B[i3][i2];
            }
        }
    }
}

void
matmult_lib(int m, int n, int k, double **A, double **B, double **C) {
  cblas_dgemm(CblasColMajor,CblasNoTrans,CblasNoTrans,m,n,k,1.,A[0],k+1,B[0],n+1,0.,C[0],n+1);
}



void print_matrix(int n, int k, double **C){
    for (int i=0; i<n; i++){
        for (int j=0; j<k; j++){
            printf("%lf \t", C[i][j]);
        }
        printf("\n");
    }
}

void reset_matrix(int n, int k, double **C){
    for (int i=0; i<n; i++){
        for (int j=0; j<k; j++){
            C[i][j]=0;
        }
    }
}

void assign(double** arr, int m, int n)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //arr[i][j] = rand()*0.0001;
            arr[i][j]=2.;
        }
    }
}

int main() {
    int m=2; //rows of A and C
    int n=3; //columns of B and C
    int k=2; //columns of A and rows of B

    double **A = (double **)malloc(m * sizeof(double *));
    for (int r = 0; r < m; r++)
        A[r] = (double *)malloc(k * sizeof(double));
    // assign array
    assign(A,m,k);

    double **B = (double **)malloc(k * sizeof(double *));
    for (int r = 0; r < k; r++)
        B[r] = (double *)malloc(n * sizeof(double));
    assign(B,k,n);

    double **C = (double **)malloc(m * sizeof(double *));
    for (int r = 0; r < m; r++)
        C[r] = (double *)malloc(n * sizeof(double));

    reset_matrix(m,n,C);
    print_matrix(m,k,A);
    printf("\n");
    print_matrix(k,n,B);
    printf("\n");
    matmult_nat(m,n,k,A,B,C);
    print_matrix(m,n,C);
    reset_matrix(m,n,C);
    print_matrix(m,k,A);
    printf("\n");
    print_matrix(k,n,B);
    printf("\n \n");
    matmult_lib(m,n,k,A,B,C);
    print_matrix(m,n,C);
    double d=1.5;
    
    printf("\n %ldd",sizeof(d));
	printf("\n %lf", 30720000./8);
    return 0;
}

