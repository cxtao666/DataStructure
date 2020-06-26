#include "CircularList.h"

using namespace std;

template <typename T>
class CircularDoublyList : public CircularList<T>{

    public:

    CircularDoublyList(){
        CircularList<T>::first = new Node<T>;
    }

    CircularDoublyList(T data[] ,int n){  
             
     CircularList<T>::first = new Node<T>;
    
     Node<T> *s ;

     Node<T> *p =  CircularList<T>::first;

     for (int i = 0; i < n; i++){

         s = new Node<T>;

         s->data = data[i];

         s->next = NULL;

         s->pre = p;

         p->next = s;

         p = s;

        }

        p->next =  CircularList<T>::first ;

         CircularList<T>::first->pre = p;
    }

     T erase (int n){

            if(n <= 0 ){

             throw "删除位置出错";
         }
        
           if(CircularList<T>::isEmpty()){
            throw "没有元素删除";
        }

         Node<T> *p = CircularList<T>::first ;

         int index = 0;

         while ( p->next != CircularList<T>::first )
         {

             // 此时p是待删除节点的前节点

             index++;

             if (index == n)
             {
             	
             
                 Node<T> *s = p->next->next;

                 T data = p->next->data;

                 p->next->next = NULL;

                 p->next->pre = NULL; 

                 p->next = s;

                 s->pre = p;

                 return data;

            }

            p = p->next;
        }

        throw "删除位置出错";
     }

     bool insert(int n , T data){
     	

              if(n <= 0 || n > CircularList<T>::len() + 1 ){

             throw "插入位置出错";
         }

         Node<T> *p = CircularList<T>::first ;

         int index = 0;

         while ( p->next != CircularList<T>::first)
         {
             // 此时p是待删除节点的前节点

             index++;

             if (index == n)
             {	

                 Node<T> *s = p->next;

                 p->next = new Node<T>;

                  p->next->data = data;

                p->next->pre = p;

                 p->next->next = s;

                 s->pre = p->next;

                 return true;
            }

            p = p->next;
        }
		
	         Node<T> *s = p->next;

                 p->next = new Node<T>;

                  p->next->data = data;

                p->next->pre = p;

                 p->next->next = s;

                 s->pre = p->next;
     }


};