#include <iostream>
using namespace std;

int n, m, k, sx, sy, fx, fy, a[400][400];
long long sum, b[400][400], mx;

void read(){

	char tt;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			tt = cin.get();
			a[i][j] = 26 - (tt-'a');
		}

}

void solve(){ // O(N*M*Q)

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			b[i][j] = a[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			for(int l = 1; l <= k; l++){
				int dx = min(l,n-i+1);
				if(k%dx == 0 && k/dx <= m-j+1)
				{
					int dy = k/dx-1;
					sum = b[i+dx-1][j+dy] - b[i-1][j+dy] - b[i+dx-1][j-1] + b[i-1][j-1];
					if(mx < sum){
						mx = sum;
						fx = i+dx-1;
						fy = j+dy;
						sx = i;
						sy = j;
					}
				}
			}
		}
}

int main(){

	read();
	solve();
	cout << sx << ' ' << sy << endl << fx << ' ' << fy << endl;

	return 0;
}