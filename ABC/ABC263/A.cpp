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
    ll L1,R1;
    ll L2,R2;
    map<ll,ll> a;
    for(int i = 0; i< 5;i++){
        ll b;
        cin >> b;
        a[b]++;
    }
    ll c = a.begin()->second;
    if (a.size() == 2 && (c == 2 || c == 3)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}