// string hash, SPFA
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n, ans = 0;
struct Node{
    vector<int> link;
    char line;
    bool inque;
    int price, dist;
};
vector<Node> adj;
map<string, int> hash_table;
int get_hash(string s){
    if(!hash_table.count(s)) {
        hash_table[s] = adj.size();
        Node n;
        n.inque = false;
        n.price = INF;
        n.line = s[0];
        adj.push_back(n);
    }
    return hash_table[s];
}
int SPFA(int start, int des){
    queue<int> q;
    q.push(start);
    int dis = 0;
    adj[start].dist = 1;
    adj[start].price = 10;
    adj[start].inque = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        adj[cur].inque = false;
        for(int i : adj[cur].link){
            int cost = adj[cur].price + ((adj[cur].dist % 3) ? 0 : 5) + ((adj[cur].line != adj[i].line) ? 5 : 0);
            if(adj[i].price > cost){
                adj[i].dist = adj[cur].dist + 1;
                adj[i].price = cost;
                if(!adj[i].inque){
                    adj[i].inque = true;
                    q.push(i);
                }
            }
        }
    }
    return adj[des].price;
}
int main(){
    IOS
    cin >> n;
    for(int i = 0;i < n;i++){
        string str1, str2;
        cin >> str1 >> str2;
        int u = get_hash(str1), v = get_hash(str2);
        adj[u].link.push_back(v);
        adj[v].link.push_back(u);
    }
    string str1, str2;
    cin >> str1 >> str2;
    int u = get_hash(str1), v = get_hash(str2);
    cout << SPFA(u, v) << '\n';

    return 0;
}