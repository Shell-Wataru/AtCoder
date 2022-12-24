#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;

    vector<vector<ll>> baseA(N,{0,0,0});
    for(int i =0;i < N;i++){
        cin >> baseA[i][0] >> baseA[i][1];
        baseA[i][2] = i;
    }
    vector<vector<ll>> sortedA(baseA);
    sort(sortedA.rbegin(),sortedA.rend());
    deque<vector<ll>> data;
    // start,length,index;
    for(int i = 0;i < N;i++){
        auto iter = lower_bound(data.begin(),data.end(),vector<ll>{sortedA[i][1],-1,-1});
        vector<ll> v;
        if(iter == data.end()){
            v = {sortedA[i][0],1,sortedA[i][2]};
        }else{
            v = {sortedA[i][0],(*iter)[1] + 1,sortedA[i][2]};
        }
        while(!data.empty() &&  data[0][0] == v[0] && ((data[0][1] < v[1] ) ||  data[0][1] == v[1] && v[2] <  data[0][2])){
            data.pop_front();
        }
        if (data.empty() || (data[0][1] < v[1] ) || (data[0][1] == v[1] && v[2] < data[0][2])){
            data.push_front(v);
        }
    }
    // for(auto d:data){
    //     cout << d[0]<< ","  << d[1] << "," << d[2] << endl;
    // }
    auto current = data.begin();
    vector<ll> answer;
    while(current != data.end()){
        ll index = (*current)[2];
        answer.push_back(index);
        current = lower_bound(current,data.end(),vector<ll>{baseA[index][1],-1,-1});
    }
    cout << answer.size() << endl;
    for(int i = 0;i < answer.size();i++){
        if (i != 0){
            cout << " ";
        }
        cout << answer[i] + 1;
    }
    cout << endl;
    return 0;
}

int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}