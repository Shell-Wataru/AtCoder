#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;

string solve()
{
    ll E, W;
    cin >> E >> W;
    vector<ll> current_status = {0};
    vector<vector<ll>> current_stacks = {{}};
    for (int i = 0; i < E; i++)
    {
        // cout << "!!" << current_status.size() << endl;
        vector<ll> target(W);
        for (int j = 0; j < W; j++)
        {
            cin >> target[j];
        }
        vector<ll> new_stack;
        for (int k = 0; k < W; k++)
        {
            for (int l = 0; l < target[k]; l++)
            {
                new_stack.push_back(k);
            }
        }
        vector<vector<ll>> new_stacks;
        do
        {
            new_stacks.push_back(new_stack);
        } while (next_permutation(new_stack.begin(), new_stack.end()));
        vector<ll> next_status(new_stacks.size(),numeric_limits<ll>::max());
        for(int j = 0;j < current_stacks.size();j++){
            ll operations = current_status[j];
            for(int k = 0;k < new_stacks.size();k++){
                ll safe_stack = 0;
                for(int l = 0;l < min(current_stacks[j].size(),new_stacks[k].size());l++){
                    if (current_stacks[j][l] != new_stacks[k][l]){
                        break;
                    }else{
                        safe_stack++;
                    }
                }
                ll new_operations = operations  +(current_stacks[j].size() - safe_stack) + (new_stacks[k].size() -safe_stack);
                next_status[k] = min(next_status[k], new_operations);
            }
        }
        swap(current_status,next_status);
        swap(current_stacks,new_stacks);
    }
    ll ans = numeric_limits<ll>::max();
    for(auto v:current_status){
        ans = min(ans,(ll)(v + current_stacks[0].size()));
    }
    return to_string(ans);
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