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
ll BASE_NUM =  1000000007;

ll solve(ll l,ll r,ll target){
    if (l + 1 == r){
        return r;
    }
    ll center = (l+r)/2;
    // cout << center << " " << target << endl;
    if (center * (center+ 3) < target){
        return solve(center,r,target);
    }else{
        return solve(l,center,target);
    }
};

int main()
{
    ll N,K;
    cin >> N >> K;
    cout << N - solve(0,BASE_NUM,2 * (N+K)) << endl;

    return 0;
}