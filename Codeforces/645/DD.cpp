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
ll BASE_NUM = 998244353;

int main()
{
    vector<ll> A = {1,2,3,4};
    cout << 1 << endl;
    cout << "4 2" << endl;
    cout << "2 1 3" << endl;
    cout << "2 2 4" << endl;
    while(true){
        char type;
        cin >> type;
        // cout << type << endl;
        if(type == '?'){
            ll n;
            cin >> n;
            ll max_a = BASE_NUM;
            for (size_t i = 0; i < n; i++)
            {
                ll a;
                cin >> a;
                a--;
                max_a = min(max_a,A[a]);
            }
            cout << max_a << endl;
        }else{
            vector<ll> ans = {4,3};
            bool correct = true;
            for(int i = 0;i < 2;i++){
                ll a;
                cin >> a;
                if (a != ans[i]){
                    correct =false;
                }
            }
            if (correct ){
                cout << "Correct" << endl;
            }else{
                cout << "Incorrect" << endl;
            }
        }
    }
    return 0;
}