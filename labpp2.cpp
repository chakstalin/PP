#include "stdafx.h"
#include <stdio.h>
#include "mpi.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)

int main(int  argc, char * argv[])
{
	int rank, resultlen, numb;
	char name[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(name, &resultlen);
	do {
		if (rank == 0) {
			printf("Enter a digit (0 or less to exit): ");
			fflush(stdout);
			scanf("%d", &numb); 
		}
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Bcast(&numb, 1, MPI_INT, 0, MPI_COMM_WORLD);
		
		printf("Process %d (%s) got %d\n", rank, name, numb);
		MPI_Barrier(MPI_COMM_WORLD);
		fflush(stdout);
	} while (numb> 0);
	MPI_Finalize();
	std::cin.get();
	return 0;
}

