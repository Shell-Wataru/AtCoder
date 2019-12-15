#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;


int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> operations;
    for(int i=0;i<n-1;i++){
        if(s[i] == 'B'){
            operations.push_back(i+1);
            s[i] = 'W';
            if(s[i+1] == 'B'){
                s[i+1] = 'W';
            }else{
                s[i+1] = 'B';
            }
        }
    }
    if (s[n-1] == 'B'){
        cout << -1 << endl;
    }else{
        cout << operations.size()<< endl;
        for(int i =0;i< operations.size();i++){
            if (i == 0){
                cout << operations[i];
            }else{
                cout << " " << operations[i];
            }
        }
        cout << endl;
    }
   return 0;
}
