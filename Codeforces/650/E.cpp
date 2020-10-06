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

    ll N,K;
    string S;
    scanf("%lld",&N);
    scanf("%lld",&K);
    cin >> S;
    sort(S.begin(),S.end());
    cout << S << endl;
    map<ll,ll> char_count;
    for(int i = 0;i < 26;i++){
        char_count[i] = 0;
    }
    for(auto c:S){
        char_count[c- 'a']++;
    }
    vector<pair<ll,ll>> char_counts;
    for(auto p: char_count){
        char_counts.emplace_back(p.second,p.first);
    }
    sort(char_counts.begin(),char_counts.end(),greater<pair<ll,ll>>());
    vector<ll> lengths(100,0);
    for(int i = 0;i < 26;i++){
        if (char_counts[i].first == 0){
            break;
        }
        ll length = 0;
        for(int j = 0;j <= i;j++){
            length += (char_counts[j].first/char_counts[i].first);
        }
        cout << i << ":" << length << endl;
        for(int j = 1;j <= length;j++){
            lengths[j] = max(lengths[j],j * char_counts[i].first);
        }
    }
    for(auto l:lengths){
        cout << l << endl;
    }
    ll ans = 0;
    for(ll i = 1;i <=K;i++){
        if (K % i == 0){
            ans = max(ans,lengths[i]);
            // cout << i << ":"<< ans << endl;
        }
    }
    cout << ans << endl;
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