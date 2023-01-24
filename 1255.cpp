//
// Created by 86195 on 2023/1/24.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define maxn 500

struct Bigint{
    int len, a[maxn];//len记录位数， a记录每个数位
    Bigint(int x = 0){ //初始化使得这个大整数能够表示整形x，默认是0
        memset(a, 0, sizeof(a));
        for (len = 1; x; len++) {
            a[len] = x % 10, x /= 10;
        }
        len--;
    }
    int &operator[](int i){
        return a[i];    //重载[], 可以直接用x[i]代表x.a[i],编写时更加自然
    }
    void flatten(int L){
        //一口气处理1到L范围内的进位并重置长度。需要保证L不小于有效长度
        //相当于把不是一位数的位都处理成一位数，故取名”展平
        len = L;
        for (int i = 1; i <= len; ++i) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        for (;!a[len];){//重置长度成为有效长度
            len--;
        }
    }
    void print(){   //输出
        for (int i = max(len,1); i >= 1; i--) {
            printf("%d",a[i]);
        }
    }
};

/*
 * 两个Bigint类相加，返回一个Bigint类
 */
Bigint operator+(Bigint a, Bigint b){
    Bigint c;
    int len = max(a.len, b.len);
    for (int i = 1; i <= len; ++i) {
        c[i] += a[i] + b[i]; //计算贡献
    }
    c.flatten(len + 1); //答案不超过 len+1 位，所以用len+1 做一遍展平处理进位
    return c;
}

/*
 * 表示两个Bigint相乘
 * */
Bigint operator*(Bigint a, Bigint b){
    Bigint c;
    int len = a.len;
    for (int i = 1; i <= len; ++i) {
        c[i] = a[i] * b[i];//计算贡献
    }
    c.flatten(len + 11);//int最长10位，所以做一遍展平处理进位
    return c;
}

int n, cnt;

int main(){
    cin >> n;
    Bigint f[5010];
    f[1] = Bigint(1);
    f[2] = Bigint(2);
    for (int i = 3; i <= n; ++i) {
        f[i] = f[i - 2] + f[i - 1];
    }
    f[n].print();
    return 0;
}
