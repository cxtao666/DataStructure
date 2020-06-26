
/*
定义一颗二叉树

遍历 : 遍历操作   层序遍历   中序遍历  后序遍历  层序遍历

增加节点

删除节点

数组构造成二叉树

修改  找到数据域为 x 的节点，把它进行修改  

打印出二叉树

*/

#include <queue>
#include <iostream>

using namespace std;

template < typename T>
class Node {

    public:
        Node *left;
        Node *right;
        T val;
        Node(T data){
            val = data;
            left = NULL;
            right = NULL;
        }
};

template <typename T>
class Binary_Tree{

    public:

    Binary_Tree(T data[] , int n){

        for (int i = 0; i < n; i ++){

            insert(data[i]);
        }
    }

    ~Binary_Tree(){

        delete root;
        root = NULL;
    }

    // 添加节点
    void insert(T data){
        
        queue<Node<T> *> list;

       if(root != NULL){
           list.push(root);
       }else if(root == NULL) {
           root = new Node<T>(data);
           return;
       }

      
       while (!list.empty())
       {

            Node<T> * s = list.front();

            list.pop();

            if(s->left != NULL ){
                list.push(s->left);
            }else if(s->left == NULL){

                s->left = new Node<T>(data);
                return;
            }

            if(s->right != NULL){

                list.push(s->right);

            }else if(s->right == NULL){

                 s->right = new Node<T>(data);
                return;
            }

        } 

    }


    //进行节点的修改
    bool  modify(T data, T newData){

        queue<Node<T> *> list;

       if(root != NULL){
           list.push(root);
       }else{
           return false;
       }

      
       while (!list.empty())
       {

            Node<T> * s = list.front();

            list.pop();

            if(data == s->val){

                s->val = newData;
                return true;
            }

            if(s->left != NULL ){
                list.push(s->left);
            }

            if(s->right != NULL){

                list.push(s->right);
            }

        }

        return false;
   }

    // 先序遍历
  void  Preorder_traversal( Node <T> * root){

      if(root == NULL){
          return;
      }

      cout << root->val << " ";

      if(root->left != NULL){
          Preorder_traversal(root->left);
      }

        if(root->right != NULL){
            Preorder_traversal(root->right);
        }

   }

    // 中序遍历
   void In_order_traversal(Node <T> * root){

       if(root == NULL){
          return;
      }

    

      if(root->left != NULL){
          Preorder_traversal(root->left);
      }
            cout << root->val << " ";
        if(root->right != NULL){
            Preorder_traversal(root->right);
        }

   }

   // 后序遍历

    void Post_order_traversal(Node <T> * root){

        if(root == NULL){
          return;
      }

      if(root->left != NULL){
          Preorder_traversal(root->left);
      }

        if(root->right != NULL){
            Preorder_traversal(root->right);
        }
        cout << root->val << " ";
    }

    // 层序遍历
   void Sequence_traversal(){

       queue<Node<T> *> list;

       

       if(root != NULL){
           list.push(root);
       }else{
           return;
       }

      
       while (!list.empty())
       {

            Node<T> * s = list.front();

            list.pop();

            cout << s->val << " ";

            if(s->left != NULL ){
                list.push(s->left);
            }

            if(s->right != NULL){

                list.push(s->right);
            }

        }

        cout << endl;
   }
    
     Node <T> * getRoot(){

         return root;
    }

    private:
        Node <T> *root = NULL;
};
