#include <algorithm>
#include <cstring>
#include <cstdio>

// 可以区间查询，单点更新
// 树状数组是一个数组来着的，用于表示数值是index的数字有多少个
// c数组表示的是这段区间的元素之和
class BIT1{  

    private:
        int *c;
        const static int maxn = 100010;

        // 进行lowbit 的运算
        int lowbit(int i)
        {
            return i & (-i);
        }

    public:
    
    //update函数将第x个整数加上v,单点更新
    void update(int x ,int v){

        for (int i = x; i < maxn; i+= lowbit(i)){
            c[i] += v;
        }
    }

    // getSumAll 函数返回前x个整数之和，区间查询
    int getSumAll(int x){

        int sum = 0;

        for (int i = x; i > 0; i -= lowbit(i)){
            sum += c[i];
        }

        return sum;
    }

    public:
        BIT1(){
            c = new int[maxn];
            memset(c, 0, sizeof(c));
        }
        ~BIT1(){
            delete[] c;
        }

};


// 可以区间更新,单点查询
// c数组表示的是这段区间的每个数当前被加了多少
class BIT2{

    private:
        int *c;
        const static int maxn = 100010;

        // 进行lowbit 的运算
        int lowbit(int i)
        {
            return i & (-i);
        }

    public:

      // 将前x个整数都加上v，区间更新
    void updateAll(int x , int v){
        for (int i = x; i > 0; i-= lowbit(i)){
            c[i] += v;
        }
    }
 
    //返回第x个整数的值，单点查询
    int getSum(int x ){ 

        int sum = 0;

        for (int i = x; i < maxn; i+= lowbit(i)){

            sum += c[i];
        }

        return sum;
    }

    public:
        BIT2(){
            c = new int[maxn];
            memset(c, 0, sizeof(c));
        }
        ~BIT2(){
            delete[] c;
        }

};