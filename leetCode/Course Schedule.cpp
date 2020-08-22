// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?



// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.


// Constraints:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
// 1 <= numCourses <= 10^5

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        graph g = buildGraph(n, pre);
        vector<bool>todo(n, false), done(n, false);
        for (int i = 0; i < n; i++) {
            if (!done[i] && !acyclic(g, todo, done, i)) {
                return false;
            }
        }
        return true;
    }
    typedef vector<vector<int>> graph;

    graph buildGraph(int n, vector<vector<int>>pre) {
        graph g(n);
        for (auto p : pre) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }

    bool acyclic(graph &g, vector<bool>&todo, vector<bool>&done, int node) {
        if (todo[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        todo[node] = done[node] = true;
        for (int v : g[node]) {
            if (!acyclic(g, todo, done, v)) {
                return false;
            }

        }
        todo[node] = false;
        return true;
    }
};