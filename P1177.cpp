//
// Created by 86195 on 2023/1/23.
//
#include "iostream"

using namespace std;

int n;

void qsort(int a[], int l, int r){
    int i = l, j = r, flag = a[(l + r) / 2],temp;
    do{
            while(a[i] < flag) i++;//从左找比flag大的数
            while(a[j] > flag) j--;//从右找比flag小的数
            if(i <= j){
                //交换
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++, j--;
            }
    }while(i <= j);

    if(l < j) qsort(a,l,j);
    if(i < r) qsort(a,i,r);

}

int main(){
    cin >> n;
    int a[n];


    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    //qsort
    qsort(a,0,n-1);

    for (int itm: a) {
        cout << itm << ' ';
    }
    cout <<endl;

}
