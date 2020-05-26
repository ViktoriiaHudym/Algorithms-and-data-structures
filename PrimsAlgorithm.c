#include <stdio.h>
#include <conio.h>
#define INFINITY 999


int main()
{
    rewind(stdin);

    int u, v, n, i, j, N=1;
    int visited[10]={0}, min, mincost = 0, graph[10][10];
    int letter = 65, letterList[10]; // Для виводу назв вершин латинськими літерами

    printf("Enter the number of nodes:");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:\n");

    for (i=0; i<n; i++){
        letterList[i] = letter;
        letter++;
    }
    letter = 65;
    for (i=0; i<n; i++) printf(" %c", letterList[i]);
    printf("\n");

    for(i=1; i<n+1; i++){ // Введення матриці суміжності
        printf("%c", letter);
        for(j=1; j<n+1; j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==0) graph[i][j]=INFINITY;
        }
        letter++;
    }
    letter = 64;

    visited[1] = 1; // Перша пройдена вершина
    while (N<n){ // Допоки не відбувся прохід по усіх вершинах
        for (i=1, min=INFINITY; i<n+1; i++) // Знаходимо позицію інцидентної вершини з мінімальним ребром
            for (j=1;j<n+1;j++)
                if (graph[i][j] < min)
                    if (visited[i]!=0){
                        min = graph[i][j];
                        u = i; // u - вершина початку ребра
                        v = j; // v - вершина кінця ребра
                    }
        if (visited[u]==0 || visited[v]==0){
           printf("\n %c-->%c   cost:%d", letter+u, letter+v, min);
           mincost += min;
           visited[v] = 1;
           N++;
        }
        graph[u][v]=graph[v][u] = INFINITY; // Деініціалізуємо залучену вершину
    }

    printf("\n\nMinimum cost = %d", mincost);
    getch();
    return 0;
}
