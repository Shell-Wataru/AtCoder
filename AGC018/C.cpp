#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    // 整数の入力
    long long X,Y,Z,i,tempA,tempB,tempC;
    int Counts[3] = {0}
    cin >> X >> Y >> Z;
    vector<vector<long long>> ABC;
    vector<vector<long long>> USED;

    for(i = 0;i< X+Y+Z;i++){
        cin >> tempA >> tempB >> tempC;
        ABC.push_back({tempA,tempB,tempC});
        if (tempA >= tempB && tempA >=tempC ){
            ABC.push_back({tempA,tempB,tempC,0});
            Counts[0]++
        }else if(tempB >= tempA && tempB >=tempC){
            ABC.push_back({tempA,tempB,tempC,1});
            Counts[1]++
        }else{
        ABC.push_back({tempA,tempB,tempC,2});
            Counts[2]++
        }
    }

    maxIndex = -1
    max = 0
    for(i = 0;i<3;i++){
        if (Counts[i] > max){
            maxIndex = i
        }
    }
    sort(ABC.begin(), ABC.end(),
                        [](vector<long long> x, vector<long long> y) -> int {
                        return ( x < y );
                        } );
    for (i)
    return 0;
}