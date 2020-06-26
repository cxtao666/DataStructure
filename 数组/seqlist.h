/* 
 对于数组来说，起点位置是0
 对于线性表来说，起点位置是1
 */
#include <iostream>

using namespace std;

const int Max_Size = 1000;
/* 
public:
bool empty  判断是否为空
int length  返回长度
void insert(n,DataType item)  在n的位置插入 item 这个元素
DataType erase(n)   删除在n的元素
findIndex (n)  返回线性表下标是n 的元素
find (DataType item)   查找线性表中是否有值是item的元素
change(n,DataType item)   将下标是n的元素修改为 item
printf()   将数组元素打印出来
private:
length  长度
arr   数组
 */

template <typename T>
class Seqlist{

    public:
    Seqlist(){
        length = 0;
    }
    ~Seqlist(){

    }
    Seqlist(T data[], int n){

        if(n > Max_Size){
            throw "数据太多，无法存储";
        }

        for (int i = 0; i < n; i++){

            arr[i] = data[i];
        }

        length = n;
    }

    bool empty(){

        if(length == 0){
            return true;
        }

        return false;
    }

    int getLen (){
        return this->length;
    }

    void insert(int n , T item){

        if(length == Max_Size){
            throw "数据已满，无法存储";
        }

        if(n < 1 || n > length + 1){
            throw "插入位置有误";
        }

        for (int i = length ; i >= n ; i--){
            arr[i-1] = arr[i];
        }

        arr[n - 1] = item;

        length++;
    }

    T findIndex(int n){

         if(n < 1 || n > length ){
             throw "查询位置有误";
        }

        return arr[n - 1];

    }

    void printf(){

         for (int i = 0; i < length; i++){
             cout << arr[i] << " ";
        }
        cout << endl;
    }

    int find(T item){

        for (int i = 0; i < length; i++){
            if(arr[i] == item){
                return i + 1;
            }
        }

        return -1;
    }

    T change(int n , T item){

         if(n < 1 || n > length ){
             throw "修改位置有误";
        }

        T temp = arr[n - 1];
        arr[n - 1] = item;

        return temp;
    }

    T erase(int n){

          if(n < 1 || n > length ){
             throw "修改位置有误";
        }

         T temp = arr[n - 1];

         for (int i = n - 1; i < length - 1; i++)
         {
             arr[i] = arr[i + 1];
         }

         length--;
         
         return temp;

    }
    private:
        int length ;
        T arr[Max_Size];
};