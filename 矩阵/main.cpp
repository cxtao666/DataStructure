#include "matrix.h"


int main(){

    int arr[][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 1}, {0, 1, 3, 5} };

    matrix s(arr,4);

    cout << s.BFS() << endl;

}
