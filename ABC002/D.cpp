#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long N,M,i,j,k,xi,yi,maxCliqueSize;
    maxCliqueSize = 0;
    cin >> N >> M;

    set<long long>* G = new set<long long>[N];

    for (i = 0;i< M ;i++){
        cin >> xi >> yi;
        G[xi-1].insert(yi-1);
        G[yi-1].insert(xi-1);
    }

    for(i = 0;i < (1<<(N)) ;i++){
        vector<long long> cliqueNodes;
        for (j=0;j<N;j++){
            if ((i & (1 << j)) >> j){
                cliqueNodes.push_back(j);
            }
        }

        bool isClique = true;
        for (j = 0;j< cliqueNodes.size();j++){
            for (k = 0;k< cliqueNodes.size();k++){
                if (j != k && G[cliqueNodes[j]].count(cliqueNodes[k]) == 0){
                    isClique = false;
                    break;
                }
            }
            if (isClique == false){
                break;
            }
        }

        if (isClique == true){
            if (cliqueNodes.size() > maxCliqueSize){
                maxCliqueSize = cliqueNodes.size();
            }
        }
    }

    cout << maxCliqueSize <<  endl;
    return 0;
}