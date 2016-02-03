/*
 
Даден е граф. Да се напише програма, която оцветява върховете на графа като 
използва различни цветове ако два върха имат общо ребро.

Вход: На първия ред на стандартния вход се въвеждат N и M - броя върхове и 
броя ребра в графа. На останалите М реда се въвеждат по 2 числа - начален и 
краен връх на реброто.

Изход: На стандартния изход да се изведат N редa с по 2 числа - номер на 
връх и цвят на върха.

Пример:
    Вход
    5 6
    1 2
    1 3
    2 3
    2 4
    3 4
    4 5

    Изход
    1 0
    2 1
    3 2
    4 0
    5 1

    Изход2
    1 black
    2 white
    3 blue
    4 yellow
    5 white

*/


#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> Edge[MAXN];
int n,m;
string Colors[MAXN] = {"black","white","blue","yellow","green","pink","purple","orange"};
 
void addEdge(int s, int f){
    Edge[s].push_back(f);
    Edge[f].push_back(s);
}
 
void greedyColoring(){
    int result[n+1];
 
    // Оцветяваме първия връх с първия цвят
    result[1]  = 0;
 
    // Маркираме останалите върхове като неоцветени
    for (int i = 2; i <= n; i++)
        result[i] = -1;  // -1 е стойността за без цвят
 
    // Временен масив за маркиране на заетите цветове.
    // Ако стройността е true - някой съсед има този цвят
    bool available[n];
    for (int i = 1; i <= n; i++) // Започва от 1, защото 0-я цвят е зает
        available[i] = true;
 
    // Слагаме цветове на останалите n-1 върха
    for (int i = 2; i <= n; i++)
    {
        // Обхождаме всички съседи и маркираме цветовете им като заети
        vector <int>::iterator it;
        for (it = Edge[i].begin(); it != Edge[i].end(); it++)
            if (result[*it] != -1)
                available[result[*it]] = false;
 
        // Намиране на първия свободен цвят
        int cr;
        for (cr = 1; cr <= n; cr++)
            if (available[cr])
                break;
 
        result[i] = cr; // Оцветяваме i-я връх
 
        // Връща състоянието на свободните цветове
        for (it = Edge[i].begin(); it != Edge[i].end(); it++)
            if (result[*it] != -1)
                available[result[*it]] = true;
    }
 
    // Отпечатваме резултата
    for (int i = 1; i <= n; i++){
        cout << i << " " << result[i] << endl;
        //cout << i << " " << Colors[result[i]] << endl;
    }
}
 
int main() {

    int a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        addEdge(a,b);
    }

    greedyColoring();
  
    return 0;
}