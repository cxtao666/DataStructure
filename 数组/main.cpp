#include "seqlist.h"

int main(){

    Seqlist<int> L;


    try {

         L.insert(1, 20);

         cout << L.empty() << endl;

         L.insert(2, 30);

         cout <<  L.find (30) << endl;
        
        cout <<  L.findIndex (2) << endl;

        cout <<  L.empty() << endl;

        cout <<  L.erase (1) << endl;

        cout <<  L.find (30) << endl;

        L.change(1, 46);

        L.printf();
    }catch(char const* s){
        cout << s << endl;
    }
   
}