#include <stdio.h>
#include <iostream>
#include <mpi.h>
#include <string>

int main(int argc, char* argv[]){
    int rank, size, charge_time, wait_time;

   //Initialize 
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    //Calculate wait time for each rank 
    charge_time = atoi(argv[rank + 1]);
    MPI_Scan(&charge_time, &wait_time, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    wait_time -= charge_time;

    std::cout << "Rank " << rank << " will start charging after " << wait_time << " minutes " << 
    "(" << wait_time/60 << " hrs, " << wait_time%60 << " min) " << "and will be done after " << charge_time << " minutes \n"; 

    MPI_Finalize();
    return (0);
}

