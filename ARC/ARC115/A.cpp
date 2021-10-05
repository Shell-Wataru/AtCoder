#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll N,M;
    cin >> N >> M;
    ll odd_count = 0;
    ll even_count = 0;
    ll ans = 0;
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        ll one_count = 0;
        for(int j = 0;j < M;j++){
            if (s[j] == '1'){
                one_count++;
            }
        }
        // cout << one_count << endl;
        if (one_count % 2 == 0){
            ans += odd_count;
            even_count++;
        }else{
            ans += even_count;
            odd_count++;
        }
    }
    cout << ans << endl;
    return 0;
}