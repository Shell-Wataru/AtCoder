#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int answer(ll first,ll last,vector<ll> &intervals,vector<ll> &sums, ll x,ll y){
    ll a = min(first,x);
    ll b = min(last,y);
    auto iter = upper_bound(intervals.begin(),intervals.end(),x+y);
    ll c = sums[iter -intervals.begin()];
    ll d = (x+y) * (intervals.end() - iter);
    return a + b + c + d;
}
int main()
{
    // 整数の入力
    ll ALL, N, M;
    cin >> ALL >> N >> M;
    vector<ll> intervals;
    vector<ll> lines;
    ll first, last;
    for (int i = 0; i < N; i++)
    {
        ll l;
        cin >> l;
        lines.push_back(l);
    }
    first = lines[0] - 1;
    last = ALL - lines[lines.size() - 1];
    for (int i = 1; i < N; i++)
    {
        intervals.push_back(lines[i] - lines[i - 1] - 1);
    }
    sort(intervals.begin(), intervals.end());
    vector<ll> sums;
    sums.push_back(0);
    for(auto i:intervals){
        sums.push_back(sums.back() + i);
    }
    for(int i = 0;i<M;i++){
        ll x,y;
        cin >> x >> y;
        cout << answer(first,last,intervals,sums,x,y) + N << endl;
    }
    return 0;
}