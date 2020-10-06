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
#include <set>
using namespace std;
using ll = long long;

ll BASE_NUM = 1e9 + 7;

int main()
{
    // 整数の入力
    ll N,Q;
    cin >> N >> Q;
    vector<pair<ll,ll>> swaps;
    for(int i = 0;i < Q;i++){
        ll type;
        ll x,y;
        cin >> type;
        cin >> x >> y;
        if (type == 1){
            swaps.push_back({x,y});
        }else if (type == 2){
            while()
        }
    }
    return 0;
}