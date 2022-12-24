

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
    ll N,Q;
    cin >> N >> Q;
    vector<vector<ll>> A(N);
    for(int i = 0;i < N;i++){
        ll l;
        cin >> l;
        for(int j = 0;j < l;j++){
            ll a;
            cin >> a;
            A[i].push_back(a);
        }
    }
    for(int i = 0;i < Q;i++){
        ll s,t;
        cin >> s >> t;
        s--;t--;
        cout << A[s][t] << endl;
    }
    return 0;
}