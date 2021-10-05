#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    string S,T;
    cin >> S >> T;
    ll ans = 0;
    deque<ll> ones;
    for(int i = 0;i < N;i++){
        if (S[i] == '1'){
            ones.push_back(i);
        }
    }
    for(int i = 0;i < N;i++){
        if (T[i] == '0'){
            if (ones.empty() || ones.front() != i){
                continue;
            }else{
                if (ones.size() < 2){
                    ans = -1;
                    break;
                }else{
                    ones.pop_front();
                    ll next_one = ones.front();
                    ones.pop_front();
                    ans += next_one - i;
                }
            }
        }else{
            if (ones.empty()){
                ans = -1;
                break;
            }else{
                ll next_one = ones.front();
                ones.pop_front();
                ans += next_one - i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}