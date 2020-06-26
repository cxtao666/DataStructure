#include "linQueue.h"

/*
用循环队列实现队列
需要设置头节点和尾节点
尾节点指向最后一个入队元素的后一个位置
头节点指向队列的第一个元素
存的数组下标是 0 到 maxsize - 1
数组存放的数据最多比数组的大小少一个
数组空间是 5 ， 存放4个元素  此时 a[0],a[1],a[2],a[3] 这 4个 位置存放了 数据，然后 first 指向下标 0 ，rear 指向下标4，此时队列已满，队列中元素个数是 4

有 2 种 情况要判断
 
first 在前  rear 在后    正常情况    队列  rear - first 
rear 在 前  first 在 后   特殊情况   队列  maxSize - first + rear 
*/

const int MaxSize = 5;

template <typename T>
class seqQueue{

    public:

    seqQueue(){
        rear =  0;
        first = 0 ;
    }

    T pop(){

        if(isEmpty()){
            throw "is empty";
        }

        T node = data[first];
        first = (first + 1) % MaxSize;

        return node;
    }

    void push(T x){
    

        if(isFull()){
            throw "is full";
        }

        data[rear] = x;
        rear = (rear + 1) % MaxSize;
        
    }
    bool isEmpty(){
        if(first == rear){
            return true;
        }
        return false;
    }

    // 判断是否已经满了
    bool isFull (){

        int b = (rear + 1) % MaxSize;

       // cout << "b" << b << endl;

        bool sign = (b == first);

      //  cout << "sign" <<  sign << endl;

        if( sign ){
            return true;
        }
        return false;
    }

    int size(){
        return (rear - first + MaxSize) % MaxSize;
    }

    // 获取队尾元素
    T getRear(){

        return data[(rear - 1 + MaxSize) % MaxSize];
    }

    // 获取队首元素
    T getFront(){

        if(isEmpty()){
            throw "is empty";
        }

        return data[first];
    }

    // 打印队列
    void printfQueue(){

        if(first < rear ){

            for (int i = first; i < rear; i++){
                cout << data[i] << " ";
            }
            cout << endl;

        }else if(rear < first){

            for (int i = first; i < MaxSize; i++){
                cout << data[i] << " ";
            }

            for (int j = 0; j < rear; j++){
                cout << data[j] << " ";
            }

            cout << endl;
        }

    }
private:
    int first;
    int rear;
    T data[MaxSize];
};