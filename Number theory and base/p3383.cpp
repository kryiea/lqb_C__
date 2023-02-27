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
    //Ѱ�Ҳ����� n ����������������a[] ������Ž������a[i] == 0 ��ʾ a �Ǻ���
    memset(a,0,sizeof(bool) * (n+1)); //����
    a[0] = a[1] = 1; //0 �� 1 ��Ҫ���ױ��
    for (int i = 2; i*i <= n; i++){
        if(a[i] == 0)// ��� i δ��֮ǰ����ɸȥ��˵�� i ������
            for (int j = i << 1; j <= n; j += i) { // ���� << 1 ������ i �ı���
                a[j] = 1; //ɸȥ i �����б��� i*J
            }
    }
}

int main(){
    scanf("%d",&N);

    a[0] = a[1] = 1; //0 �� 1 ��Ҫ���ױ��
    for (int i = 2; i*i <= n; i++){
        if(a[i] == 0)// ��� i δ��֮ǰ����ɸȥ��˵�� i ������
            for (int j = i << 1; j <= n; j += i) { // ���� << 1 ������ i �ı���
                a[j] = 1; //ɸȥ i �����б��� i*J
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