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

ll f(ll x){
    return x*x + 2* x + 3;
}

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    cout << 111*(S[0]-'0') + 111*(S[1]-'0') + 111*(S[2]-'0') << endl;
    return 0;
}