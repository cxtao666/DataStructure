
// 实现一个二分查找
// 用递归实现和非递归实现

#include <iostream>

using namespace std;

class BinarySearch{

    private:
        int sign; // 用于标记是否找到了值的下标

    public:

    // 在 arr 数组当中，要查找的值是 x
    // arr 数组按从小到大的顺序排序
    BinarySearch(int * arr , int length , int x){

        sign = -1;

        int l = 0;
        int r = length - 1;

        RecursiveSearch(arr, l, r, x);

        search(arr, l, r , x);

      //  cout << sign << endl; 

        if(sign != -1 ){
            cout << "在" << sign << "找到了" << x << endl;
        }else{
            cout << "找不到" << endl;
        }

    }

    void  RecursiveSearch(int *arr , int l , int r , int x){

        if( l > r ){
            return;
        }

        int mid = (l + r) / 2;

        if(arr[mid] == x){
            sign = mid;
            return;
        }else if(arr[mid] > x){

            RecursiveSearch(arr, l , mid -1 , x);

        }else if(arr[mid] < x){

            RecursiveSearch(arr, mid + 1 , r , x);
        }

    }

    void search(int *arr , int l , int r , int x){

        while(l < r){

            int mid = (l + r) / 2;

            if(arr[mid] >= x){

                r = mid;

            }else {

                l = mid + 1;
            }
        } 

        if(arr[l] == x){
            sign = l;
        }  

    }

};

int main(){

    int arr[] = {2, 4, 6, 8, 34, 78, 99, 123};

    BinarySearch p(arr,8,6);

}