#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    ll counter = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] != S[S.length()-1-i]){
            S[i] = S[S.length()-1-i];
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}