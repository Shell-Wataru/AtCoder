#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <numeric>

using namespace std;
using ll = long long;

string solve(){
    ll N;
    cin >> N ;
    vector<ll> a(N);
    vector<ll> b(N);
    for(int i = 0;i < N;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.rbegin(),b.rend());
    vector<ll> answers(N);
    for(int i = 0;i < N;i++){
        ll index = lower_bound(b.begin(),b.end(),2*a[i],greater<ll>()) - b.begin();
        if (b[index] == a[i]){
            index++;
        }
        if (index == N){
            answers[i] = -1;
        }else{
            answers[i] = b[index];
        }
    }
    string ans = "";
    for(int i = 0;i < N;i++){
        if (i != 0){
            ans += " ";
        }
        ans += to_string(answers[i]);
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
        cout << "Case #" << i  << ": "<< ans << endl;
    }

    return 0;
}