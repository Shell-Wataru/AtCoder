#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
    string S;
    cin >> S;
    vector<ll> counts(10,0);
    if (S.size() <= 2){
        ll num_1 = stoll(S);
        reverse(S.begin(),S.end());
        ll num_2 = stoll(S);
        if (num_1 % 8 == 0 || num_2 % 8 == 0){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
        return 0;
    }
    for(auto c:S){
        counts[c-'0']++;
    }
    for(int i = 100;i < 1000;i++){
        if (i % 8 == 0){
            vector<ll> sub_counts(10,0);
            string s = to_string(i);
            sub_counts[s[0]-'0']++;
            sub_counts[s[1]-'0']++;
            sub_counts[s[2]-'0']++;
            bool is_ok = true;
            for(int j = 0;j < 10;j++){
                if (sub_counts[j] > counts[j]){
                    is_ok = false;
                    break;
                }
            }
            if (is_ok){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No" << "\n";
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;
    //   for (int i = 1; i <= t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}