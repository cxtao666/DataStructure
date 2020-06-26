// 稀疏图
// 采用邻接表实现
#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

// 处理 自环边的问题
class SparseGraph{

    private:
        int n, m;
        bool directed;
        vector<vector<int> > g;
         int * arr ;  // 标记数组

        public:

         // 清空标记数组
        void clearSign(){

         for (int i = 0; i < n; i++){
                arr[i] = 0;
            }
        }

        SparseGraph(int n , bool directed){

           arr = new int[n];

            clearSign();

            this->n = n;
            this->m = 0;
            this->directed = directed;

            for (int i = 0; i < n; i++){
                g.push_back(vector<int>());
            }

        }
        ~SparseGraph(){
            delete[] arr;
        }

        int V() { return n; }

        int E() { return m; }

        // 添加关系
        void addEdge(int v, int w){

            assert(v >= 0 && v < n);

            assert(w >= 0 && w < n);

            g[v].push_back(w);

            // 自环边处理
            if( v != w && !directed){
                g[w].push_back(v);
            }

            m++;
        }


       // 平行边的处理
        bool hasEdge(int v , int w){

            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);

            for (int i = 0; i < g[v].size(); i++){
                if(g[v][i] == w)
                    return true;
                return false;
            }
        }

        // 迭代器
        class adjIterator{

            private:
                SparseGraph &G;
                int v;
                int index;

            public:
                adjIterator(SparseGraph &graph, int v) :G(graph) {
                    this->v = v;
                    this->index = 0;
                }

                int begin(){
                    index = 0;
                    if(G.g[v].size())
                        return G.g[v][index];
                    return -1;
                }

                int next(){
                    index++;
                    if(index < G.g[v].size())
                        return G.g[v][index];
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
    
                        if(arr[g[index][i]] == 0){
                           
                            dfs(g[index][i]);
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
                        
                        if(arr[g[num][i]] == 0){
                             arr[g[num][i]] = 1;
                            list.push(g[num][i]);
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