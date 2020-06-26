#include <iostream>
using namespace std;
/* 
使用带头节点的头插法链表实现栈
isEmpty 判断栈是否是空的
push   往栈顶添加元素
pop   移除栈顶元素
getTop   获取栈顶的元素
栈的初始化
栈的销毁
 */

// bug 原因  first 节点没初始化赋值，只定义了 但是没指向对象
template <typename T>
class Node {
    public:
    T data;
    Node *next = NULL;
};

template <typename T>
class LinkStack{

    public:

    LinkStack(){

        first = new Node<int>();
    }

     LinkStack(T arr[],int n){
			
         	 first = new Node<int>();
        
         for (int i = 0; i < n; i++){
             push(arr[i]);
            
         }
    }

    void printfStack(){

        Node<T> *q = first->next;
        
        while(q != NULL){
            cout << q->data << " ";
            q = q->next;
        }

        cout << endl;
    }

    ~LinkStack(){
        delete first;
        first = NULL;
    }
   void push(T data){

        Node<T>* s =  new Node<T>;
        s->data = data;
         

         Node<T> *q;

         q = first->next;
         first->next = s;

         s->next = q;

         return;

    }

    T getTop(){
       if(isEmpty){
           throw "栈是空的，没有元素返回";
       }
       else{
           return first->next->data;
       }
    }

    T pop(){

          if(isEmpty()){
           throw "栈是空的，没有元素返回";
       }
       else{
           T data = first->next->data;

           first->next = first->next->next;

           return data;
       }
    }

    bool isEmpty(){

        if(first->next == NULL){
            return true;
        }
        return false;
    }

    private :
        Node<T> * first;

};
