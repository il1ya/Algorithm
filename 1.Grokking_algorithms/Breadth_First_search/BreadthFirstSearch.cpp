// Алгоритм поиска в ширину
#include <iostream>
#include <vector>
#include <queue>                        // подключаем заголовочный файл очереди
int main()
{
    std::vector<std::vector<int> > g;   // граф
    const int n = 4;                    // число вершин
    int s = 0;                          // стартовая вершина (вершины везде нумеруются с нуля)
    // чтение графа
    int Adj[n][n] {{0,0,1,0}, {0,0,1,0}, {0,0,0,1}, {0,2,0,0}};
    for(int i = 0; i < n; i++){
        g.push_back(std::vector<int>());
        for(int j = 0; j < n; j++){
            if(Adj[i][j])
                g[i].push_back(j);
                /*g[i].push_back(0);
                g[i][j]=Adj[i][j];*/
        }
    }
    std::queue<int> q;
    q.push(s);
    std::vector<bool> used(n);
    std::vector<int> d(n), p(n);
    used[s] = true;
    p[s] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(size_t i = 0; i < g[v].size(); ++i){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    for(int i = 0; i < n; i++)
        std::cout << d[i] << " ";
        std::cout << std::endl;
        return 0;
}
/*
для того какой результат Вы находите Вам вообще не нужен вектор p. 
вы просто выводите расстояния от вершины 0 до всех остальных вершин (причем если расстояние 0 (за исключением самой вершины 0), то значит вершина вообще недостижима из вершины 0). 
Вектор p нужен только когда нужно будет вывести на экран не длинну пути, а сам путь (через какие вершины проходит самый короткий путь от вершины 0 до нужной вершины).
Взята с http://www.cyberforum.ru/cpp-beginners/thread235665.html */