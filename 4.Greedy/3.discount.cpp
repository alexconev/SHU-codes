/*

Посещавайки преди Коледа голям магазин, Ели избрала голямо количество подаръци за роднини и приятели. Ели може да икономиса определена сума пари, ако се възползва от предпразничните отстъпки, които магазинът предлага:
1. При покупка на три стоки се заплаща сума, равна на сумата от цените на двете най-скъпи от тях;
2. При покупка на четири стоки се заплаща сума, равна на сумата от цените на трите най-скъпи от тях;
Използвайки тези отстъпки, Ели може да обедини избраните подаръци в тройки и четворки и, минавайки няколко пъти през касата, да намали общата сума, която ще заплати. Например, ако цените на пет избрани подаръка са 50,80,50,100 и 20 лв., то Ели може да купи най-напред първите четири подаръка, да получи за тях отстъпка от 50 лв., а след това да купи петия подарък по неговата истинска цена. По този начин, за петте подаръка, тя ще плати общо 250 вместо 300лв.
Напишете програма discount, която по цените на всички подаръци, избрани от Ели, определя минималната сума, за което те могат да бъдат закупени.

Вход
	От първия ред на стандартния вход се въвежда цяло, положително число N - брой на подаръците, които е избрала Ели.
	От втори ред се въвеждат N цели, положителни числа, разделени с по един интервал - цените на избраните подаръци.
	Бележка: Могат да бъдат обединявани не само подаръци, чиито цени следват една след друга във входните данни.

Изход
	На еидн ред от стандартния изход програмата трябва да изведе намерената минимална сума, с която Ели може да закупи избраните подаръци.

Ограничения
	1 <= N <= 10 000
	Сумата от цените на всички избрани подаръци е по-малка от 10^9 лв.

Пример #1:
	Вход
	5
	50 80 50 100 20

	Изход
	250


	(50 80 50 100) = 230
			  (20) =  20
	----------------------
					 250

	(50 80 50) = 130
	  (100 20) = 120
	-----------------
				 250

*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, a[10001], sum;

int main(){

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}

	sort(a,a+n);

	int j = 1;
	for(int i = n-1; i >= 0; i--){
		if(j%3 == 0) sum -= a[i];
		j++;
	}

	cout << sum << endl;

	return 0;
}

/*

Анализ:


*/