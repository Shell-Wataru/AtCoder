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
using namespace std;
// using int = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    int N;
    scanf("%d",&N);
    int MaxL  = 100000;
    map<int,map<int,int>> DP;
    vector<pair<int,int>> nodes(N);
    vector<bool> calculated(N);
    // cout << "aa" << endl;

    for(int i = 0;i < N;i++){
        scanf("%d",&nodes[i].first);
        scanf("%d",&nodes[i].second);
    }
    DP[0][0] = 0;
    DP[0][nodes[0].second] = nodes[0].first;
    calculated[0] =true;
    // cout << "bb" << endl;
    // for(int i = 1;i < N;i++){
    //     int parent = (i-1)/2;
    //     // cout << parent << endl;
    //     for(int j = MaxL;j >= 0;j--){
    //         DP[i][j] = DP[parent][j];
    //         if(j >= nodes[i].second){
    //             DP[i][j] = max(DP[i][j],DP[parent][j - nodes[i].second] + nodes[i].first);
    //         }
    //     }
    // }
    int Q;
    scanf("%d",&Q);
    for(int i = 0;i < Q;i++){
        int v,L;
        scanf("%d",&v);
        scanf("%d",&L);
        v--;
        vector<int> ancesters;
        ancesters.push_back(v);
        while(v > 0){
            v = (v-1)/2;
            ancesters.push_back(v);
        }
        reverse(ancesters.begin(),ancesters.end());
        for(auto &a:ancesters){
            // cout << a;
            if (calculated[a]){
                continue;
            }
            // cout << "=" << endl;
            int parent = (a-1)/2;
            // cout << parent << endl;
            for(auto p:DP[parent]){
                DP[a][p.first] = max(DP[a][p.first],p.second);
                if (p.first + nodes[a].second <= MaxL){
                    DP[a][p.first + nodes[a].second] = max(DP[a][p.first + nodes[a].second], p.second + nodes[a].first);
                }
            }
            // cout << endl;
            calculated[a] = true;
        }
        // cout << endl;
        auto iter = lower_bound(DP[ancesters.back()].begin(),DP[ancesters.back()].end(),L);
        cout << (*iter).first << " "<< (*iter).second << "\n";
        // cout << DP[ancesters.back()][L] << "\n";
    }
    cout << flush;
    return 0;
}