//
// Created by 86195 on 2023/2/21.
//
/**
 *HEX，英文全称 Hexadecimal，表示十六进制。
 * DEC，英文全称 Decimal，表示十进制。
 * OCT，英文全称 Octal，表示八进制。
 * BIN，英文全称 Binary，表示二进制
 */

#include <iostream>

using namespace std;

int char_to_int(char a){
    return '0' <= a &&a <= '9' ? a-'0' : 10+a-'A';
}

char int_to_chat(int a){
    return  a<=9 ? '0'+a : a-10+'A';
}

int main(){
    int output[33];
    int n, m, dec = 0, num = 0;
    string input;
    cin >> n >> input >> m;
    //原数转为十进制：秦九韶算法（Horner法则）
    for (int i = 0; i < input.length(); ++i) {
        dec = dec * n + char_to_int(input[i]);
    }
    //转为m进制
    while (dec != 0){
        output[num++] = dec % m;
        dec /= m;
    }
    //输出转换好的数字
    for (int i = num -1; i >= 0 ; i--) {
        cout << int_to_chat(output[i]);
    }
    cout << endl;
    return 0;
}
