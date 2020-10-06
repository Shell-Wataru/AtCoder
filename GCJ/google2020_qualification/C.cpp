#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

struct work{
    ll start,end,index;
    char assginee;
};

string solve(){
    ll N;
    cin >> N;
    vector<ll> occupyed_count(24 * 60 + 1);
    vector<work> works(N);
    for(int i = 0;i < N;i++){
        work w;
        cin >> w.start >> w.end;
        w.index = i;
        occupyed_count[w.start]++;
        occupyed_count[w.end]--;
        works[i] = w;
    }

    bool cannnot = false;
    for(int i = 1;i<= 24*60;i++){
        occupyed_count[i] += occupyed_count[i-1];
        if (occupyed_count[i] > 2){
            cannnot = true;
        }
    }

    if(cannnot){
        return "IMPOSSIBLE";
    }else{
        sort(works.begin(),works.end(),[](work &a, work &b){
            return a.start < b.start;
        });
        ll j_ends = 0;
        ll c_ends = 0;
        for(int i = 0;i < N;i++){
            if (j_ends <= works[i].start){
                works[i].assginee = 'J';
                j_ends =works[i].end;
            }else{
                works[i].assginee = 'C';
                c_ends =works[i].end;
            }
        }

        sort(works.begin(),works.end(),[](work &a, work &b){
            return a.index < b.index;
        });
        string ans  = "";
        for(int i = 0;i < N;i++){
            ans += works[i].assginee;
        }
        return ans;
    }
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