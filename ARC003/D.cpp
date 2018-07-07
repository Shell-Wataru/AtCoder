#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>

using namespace std;

long long N,M,K,i,j,badPairA,badPairB;
int* Table;
mt19937 mt(0);

bool Check(bool** BadPairs,long long N,long long K){
    for (int i = 0;i<N ;i++){
        Table[i] = i;
    }

    uniform_int_distribution<int> randN(0, N-1);
    uniform_int_distribution<int> randN_1(1, N-1);
    for (int i = 0;i<K;i++){
        int irekaeA = randN(mt);
        int irekaeB = (irekaeA + randN_1(mt)) % N;
        int temp = Table[irekaeA];
        Table[irekaeA] = Table[irekaeB];
        Table[irekaeB] = temp;
    }

    for(int i = 0;i<N;i++){
        if (BadPairs[Table[i]][Table[(i+1)%N]]){
            return false;
        }
    }
    return true;
}

int main()
{
    // 整数の入力
    cin >> N >> M >> K;
    Table = new int[N];
    bool** BadPairs = new bool*[N];
    for (i = 0;i<N;i++){
        BadPairs[i] = new bool[N];
        for(j =0;j<N;j++){
            BadPairs[i][j] = false;
        }
    }

    for (i = 0;i<M;i++){
        cin >> badPairA >> badPairB;
        BadPairs[badPairA][badPairB] = true;
        BadPairs[badPairB][badPairA] = true;
    }

    double total = 0;
    int times = 4000000;
    for (i = 0;i<4000000;i++){
        if (Check(BadPairs,N,K)){
            total += 1;
        }
    }
    cout << total/times << endl;
    return 0;
}