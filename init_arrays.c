#include <stdio.h>
#include "datatools.h"
#include "init_arrays.h"

void init_arrays(int m, int n, double** u, double** u_update, double** F){
	int y, x;
	int zerox, zeroy, thrdx, m23rdy, m3rdy;
	zerox = n/2 - 1;
	zeroy = m/2 - 1;
	thrdx = n/6 *4 - 1;
	m23rdy = m/6 - 1;
	m3rdy = m/3 - 1;

	
	for(y = 0; y < m; y++){
		for(x = 0; x < n; x++){
			
			u[y][x] = 0;
			u_update[y][x] = 0;
			
			F[y][x] = 0;

			if(y == (m-1)){
				u[y][x] = 20;
				u_update[y][x] = 20;
			}
			if(y == 0){
				u[y][x] = 0;
				u_update[y][x] = 0;
			}
			if(x == (n-1) || x == 0){
				u[y][x] = 20;
				u_update[y][x] = 20;
			}

			if(x > zerox && x < thrdx && y > m23rdy && y < m3rdy){

				F[y][x] = 200;
			}
			/*if(y > m23rdy && y < m3rdy){
				printf("Hitting loop 2\n");
				F[y][x] = 200;
			}*/
		}
	}
}
		
		
