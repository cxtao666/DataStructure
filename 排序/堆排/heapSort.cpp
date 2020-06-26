#include<stdio.h>
#include<iostream>
#include "heap.h"
#include "SortTestHelper.h"
using namespace std;
   
template<typename T>
// 堆排序
void heapSort1(T arr[],int n){
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for (int i = 0; i < n;i++){
        maxheap.insert(arr[i]);
    }
    for (int i = n - 1; i >= 0;i--){
        arr[i] = maxheap.extractMax();
    }
}

// 一半数据进行shiftdown操作
template<typename T>
void heapSort2(T arr[],int n){
    MaxHeap<T> maxhead = MaxHeap<T>(arr, n);

    for (int i = n - 1; i >= 0;i++){
        arr[i] = maxhead.extractMax();
    }
}

template<typename T>
 void __shiftDown(T arr,int n,int k){

        while(2*k+1 <= n){
            int j = 2 * k +1;
            
            if(j+1 < n && arr[j+1] > arr[j]){
                j += 1;
            }
            if(arr[k] >= arr[j]){
                break;
            }
            swap(arr[k], arr[j]);
            k = j;
        }
    }


// 原地堆排序
template<typename T>
void heapSort(T arr[],int n){
    MaxHeap<T> maxhead = MaxHeap<T>(arr, n);

    //heapify 将数组的凌乱数据构建成堆 
    for (int i = (n-1)/2; i >= 0;i--){
        __shiftDown(arr, n, i);
    }

    for (int i = n - 1; i > 0;i--){
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }

}

   
 int main (){ 

       int n = 1000000;

    // 测试1 一般性测试
    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);
    int* arr5 = SortTestHelper::copyIntArray(arr1, n);
    int* arr6 = SortTestHelper::copyIntArray(arr1, n);

    //SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
    // SortTestHelper::testSort("Heap Sort 1", heapSort2, arr5, n);
     SortTestHelper::testSort("Heap Sort 1", heapSort, arr5, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    cout<<endl;
     return 0;
}