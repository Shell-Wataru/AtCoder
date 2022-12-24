#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;


int main()
{
    // vector<ll> a = {5,1,4,2,3,6};
    // vector<ll> a = {5,4,3,2,1,6};
    vector<ll> a = {6,1,2,3,4,5};
    // vector<ll> a = {5,6,3,2,1,4};
    cout << 1 << endl;
    cout << a.size() << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            vector<ll> answer(a.size());
            for(int i = 0;i < a.size();i++){
                cin >> answer[i];
                cerr << answer[i] << ",";
            }
            cerr << endl;
            break;
        }else{
            ll t,i,j,x;
            cin >> t >> i >> j >> x;
            // cerr << t << " " << i <<" " << j << " " << x << endl;
            i--;j--;
            if (t == 1){
                cout << max(min(x,a[i]),min(x+1,a[j])) << endl;
            }else{
                cout << min(max(x,a[i]),max(x+1,a[j])) << endl;
            }
        }
    }
    return 0;
}
