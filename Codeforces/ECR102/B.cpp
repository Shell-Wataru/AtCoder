#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int solve()
{
    string s;
    string t;
    cin >> s;
    cin >> t;
    ll lcm_length =  s.size() * t.size()/ gcd(s.size(),t.size());
    string a = "";
    string b = "";
    for(int i = 0;i < lcm_length/s.length();i++){
        for(auto c:s){
            a += c;
        }
    }
    for(int i = 0;i < lcm_length/t.length();i++){
        for(auto c:t){
            b += c;
        }
    }
    if (a == b){
        cout << a << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
