#include "IndexMinHeap.h"

class Node{

    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

   bool operator>=(const Node & num1){

       return this->data >= num1.data;
    }

   bool operator<(const Node & num1){
      return this->data < num1.data; 
   }

     bool operator>(const Node & num1){
        return this->data > num1.data;
    }

    bool operator<=(const Node & num1){

        return this->data <= num1.data;
    }

};

class Huffmantree{

    private:
    // 哈夫曼树的头结点
        Node *first;

    public:
    IndexMaxHeap<Node *> *heap;

    Huffmantree(int arr[], int n)
    {

        heap = new IndexMaxHeap<Node *>(n);

        for (int i = 0; i < n; i++)
        {
            Node * node = new Node(arr[i]);
            heap->insert(node);
        }
    }

    // 构建哈夫曼树
    Node * createTree(){

        if(heap->size() == 0){
            return NULL;
        }

        while(heap->size() > 1){

        Node * first = heap->extractMax();
        Node * two = heap->extractMax();

        Node * newNode = new Node(first->data + two->data);

        cout << newNode->data << " " << first->data << " " << two->data << endl;

        newNode->left = first;

        newNode->right = two;

        heap->insert(newNode);
     
        }

       Node * head = heap->extractMax();

       first = head;

       return first;
    }

    ~Huffmantree(){

    }

    void dfs(Node * base){

        cout << base->data << " ";

        if(base->left != NULL){
            dfs(base->left);
        }

        if(base->right != NULL){
            dfs(base->right);
        }

    }

    // 打印哈夫曼树
    void printf(){

        dfs(first);
        cout << endl;
     }
};