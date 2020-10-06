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
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

int main()
{
    ll N,K;
    string S;
    cin >> N >> K;
    cin >> S;
    map<vector<ll>,ll> data;
    vector<ll> s(26,0);
    for(int i = 0;i < K;i++){
        // cout << S[i] - 'a' << endl;
        s[S[i] - 'a']++;
    }
    data[s] = K -1;
    bool is_clear = false;
    for(int i = K;i < N;i++){
        s[S[i - K] - 'a']--;
        s[S[i] - 'a']++;
        if (data.find(s) != data.end()){
            if (data[s] <= i - K){
                is_clear = true;
            }
        }else{
            data[s] = i;
        }
    }
    if (is_clear){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}