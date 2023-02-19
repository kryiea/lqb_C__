//
// Created by 86195 on 2023/2/19.
//

#include <cstdio>
#include <algorithm>

using namespace std;

struct water{
    int num, time;
}p[1010];

//ʱ���� ���С
bool cmp(water a, water b){
    if(a.time != b.time){
        return a.time<b.time;
    }
    return a.num < b.num;
}

int n;
double sum = 0;

int main(){
    scanf("%d", &n);
    if(n == 0) return 0;
    for (int i = 1; i <=n; ++i) {
        scanf("%d", &p[i].time);//ʱ��
        p[i].num = i;//���
    }
    //����ʱ���ٵ���ǰ
    sort(p + 1, p + n + 1, cmp);

    for (int i = 1; i < n+1; ++i) {
        printf("%d ", p[i].num);
        sum += i * p[n-i].time;
    }
    printf("\n%.2lf\n",1.0 * sum / n);
    return 0;
}
