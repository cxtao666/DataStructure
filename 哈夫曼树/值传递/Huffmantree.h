#include "IndexMinHeap.h"

class Node{

    public:
    int data;
    Node * left;
    Node * right;

    Node(int data )
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
     }

    Node()
    {

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
    IndexMaxHeap<Node> *heap;

    Huffmantree(int arr[], int n)
    {

        first = NULL;
        heap = new IndexMaxHeap<Node>(n);

        for (int i = 0; i < n; i++)
        {
            Node node (arr[i]);
            heap->insert(node);
        }
    }

    // 构建哈夫曼树
    Node * createTree(){


        while(heap->size() > 1){

        Node  first = heap->extractMax();
        Node  two = heap->extractMax();

        Node  newNode (first.data + two.data);

        cout << newNode.data << " " << first.data << " " << two.data << endl;

        newNode.left = &(first) ;

        newNode.right = &(two);

        heap->insert(newNode);
     
        }

       Node head = heap->extractMax();

       first = &head;

       cout << head.right->data << endl;

       // 打印哈夫曼树
        dfs(&head);

       return first;
    }

    ~Huffmantree(){

    }

    void dfs(Node* base){

        cout << base->data << " ";

        if(base->left != NULL){
            dfs(base->left);
        }

        if(base->right != NULL){
            dfs(base->right);
        }

    }

    

};