#include <iostream>
#include <string>
using namespace std;
 
class CMyString {
public:
    CMyString(char * pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    // 返回类型为引用，才可以连续赋值；传入的参数设为const，减少复制构造函数的调用。
    CMyString& operator = (const CMyString& str);
    void Print();
private:
    char* m_pData;
};
 
CMyString::CMyString(char* pData) {
    if(pData == NULL) {
        m_pData = new char[1];
        m_pData = '\0';
    }
    else {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString :: ~CMyString() { delete []m_pData;}

CMyString& CMyString::operator= (const CMyString& str) {
    if(this == &str) return *this;
    delete []m_pData;
    m_pData = NULL;
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}
 
void CMyString::Print() { cout << m_pData << endl;}

void test1() { //普通赋值
    cout << "****test1:**** " << endl;
    CMyString str1("hello world");
    CMyString str2;
    str2 = str1;
    cout << "赋值后应该是：" <<endl;;
    str1.Print();
    cout << "赋值后实际是：" <<endl;
    str2.Print();
}
 
void test2() { //自身赋值
    cout << "****test2: ****" << endl;
    char *text = "my name is lmm";
    CMyString str1(text);
    str1 = str1;
    cout << "赋值后应该是：" <<endl;
    cout << text << endl;
    cout << "赋值后实际是：" << endl;
    str1.Print();
}
 
void test3() { //连续赋值
    cout << "****test3: ****" << endl;
    CMyString str1("lucky dog");
    CMyString str2, str3;
    str3 = str2 = str1;
    cout << "连续赋值后应该是：" ;
    str1.Print();
    cout << "连续赋值后str2 是：" <<endl;
    str2.Print();
    cout << "连续赋值后str3 是：" <<endl;
    str2.Print();
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}