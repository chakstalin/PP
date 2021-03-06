#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(int  argc, char * argv[])
{
	double PI25DT = 3.141592653589793238462643;		// 
	int size, n;
	double mypi = 0.0, startwtime, endwtime;
	do {
		printf("Choose intervals number (n), (0 - Exit): ");//kjk
		scanf_s("%d", &n);
		if (n <= 0) break;
		startwtime = omp_get_wtime();
#pragma omp parallel reduction (+: mypi) num_threads(4)
		{
			int rank;
			double sum, x, h;
			rank = omp_get_thread_num();
			size = omp_get_num_threads();
			printf("Process %d started\n", rank);
			sum = 0.0; h = 2 * n;
#pragma omp for
			for (int i = 1; i <= n; i++)
			{
				x = (2 * i - 1) / h;
				sum += 4 / (1 + x * x);
			}
			sum *= 1 / (double)n;
			mypi += sum;
		}
		endwtime = omp_get_wtime();
		printf("Result: pi=%.16f, Rashozhdenie s etalonom %.16f\nwork time %f sec\n", mypi, fabs(mypi - PI25DT), endwtime - startwtime);
		mypi = 0;
	} while (n > 0);
	return 0;
}
