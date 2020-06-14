#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
/*          INT ADDITION TEST BEGINS          */

static void int_Addition(benchmark::State& state) {
    srand((unsigned)time(0));
    int a = rand();
    srand((unsigned)time(0));
    int b =rand();
    for (auto i : state){
        a + b;
    }
}
// Register the function as a benchmark
BENCHMARK(int_Addition);

/*          INT ADDITION TEST ENDS          */

/*          MERGE SORT ALGORITHM BEGINS          */

void merge(int arr[],int left, int right, int mid){
    int i,j,k,temp[right-left+1];
    i = left;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <=right)
    {
        if(arr[i]<arr[j]){
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
        
    }
    while (i<=mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    while(j<=right){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for ( i = left; i < right; i++)
    {
        arr[i] = temp[i-left];
    }
}

void mergesort(int arr[], int left, int right){
    if(left<right){
        int mid = (left + right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr, left, right, mid);
    }
}

/*          MERGE SORT ALGORITHM ENDS          */

/*          MERGE SORT TEST FOR SIZE 10 BEGINS             */

static void mergeSort_Size10(benchmark::State& state) {
        int arr[10];
        for(int i = 0; i < 10; i++){
            srand((unsigned)time(0));
            arr[i] = rand();
        }
        for(auto i : state){
            mergesort(arr,0,9);
        }
}
BENCHMARK(mergeSort_Size10);

/*          MERGE SORT TEST FOR SIZE 10 ENDS             */

/*          MERGE SORT TEST FOR SIZE 100 BEGINS             */

static void mergeSort_Size100(benchmark::State& state) {
        int arr[100];
        for(int i = 0; i < 100; i++){
            srand((unsigned)time(0));
            arr[i] = rand();
        }
        for(auto i : state){
            mergesort(arr,0,99);
        }
}

BENCHMARK(mergeSort_Size100);

/*          MERGE SORT TEST FOR SIZE 10O ENDS             */

/*          MERGE SORT TEST FOR SIZE 1000 BEGINS             */

static void mergeSort_Size1000(benchmark::State& state) {
        int arr[1000];
        for(int i = 0; i < 1000; i++){
            srand((unsigned)time(0));
            arr[i] = rand();
        }
        for(auto i : state){
            mergesort(arr,0,999);
        }
}

BENCHMARK(mergeSort_Size1000);

/*          MERGE SORT TEST FOR SIZE 1000 ENDS             */

/*          QUICK SORT ALGORITH BEGINS          */

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int start, int end){
    int pivotIndex = start;
    int pivotValue = arr[end];
    for(int i = start; i <= end-1; i++ ){
        if(arr[i] < pivotValue){
            swap(arr, i, pivotIndex);
            pivotIndex++;
        }
    }
    swap(arr, pivotIndex, end);
    return pivotIndex;
}
void quickSort(int arr[], int start, int end){
    if(start < end){
        int index = partition(arr, start, end);
        quickSort(arr,start, index-1);
        quickSort(arr,index+1, end);
    }
}
/*          QUICK SORT ALGORITHM ENDS           */

/*          QUICK SORT TEST FOR SIZE 10 BEGINS          */
static void quickSort_size10(benchmark::State& state){
    int arr[10];
        for(int i = 0; i < 10; i++){
            srand((unsigned)time(0));
            arr[i] = rand();
        }
        for(auto i : state){
            quickSort(arr,0,9);
        }
}

BENCHMARK(quickSort_size10);
/*          QUICK SORT TEST FOR SIZE 10 ENDS          */

/*           SORT TEST FOR IN BUILT FUNCTION FOR SIZE 10 BEGINS          */
static void InBuiltSort_size10(benchmark::State& state){
    int arr[10];
        for(int i = 0; i < 10; i++){
            srand((unsigned)time(0));
            arr[i] = rand();
        }
        for(auto i : state){
            std::sort(arr,arr+10);
        }
}

BENCHMARK(InBuiltSort_size10);

/*           SORT TEST FOR IN BUILT FUNCTION FOR SIZE 10 ENDS          */

/*          QUICK SORT TEST FOR SIZE 100 BEGINS          */
static void quickSort_size100(benchmark::State& state){
    int arr[100];
        for(int i = 0; i < 100; i++){
            srand((unsigned)time(0));
            arr[i] = rand();
        }
        for(auto i : state){
            quickSort(arr,0,99);
        }
}

BENCHMARK(quickSort_size100);
/*          QUICK SORT TEST FOR SIZE 100 ENDS          */

/*           SORT TEST FOR IN BUILT FUNCTION FOR SIZE 100 BEGINS          */
static void InBuiltSort_size100(benchmark::State& state){
    int arr[100];
        for(int i = 0; i < 100; i++){
            srand((unsigned)time(0));
            arr[i] = rand();
        }
        for(auto i : state){
            std::sort(arr,arr+100);
        }
}

BENCHMARK(InBuiltSort_size100);

/*           SORT TEST FOR IN BUILT FUNCTION FOR SIZE 100 ENDS          */

/*          QUICK SORT TEST FOR SIZE 1000 BEGINS          */
static void quickSort_size1000(benchmark::State& state){
    int arr[1000];
        for(int i = 0; i < 1000; i++){
            srand((unsigned)time(0));
            arr[i] = rand();
        }
        for(auto i : state){
            quickSort(arr,0,999);
        }
}

BENCHMARK(quickSort_size1000);
/*          QUICK SORT TEST FOR SIZE 1000 ENDS          */

/*           SORT TEST FOR IN BUILT FUNCTION FOR SIZE 10000 BEGINS          */
static void InBuiltSort_size1000(benchmark::State& state){
    int arr[1000];
        for(int i = 0; i < 1000; i++){
            srand((unsigned)time(0));
            arr[i] = rand();
        }
        for(auto i : state){
            std::sort(arr,arr+1000);
        }
}

BENCHMARK(InBuiltSort_size1000);

/*           SORT TEST FOR IN BUILT FUNCTION FOR SIZE 1000 ENDS          */

BENCHMARK_MAIN();