#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000000;

string solve()
{
    ll N,L;
    cin >> N >> L;
    priority_queue<ll,vector<ll>,greater<ll>> left_q;
    priority_queue<ll,vector<ll>,greater<ll>> right_q;
    vector<pair<ll,ll>> ants(N);
    for(int i = 0;i < N;i++){
        ll p,d;
        cin >> p >> d;
        if (d == 0){
            left_q.push(p);
        }else{
            right_q.push(L-p);
        }
        ants[i] = {p,i+1};
    }
    sort(ants.begin(),ants.end());
    ll l = 0;
    ll r = N-1;
    string ans;
    while(left_q.size() + right_q.size() >= 1){
        if (left_q.empty()){
            ans += to_string(ants[r].second) + " ";
            r--;
            right_q.pop();
        }else if (right_q.empty()){
            ans += to_string(ants[l].second) + " ";
            l++;
            left_q.pop();
        }else if(left_q.top() < right_q.top()){
            ans += to_string(ants[l].second) + " ";
            l++;
            left_q.pop();
        }else if (left_q.top() > right_q.top()){
            ans += to_string(ants[r].second) + " ";
            r--;
            right_q.pop();
        }else if (ants[l].second < ants[r].second){
            ans += to_string(ants[l].second) + " ";
            l++;
            left_q.pop();
        }else{
            ans += to_string(ants[r].second) + " ";
            r--;
            right_q.pop();
        }
    }
    ans.pop_back();
    return ans;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}