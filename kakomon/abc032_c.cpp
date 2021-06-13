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
    ll N,K;
    cin >> N >> K;
    vector<ll> s(N);
    bool contains_zero = false;
    for(int i = 0;i < N;i++){
        cin >> s[i];
        if (s[i] == 0){
            contains_zero = true;
        }
    }
    if (contains_zero){
        cout << N << endl;
        return 0;
    }
    if (K == 0){
        cout << 0 << endl;
        return 0;
    }

    ll l = 0;
    ll r = -1;
    ll total = 1;
    ll max_length = 0;
    while(r < N){
        if (total <= K){
            max_length = max(max_length, r-l+1);
            r++;
            if (r >= N){
                // cout << "!!" << endl;
                break;
            }
            total *= s[r];
        }else{
            total /= s[l];
            l++;
        }
    }
    cout << max_length << endl;
    return 0;
}