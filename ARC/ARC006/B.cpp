#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>

using namespace std;
int position(int x){
    int M = 8;
    return M - abs( abs(x)%(2*M) - M);
}

int main()
{
    // 整数の入力
    long long N,L;
    cin >> N >> L;
    string* amida = new string[L];
    string goal;
    cin.ignore();
    for (int i = 0;i< L;i++){
        getline(cin,amida[i]);
    }
    getline(cin,goal);
    long long index = goal.find('o');
    for (int i = L-1 ;i>= 0;i--){
        long long diff = 0;
        if (index > 0){
            if (amida[i][index -1] == '-'){
                diff = - 2;
            }
        }

        if (index < 2 * N - 2){
            if (amida[i][index + 1] == '-'){
                diff =  2;
            }
        }
        index = index + diff;
    }
    cout << index/2 + 1 << endl;
    return 0;
}