#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

bool makable(vector<long long> b,long long remove_i){
    if (b[remove_i] !=  remove_i + 1){
        return false;
    }

    for(int i = 0;i< b.size();i++){
        long long c = i+1;
        if (remove_i == i){
            continue;
        }else if (i > remove_i ){
            c--;
        }

        if (b[i] > c){
            return false;
        };

    }
    return true;
}



int main()
{
    // 整数の入力
    long long  N,temp;
    vector<long long> b;
    vector<long long> tejun;

    cin >> N;

    for(int i = 0; i< N;i++){
        cin >> temp;
        b.push_back(temp);
    }

    while(b.size() > 0){
        bool changed = false;
        for (int i = b.size() - 1;i>=0;i--){
            if (makable(b,i)){
                tejun.push_back(b[i]);
                b.erase(b.begin() +i);
                changed = true;
                break;
            }
        }

        if (!changed){
            break;
        }
    }


    if (b.size() != 0){
        cout << -1 << endl;
    }else{
        for (int i = N - 1 ;i >= 0;i--){
            cout << tejun[i] << endl;
        }
    }
    return 0;
}