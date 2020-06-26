#include "CircularDoublyList.h"

int main(){

    int arr[] = {4, 5, 3, 21, 6, 7, 8};

    CircularDoublyList<int> L(arr,7);

    L.printflist();
 	cout << L.len()<<endl;
 	
    L.insert(2,13);
   
   L.printflist();

    L.erase(4);

    cout << L.find(21) << endl;

   cout << L.findIndex(2) << endl;

    L.change(3, 21);

    L.printflist(); 
}
