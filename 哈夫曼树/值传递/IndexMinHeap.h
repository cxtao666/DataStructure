#include<stdio.h>
#include<iostream>
#include <algorithm>
#include<assert.h>
using namespace std;

// 构建最小堆

template <typename  Item>
class IndexMaxHeap
{
private:
    /* data */
    Item *data;  // 数组指针
    int count ;  // 堆的大小
    int capacity; // 标记数组长度
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
    //向最小堆插入数据
    // 传入的i对用户而言,是从0索引的，堆的数组是从1开始的
    void insert(Item item){
   
        data[count+1] = item;
        
        count++;

        shiftUp(count);
       
    }
    void list (){
        for (int i = 1; i <= count;i++){
            cout << data[i]->data << endl;
        }
    }

    // 把堆顶元素弹出
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

      //  cout << k << " " << data[k] << " " <<  data[k/2]<< endl; 
        // 和自己的父亲节点比，比父亲节点小，就交换位置，一直这样循环下去

       // bool sign = data[k] <= data[k / 2];

      //  cout << sign << endl;
        while(data[k] <= data[k/2] && k/2 > 0){
            swap(data[k/2], data[k]);
            k = k/2;
        }

    }
    // 向下移动
    void shiftDown(int k){
        while(2*k <= count){
            int j = 2 * k;
            
            // 比较2个儿子节点哪个小，下标取小的
            if(j+1 <= count && data[j+1] < data[j]){
                j += 1;
            }

            // 在拿小的儿子节点和父亲节点比，如果比父亲节点小，那么就儿子和父亲交换位置，并继续循环
            if(data[k] <= data[j]){
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