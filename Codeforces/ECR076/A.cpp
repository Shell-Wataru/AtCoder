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

int solve(){
    ll N,x,a,b,small,big;
    cin >> N>> x>> a>> b;
    small = min(a,b);
    big = max(a,b);
    ll zero_x = small - 1 + N - big;
    if (x >= zero_x){
        cout << N - 1 << endl;
    }else{
        cout << big - small + x << endl;
    }
    return 0;
};

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for(int i = 0;i<t;i++){
        solve();
    }
   return 0;
}