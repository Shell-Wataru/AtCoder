#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

struct compass_neighbor
{
    ll x, y, value;
};

string solve()
{
    ll N,D;
    cin >> N >> D;
    vector<ll> A;
    map<ll,map<ll,ll>> DATA;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        A.push_back(a);
        ll powers = 0;
        while(a % 2 == 0){
            a = a/2;
            powers++;
        }
        DATA[a][powers]++;
    }
    ll min_cuts = 10000000000ll;
    for(auto p:DATA){
        ll head = p.first;
        ll power = (*p.second.begin()).first + 1;
        ll serves = 0;
        while(serves < D){
            power--;
            serves = 0;
            for(auto a:A){
                serves += (a>>power)/head;
            }
        }

        ll cuts = 0;
        ll remain_d = D;
        for(auto pp:p.second){
            ll one_d = 1<<(pp.first-power);
            ll uses = min(remain_d/one_d,pp.second);
            cuts += one_d * uses - uses;
            remain_d -= one_d * uses;
        }
        cuts += remain_d;
        min_cuts = min(min_cuts,cuts);
    }
    return to_string(min_cuts);
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