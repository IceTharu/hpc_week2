#include <stdio.h>
#include "datatools.h"
#include <math.h>
#include "init_arrays.h"
#include "jacobi.h"



void main(){
	double spacing = 0.002;
	int max_iter = 100;
	int m = 2/spacing;
	int n = 2/spacing;
	double** u;
	double** u_update;
	double** F;

	u = malloc_2d(m,n);
	u_update = malloc_2d(m,n);
	F = malloc_2d(m,n);

	init_arrays(m,n,u,u_update,F);

	jacobi(m,n,max_iter,spacing,u,u_update,F);

	

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%lf ", u[i][j]);
		}
		printf("\n");
	} 
	free_2d(u);
	free_2d(u_update);
	free_2d(F);
}
