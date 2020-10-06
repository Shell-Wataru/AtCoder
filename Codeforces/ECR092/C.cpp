#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    // cout << "==" << endl;
    string S;
    cin >> S;
    ll min_erases = numeric_limits<ll>::max();
    for(int i = 0; i < 10;i++){
        for(int j = 0;j < 10;j++){
            ll index = 0;
            ll erases = 0;
            for(int k = 0; k < S.size();k++){
                if (index % 2 == 0){
                    if (S[k] - '0' == i){
                        index++;
                    }else{
                        erases++;
                    }
                }else{
                    if (S[k] - '0' == j){
                        index++;
                    }else{
                        erases++;
                    }
                }
            }
            if (i != j && index % 2 == 1){
                erases++;
            }
            min_erases = min(min_erases,erases);
        }
    }
    cout << min_erases << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
