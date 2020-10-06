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
    ll n,x,m;
    string S;
    ll one_count = 0;
    ll zero_count = 0;
    cin >> S;
    for(int i = 0;i < S.length();i++){
        if (S[i] == '0'){
            zero_count++;
        }else{
            one_count++;
        }
    }
    if (min(zero_count,one_count) % 2 == 0){
        cout << "NET" << endl;
    }else{
        cout << "DA"  << endl;
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
