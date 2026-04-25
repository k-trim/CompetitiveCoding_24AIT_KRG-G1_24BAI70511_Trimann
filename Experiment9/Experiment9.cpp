#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> edges(n - 1);
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> edges[i].first >> edges[i].second;
        deg[edges[i].first]++;
        deg[edges[i].second]++;
    }

    vector<int> ans(n - 1, -1);
    int special = -1;
    for (int i = 1; i <= n; i++) 
    {
        if (deg[i] >= 3) 
        {
            special = i;
            break;
        }
    }

    int label = 0;
    if (special != -1) 
    {
        for (int i = 0; i < n - 1; i++) 
        {
            if (edges[i].first == special || edges[i].second == special) 
            {
                ans[i] = label++;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) 
    {
        if (ans[i] == -1) 
            ans[i] = label++;
    }
    for (int x : ans) cout << x << '\n';
    return 0;
}