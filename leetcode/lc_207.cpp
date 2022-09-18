// 207. course schedule

// toplogical sort by dfs, time complexity: O(V+E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(2005);
        for(int i = 0;i < prerequisites.size();i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        int visited[2005] = {false};
        int checked[2005] = {false};
        for(int i = 0;i < numCourses;i++){
            if(is_cycle(i, adj, visited, checked)) return false;
        }
        return true;
    }
private:
    bool is_cycle(int course, vector<vector<int>>& adj, int* visited, int* checked){
        if(checked[course]) return false;
        if(visited[course]) return true;
        int s = adj[course].size();
        if(s == 0) return false;
        visited[course] = true;
        for(int i = 0;i < s;i++){
            if(is_cycle(adj[course][i], adj, visited, checked)) return true;
        }
        visited[course] = false;
        checked[course] = true;
        return false;
    }
};

// toplogical sort Kahn's algorithm(by bfs), time complexity: O(V+E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(2005);
        int indegree[2005] = {0};
        for(int i = 0;i < prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> Q;
        for(int i = 0;i < numCourses;i++){
            if(indegree[i] == 0) Q.push(i);
        }
        int coursecnt = 0;
        while(!Q.empty()){
            int vertex = Q.front();
            Q.pop();
            coursecnt++;
            for(int i = 0;i < adj[vertex].size();i++){
                indegree[adj[vertex][i]]--;
                if(indegree[adj[vertex][i]] == 0) Q.push(adj[vertex][i]);
            }
        }
        return coursecnt == numCourses;
    }
};