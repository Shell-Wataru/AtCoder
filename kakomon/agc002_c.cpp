#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll N,L;
    cin >> N >> L;
    vector<ll> a(N);
    for(int i = 0;i< N;i++){
        cin >> a[i];
    }
    vector<ll> answer;
    for(int i = 0;i < N-1;i++){
        if (a[i] + a[i+1] >= L){
            answer.push_back(i+1);
            for(int j = i+2;j< N;j++){
                answer.push_back(j);
            }
            for(int j = i;j>=1;j--){
                answer.push_back(j);
            }
            reverse(answer.begin(),answer.end());
            cout << "Possible" << endl;
            for(int j = 0 ;j < N-1;j++){
                cout << answer[j] << endl;
            }
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}