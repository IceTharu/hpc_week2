#include <stdio.h>
#include <stdlib.h>
#include "check_convergence.h"





void gauss_seidel(int m, int n, int max_iter, double spacing, double** u, double** F){
	
	int convergence = 0;
	int i, j;
	int iter = 0;
	while(iter < max_iter && convergence == 0){

		iter++;
		for(i = 1; i < m-1;i++){
			for(j = 1; j < n-1; j++){
				u_update[i][j] = (u[i][j-1] + u[i][j+1] + u[i-1][j] + u[i+1][j] + ((spacing*spacing) * F[i][j]))/4;

				if(i == m-2 && j == n-2){

					convergence = check_convergence(m, n, u, u_update, 0.00001);
					if(convergence == 1){
						printf("Converged at iteration %d",iter);
					}

					for(i = 0; i < m; i++){
						for(j = 0; j < n; j++){
							u[i][j] = u_update[i][j];

						}
					}
					
				}	
			}
			
		}
	}

}
