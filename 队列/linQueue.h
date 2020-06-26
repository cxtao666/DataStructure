#include <iostream>

using namespace std;

/*
 *  用链表实现队列
 * 
 *  队列 先进先出
 *  使用2个指针，头指针和尾指针 
 *  分别指向链表的头和尾
 *  头是第一个元素的前节点
 *  尾是最后一个元素的节点
 *  出队把链表的头指针节点的下一个节点返回
 *  用尾插法
 * */

template <typename T>
class Node{

    public:
        Node(T val){
            this->val = val;
        }
        T val;
        Node *next = NULL;
};

template <typename T>
class linQueue{

    public:

    linQueue(){
        first = new Node<T>(0);
        end = first;
        num = 0;
    }

    ~linQueue(){
        delete first;
        first = NULL;
        end = NULL;
    }

    // 判断队列是否为空
    bool isEmpty(){
        if(first->next == NULL){
            return true;
        }
        return false;
    }

    // 入队,使用尾插法
    void push(T data){
        Node<T> *newNode = new Node<T>(data);
        end->next = newNode;
        end = newNode;
        num++;
    }

    // 出队
   T pop(){

       if(isEmpty()){
           throw "队列为空";
       }

       T data = first->next->val;

       first->next = first->next->next;

       return data;
    }

    //获取队首元素
    T getFront(){
        
        if(isEmpty()){
             throw "队列为空";
        }

        return first->next->val;
    }

    // 获取队尾元素
    T getRear(){
        if(isEmpty()){
             throw "队列为空";
        }
        return end->val;
    }

    // 获取队列中的元素个数
    int size(){

        return num;
    }

    // 打印队列
    void printfQueue(){

        Node<T> *head = first->next;

        while(head != NULL){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    private:
        Node<T> *first;
        Node<T> *end;
        int num;
};