#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int solve()
{

    ll N;
    cin >> N;
    vector<pair<ll,ll>> A(N);
    for (size_t i = 0; i < N; i++)
    {
        scanf("%lld",&A[i].first);
        scanf("%lld",&A[i].second);
    }
    ll count = 0;
    sort(A.begin(),A.end(),[](pair<ll,ll> &l,pair<ll,ll> &r ){
        if (l.first == r.first){
            return l.second > r.second;
        }else{
            return l.first < r.first;
        }
    });
    vector<pair<ll,ll>> s;
    for(int i = 0;i < N;i++){
        while(!s.empty() && s.back().second < A[i].first){
            s.pop_back();
        }
        if (s.empty() || A[i].second <= s.back().second){
            // cout << A[i].first << "~" <<A[i].second << endl;
            count++;
            s.push_back(A[i]);
        }
    }
    cout << count << endl;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}