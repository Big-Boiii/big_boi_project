#include "cblas.h"

void
matmult_lib(int m, int k, int n, double **A, double **B, double **C) {
  cblas_gemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,m,n,k,1,A,m,B,k,1,C,m)
}


