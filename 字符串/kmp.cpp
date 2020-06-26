#include <cstring>

int next[1000];

/// getNext求解长度为 next 的 字符串 s 的 next 数组
void getNext(char s [] , int len){

    int j = -1;

    next[0] = -1;   //初始化 j = next[0] = -1

    for (int i = 1; i < len; i++){  // 求解next[1] ~ next[len - 1]

    while( j  != -1 && s[i] != s[ j + 1]){
        j = next[i];   // 反复令 j = next[j]
    }  // 直到j 回退到-1 , 或是 s[i] == s[j + 1]

    if(s[i] == s[j + 1]){  //如果s[i] == s[j + 1]
        j++;  // 则next[i] = j + 1 , 先令 j 指向 这个 位置
    }

    next[i] = j; // 令next[i] = j ;

    }
}

// kmp 算法，判断pattern 是否是text的子串
bool KMP(char text[] , char pattern []){

    int n = strlen(text), m = strlen(pattern); // 字符串长度

    getNext(pattern, m);  // 计算pattern 的 next 数组

    int j = -1;  // 初始化 j 为 -1 , 表示当前没有任意一位被匹配

    for (int i = 0; i < n; i++){     // 试图匹配text[i]

        while( j != -1 && text[i] != pattern[ j + 1]){

            j = next[j]; // 不断回退，直到j回到-1 或 text[i] == pattern[j + 1]
        }

        if(text[i] == pattern[ j + 1]){
            j++;   //text[i] 与 pattern[j+ 1] 匹配成功，令 j 加 1
        }

        if(j == m -1){  // pattern完全匹配，说明pattern是text的子串
            return true;
        }

        return false; // 执行完text 还没有匹配成功，说明pattern 不是 text的子串

    }
}