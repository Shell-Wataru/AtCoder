#include<iostream>
#include <algorithm>
#include <vector>
#include <deque> 
using namespace std;

int main()
{
    // 整数の入力
    long long  N,V,L,i,j;
    double T;
    double totalQ;
    cin >> N >> L;
    deque<int> VList;
    deque<double> TList;

    cin >> T >> V;
    TList.push_front(T);
    VList.push_front(V);
    totalQ = T*V;
    cout << fixed << T << endl;
    for (i=1;i<N;i++){
        cin >> T >> V;
        int tempV = V;
        while (tempV> 0){
            if (tempV >= VList.back()){
                tempV = tempV- VList.back();
                totalQ = totalQ - VList.back() * TList.back();
                VList.pop_back();
                TList.pop_back();
            }else{
                VList.back() = VList.back() - tempV;
                totalQ = totalQ - tempV * TList.back();
                tempV = 0;
            }
        }

        if (VList.size() == 0){
            TList.push_front(T);
            VList.push_front(V);
            totalQ = T*V;
        }else{
            totalQ += T*V;
            while (!TList.empty() && T <= TList[0]){
                T = (T*V+TList[0]*VList[0])/(V+VList[0]);
                V = V+VList[0];
                TList.pop_front();
                VList.pop_front();
            }
            TList.push_front(T);
            VList.push_front(V);
        }

        cout << fixed << totalQ/L << endl;
    }

    return 0;
}