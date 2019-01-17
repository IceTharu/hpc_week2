#include <stdio.h>
#include <stdlib.h>
#include "check_convergence.h"
#include "update.h"
#include <omp.h>






void jacobi_omp(int m, int n, int max_iter, double spacing, double** u, double** u_update, double** F){
	
	int convergence = 0;
	int i, j;
	int iter;

	#pragma omp parallel shared(m,n,max_iter,spacing,u,u_update,F) private(i,j,iter)
	{
	iter = 0;
	while(iter < max_iter && convergence == 0){

		iter++;
		#pragma omp for
		for(i = 1; i < m-1;i++){
			for(j = 1; j < n-1; j++){
				u_update[i][j] = (u[i][j-1] + u[i][j+1] + u[i-1][j] + u[i+1][j] + ((spacing*spacing) * F[i][j]))/4;
				if(i == m-2 && j == n-2){
					
					check_convergence(m,n,u,u_update,0);
					update(m, n, u, u_update);
					
				}
			}
	
		}
		
	



	}
	} /*Parallel end*/

}
