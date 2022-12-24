#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

int solve()
{
    ll n,q;
    string S;
    cin >> n >> S >> q;
    for(int i = 0;i < q;i++){
        ll k;
        cin >> k;
        ll a_count = 0;
        ll b_count = 0;
        ll c_count = 0;
        ll ab_count = 0;
        ll abc_count = 0;
        for(int j = 0;j < k;j++){
            if (S[j] == 'D'){
                a_count++;
            }else if (S[j] == 'M'){
                b_count++;
                ab_count += a_count;
            }else if (S[j] == 'C'){
                c_count++;
                abc_count += ab_count;
            }
        }
        for(int j = k;j < n;j++){
            if (S[j-k] == 'D'){
                a_count--;
                ab_count -= b_count;
            }else if (S[j-k] == 'M'){
                b_count--;
            }else if (S[j-k] == 'C'){
                c_count--;
            }
            if (S[j] == 'D'){
                a_count++;
            }else if (S[j] == 'M'){
                b_count++;
                ab_count += a_count;
            }else if (S[j] == 'C'){
                c_count++;
                abc_count += ab_count;
            }
        }
        cout << abc_count << endl;
    }
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
