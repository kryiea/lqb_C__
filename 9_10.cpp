//
// Created by 86195 on 2023/2/27.
//
#include <valarray>
#include <iostream>
#include <queue>

using namespace std;

int convert2ten(int a, int num){
    //a 转 10 进制
    int ys = 0;
    int res = 0;
    int cont = 0;
    while(num != 0){
        ys = num % 10;
        num /= 10;
        res += ys * pow(a,cont++);
    }
    return res;
}

int convert10b(int b, int num){
    queue<int> mod;
    int ys = 0 ;
    int cont = 0;
    int res = 0;

    while(num != 0){
        ys = num % b;
        num = num / b;
        mod.push(ys);
    }

    while (!mod.empty()){
        ys = mod.front();
        res += ys * pow(10,cont++);
        mod.pop();
    }
    return res;
}

int main(){
    int x,a,b;

    cin >> a >> x >> b;

    cout << convert10b(b,convert2ten(a,x)) ;

    return 0;
}
