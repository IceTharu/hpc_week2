
#ifndef __JACOBI_OMP_H
#define __JACOBI_OMP_H

void jacobi_omp(int m, int n, int max_iter, double spacing, double** u, double** u_update, double** F);

#endif
