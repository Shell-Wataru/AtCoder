#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <atcoder/string>
using namespace std;
using ll = long long;
using namespace atcoder;

bool lt_substr(const vector<int> &s, const vector<int> &t, int si = 0, int ti = 0)
{
    int sn = (int)s.size(), tn = (int)t.size();
    while (si < sn && ti < tn)
    {
        if (s[si] < t[ti])
            return true;
        if (s[si] > t[ti])
            return false;
        ++si, ++ti;
    }
    return si >= sn && ti < tn;
}

int lower_bound(const vector<int> &s, vector<int> &t, const vector<int> &sa)
{
    int low = -1, high = (int)sa.size();
    while (high - low > 1)
    {
        int mid = (low + high) / 2;
        if (lt_substr(s, t, sa[mid]))
            low = mid;
        else
            high = mid;
    }
    return high;
}

pair<int, int> lower_upper_bound(const vector<int> &s, vector<int> &t, const vector<int> &sa)
{
    int idx = lower_bound(s, t, sa);
    int low = idx - 1, high = (int)sa.size();
    t.back()++;
    while (high - low > 1)
    {
        int mid = (low + high) / 2;
        if (lt_substr(s, t, sa[mid]))
            low = mid;
        else
            high = mid;
    }
    t.back()--;
    return {idx, high};
}

template <typename T>
struct Compress
{
    vector<T> xs;

    Compress() = default;

    Compress(const vector<T> &vs)
    {
        add(vs);
    }

    Compress(const initializer_list<vector<T>> &vs)
    {
        for (auto &p : vs)
            add(p);
    }

    void add(const vector<T> &vs)
    {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x)
    {
        xs.emplace_back(x);
    }

    void build()
    {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector<int> get(const vector<T> &vs) const
    {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x)
                  { return lower_bound(begin(xs), end(xs), x) - begin(xs); });
        return ret;
    }

    int get(const T &x) const
    {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    size_t size() const
    {
        return xs.size();
    }
    const T &operator[](int k) const
    {
        return xs[k];
    }
};

string solve()
{
    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> B(N);
    Compress<ll> C;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        C.add(A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
        C.add(B[i]);
    }
    C.build();
    for (int i = 0; i < N; i++)
    {
        A[i] = C.get(A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        B[i] = C.get(B[i]);
    }
    for (int i = 0; i < N-1; i++)
    {
        A.push_back(A[i]);
    }
    vector sa = suffix_array(A, (int)C.size());
    auto p = lower_upper_bound(A,B,sa);
    // cout << p.first << "~" << p.second << endl;
    if (p.first == p.second){
        return "NO";
    }

    bool initial_only = (p.first+1 == p.second && sa[p.first] == 0);
    bool initial_ok = false;
    for(int i = p.first;i < p.second;i++){
        if (sa[i] == 0){
            initial_ok = true;
        }
    }
    if ((K == 0 && initial_ok) ||
        (K == 1 && !initial_only) ||
        (N == 2 && (K % 2 == 1) && !initial_only) ||
        (N == 2 && (K % 2 == 0) && initial_ok) ||
        (N > 2 && K > 1))
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;
    // cerr << T << endl;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}