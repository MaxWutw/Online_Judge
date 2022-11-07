#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define L(x) (x << 1)
#define R(x) ((x << 1) | 1)
using namespace std;
typedef long long ll;
ll st[500005 << 2], lazy[500005 << 2];
int n;
void build(int pos, int x, int v = 1, int l = 0, int r = n - 1){
	if(l == r){
		st[v] = x; return;
	}
	int m = (l + r) >> 1;
	if(pos <= m) build(pos, x, L(v), l, m);
	else build(pos, x, v << 1 | 1, m + 1, r);
	st[v] = st[L(v)] + st[R(v)];
}

void push(int v, int l, int r){
	st[v] += lazy[v] * (r - l + 1);
	if(l != r){
		lazy[L(v)] += lazy[v];
		lazy[R(v)] += lazy[v];
	} 
	lazy[v] = 0;
}

void upd(int ql, int qr, int x, int v = 1, int l = 0, int r = n - 1){
	if(lazy[v]) push(v, l, r);
	st[v] += x * (qr - ql + 1);
	if(ql == l && qr == r){
		if(l != r){
			lazy[L(v)] += x;
			lazy[R(v)] += x;
		}
		return;
	}
	int m = (l + r) >> 1;
	if(qr <= m) upd(ql, qr, x, L(v), l, m); 
	else if(ql > m) upd(ql, qr, x, R(v), m + 1, r); 
	else{
		upd(ql, m, x, L(v), l, m);
		upd(m + 1, qr, x, R(v), m + 1, r);
	}
}

ll qry(int ql, int qr, int v = 1, int l = 0, int r = n - 1){
	if(lazy[v]) push(v, l, r);
	if(ql == l && qr == r) return st[v];
	int m = (l + r) >> 1;
	if(qr <= m) return qry(ql, qr, L(v), l, m);
	else if(ql > m) return qry(ql, qr, R(v), m + 1, r);
	else return qry(ql, m, L(v), l, m) + qry(m + 1, qr, R(v), m + 1, r);
}

int main(){
	IOS
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		build(i, x);
	}
	int q;
	cin >> q;
	while(q--){
		int v;
		cin>>v;
		if(v == 1){
			int x, y, k;
			cin>>x>>y>>k;
			x--, y--;
			upd(x, y, k);
		}
		else{
			int x, y;
			cin >> x >> y;
			x--, y--;
			cout << qry(x, y) << '\n';
		} 
	}
	
	return 0;
}
