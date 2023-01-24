//
// Created by 86195 on 2023/1/23.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;
    int a[n+1];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a,a+n);
    cnt = unique(a,a+n) - a;

    cout << cnt << endl;

    for (int i = 0; i < cnt; ++i) {
        cout << a[i] << ' ';

    }

    return 0;
}
