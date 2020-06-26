#include "stdlib.h"
#include "time.h"
#include <vector>
#include "SparseGraph.h"
using namespace std;
int main(){

    int N = 20;

    int M = 100;

    srand(time(NULL));

    SparseGraph g1(N, false);

    // 往邻接表中添加数据
    for (int i = 0; i < M; i++){
        int a = rand() % N;
        int b = rand() % N;
        g1.addEdge(a, b);
    }

    // 打印邻接表的数据
    for (int v = 0; v < N; v++){
        cout << v << " : ";
        SparseGraph::adjIterator adj(g1, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }

     // 从0开始遍历
    g1.BFS(0);

    // 从0 开始遍历
    g1.DFS(0);

    return 0;
}