#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    sort(S.begin(),S.end());
    if (S[0] == S[1] && S[1] == S[2]){
        cout << 1 << endl;
    }else if (S[0] == S[1] || S[1] == S[2]){
        cout << 3 << endl;
    }else{
        cout << 6 << endl;
    }
    return 0;
}