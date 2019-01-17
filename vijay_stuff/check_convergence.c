#include <stdio.h>
#include <stdlib.h>

int check_convergence(int m, int n, double**u, double**u_update, double thresh){
	double diff_sum = 0;
	int i, j;
	int convergence = 0;
	#pragma omp single
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			diff_sum += (u[i][j] - u_update[i][j])*(u[i][j] - u_update[i][j]);
		}
	}
	/*printf("%lf\n", diff_sum);*/
	if(diff_sum < thresh){
		convergence = 1;
	}
	
	return convergence;

}
