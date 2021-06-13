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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    ll H,W,M;
    cin >> H >> W >> M;
    vector<ll> yoko(H,numeric_limits<ll>::max());
    vector<ll> tate(W,numeric_limits<ll>::max());
    for(int i =0;i < M;i++){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        yoko[x] = min(yoko[x],y);
        tate[y] = min(tate[y],x);
    }

    return 0;
}