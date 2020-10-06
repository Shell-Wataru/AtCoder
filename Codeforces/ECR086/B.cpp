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
    string T;
    cin >> T;
    bool all_zero = all_of(T.begin(),T.end(),[](char a){return a == '0';});
    bool all_one = all_of(T.begin(),T.end(),[](char a){return a == '1';});
    if (all_zero || all_one){
        cout << T << endl;
    }else{
        for(int i = 0;i < 2 * T.size();i++){
            if (i % 2 == 0){
                cout << '0';
            }else{
                cout << '1';
            }
        }
        cout << endl;
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
