#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    string ans = "";
    ll N;
    cin >> N;
    vector<vector<ll>> Square(N,vector<ll>(N,0));
    for(int i = 0;i< N;i++){
        for(int j = 0;j<N;j++){
            cin >> Square[i][j];
        }
    }

    ll trace = 0;
    for(int i = 0;i< N;i++){
        trace += Square[i][i];
    }

    ll rows = 0;
    for(int i = 0;i< N;i++){
        set<ll> unique_ns;
        for(int j = 0;j<N;j++){
            if (unique_ns.find(Square[i][j]) == unique_ns.end()){
                unique_ns.insert(Square[i][j]);
            }else{
                rows++;
                break;
            }
        }
    }

    ll columns = 0;
    for(int i = 0;i< N;i++){
        set<ll> unique_ns;
        for(int j = 0;j<N;j++){
            if (unique_ns.find(Square[j][i]) == unique_ns.end()){
                unique_ns.insert(Square[j][i]);
            }else{
                columns++;
                break;
            }
        }
    }
    ans = to_string(trace) + " " + to_string(rows) + " " + to_string(columns);
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