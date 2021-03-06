/*

Да се намери N-тото число в редицата на Фибоначи.

Вход
На стандартния вход се задава числото N.

Изход
На стандартния изход се изпечатва N-тото число от редицата на Фибоначи.

Пример #1
	Вход
	8

	Изход
	13


	1 2 3 4 5 6 7  8
	0 1 1 2 3 5 8 13

*/

#include <iostream>
#include <ctime>
using namespace std;

long long solve(int x){	// рекурсия

	if(x == 1) return 0;
	if(x == 2) return 1;

	return solve(x-1)+solve(x-2);
}

long long mem[128];
long long solve2(int x){ // оптимизирана рекурсия (с пазене на изчислените резултати)

	if(x == 1) { return mem[x] = 0; }
	if(x == 2) { return mem[x] = 1; }

	long long f1,f2;

	if(mem[x-1]) f1 = mem[x-1];
	else mem[x-1] = f1 = solve2(x-1);

	if(mem[x-2]) f2 = mem[x-2];
	else mem[x-2] = f2 = solve2(x-2);

	return f1+f2;
}

long long solve3(int x){ // изчисляване на всеки член до достигане на търсения

	long long f0 = 0, f1 = 1, ft;

	for(int i = 2; i < x; i++){
		ft = f1;
		f1 += f0;
		f0 = ft;
	}

	if(x == 1) return f0;
	else return f1;
}

int main(){

	int n;
	cin>>n;

	int start_s=clock();

	//cout<< solve(n) << endl; // O(1,6^n)
	//cout<< solve2(n) << endl;  // O(n)
	cout<< solve3(n) << endl;  // O(n)

	int stop_s=clock();
	cerr << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << " sec" << endl;

	return 0;
}

/*

АНАЛИЗ:
Бавното решение на задачата се реализира чрез рекурсия, която работи бавно поради многократното
изчисление на дадени членове от редицата. Сложност: O(1,6^N)

Оптимизация на горния подход е запазване на вече изчислените стойности и директното им
връщане. Сложност: O(N)

Бързото решение е директно пълнене на масив. Сложност: O(N)

*/