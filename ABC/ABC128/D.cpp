#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <queue>

using namespace std;

int main()
{
        // 整数の入力
    long long N,K,xi,yi,zi;
    cin >> N>> K;
    vector<long long> V;
    long long *maxs = new long long[101];
    fill(maxs,maxs+101,0);
    for (int i = 0;i< N;i++){
        long long temp;
        cin >> temp;
        V.push_back(temp);
    }

    for (int right = 0; right <= N;right++){
        for(int left = 0; left <= N - right;left++){
            vector<long long> current_takes;
            for(int i = 0; i <left;i++){
                current_takes.push_back(V[i]);
            }
            for(int i = 0; i <right;i++){
                current_takes.push_back(V[N-1-i]);
            }
            sort(current_takes.begin(),current_takes.end(),greater<long long>() );
            long long total = 0;
            for(int i = 0;i < right + left;i++){
                total += current_takes[i];
                if(total > maxs[2 * (right+left) - 1 -i]){
                    maxs[2 * (right+left) - 1 -i] = total;
                }
            }
        }
    }
    // long long maximum = 0;
    // for (int i = 0;i<= 2 *N;i++){
    //     cout << i << ":" << maxs[i] << endl;
    // }
    cout << *max_element(maxs,maxs+K+1) << endl;
    return 0;
}