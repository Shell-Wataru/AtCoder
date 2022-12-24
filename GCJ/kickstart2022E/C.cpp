#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000000;

string solve()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    string dummyS;
    for(auto c:S){
        dummyS += c;
        dummyS += '$';
    }
    dummyS.pop_back();
    ll M = dummyS.size();
    vector<ll> R(M);
    int i = 0, j = 0;
    while (i < M)
    {
        while (i - j >= 0 && i + j < M && dummyS[i - j] == dummyS[i + j])
            ++j;
        R[i] = j;
        int k = 1;
        while (i - k >= 0 && k + R[i - k] < j)
            R[i + k] = R[i - k], ++k;
        i += k;
        j -= k;
    }
    ll min_r = M;
    for(int i = 0;i < M;i++){
        if (R[i] - 1 == i &&  2*R[i] -1 + (M - (2*R[i]-1))/2 + R[2*R[i] -1 + (M - (2*R[i]-1))/2] == M ){
            min_r = min(min_r,R[i]);
        }
    }
    // cout << dummyS << endl;
    // cout << "min_r:" << min_r << endl;
    string Q = dummyS.substr(0,2*min_r-1);
    string ans;
    for(auto c:Q){
        if (c != '$'){
            ans += c;
        }
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}