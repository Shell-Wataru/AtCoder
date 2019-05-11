#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <regex>
using namespace std;


int main()
{
    // 整数の入力
    string S,AC,WA;
    AC = "AC";
    WA = "WA";
    cin >> S;
    regex pt{"(W+)A"};
    sregex_iterator end;
    sregex_iterator ite{S.begin(), S.end(), pt};
    for (; ite != end ; ++ite) {
        smatch match = *ite;

        S[match.position()] = 'A';
        for (int i = 1; i < match.length();i++){
            S[match.position() + i] = 'C';
        }
    }

    cout << S << endl;

    return 0;
}