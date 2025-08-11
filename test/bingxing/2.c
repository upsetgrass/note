#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // 初始化 MPI 环境
    MPI_Init(&argc, &argv);

    // 获取当前进程的编号
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // 获取总的进程数
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // 每个进程打印自己的信息
    printf("Hello world from process %d out of %d processes\n", world_rank, world_size);

    // 关闭 MPI 环境
    MPI_Finalize();

    return 0;
}

