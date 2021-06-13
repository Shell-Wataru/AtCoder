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
    vector<ll> A = {5,1,4,2,3,6};
    cout << A.size() << endl;
    while(true){
        char t;
        cin >> t;
        if (t == '!'){
            ll answer;
            cin >> answer;
            cerr << answer << endl;
            break;
        }else{
            ll l,r;
            cin >> l >> r;
            l--;
            r--;
            ll first_value = numeric_limits<ll>::min();
            ll second_value = numeric_limits<ll>::min();
            ll first_index = -1;
            ll second_index = -1;
            for(int i = l;i <= r;i++){
                if (A[i] > first_value){
                    second_value = first_value;
                    second_index = first_index;
                    first_value = A[i];
                    first_index = i;
                }else if (A[i] > second_value){
                    second_value = A[i];
                    second_index = i;
                }
            }
            cout << second_index + 1 << endl;
        }
    }
    return 0;
}
