#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    string s;
    cin >> s;
    vector<char> current;
    for(auto &c : s){
        if (current.empty()){
            current.push_back(c);
        }else{
            if (c == 'A'){
                current.push_back(c);
            }else{
                current.pop_back();
            }
        }
    }
    cout << current.size() << endl;
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
