#include <iostream>
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
#include <cstring>

using namespace std;
using ll = long long;

template <int char_size>
struct TrieNode
{
    int nxt[char_size];

    int exist;
    vector<int> accept;

    TrieNode() : exist(0)
    {
        memset(nxt, -1, sizeof(nxt));
    }
};

template <int char_size, int margin>
struct Trie
{
    using Node = TrieNode<char_size>;

    vector<Node> nodes;
    int root;

    Trie() : root(0)
    {
        nodes.push_back(Node());
    }

    void update_direct(int node, int id)
    {
        nodes[node].accept.push_back(id);
    }

    void update_child(int node, int child, int id)
    {
        ++nodes[node].exist;
    }

    void add(const string &str, int str_index, int node_index, int id)
    {
        if (str_index == str.size())
        {
            update_direct(node_index, id);
        }
        else
        {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] == -1)
            {
                nodes[node_index].nxt[c] = (int)nodes.size();
                nodes.push_back(Node());
            }
            add(str, str_index + 1, nodes[node_index].nxt[c], id);
            update_child(node_index, nodes[node_index].nxt[c], id);
        }
    }

    void add(const string &str, int id)
    {
        add(str, 0, 0, id);
    }

    void add(const string &str)
    {
        add(str, nodes[0].exist);
    }

    void query(const string &str, const function<void(int)> &f, const function<void(int)> &g, int str_index, int node_index)
    {
        if (str_index < str.size())
        {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] != -1)
            {
                query(str, f, g, str_index + 1, nodes[node_index].nxt[c]);
            }
        }
        g(str_index);
        for (auto &idx : nodes[node_index].accept){
            f(idx);
        }

    }

    void query(const string &str, const function<void(int)> &f, const function<void(int)> &g)
    {
        query(str, f, g, 0, 0);
    }

    int count() const
    {
        return (nodes[0].exist);
    }

    int size() const
    {
        return ((int)nodes.size());
    }
};

int main()
{
    Trie<26, 'a'> trie;
    // 整数の入力
    ll N;
    cin >> N;
    vector<string> S(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> S[i];
        reverse(S[i].begin(), S[i].end());
        trie.add(S[i].substr(0, S[i].size() - 1),i);
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        vector<ll> use_count(26,0);
        auto update = [&](int idx)
        {
            if (use_count[S[idx].back()-'a'] > 0){
                ans++;
            }
        };
        auto count_up = [&](int string_idx)
        {
            if (string_idx < S[i].size()){
                use_count[S[i][string_idx] - 'a']++;
            }
        };
        trie.query(S[i], update,count_up);
    }
    cout << ans - N << endl;
    return 0;
}