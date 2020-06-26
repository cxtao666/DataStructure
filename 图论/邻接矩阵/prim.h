
#include "DenseGraph.h"


const int INF = 100000000;

// 使用 prim 算法解决 最小生成树的问题
// 基于邻接矩阵版
// g 是邻接矩阵 
// 开辟一个d数组用于存储顶点和集合S的最短距离
// 开辟一个标记数组vis，用于判断是否已经被访问了

int DenseGraph::prim(){

    vector<int> d(g.size());

    vector<bool> vis(g.size());

    int len = g.size();

    for (int i = 0; i < len; i++){
        d[i] = INF;
    }

    for (int i = 0; i < len; i++){
        vis[i] = false;
    }


    // 0 号结点到自身的距离是0
    d[0] = 0;

    int ans = 0; // 用于存放最小生成树的边权之和

    // 因为总共有len个点需要访问
    for (int i = 0; i < g.size(); i++){

        int MIN = INF; // MIN 是距离最小的值

        int u = -1;  //u是距离最小的点的下标

        // 找到最小的d[u]的点
        for (int j = 0; j < len; j++)
        {
            if(d[j] < INF  && vis[j] == false){

                MIN = d[j];

                u = j;
            }
        }

        // 把最小的距离加到ans 里面
        ans = ans + MIN;

        // 找不到小于INF的d[u]，则剩下的顶点和集合S不联通
        if(u == -1){
            return -1;
        }

        
        // 表示u这个点已经被访问了
        vis[u] = true;

        // 遍历和u 相连接的点，并更新d[]数组
        for (int j = 0; j < g[u].size(); j++)
        {
            if (g[u][j] < d[j] && vis[j] != true && g[u][j] != INF)
            {
                d[j] = g[u][j];
            }

        }
    }
}