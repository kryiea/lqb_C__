//
// Created by 86195 on 2023/1/23.
//

#include "iostream"

using namespace std;

int main(){
    int a[1001] = {0}; //票箱：全部初始化0票
    int n,m,temp;

    cin >> n >> m;

    //记票
    for (int i = 1; i <= m; ++i) {
        cin >> temp;
        a[temp]++;
    }
    //排序 n2
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            cout << i <<' ';
        }
    }
    cout << endl;
    return  0;
}