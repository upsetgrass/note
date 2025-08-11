#include <stdio.h>
#include <omp.h>

int main() {
    int arr[1000];
    for (int i = 0; i < 1000; ++i)
        arr[i] = i + 1;

    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 1000; ++i) {
        if (i % 100 == 0)
            printf("Thread %d working on i = %d\n", omp_get_thread_num(), i);
        sum += arr[i];
    }

    printf("Total sum = %d\n", sum);
    return 0;
}
