//
// Created by 86195 on 2023/2/21.
//
/**
 *HEX��Ӣ��ȫ�� Hexadecimal����ʾʮ�����ơ�
 * DEC��Ӣ��ȫ�� Decimal����ʾʮ���ơ�
 * OCT��Ӣ��ȫ�� Octal����ʾ�˽��ơ�
 * BIN��Ӣ��ȫ�� Binary����ʾ������
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
    //ԭ��תΪʮ���ƣ��ؾ����㷨��Horner����
    for (int i = 0; i < input.length(); ++i) {
        dec = dec * n + char_to_int(input[i]);
    }
    //תΪm����
    while (dec != 0){
        output[num++] = dec % m;
        dec /= m;
    }
    //���ת���õ�����
    for (int i = num -1; i >= 0 ; i--) {
        cout << int_to_chat(output[i]);
    }
    cout << endl;
    return 0;
}
