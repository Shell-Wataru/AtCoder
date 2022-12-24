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
    ll R,C;
    cin >> R >> C;
    vector<vector<ll>> A(2,vector<ll>(2));
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            cin >> A[i][j];
        }
    }
    cout << A[R-1][C-1] << endl;
    return 0;
}