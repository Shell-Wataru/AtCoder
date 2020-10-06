#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int solve(){
    string S;
    cin >> S;
    ll first_one = -1;
    ll last_one = - 1;
    for(int i = 0;i< S.size();i++){
        if (first_one != -1){
            if(S[i] == '1'){
                last_one = i;
            }
        }else{
            if(S[i] == '1'){
                first_one = i;
            }
        }
    }
    ll count = 0;
    for(int i = first_one; i < last_one;i++){
        if (S[i] == '0'){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
int main()
{
    // 整数の入力
    long long T;
    cin >> T;
    for(int i = 0;i< T;i++){
        solve();
    }

    return 0;
}