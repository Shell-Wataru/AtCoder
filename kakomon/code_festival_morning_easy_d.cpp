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
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;



int main()
{
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> men(n);
    vector<ll> a(m);
    for(int i = 0;i < n;i++){
        cin >> men[i].first >> men[i].second;
    }

    for(int i = 0;i < m;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    sort(men.begin(),men.end());
    priority_queue<ll,vector<ll>,greater<ll>> q;
    ll ans = 0;
    ll men_index = 0;
    for(int i = 0;i < m;i++){
        while(men_index < n && men[men_index].first <= a[i]){
            q.push(men[men_index].second);
            men_index++;
        }
        while(!q.empty() && q.top() < a[i]){
            q.pop();
        }
        if (!q.empty()){
            q.pop();
            ans++;
        }
    }
    cout << ans << endl;
  return 0;
}
