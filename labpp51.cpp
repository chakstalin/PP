#include "stdafx.h"
#include <stdio.h>
#include <omp.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)

int main(int argc, char **argv)

{
	
	double start, end;

	start = omp_get_wtime();

#pragma omp parallel num_threads(4)

	{

		printf("Hello, mutithreaded world: thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());

	}

	end = omp_get_wtime();

	printf("Total running time %f\n", end - start);

	

	return 0;

}

