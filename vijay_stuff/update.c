#include <stdio.h>
#include <omp.h>

void update(int m, int n, double** u, double** u_update){
	/*printf("Updating\n");*/
	int i,j;	
	#pragma omp for private(i,j)
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			/*printf("i, j, thread %d %d %d\n",i,j,omp_get_thread_num());*/
			u[i][j] = u_update[i][j];

		}
	}
}
