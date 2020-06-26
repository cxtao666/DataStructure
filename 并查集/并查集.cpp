#include <iostream>

using namespace std;

const int N = 110;
int father[N];
bool isRoot[N];

int findFather(int x){

    int a = x;

    while(x != father[x]){
        x = father[x];
    }

    // 路径压缩
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

// 用递归的方法实现查找父节点
int findFather2(int v){
    if(v == father[v])
        return v;
    else{
        int F = findFather2(father[v]);

        father[v] = F;

        return F;
    }
}

void Union(int a,int b){

    int faA = findFather(a);
    int faB = findFather(b);

    if(faA != faB){
        father[faA] = faB;
    }
}

void init(int n){

    for (int i = 1; i <= n; i++){
        father[i] = i;
        isRoot[i] = false;
    }
}

