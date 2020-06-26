#include <iostream>
using namespace std;

class QuickSort{

    private:

    void  sort(int * arr , int l , int r){

        if(l >= r){
            return;
        }

        int x = l ;

        int y = r;

        int data = arr[l]; // 保存的快排的第一个元素，把第一个位置空出来

        while( x < y){
            
            while(x < y && arr[y] > data){
                y--;
            }

            arr[x] = arr[y];

            while(x < y && arr[x] <= data){
                x++;
            }

            arr[y] = arr[x];
        }

        arr[x] = data;

        sort(arr, l, x - 1); // 对左区间进行排序

        sort(arr, x + 1, r); // 对右区间进行排序

    }

    public:

    QuickSort(int * arr , int length){

        int l = 0;
        int r = length - 1;

        sort(arr,l, r);

        for (int i = 0; i < length ; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }


};

int main(){

    int arr[] = {2, 1, 4, 2, 6, 8, 4, 32, 1, -3};

    QuickSort p(arr, 10); 

}