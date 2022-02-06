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

string convert(string S)
{
    string ret;
    for(auto c:S){
        ret += c;
        if (ret.size() >= 3){

            if (ret.substr(ret.size()-3,3) == "ABC" || ret.substr(ret.size()-3,3) == "BCA" || ret.substr(ret.size()-3,3) == "CAB"){
                ret.pop_back();
                ret.pop_back();
                ret.pop_back();
            }
        }
    }
    return ret;
}
int main()
{
    // 整数の入力
    string S, T;
    ll N;
    cin >> N;
    cin >> S >> T;
    S = convert(S);
    T = convert(T);
    // cout << S << endl;
    // cout << T << endl;
    if (S == T)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}