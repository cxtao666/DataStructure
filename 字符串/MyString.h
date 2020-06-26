#include "MyStringimpl.h"

 char* myString::c_str() const{

    return this->m_data;
}

myString::myString(const char *s){

    if(strlen(s) == 0){
        this->m_data = NULL;
    }else{
         this->m_data = new char[strlen(s)+1];
         strcpy(this->m_data,s);
    }

    }

    myString::myString(){

        this->m_data = NULL;
    }
    

myString::myString(const myString &str){

    if(str.m_data == NULL){
        this->m_data = NULL;
        return;
    }

    this->m_data = new char[strlen(str.m_data)+1];
    strcpy(this->m_data,str.m_data);
    
}

myString:: myString( myString &str, size_t pos, size_t len){

        
    if(str.m_data == NULL){
        this->m_data = NULL;
        return;
    }

     this->m_data = new char[len+1];

    myString s = str.substr(pos, len);

    strcpy(this->m_data,s.m_data);
}

myString myString::substr(size_t pos,size_t length){

    if(m_data == NULL){
        throw "字符串没有赋值";
    }

    int j = pos;

    myString s;

    s.m_data = new char[length + 1];

    int i;

    for (i = 0; i < length; i++){
        s.m_data[i] = m_data[j++];
    }

    s.m_data[length] = '\0';

    return s;
}

myString::~myString(){
    delete m_data;
    m_data = NULL;
}

void myString::clear(){
     delete m_data;
    m_data = NULL;
}

size_t myString::length() const{

    return strlen(m_data);
}

const  int myString::find( myString &w) {

    for (int i = 0; i < strlen(m_data); i++)
    {
        int k = i;
        bool sign = true;
        for (int j = 0; j < strlen(w.m_data); j++){

            if(m_data[k++] != m_data[j]){
                sign = false;
                break;
            }
        }

        if(sign){
            return i;
        }
    }

    return -1;
}

void ComputePrefix(myString s,int next[]){
    int n = s.length();
    int q,k;
    next[0] = 0;
    for(k=0,q=1;q<n;q++){
        while(k>0 && s[k]!=s[q])
            k = next[k];
        if(s[k]==s[q])
            k++;
        next[q] = k;
    }
}

const int myString::fastfind(const myString &w){

     int n = length();
    int m = w.length();
    int next[w.length()];
    ComputePrefix(w , next);

    for(int i=0,q=0;i<n;i++) {
        while(q>0 && w.m_data[q] != m_data[i])
            q = next[q];
        if(w.m_data[q]==m_data[i])
            q++;
        if(q==m)
        {
            return i-m+1 ;
            q=0;
        }
    }

    return -1;
}

 bool myString::empty() const{

     if(m_data == NULL){
         return true;
     }else{
         return false;
     }
 }

char& myString::operator[](size_t pos){

    if(empty() || pos > strlen(m_data)){
        throw "is wrong";
    }

    return m_data[pos];
}


    myString & myString::operator=(const myString &str){

      m_data = new char[strlen(str.m_data) + 1]  ;

      strcpy(m_data, str.m_data);

      return *this;

}
    myString & myString::operator=(const char *s){

         m_data = new char[strlen(s) + 1]  ;

      strcpy(m_data, s);

      return *this;


    }

    // + 号有bug
    myString  myString::operator+(const myString &str){

        myString newString;

        newString.m_data = new char[strlen(this->m_data) + strlen(str.m_data) + 1];

        strcpy(newString.m_data, m_data);

        int j = 0;

        for (int i = strlen(this->m_data); i < strlen(this->m_data) + strlen(str.m_data);i++){

            newString[i] = str.m_data[j++];
        }

        newString[strlen(this->m_data) + strlen(str.m_data)] = '\0';

        return newString;
    }
    myString myString::operator+(const char *s){

           myString newString;

        newString.m_data = new char[strlen(this->m_data) + strlen(s) + 1];

        strcpy(newString.m_data, m_data);

        int j = 0;

        for (int i = strlen(this->m_data); i < strlen(this->m_data) + strlen(s);i++){

            newString[i] = s[j++];
        }

        newString[strlen(this->m_data) + strlen(s)] = '\0';

        return newString;

    }
    myString  myString::operator+(char c){
           myString newString;

        newString.m_data = new char[strlen(this->m_data) + 2];

        strcpy(newString.m_data, m_data);

        newString[strlen(this->m_data)] = c;

        newString[strlen(this->m_data) + 1] = '\0';

        return newString;

    }

    bool  myString::operator==(const myString &str){

        if( strcmp(m_data, str.m_data) == 0){
            return true;
        }
        return false;
    }

    void myString::insert(size_t pos,const myString &str){

        char *s = new char[strlen(str.m_data) + strlen(m_data) + 1];

        for (int i = 0; i < pos; i++){

            s[i] = m_data[i];
        }

        int j = pos;

        for (int i = 0; i < strlen(str.m_data); i++){

            s[j++] = str.m_data[i];
        }

        for (int i = pos ; i < strlen(m_data); i++){

            s[j++] = m_data[i];

        }

        s[j++] = '\0';

        delete m_data;

        m_data = s;
    }

    void myString::erase(size_t pos,size_t length){

        char *s;

        if( (pos + length) > strlen(m_data)){
               s = new char[ pos + 1];

        }else{

             s = new char[  strlen(m_data) + 1 - length];
        }

        for (int i = 0; i < pos;i++){
            s[i] = m_data[i];
        }

        int j = pos;

        for (int i = pos + length; i < strlen(m_data);i++){
            s[j++] = m_data[i];
        }

        s[j] = '\0';

        delete m_data;
        m_data = s;
    }

    myString myString::replace(size_t pos,size_t length , const myString &str){

        myString s;

        s.m_data = new char[strlen(m_data) + 1];

        for (int i = 0; i < strlen(m_data); i++){
            s.m_data[i] = m_data[i];
        }
        int j = 0;

        for (int i = pos; i < pos + length; i++){
            s.m_data[i] = str.m_data[j++];
        }

        return s;
    }

    // 有bug "" 这样无法分割
    vector<myString> myString::split(const myString& delim){

      char * p = strtok(m_data, delim.m_data);

      vector<myString> res;

      while (p)
      {
         
          myString s = p;   //分割得到的字符串转换为string类型
          res.push_back(s); //存入结果数组
          p = strtok(NULL, delim.m_data);
	}

     return res;
    }

    // 使用友元
    // bug  cout << s.replace(0, 3,"zzz") << endl; 这样不行
    // cout << s.replace(0, 3,"zzz").c_str() << endl;  这样行
    std::ostream &operator<<(std::ostream &out, myString &str){
        out << str.c_str() ;
        return out;
    }

    std::istream &operator>>(std::istream &in, myString &str){
        char *s = new char [1000];
        in >> s;
        str = s;
        return in;
    }