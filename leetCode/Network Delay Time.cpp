// There are N network nodes, labelled 1 to N.

// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

// Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.



// Example 1:



// Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
// Output: 2


// Note:

// N will be in the range [1, 100].
// K will be in the range [1, N].
// The length of times will be in the range [1, 6000].
// All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

vector<pair<int, int>> G[109];
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k)
    {
        for (int i = 0; i < 109; i++)G[i].clear();
        for (int i = 0; i < t.size(); i++)
        {
            G[t[i][0]].push_back({t[i][1], t[i][2]});

        }
        vector<int> dis(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dis[k] = 0;
        while (!pq.empty())
        {

            int node = pq.top().second; pq.pop();

            for (auto child : G[node])
            {
                if (dis[child.first] > dis[node] + child.second)
                {
                    dis[child.first] = dis[node] + child.second;
                    pq.push({dis[child.first], child.first});
                }
            }
        }
        int ma = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] == 1e9)return -1;
            ma = max(ma, dis[i]);
        }
        return ma;
    }
};