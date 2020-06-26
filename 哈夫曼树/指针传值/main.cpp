#include "Huffmantree.h"

// 传的是指针，没法比大小,函数符重载失效

int main(){


    int arr[] = {1, 2, 3, 4, 5, 6};

    Huffmantree tree(arr, 6);

    tree.createTree();

    tree.printf();
}