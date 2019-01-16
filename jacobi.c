#include <stdio.h>
#include <stdlib.h>
#include "check_convergence.h"





void jacobi(int m, int n, int max_iter, double spacing, double** u, double** u_update, double** F){
	
	int convergence = 0;
	int i, j;
	int iter = 0;

	while(iter < max_iter && convergence == 0){
		printf("Haha i didnt break\n");
		iter++;
		for(i = 1; i < m-1;i++){
			for(j = 1; j < n-1; j++){
				u_update[i][j] = (u[i][j-1] + u[i][j+1] + u[i-1][j] + u[i+1][j-1] + ((spacing*spacing) * F[i][j]))/4;

				if(i == m-2 && j == n-2){

					convergence = check_convergence(m, n, u, u_update, 10);
					if(convergence == 1){
						printf("Converged at %d\n", iter);
						break;
						
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
