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
    S.replace(3,1,"8");
    cout << S << endl;
    return 0;
}