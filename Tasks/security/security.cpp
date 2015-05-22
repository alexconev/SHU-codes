#include <iostream>
using namespace std;

int n;
long long br;

int k=2, a[51];
void solve0(int pos=0) // O(N*2^N)
{
	if(pos == n){
		for(int j=2;j<n;j++)
			if(a[j]==1 && a[j-1]==1 && a[j-2]==1)
				return;
		br++;

		return;
	}

	for(int i = 0; i < 2; i++){
		a[pos] = i;
		solve0(pos+1);
	}

	return;
}

void solve(){ // O(N)
	long long b[52];
	b[1] = 2;
	b[2] = 4;
	b[3] = 7;
	for(int i=4;i<=n;i++)
		b[i] = b[i-1] + b[i-2] + b[i-3];

	br = b[n];
}

int main(){

	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin >> n;
		solve();
		cout << br << endl;
	}

	return 0;
}