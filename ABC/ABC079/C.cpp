#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
        // 整数の入力
    string ABCD,plus,minus;
    plus = "+";
    minus = "-";
    long A,B,C,D;
    cin >> ABCD;
    A = ABCD[0] - '0';
    B = ABCD[1] - '0';
    C = ABCD[2] - '0';
    D = ABCD[3] - '0';
    if (A+B+C+D==7){
        cout << to_string(A) + plus + to_string(B) + plus + to_string(C) + plus + to_string(D) + "=7" << endl;
    }else if(A+B+C-D==7){
        cout << to_string(A) + plus + to_string(B) + plus + to_string(C) + minus + to_string(D)  + "=7"<< endl;
    }else if(A+B-C+D==7){
        cout << to_string(A) + plus + to_string(B) + minus + to_string(C) + plus + to_string(D)  + "=7"<< endl;
    }else if(A+B-C-D==7){
        cout << to_string(A) + plus + to_string(B) + minus + to_string(C) + minus + to_string(D) + "=7" << endl;
    } else if (A-B+C+D==7){
        cout << to_string(A) + minus + to_string(B) + plus + to_string(C) + plus + to_string(D) + "=7" << endl;
    }else if(A-B+C-D==7){
        cout << to_string(A) + minus + to_string(B) + plus + to_string(C) + minus + to_string(D) + "=7" << endl;
    }else if(A-B-C+D==7){
        cout << to_string(A) + minus + to_string(B) + minus + to_string(C) + plus + to_string(D) + "=7" << endl;
    }else if(A-B-C-D==7){
        cout << to_string(A) + minus + to_string(B) + minus + to_string(C) + minus + to_string(D) + "=7" << endl;
    }

    return 0;
}