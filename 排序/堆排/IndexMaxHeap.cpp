#include<stdio.h>
#include<iostream>
#include <algorithm>
#include<assert.h>
using namespace std;

template <typename  Item>
class IndexMaxHeap
{
private:
    /* data */
    Item *data;
    int count ;
    int capacity;
    int *indexes;

public:
    IndexMaxHeap(int capacity);   //参数要和外面的参数一样
    ~IndexMaxHeap();

    IndexMaxHeap(Item arr[], int n);

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }
    //向最大堆插入数据
    // 传入的i对用户而言,是从0索引的
    void insert(int i,Item item){
        data[count + 1] = item;
        count++;
        assert(count + 1);  //错误处理
        shiftUp(count);
    }
    void list (){
        for (int i = 1; i <= count;i++){
            cout << data[i] << endl;
        }
    }

    Item extractMax(){
        assert(count > 0);

        Item ret = data[1];

        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;
    }
private:
        
// 向上移动
    void shiftUp(int k){
        while(data[k/2] < data[k]){
            swap(data[k / 2], data[k]);
            k = k / 2;
        }
    }
    // 向下移动
    void shiftDown(int k){
        while(2*k <= count){
            int j = 2 * k;
            
            if(j+1 <= count && data[j+1] > data[j]){
                j += 1;
            }
            if(data[k] >= data[j]){
                break;
            }
            swap(data[k], data[j]);
            k = j;
        }
    }
};

template <typename  Item>
IndexMaxHeap<Item>::IndexMaxHeap(int capacity)  //这里<>要把模板写了
{
    count = 0;
    data = new Item[capacity + 1];
    indexes = new int[capacity + 1];

    this->capacity = capacity;
}

template <typename Item>
IndexMaxHeap<Item>::~IndexMaxHeap()
{
    delete[] data;
    delete[] indexes;
}

template <typename Item>
IndexMaxHeap<Item>:: IndexMaxHeap(Item arr[], int n){
    data = new Item[n + 1];
    capacity = n;
    for (int i = 0; i < n;i++){
        data[i + 1] = arr[i];
    }
    count = n;

    for (int i = count / 2; i >= 1;i--){
        shiftDown(i);
    }
}