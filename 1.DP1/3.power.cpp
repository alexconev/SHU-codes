/*

Въвеждат се числата x и y и да се намери x^y

*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

long long power(int x, int y){
	if(y == 0) return 1;
	if(y == 1) return x;

	if(y%2 == 0){
		long long temp = power(x,y/2);
		return temp*temp;
	}
	else
		return power(x,y-1)*x;
}

long long power2(int x, int y){
   long long res = 1;
   for(int i=1; i <= y; i++)
     res *= x;
   return res;
}

int main(){

	int x,y;
	long long res;

	cin>>x>>y;

	int start_s = clock();

	for(int i=0;i<1000000;i++){
		res = power2(x,y);  // O(y)
		//res = pow(x,y);   //
		//res = power(x,y); // O(log(y))
	}

	cout << res << endl;

	int stop_s = clock();
	cerr << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << " sec" << endl;

	return 0;
}