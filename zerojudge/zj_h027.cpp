// array, loop
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
	IOS
	int a[105][105], b[105][105];
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
	int b_sum = 0, cnt = 0, min_sum = 10000000, foo = 0;
	for(int k = 0;k < n - s + 1;k++){
		for(int j = 0;j < m - t + 1;j++){
            cnt = 0;
            b_sum = 0;
            for(int i = 0;i < s;i++){
				for(int f = 0;f < t;f++){
					if(b[i + k][f + j] != a[i][f]) cnt++;
					b_sum += b[i + k][f + j];
				}
			}
			if(cnt <= r){
				foo++;
				min_sum = min(min_sum, abs(b_sum - a_sum));
			}
		}
	}
    cout << foo << '\n';
	if(foo == 0) cout << -1 << '\n';
	else cout << min_sum << '\n';

    return 0;
}