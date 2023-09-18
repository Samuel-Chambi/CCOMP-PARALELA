#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20000;
int A[MAXN][MAXN];
int x[MAXN];
int y[MAXN];

void clean(){
    memset(y , 0 , sizeof(x));

}
void fill(){
    for(int i = 0; i < MAXN; i++) x[i] = (rand() % 50) + 1 ;
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++)
        {
            A[i][j] = (rand() % 50) + 1;
        }
    }
}
void f()
{
    for(int i = 0; i < MAXN; i++)
    {
        for(int j = 0; j < MAXN; j++){
            y[i] += A[i][j] * x[j];
        }
    }
}
 
void g(){
    for(int j = 0; j < MAXN; j++){
        for(int i = 0; i < MAXN; i++){
            y[i] += A[i][j] * x[j];    
        }
    }
}
int main()
{
    srand(time(NULL));
    unsigned start, end;
    clean();
    fill();
 
    start = clock();
    f();
    end = clock();
 
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC));
    cout << "Primer Bucle : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;

    start = clock();
    g();
    end = clock();
    time_taken = (double(end - start) / double(CLOCKS_PER_SEC));

    cout << "Segundo Bucle : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}