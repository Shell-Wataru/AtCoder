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

ll all_counts(ll n){
    if (n == 0){
        return 1;
    }else{
        return 2*all_counts(n-1) + 3;
    }
}

ll patty_counts(ll n){
    if (n == 0){
        return 1;
    }else{
        return 2*patty_counts(n-1) + 1;
    }
}

ll eat_patty_counts(ll n, ll x){
    if (x == 0){
        return 0;
    }else if (all_counts(n) == x){
        return patty_counts(n);
    }
    ll ans = 0;
    x -= 1;
    ans += eat_patty_counts(n-1,min(all_counts(n-1),x));
    x =max(0ll,x-all_counts(n-1));
    if (x > 0){
        ans++;
        x--;
    }
    ans += eat_patty_counts(n-1,min(all_counts(n-1),x));
    return ans;
}
int main(){
    ll N,X;
    cin >> N >> X;
    cout << eat_patty_counts(N,X) << endl;
    return 0;

}