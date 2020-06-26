// 稠密图 
// 采用邻接矩阵

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

const int INF = 100000000;

// 处理邻接矩阵
class DenseGraph{

    private:
        int n, m;   // n判断二维矩阵的长和宽
        // m 用于判断关系的数量
        bool directed; // 判断图是不是有向图
        vector<vector<int> > g;
        int * arr ;  // 标记数组

    public :

    // 使用prim 算法求最小生成树
        int prim();

    // 使用kruskal 算法求最小生成树
        int kruskal();

        // 清空标记数组
        void clearSign(){

         for (int i = 0; i < n; i++){
                arr[i] = 0;
            }
        }


        DenseGraph(int n , bool directed){

            // 初始化标记数组
            arr = new int[n];

            clearSign();

            this->n = n;
            this->m = 0;
            this->directed = directed;

            for (int i = 0; i < n; i++){
                g.push_back(vector<int>(n, INF));
            }

        }

        ~DenseGraph(){
            delete [] arr;
        }

        int V(){
            return n;
        }

        int E(){
            return m;
        }

        // 添加关系
        void addEdge(int v,int w , int num ){

            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);

            if(hasEdge(v,w)){
                return;
            }

            g[v][w] = num;

            if(!directed){
                g[w][v] = num;
            }

            m++;
        }

        // 判断关系是否存在
        bool hasEdge(int v , int w){
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);

            if(g[v][w] != INF){
                return true;
            }

            return false;
        }
        

        // 实现迭代器
         class adjIterator{

            private:
                DenseGraph &G;
                int v;
                int index;

            public:
                adjIterator(DenseGraph &graph, int v) :G(graph) {
                   

                    this->v = v;
                    this->index = -1;
                }

                int begin(){
                    index = -1;
                    return next();
                }

                int next(){

                    for (index += 1; index < G.V(); index++)
                    if(G.g[v][index])
                        return index;
                    return -1;
                }

                bool end(){
                    return index >= G.g[v].size();
                }
         };

         private:
        // 使用dFS对图进行遍历     
        void dfs(int index){

            // 显示dfs 遍历图的顺序
            cout << index << " ";
            
             arr[index] = 1;

            for (int i = 0; i < g[index].size(); i++){

                    if(g[index][i] != INF){
                        
                        if(arr[i] == 0){
                           
                            dfs(i);
                        }
                       
                    }
            }
        }
            // 使用 BFS 对图进行遍历
        void bfs(int index){

            queue<int> list;

            list.push(index);

            arr[index] = 1;

            while(list.size()){

                int num = list.front();

                list.pop();
                     
                // 打印遍历的元素
                cout << num << " ";

                for (int i = 0; i < g[num].size(); i++){

                         if(g[num][i] != INF){
                        
                        if(arr[i] == 0){
                             arr[i] = 1;
                            list.push(i);
                        }
                       
                    }
                }
                
            }

        }

        public:
        void DFS(int index){

            clearSign();
            dfs(index);
            cout << endl;
        }

        void BFS(int index){
           clearSign();
            bfs(index);
            cout << endl; 
        }

};