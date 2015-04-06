/*

Да се напише програма, която по зададено число N запълва квадратна матрица с числата от 1 до N във вид
на спирала и по зададена позиция [i,j] изкарва числото на тази клетка.

Вход
На първия ред е числото N, на втория ред се задават реда I и колоната J на търсената клетка

Изход
На единствения ред да се изпечата стойността, която е присвоена след спираловидното запълване,
на позиция [I,J]

Пример #1
	Вход
	16
	2 2

	Изход
	13

{
	1  2  3  4
	12 13 14 5
	11 16 15 6
	10  9  8 7
}

*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){

	int n,i,j,sqn,a[15][15];
	cin >> n;
	cin >> i >> j;

	sqn = (int)sqrt(n);

	int x = 0, y = 0;
	int dx = 0, dy = 1;
	int br = 1, lvl = 1;

	while( n >= br ){

		a[x][y] = br++;

		x += dx; y += dy;

		if( y == sqn-lvl && x == lvl-1 ) { dx = 1; dy = 0; }
		else if( x == sqn-lvl && y == sqn-lvl ) { dx = 0; dy = -1; }
		else if( y == lvl-1 && x == sqn-lvl ) { dx = -1; dy = 0; }
		else if( x == lvl && y == lvl-1 ) { dx = 0; dy = 1; }

		if( x == lvl && y == lvl-1 ) lvl++;
	}

	cout << a[i-1][j-1] << endl;

	return 0;
}