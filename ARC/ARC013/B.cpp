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
    long long N;
    ll max_a = 0,max_b = 0,max_c =0;
    cin >> N;
    for(int i = 0;i < N;i++){
        ll a,b,c;
        vector<ll> box;
        cin >> a >> b >> c;
        box.push_back(a);
        box.push_back(b);
        box.push_back(c);
        sort(box.begin(),box.end());
        max_a = max(box[0],max_a);
        max_b = max(box[1],max_b);
        max_c = max(box[2],max_c);
    }
    cout << max_a * max_b * max_c << endl;
    return 0;
}