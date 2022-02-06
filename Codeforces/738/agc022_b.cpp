#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> answers;
    ll total = 0;
    for(int i = 1;i <= 30000;i++){
        if (i % 2 == 0 || i % 3 == 0){
            answers.push_back(i);
            total += i;
            if (answers.size() == n-1){
                break;
            }
        }
    }
    cout << total << endl;
    for(int i = 1;i <= 30000;i++){
        if (!(i % 2 == 0 || i % 3 == 0) && gcd(total,i) != 1 && ( (total + i) % 6 == 0 )){
            answers.push_back(i);
            break;
        }
    }
    for(int i = 0;i < n;i++){
        if (i != 0){
            cout << " ";
        }
        cout << answers[i];
    }
    cout << endl;
    return 0;
}
