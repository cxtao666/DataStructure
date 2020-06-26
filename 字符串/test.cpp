#include <iostream>
using namespace std;

class test{
public: 
  test s(test &p);

private:
    int *a;
};

test test::s ( test & p){
    test q;
    test &x = q;
    p.a = new int [5];
    return x;
}

int add(int a,int b){
    return a + b;
}

int math(int (&p3) (int,int)){
    return p3(5, 4);
}

int main(){

    test p;

    test q = p.s(p);

    int b = 5;

    int &a = b;

    int c = a;

    c = 10;

    cout << a << endl;

    cout << b << endl;

    cout << c << endl;

    cout << math(add) << endl;
}

