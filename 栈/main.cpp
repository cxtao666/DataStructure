#include "linkStack.h"

int main(){

    int arr[] = {4, 5, 2, 1, 6};

    LinkStack<int> p(arr,5);

   // LinkStack<int> p;

    p.push(5);

    p.printfStack();

    p.pop();

    p.printfStack();
}