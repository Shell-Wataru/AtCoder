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
    cin >>  N;
    vector<ll> ans;
    ll total = 0;
    for (size_t i = 1; i <= N; i++)
    {
        if (total + i < N){
            total += i;
            ans.push_back(i);
        }else if (total +i == N){
            ans.push_back(i);
            total+= i;
            break;
        }else{
            ll remain = N-total;
            for(int j = 0;j < remain;j++){
                ans[ans.size()-1-j]++;
            }
            break;
        }
    }
    for(auto a:ans){
        cout << a << "\n";
    }
    cout << flush;
    return 0;
}