#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
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