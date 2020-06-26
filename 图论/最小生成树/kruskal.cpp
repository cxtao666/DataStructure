#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV = 110;

const int MAXE = 10010;

struct edge{

    int u, v;

    int cost;

} E[MAXE];

bool cmp(edge a,edge b){
    return a.cost < b.cost;
}

int father[MAXV];  // 并查集数组

int findFather(int x){ // 并查集查询函数

    int a = x;

    while(x != father[x]){
        x = father[x];
    }

    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}

int kruskal(int  n , int m){

    // ans 为 所求边权之和，Num_Edge 为 当前生成树 的边数
    int ans = 0 , Num_Edge = 0;

    for (int i = 0; i < n; i++){
        father[i] = i;
    }

    sort(E, E + m, cmp);

    for (int i = 0; i < m;  i++)
    {
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);

        if(faU != faV){

            father[faU] = faV;

            ans += E[i].cost;

            Num_Edge++;

            if(Num_Edge == n -1) break ;

        }
    }

    if(Num_Edge != n -1)
        return -1;
    else
        return ans;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
    }

    int ans = kruskal(n, m);

    printf("%d\n", ans);

    return 0;
}


