#include "Binary tree.h"

int main(){

    int arr[] = {0, 1, 4, 5, 7, 8, 2};

    Binary_Tree <int> p (arr,7);

    p.Sequence_traversal();

    p.In_order_traversal(p.getRoot());

    cout << endl;

    p.insert(3);

    p.Preorder_traversal(p.getRoot());

    cout << endl;

    p.Post_order_traversal(p.getRoot());

    cout << endl;

    cout << p.modify(4,10) << endl;

     p.Post_order_traversal(p.getRoot());

    cout << endl;
}