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
    vector<pair<ll,ll>> A;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        if (i == 0){
            A.emplace_back(a,1);
        }else if (A.back().first == a){
            A.back().second++;
        }else{
            A.emplace_back(a,1);
        }
    }
    if (A.size() > 1 && A.front().first == A.back().first){
        A.front().second += A.back().second;
        A.pop_back();
    }
    if (A.size() == 1){
        cout << -1 << endl;
    }else{
        ll max_turns = 1;
        for(auto p: A){
            max_turns = max(max_turns, (p.second - 1)/2 + 1);
        }
        cout << max_turns << endl;
    }
   return 0;
}