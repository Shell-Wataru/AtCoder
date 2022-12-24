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

vector<ll> repeats(vector<ll> &to,ll k){
    if (k == 1){
        return to;
    }
    vector<ll> half = repeats(to,k/2);
    vector<ll> ans = half;
    for(int i = 0;i < ans.size();i++){
        ans[i] = half[ans[i]];
    }
    if (k % 2 == 1){
        for(int i = 0;i < ans.size();i++){
            ans[i] = to[ans[i]];
        }
    }
    return ans;
}
int main()
{
    ll N,M,D;
    cin >> N >> M >> D;
    vector<ll> from(N);
    vector<ll> to(N);
    iota(from.begin(),from.end(),0);
    for(int i = 0;i < M;i++){
        ll a;
        cin >> a;
        swap(from[a],from[a-1]);
    }
    for(int i = 0;i < N;i++){
        to[from[i]] = i;
    }
    vector<ll> ans = repeats(to,D);
    for(int i = 0;i < N;i++){
        cout << ans[i] + 1 << endl;
    }
    return 0;
}