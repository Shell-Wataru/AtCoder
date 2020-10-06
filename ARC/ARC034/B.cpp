#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;


int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> ans;
    for(int i = 0;i < 9*20;i++){
        ll x = N - i;
        ll sum = 0;
        string s = to_string(x);
        for(auto c:s){
            sum += c - '0';
        }
        if (sum + x == N){
            ans.push_back(x);
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for(auto s:ans){
        cout << s << endl;
    }
    return 0;
}