#include <iostream>
#include <queue>

using namespace std;

class matrix {

    public:

    matrix(int (*arr)[4],int len){
        n2Arr = arr;
        this->len = len;
        Bfsblock = 0;
        Dfsblock = 0;
    }

    ~matrix(){
        delete n2Arr;
    }

    void bfs(int i , int j){

        queue< pair<int,int> > list;

        pair<int, int> q = make_pair(i, j);

        list.push(q);

        while(!list.empty()){

            int i, j;

            pair<int, int> data = list.front();
            
            list.pop() ;

            i = data.first;

            j = data.second;

            for (int a = 0; a < 4; a++)
            {

                if (i + x[a] >= 4 || i + x[a] < 0 || j + y[a] < 0 || j + y[a] >= len)
                {
                    continue;
                }

                if (n2Arr[i + x[a]][j + y[a]] > 0 && BFSarr[i + x[a]][j + y[a]] == false)
                {
                    BFSarr[i + x[a]][j + y[a]] = true;
                    pair<int, int> q = make_pair(i + x[a], j + y[a]);
                    list.push(q);
                }

        }

        }

       

    }

    // 遍历二维矩阵有多少块
   int   BFS(){

        BFSarr[len][4] = {false};

       for (int i = 0; i < len; i++){

           for (int j = 0; j < 4; j++){

              if(n2Arr[i][j] != 0 && BFSarr[i][j] == false){

                   bfs(i, j);
                 Bfsblock++;
              }
    
           }    
       }

       return Bfsblock;
    }

    int DFS(){

         DFSarr[len][4] = {false};

       for (int i = 0; i < len; i++){

           for (int j = 0; j < 4; j++){

              if(n2Arr[i][j] != 0 && DFSarr[i][j] == false){

                   dfs(i, j);
                 Dfsblock++;
              }
    
           }    
       }

       return Dfsblock;

    }

    void dfs(int i , int j){

              for (int a = 0; a < 4; a++)
            {

                if (i + x[a] >= 4 || i + x[a] < 0 || j + y[a] < 0 || j + y[a] >= len)
                {
                    continue;
                }

                if (n2Arr[i + x[a]][j + y[a]] > 0 && DFSarr[i + x[a]][j + y[a]] == false )
                {
                    DFSarr[i + x[a]][j + y[a]] = true;

                    dfs(i + x[a], j + y[a]);
                }

        }

    }


    private:
       int (*n2Arr)[4];
       int len;
       int x[4] = {0, 1, 0, -1};
       int y[4] = {1, 0, -1, 0};
       int Bfsblock ;
       int Dfsblock;
       bool BFSarr[1000][4];
       bool DFSarr[1000][4];
};
