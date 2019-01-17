#include <stdio.h>
#include "datatools.h"
#include <math.h>
#include "init_arrays.h"
#include "jacobi.h"
#include "gaussseidel.h"
#include "omp.h"
#include <stdlib.h>

void main(int argc, char *argv[]){
	double spacing = 0.1;
	int max_iter = 10000;
	double** u,** u_GS;
	double** u_update,** u_update_GS;
	double** F;
	double thresh = 10;
	// Optional command line settings. 

	if ( argc == 2 ) spacing = atof(argv[1]);
	else if ( argc == 3 ){
	  spacing = atof(argv[1]);
	  max_iter = atoi(argv[2]);
	}
	else if (argc == 4){
	  spacing = atof(argv[1]);
	  max_iter = atoi(argv[2]);
	  thresh = atof(argv[3]);
	}

	
	int m = 2/spacing;
	int n = 2/spacing;

	u = malloc_2d(m,n);
	u_GS = malloc_2d(m,n);
	u_update = malloc_2d(m,n);
	u_update_GS = malloc_2d(m,n);
	F = malloc_2d(m,n);

	init_arrays(m,n,u,u_update,F);
	double timejac = omp_get_wtime();
	jacobi(m,n,max_iter,spacing,u,u_update,F,thresh);
	double tot_timejac = omp_get_wtime() - timejac;
	printf("%f\n",tot_timejac);
   

	init_arrays(m,n,u_GS,u_update_GS,F);
	double timegaus = omp_get_wtime();
	gaussseidel(m,n,max_iter,spacing,u_GS,u_update_GS,F,thresh);
	double tot_timegaus = omp_get_wtime() - timegaus;
	printf("%f\n",tot_timegaus);
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%lf ", u[i][j]);
		}
		printf("\n");
	} 

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%lf ", u_GS[i][j]);
		}
		printf("\n");
	}
	
	free_2d(u);
	free_2d(u_GS);
	free_2d(u_update);
	free_2d(u_update_GS);
	free_2d(F);
}
