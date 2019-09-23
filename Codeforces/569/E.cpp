#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

struct node
{
    ll max_value,plus_count,minus_count;
};

class SegTree
{
    int MAX_N;
    int highestOneBit(int i)
    {
        i |= (i >> 1);
        i |= (i >> 2);
        i |= (i >> 4);
        i |= (i >> 8);
        i |= (i >> 16);
        return i - (i >> 1);
    }

public:
    node *dat;

    SegTree(int size = 100000)
    {
        int HOB = highestOneBit(size);
        if (HOB != size)
        {
            MAX_N = HOB << 1;
        }
        else
        {
            MAX_N = HOB;
        }
        dat = new node[MAX_N * 2];
        for (int i=0;i<(MAX_N * 2);i++){
            node n = {0LL,0LL,0LL};
            dat[i] = n;
        }
        fill(dat, dat + (MAX_N * 2), *(new node));
    }

    void update(int index, node x)
    {
        for (int i = index + MAX_N; i > 0; i >>= 1)
        {
            //iが対応するインデックス
            if (i >= MAX_N)
            {
                dat[i] = x;
            }
            else
            {
                update_node(dat[i],dat[2*i],dat[2*i+1]);
            }
        }
    }

    void update_node(node &parent, node &lson,node &rson){
        ll plus_diff = max(rson.minus_count + lson.plus_count,0LL);
        ll minus_diff = min(rson.minus_count + lson.plus_count,0LL);
        parent.plus_count = rson.plus_count + plus_diff;
        parent.minus_count = minus_diff + rson.minus_count;
        if (parent.plus_count <= 0){
            parent.max_value = -1;
        }else{
            parent.max_value = rson.max_value;
        }
    }

    node query(int L, int R)
    {
        L += MAX_N;
        R += MAX_N;
        node c;
        for (; L < R; L >>= 1, R >>= 1)
        {
            if (R & 1)
            {
                --R;
                update_node(c,c,dat[R]);
            } //--Rが対応するインデックス
            if (L & 1)
            {
                update_node(c,dat[L],c);
                L++;
            } //L++が対応するインデックス
        }
        return c;
    }
};


int main()
{
    map<ll,ll> a;
    a[0] = 1;
    auto b = a.begin();
    auto c = a.find(0);
    cout << (b == c) << endl;
    // 整数の入力
    long long N,M;
    vector<ll> A;
    vector<ll> B;
    cin >> N >> M;
    for (int i =0 ;i<N;i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }

    for (int i =0 ;i<N;i++){
        ll b;
        cin >> b;
        B.push_back(b);
    }

    ll q;
    cin >> q;

    for(int i = 0;i<q;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if (a == 1){

        }else{

        }
    }
    return 0;
}