#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int maxn = 1e4;
char s[maxn];
map<int, int> to[maxn];
int len[maxn], from[maxn], link[maxn];
int node, pos;
int sz = 1, n = 0;

int make_node(int _pos, int _len)
{
    from[sz] = _pos;
    len [sz] = _len;
    return sz++;
}

void go_edge()
{
    while(pos > len[to[node][s[n - pos]]])
    {
        node = to[node][s[n - pos]];
        pos -= len[node];
    }
}

void add_letter(int c)
{
    s[n++] = c;
    pos++;
    int last = 0;
    while(pos > 0)
    {
        go_edge();
        int edge = s[n - pos];
        int &v = to[node][edge];
        int t = s[from[v] + pos - 1];
        if(v == 0)
        {
            v = make_node(n - pos, inf);
            link[last] = node;
            last = 0;
        }
        else if(t == c)
        {
            link[last] = node;
            return;
        }
        else
        {
            int u = make_node(from[v], pos - 1);
            to[u][c] = make_node(n - 1, inf);
            to[u][t] = v;
            from[v] += pos - 1;
            len [v] -= pos - 1;
            v = u;
            link[last] = u;
            last = u;
        }
        if(node == 0)
            pos--;
        else
            node = link[node];
    }
}

int main()
{
    len[0] = inf;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        add_letter(s[i]);

    // root is 0
    // descendant of root is to[node][char]
    for(int i = 0; i < sz; ++i) {
    	printf("from[%d] = %d, len[%d] = %d\n", i, from[i], i, len[i]);
    	for (map<int, int>::iterator it = to[i].begin(); it != to[i].end(); ++it) {
    		printf("to[%d][%c] = %d\n", i, (char)it->first, it->second);
    	}
    }
    for(int i = 1; i < sz; i++)
        ans += min((int)s.size() - from[i], len[i]);
    cout << ans << "\n";
}
