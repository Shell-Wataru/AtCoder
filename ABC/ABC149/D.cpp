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
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;


int main()
{
    // 整数の入力
    ll N,K,R,S,P;
    string T;
    cin >> N >> K;
    cin >> R >> S >> P;
    cin >> T;
    vector<vector<char>> data(K);
    for(int i = 0;i< N;i++){
        data[i % K].push_back(T[i]);
    }

    map<char,ll> scores{
        {'s',R},
        {'p',S},
        {'r',P},
        {'-',0}
    };
    ll count = 0;
    for(int i = 0;i< K;i++){
        char last_char = '-';
        ll char_continue = 0;
        for(auto c: data[i]){
            if (c == last_char){
                char_continue++;
            }else{
                count += (char_continue + 1)/2 * scores[last_char];
                last_char = c;
                char_continue = 1;
            }
        }
        count += (char_continue + 1)/2  * scores[last_char];
    }

    cout << count << endl;
    return 0;
}