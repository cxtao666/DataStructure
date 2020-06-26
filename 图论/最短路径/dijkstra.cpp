#include <algorithm>

using namespace std;

const int MAXV = 1000;

const int INF = 1000000000;

struct Node{
    int v, dis;
};

class DJ {

private:
 int n, G[MAXV][MAXV];   //n为顶点数，MAXV为最大顶点数

int d[MAXV];    //起点到达各点的最短路径长度

bool vis[MAXV] = {false};   //标记数组，vis[i] == true 表示已访问。初值均为false

vector<Node> Adj[MAXV];

public:

// 邻接矩阵版
void dijkstra(int s){   //s 为起点

    fill(d, d + MAXV, INF); //fill函数将整个d数组赋为INF （慎用memset）

    d[s] = 0;   // 起点s到达自身的距离为0

    for (int i = 0; i < n;i++){  //循环n次
        int u = -1, MIN = INF;  //u使d[u]最小，MIN存放该最小的d[u]

        for (int j = 0; j < n; j++){    //找到未访问的顶点中 d[] 最小的

            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        // 找不到小于INF 的 d[u], 说明剩下的顶点和起点s不连通

        if(u == -1)
            return;
        vis[u] = true;  //标记u 为已访问

        for (int v = 0; v < n; v++){
            // 如果未访问&& u能达到v && 以u为中介点可以使d[v]更优
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
            }
        }
    }
}



//邻接表版
void dijkstra_vector(int s){  // s 为起点
    fill(d, d + MAXV, INF); // fill函数将整个d数组赋为INF

    d[s] = 0;   // 起点s 到达 自身 的距离 为 0

    for (int i = 0; i < n; i++){    //循环n次

        int u = -1, MIN = INF;  //u使d[u]最小，MIN 存放该最小的 d[u]

        for (int j = 0; j < n; j++){    //找到未访问的顶点中 d[] 最小的

            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }

        }

        // 找不到小于INF 的 d[u] ，说明剩下的顶点和起点 s 不连通
        if(u == -1)
            return;

        vis[u] = true;  //标记u为已访问

        // 只有下面这个for与邻接矩阵的写法不同
        for (int j = 0; j < Adj[u].size(); j++){
            int v = Adj[u][v].v;    //通过邻接表直接获得u能到达的顶点v

            if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]){
                
                //如果v未访问&&以u为中介点可以使d[v]更优
                d[v] = d[u] + Adj[u][j].dis; // 优化d[v]
            }
        }
    }
}


};



