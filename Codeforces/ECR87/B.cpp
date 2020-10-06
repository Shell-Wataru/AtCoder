#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    string S;
    cin >> S;
    vector<ll> last_one_index(S.length(),-1);
    vector<ll> last_two_index(S.length(),-1);
    vector<ll> last_three_index(S.length(),-1);
    ll min_length = BASE_NUM;
    for(int i = 0;i < S.length();i++){
        if (i > 0){
            last_one_index[i] = last_one_index[i-1];
            last_two_index[i] = last_two_index[i-1];
            last_three_index[i] = last_three_index[i-1];
        }
        if (S[i] == '1'){
            last_one_index[i] = i;
        }else if(S[i] == '2'){
            last_two_index[i] = i;
        }else if(S[i] == '3'){
            last_three_index[i] = i;
        }

        if (last_one_index[i] != -1 && last_two_index[i] != -1 && last_three_index[i] != -1){
            ll length = max(last_one_index[i],max(last_two_index[i],last_three_index[i])) - min(last_one_index[i],min(last_two_index[i],last_three_index[i])) + 1;
            min_length = min(min_length,length);
        }
    }
    if (min_length == BASE_NUM){
        cout << 0 << endl;
    }else{
        cout << min_length << endl;
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
