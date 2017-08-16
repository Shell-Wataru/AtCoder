#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    if(S[0] == S[2]){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
    return 0;
}