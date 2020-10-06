#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator>  // std::rbegin, std::rend


using namespace std;
using ll = long long;


int main()
{
    // 整数の入力
    ll n;
    string S;
    cin >> n;
    cin >> S;
    ll r_count = 0;
    ll l_count = 0;
    for(auto c: S){
        if (c == 'R'){
            r_count++;
        }else{
            l_count++;
        }
    }
    cout << r_count + l_count + 1 << endl;
    return 0;
}