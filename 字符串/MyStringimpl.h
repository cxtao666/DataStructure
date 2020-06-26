// size_t是一种无符号的整型数，它的取值没有负数，在数组中也用不到负数，而它的取值范围是整型数的双倍


/*
自己实现一个字符串的类

需要处理的内容
1.输入输出运算符重载
2.+号运算符重载  = 号运算符重载 == 号运算符重载  > < 判断大小 
3.普通构造函数  拷贝构造函数   析构函数
4. [] 数组下标重载
5. 获取长度
6. 字符串的子串的增删改查  
7. 使用kmp 算法实现子串的匹配
9. 字符串长度的处理
10. 清空字符串
11. char 数组和string 之间的转换
*/

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

class myString
{
    // 友元
    friend std::ostream &operator<<(std::ostream &out, myString &str);
    friend std::istream &operator>>(std::istream &in, myString &str);

public:
    myString();
    myString(const myString &str);
    myString(myString &str, size_t pos, size_t len);
    myString(const char *s);
    ~myString();
    // 清空string 的数据
    void clear() ;

    //const char *end() const;
    //const char *begin() const;

    // 返回字符串的首字符地址,字符串转 char *数组

    char* c_str() const;
    size_t length() const ;

    //进行查找BF
    const int find( myString &w) ;

    // 使用kmp 算法进行快速查找
    const int fastfind(const myString &w);

    char &operator[](size_t pos);

   // const char &operator[](size_t pos) const;
    myString &operator=(const myString &str);
    myString &operator=(const char *s);
    myString operator+(const myString &str);
    myString operator+(const char *s);
    myString operator+(char c);

    // 在pos 的位置插入 字符串 str
    void insert(size_t pos,const myString &str);

    bool operator==(const myString &str);

    // 删除一个区间内的字符串 
    void erase(size_t pos,size_t length);

    // 截取子字符串
    myString substr(size_t pos,size_t length) ;


    // 进行字符串替换
    myString replace(size_t pos,size_t length ,const myString &str);

    // 判空
    bool empty() const;

    //字符串分割
    vector<myString> split(const myString& delim);

private:
    //用于保存字符串,指向char 数组
    char *m_data;
};

#endif