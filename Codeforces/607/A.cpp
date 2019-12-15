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

bool ends_with(const std::string& s, const std::string& suffix) {
   if (s.size() < suffix.size()) return false;
   return std::equal(std::rbegin(suffix), std::rend(suffix), std::rbegin(s));
}
int solve(){
    string s;
    cin >> s;
    if (ends_with(s,"po")){
        cout << "FILIPINO" << endl;
    }else if (ends_with(s,"desu") || ends_with(s,"masu")){
        cout << "JAPANESE" << endl;
    }else{
        cout << "KOREAN" << endl;
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}