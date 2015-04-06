/*
By Александър Георгиев

Ели е наследила от баба си винарска изба. В нея има N ≤ 200 бутилки вино, наредени
в редица. За простота ще ги номерираме с числата от 0 до N-1, включително. Техните начални
цени са неотрицателни цели числа, които са ни дадени в масива P[]. Цената на i-тата бутилка
е дадена в Pi. Колкото повече отлежават бутилките, толкова по-скъпи стават те. Ако бутилка k
е отлежала Х години, нейната цена става X*Pk.

В завещанието си бабата на Ели е поискала всяка година внучка ѝ да продава по една от тях,
като избира или най-лявата или най-дясната останала. Каква е максималната сума пари, която
Ели може да спечели, ако продава бутилките в най-добрия за нея ред? Считаме, че бутилките са
отлежавали 1 година, когато бива продадена първата от тях.

Например ако имаме 4 бутилки с цени {P0 = 1, P1 = 4, P2 = 2, P3 = 3}, оптималното решение би
било да продаде бутилките в реда {0, 3, 2, 1} за печалба 1*1 + 2*3 + 3*2 + 4*4 = 29.

Вход
	4
	1 4 2 3

Изход
	29

*/

#include <iostream>
using namespace std;

int price[256], n;

int solve(int year, int left, int right){
	if(left > right) return 0;

	int winLeft = solve (year + 1, left + 1, right) + year * price[left];
	int winRight = solve (year + 1, left, right - 1) + year * price[right];

	return max(winLeft, winRight);
}

int main(){

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> price[i];

	cout << solve(1, 0, n-1) << endl;

	return 0;
}

/*

Оптимизация за намаляване на изчисленията:

int dyn[256][256][256];

int solve(int year, int left, int right){
	if(left > right) return 0;

	if(dyn[year][left][right] != 0)
		return dyn[year][left][right];

	int winLeft = recurse (year + 1, left - 1, right) + year * price[left];
	int winRight = recurse (year + 1, left, right - 1) + year * price[right];

	return dyn[year][left][right] = max(winLeft, winRight);
}

*/