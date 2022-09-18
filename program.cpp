#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(2005);
        int indegree[2005] = {0};
        for(int i = 0;i < prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0])
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
                if(indegree[adj[vertex][i]] == -) Q.push(adj[vertex][i]);
            }
        }
        return coursecnt == numCourses;
    }
};
int main(){
    solution = Solution();
    vector<vector<int>> vec = {{1, 0}, {0, 1}};
    solution.canFinish(2, vec);
    
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;
// // void foo(int *a){
// //     cout << a[5] << endl;
// // }
// int main(){
//     // int a[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9};
//     // foo(a);
//     vector<vector<int>> vec;
//     vec.push_back(.push_back(4);
//     cout << vec[0][0] << endl;

//     return 0;
// }