//
// Created by 86195 on 2023/1/2

#include <iostream>
#include <algorithm>

using namespace std;

struct Stu{
    int chinese;
    int english;
    int math;
    int sum;
    int num;
}stu[302];

bool cmp(Stu a, Stu b){
    if(a.sum != b.sum) return a.sum > b.sum;
    if(a.sum == b.sum && a.chinese != b.chinese) return a.chinese > b.chinese;
    else return a.num < b.num;
}


int main(){
    int stu_num;
    cin >> stu_num;
    //录入成绩
    for (int i = 1; i <= stu_num; ++i) {
        cin >> stu[i].chinese >> stu[i].math >> stu[i].english;
        stu[i].sum = stu[i].chinese + stu[i].math + stu[i].english;
        stu[i].num = i;

    }
    //按照总分排序
    sort(stu+1,stu + stu_num + 1, cmp);

    for (int i = 1; i <= 5; ++i) {
        cout << stu[i].num << ' ' << stu[i].sum << endl;
    }


    return 0;
}