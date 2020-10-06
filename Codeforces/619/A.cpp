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

int solve(){
    string a,b,c;
    cin >> a >> b >> c;
    for(int i = 0;i< a.length();i++){
        if (a[i] != c[i] && b[i] != c[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
   return 0;
}