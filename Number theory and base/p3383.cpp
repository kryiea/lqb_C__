//
// Created by 86195 on 2023/2/21.
//

#include <cstring>
#include <cstdio>

using namespace std;

#define maxn 10000010

int n, N, x;
bool a[maxn];

void Eratosthenes(int n, bool a[]){
    //寻找不超过 n 的所有质数，数组a[] 用来存放结果，用a[i] == 0 表示 a 是合数
    memset(a,0,sizeof(bool) * (n+1)); //清零
    a[0] = a[1] = 1; //0 和 1 需要特俗标记
    for (int i = 2; i*i <= n; i++){
        if(a[i] == 0)// 如果 i 未被之前的数筛去，说明 i 是质数
            for (int j = i << 1; j <= n; j += i) { // 左移 << 1 ，代表 i 的倍数
                a[j] = 1; //筛去 i 的所有倍数 i*J
            }
    }
}

int main(){
    scanf("%d",&N);

    a[0] = a[1] = 1; //0 和 1 需要特俗标记
    for (int i = 2; i*i <= n; i++){
        if(a[i] == 0)// 如果 i 未被之前的数筛去，说明 i 是质数
            for (int j = i << 1; j <= n; j += i) { // 左移 << 1 ，代表 i 的倍数
                a[j] = 1; //筛去 i 的所有倍数 i*J
            }
    }

    for (scanf("%d",&n); n--;) {
        scanf("%d", &x);
        if(a[x] == 0){
            printf("\n%d",x);
        }
    }

    return 0;
}