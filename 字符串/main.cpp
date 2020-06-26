#include "MyString.h"

class Test{
    public :
        Test(const char * s){
            m_data = s;
        }
       const char * m_data;
};

void add( const Test & test){
    cout << test.m_data << endl;
}

int main(){
    add("abcd");

    myString a = "abcd";

   int c = a.fastfind("cd");

   cout << c << endl;
}