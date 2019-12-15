#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

// ll pat(ll n){
//     vector<ll> A;
//     A.push_back[1];
//     A.push_back[1];
//     for(int i = 2;i<n;i++){
//         A.push_back( (A[i-1]+A[i-2]) % BASE_NUM);
//     }
//     return A[n];
// }

int solve(){
    string s;
    cin >> s;
    set<ll> one_positions;
    set<ll> two_positions;
    string::size_type current_pos = s.find("one");
    while(current_pos != string::npos){
        one_positions.insert(current_pos);
        current_pos = s.find("one",current_pos + 3);
    }

    current_pos = s.find("two");
    while(current_pos != string::npos){
        two_positions.insert(current_pos);
        current_pos = s.find("two",current_pos + 3);
    }

    vector<ll> result;
    for(auto i:one_positions){
        if(two_positions.find(i - 2) == two_positions.end()){
            result.push_back(i+1);
        }else{
            result.push_back(i);
        }
    }

    for(auto i:two_positions){
        if(one_positions.find(i + 2) == one_positions.end()){
            result.push_back(i+1);
        }
    }
    cout << result.size() << endl;
    for(int i = 0;i< result.size();i++){
        if (i == 0){
            cout << result[i] + 1;
        }else{
            cout << " " << result[i] + 1;
        }
    }
    cout << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for(int i= 0;i< t;i++){
        solve();
    }
    return 0;
}
