
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <map>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    ll ans = 0;
    for(int i = 3; i  < S.size();i++){
        if (S[i-3] == 'Z' && S[i-2] == 'O' && S[i-1] == 'N' && S[i] == 'e'){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}