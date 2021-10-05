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
#include <stack>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    if (N == 0){
        cout << 0 << endl;
        return 0;
    }
    ll base = 1;
    vector<ll> ans;
    while(N != 0){
        if (N % 2 == 1 || N % 2 == -1){
            ans.push_back(1);
            N -= base;
        }else{
            ans.push_back(0);
        }
        N /= 2;
        base *= -1;
    }

    reverse(ans.begin(),ans.end());
    for(auto a:ans){
        cout << a;
    }
    cout << endl;
    return 0;
}