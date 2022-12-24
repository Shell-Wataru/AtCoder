#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> snuke(1000001,0);
    for(int i = 0;i < N;i++){
        ll a,b;
        cin >> a >> b;
        b++;
        snuke[a]++;
        snuke[b]--;
    }
    for(int i = 0;i < 1000000;i++){
        snuke[i+1] += snuke[i];
    }
    ll max_buyer = 0;
    for(int i = 0;i <= 1000000;i++){
        max_buyer = max(max_buyer,snuke[i]);
    }
    cout << max_buyer << endl;
    return 0;
}