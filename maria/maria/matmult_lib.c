#include "cblas.h"

void
matmult_lib(int m, int n, int k, double **A, double **B, double **C) {
  cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,m,n,k,1.,&A[0][0],m,&B[0][0],k,0.,&C[0][0],m);
}

