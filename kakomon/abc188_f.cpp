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
#include <climits>
using namespace std;
using ll = long long;

map<ll,ll> cache;

ll count(ll X,ll Y){
    if (cache.find(Y) != cache.end()){
        return cache[Y];
    }else if (Y <= X){
        return X - Y;
    }else if ( Y % 2 == 0){
        ll ans1 = count(X,Y/2) + 1;
        ll ans2 = Y - X;
        cache[Y] = min(ans1,ans2);
        return cache[Y];
    }else{
        ll ans1 = count(X,Y+1) + 1;
        ll ans2 = count(X,Y-1) + 1;
        ll ans3 = Y - X;
        cache[Y] = min(ans1,min(ans2,ans3));
        return cache[Y];
    }
}

int main()
{
    ll X, Y;
    cin >> X >> Y;
    cout << count(X,Y) << endl;
    return 0;
}