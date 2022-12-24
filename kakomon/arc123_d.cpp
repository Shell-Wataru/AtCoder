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

ll value(vector<ll> &B,vector<ll> &C, ll addition)
{
    ll total = 0;
    for(auto b:B){
        total += abs(b+addition);
    }
    for(auto c:C){
        total += abs(c-addition);
    }
    return total;
}


ll three_search(vector<ll> &B,vector<ll> &C, ll l, ll r)
{
    // cout << l << "~" << r << endl;
    if (l + 2 >= r)
    {
        vector<pair<ll, ll>> values;
        for (ll i = l; i < r; i++)
        {
            values.push_back({value(B, C, i), i});
        }
        sort(values.begin(), values.end());
        return values.front().second;
    }
    else
    {
        ll t1 = l + (r-l) / 3;
        ll t2 = l + 2*(r-l) / 3;
        ll t1_value = value(B, C, t1);
        ll t2_value = value(B, C, t2);
        // cout << t1 << ":" << t1_value << endl;
        // cout << t2 << ":" << t2_value << endl;
        if (t1_value <= t2_value)
        {
            return three_search(B, C, l, t2);
        }
        else
        {
            return three_search(B, C, t1, r);
        }
    }
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll total = 0;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        total += abs(A[i]);
    }
    ll current_b;
    ll current_c;
    if (A[0] >= 0){
        current_b = 0;
        current_c = A[0];
    }else{
        current_b = A[0];
        current_c = 0;
    }
    vector<ll> B = {current_b};
    vector<ll> C = {current_c};
    // cout << current_b << "," << current_c << endl;
    for(int i  = 1;i < N;i++){
        if (A[i] - A[i-1] >= 0){
            current_b += A[i] - A[i-1];
        }else{
            current_c += A[i] - A[i-1];
        }
        B.push_back(current_b);
        C.push_back(current_c);
        // cout << current_b << "," << current_c << endl;
    }
    ll addition = three_search(B,C,-total,total+1);
    // cout << addition << endl;
    cout << value(B,C,addition) << endl;
    return 0;
}