#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

ll MAX_N = 1000000;
vector<ll> max_counts(MAX_N, 0);

string solve()
{
    ll N;
    cin >> N;
    vector<string> G(N);
    for(int i = 0; i < N;i++){
        cin >> G[i];
    }
    ll minimum_puts = numeric_limits<ll>::max();
    ll row_patterns = 0;
    ll column_patterns = 0;
    set<ll> unique_puts_positions;

    for(int i = 0;i < N;i++){
        ll puts = 0;
        set<ll> puts_positions;
        for(int j = 0;j < N;j++){
            if (G[i][j] == '.'){
                puts++;
                puts_positions.insert(N*i+j);
            }else if (G[i][j] == 'X'){
                continue;
            }else if (G[i][j] == 'O'){
                puts = numeric_limits<ll>::max();
                break;
            }
        }
        if (puts < minimum_puts){
            row_patterns = 1;
            minimum_puts = puts;
            unique_puts_positions = puts_positions;
        }else if (puts == minimum_puts){
            row_patterns++;
            unique_puts_positions.insert(puts_positions.begin(),puts_positions.end());
        }
    }
    for(int i = 0;i < N;i++){
        ll puts = 0;
        set<ll> puts_positions;
        for(int j = 0;j < N;j++){
            if (G[j][i] == '.'){
                puts++;
                puts_positions.insert(N*j+i);
            }else if (G[j][i] == 'X'){
                continue;
            }else if (G[j][i] == 'O'){
                puts = numeric_limits<ll>::max();
                break;
            }
        }
        if (puts < minimum_puts){
            column_patterns = 1;
            minimum_puts = puts;
            unique_puts_positions = puts_positions;
        }else if (puts == minimum_puts){
            column_patterns++;
            unique_puts_positions.insert(puts_positions.begin(),puts_positions.end());
        }
    }
    if (minimum_puts == numeric_limits<ll>::max()){
        return "Impossible";
    }else if (minimum_puts == 1){
        return "1 " + to_string(unique_puts_positions.size());
    }else{
        return "" + to_string(minimum_puts) + " " + to_string(row_patterns + column_patterns);
    }

}
int main()
{
    ll T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}