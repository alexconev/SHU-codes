#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

char getch(){
	char a[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int b = rand() % 26;
	return a[b];
}

void gentest(int n, int m, int k, int testNum){

    char filePath[32];
    sprintf(filePath, "oil.%d.in", testNum);
    freopen(filePath, "w", stdout);

    cout << n << ' ' << m << ' ' << k << endl;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << getch();
		}
		cout << endl;
	}
}

int main(){

	gentest(4,5,6,0); // N*M*Q*K Q = 2
	gentest(36,45,18,1); // N*M*Q*K Q = 6
	gentest(65,75,24,2); // N*M*Q*K Q = 8
	gentest(98,118,16,3); // N*M*Q*K Q = 5
	gentest(135,95,12,4); // N*M*Q*K Q = 6
	gentest(72,62,54,5); // ~N*M*Q*K/2 Q = 8
	gentest(76,75,36,6); // ~N*M*Q*K/2 Q = 9
	gentest(283,295,72,7); // N*M*Q Q = 12
	gentest(310,330,80,8); // N*M*Q Q = 10
	gentest(245,255,120,9); // N*M*Q Q = 16
	gentest(212,205,720,10); // N*M*Q Q = 23

	return 0;
}