#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
	IOS
	int a[15][15], b[105][105];
	int s, t, n, m, r, a_sum = 0;
	cin >> s >> t >> n >> m >> r;
	for(int i = 0;i < s;i++){
		for(int j = 0;j < t;j++){
			cin >> a[i][j];
			a_sum += a[i][j];
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> b[i][j];
		}
	}
	int b_sum = 0, cnt = 0, max_sum = 0, min_cnt = 150;
	for(int k = 0;k < n - s + 1;k++){
		for(int i = k;i < s + k;i++){
			for(int j = 0;j < m - t + 1;j++){
				for(int f = j;f < t + j;f++){
					if(b[i][f] != a[i][f]) cnt++;
					else b_sum += b[i][f];
					if(cnt > r) break;
				}
			}
			min_cnt = min(min_cnt, cnt);
			max_sum = max(max_sum, b_sum);
		}
	}

    return 0;
}
