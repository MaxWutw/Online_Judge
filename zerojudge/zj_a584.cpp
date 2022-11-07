// string hash, BFS
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int n, ans = 0;
struct Node{
    vector<int> child;
    bool vis;
};
vector<Node> adj;
map<string, int> hash_table;
int get_hash(string s){
    if( !hash_table.count(s) ) {
        hash_table[s] = adj.size();
        Node n;
        n.vis = false;
        adj.push_back(n);
    }
    return hash_table[s];
}
int BFS(int start, int des){
    queue<int> q;
    if(start == des) return 0;
    q.push(start);
    int cnt = 1, dis = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        adj[cur].vis = true;
        for(int i : adj[cur].child){
            if(i == des) return dis;
            if(!adj[i].vis) q.push(i);
        }
        if(--cnt == 0){
            cnt = q.size();
            dis++;
        }
    }
    return -1;
}
int main(){
    IOS
    while(cin >> n){
        adj.clear();
        hash_table.clear();
        string s;
        // cin.ignore();
        getline(cin, s);
        for(int i = 0;i < n;i++){
            getline(cin, s);
            stringstream ss(s);
            ss >> s;
            int first = get_hash(s);
            // cout << first << ' ';
            while(ss >> s){
                int des = get_hash(s);
                adj[first].child.push_back(des);
                adj[des].child.push_back(first);
            }
        }
        string str1, str2;
        cin >> str1 >> str2;
        int u = get_hash(str1), v = get_hash(str2);
        cout << BFS(u, v) << '\n';
    }

    return 0;
}