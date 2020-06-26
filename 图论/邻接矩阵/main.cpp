
#include "stdlib.h"
#include "time.h"
#include <vector>
#include "DenseGraph.h"
using namespace std;
int main(){

    int N = 20;

    int M = 100;

    srand(time(NULL));

    // 不是有向图
    DenseGraph g2(N, false);

    for (int i = 0; i < M; i++){
        int a = rand() % N;
        int b = rand() % N;
        int c = rand() % 1000;
        g2.addEdge(a, b, c);
    }

    // 打印出邻接矩阵
     for (int v = 0; v < N; v++){

        cout << v << " : ";

        DenseGraph::adjIterator adj(g2, v);

        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }
    cout << endl;

    // 从0开始遍历
    g2.BFS(0);

    // 从0 开始遍历
    g2.DFS(0);

    return 0;
}