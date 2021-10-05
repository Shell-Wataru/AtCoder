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
    string S;
    cin >> S;
    ll count_25 = 0;
    ll ans = 0;
    for(int i = 1;i < S.length();i++){
        if (S[i-1] == '2' && S[i] == '5'){
            count_25++;
        }else if (S[i-1] == '5' && S[i] == '2'){
            continue;
        }else{
            ans += count_25 * (count_25+1)/2;
            count_25 = 0;
        }
    }
    ans += count_25 * (count_25+1)/2;
    cout << ans << endl;
    return 0;
}