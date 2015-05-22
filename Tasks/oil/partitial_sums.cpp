#include <iostream>
using namespace std;

int n,m,sx,sy,fx,fy,a[100][100],b[100][100];
long long sum;

void read(){

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];

	cin >> sx >> sy >> fx >> fy;
}

void solve0(){

	for(int i = sx; i <= fx; i++)
		for(int j = sy; j <= fy; j++)
			sum += a[i][j];
}

void solve(){

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			b[i][j] = a[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];

	sum = b[fx][fy] - b[sx-1][fy] - b[fx][sy-1] + b[sx-1][sy-1];
}


int main(){

	read();
	int start_s = clock();
	solve();
	cout << sum << endl;
	int stop_s = clock();
	cerr << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << " sec" << endl;

	return 0;
}