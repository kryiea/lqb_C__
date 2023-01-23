#include <iostream>
#include "cmath"

#define max_n 520

using namespace std;

int a[max_n],b[max_n],c[max_n];

int main() {
    string A, B;
    cin >> A >> B;

    int len = max(A.length(),B.length());
    
    //存进数组
    for(int i = A.length()-1, j = 1; i>=0; i--,j++){
        a[j] = A[i] - '0';
    }
    for(int i = B.length()-1, j = 1; i>=0; i--,j++){
        b[j] = B[i] - '0';
    }

    //加法运算
    for (int i = 1; i <= len; ++i) {
        c[i] += a[i] + b[i];
        c[i+1] = c[i] / 10;//模拟进位。有则下一位加1
        c[i] %= 10;//一律取一次 个位
    }
    if(c[len+1]) len++;

    for (int i = len; i >= 1; i--) {
        cout << c[i];

    }
    

    return 0;
}
