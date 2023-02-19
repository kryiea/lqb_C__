//
// Created by 86195 on 2023/1/27.
//
#include <algorithm>
#include <cstdio>

using namespace std;

struct coin{
    int m,v;    //金币的重量和价值
}a[110];

bool cmp(coin x, coin y){
    return x.v * y.m > y.v * x.m; // 判断单价
};
int main(){
    int n, t, c, i;
    float ans = 0;
    scanf("%d%d",&n, &t);
    c = t; //背包的剩余容量
    for(i = 0; i < n; i++){
        scanf("%d%d",&a[i].m,&a[i].v);
    }
    sort(a,a+n, cmp);//对单价排序
    for(i = 0; i < n; i++){
        if(a[i].m > c) break;   //如果不能完整装下就跳出
        c -= a[i].m;
        ans += a[i].v;
    }
    if(i < n){
        ans += 1.0 * c / a[i].m * a[i].v; //剩余空间装下部分金币
    }
    printf("%.2lf",ans);
    return 0;
}