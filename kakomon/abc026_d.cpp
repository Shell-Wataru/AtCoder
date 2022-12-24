#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>

using namespace std;
using ll = long long;

double timing(ll A,ll B,ll C, double l,double r){
    double center = (l+r)/2;
    double value = A*center + B * sin(C* center * M_PI) - 100;
    // cout << value << endl;
    if (abs(value) < 1e-8){
        return center;
    }else if (value < 0){
        return timing(A,B,C,center,r);
    }else{
        return timing(A,B,C,l,center);
    }
}
int solve()
{
    ll A,B,C;
    cin >> A>> B>> C;
    cout << fixed << setprecision(12)<< timing(A,B,C,0,1000000000) << endl;
    return 0;
}

int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}
