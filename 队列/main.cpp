#include "seqQueue.h"

int main(){

try{

    seqQueue<int> list;

    list.push(5);

    list.push(4);

    list.push(100);

    list.push(9);

    cout << list.pop() << endl; // 输出5

    list.push(13);

    cout << list.getRear() << endl; // 输出13

    cout << list.getFront() << endl;// 输出 4

    list.printfQueue();

    list.pop();

    cout << list.size() << endl;
}
catch(char const * s){
    cout << s << endl;
}
    

}