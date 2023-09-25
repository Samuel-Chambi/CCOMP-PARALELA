#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#define Matrix vector< vector<int> >
using namespace std;
const int MAXN = 500;
Matrix A, B, C, C0;

void M1(Matrix& C, const Matrix& A, const Matrix& B)
{
    for (int f = 0; f < MAXN; ++f)
        for (int c = 0; c < MAXN; ++c)
            for (int k = 0; k < MAXN; ++k)
                C[f][c] += A[f][k] * B[k][c];
}

void M2(Matrix& C, const Matrix& A, const Matrix& B)
{
    int blockSize = 32;
    for (int i = 0; i < MAXN; i += blockSize)
        for (int j = 0; j < MAXN; j += blockSize)
            for (int k = 0; k < MAXN; k += blockSize)
                for (int i0 = i; i0 < min(i + blockSize, MAXN); i0++)
                    for (int j0 = j; j0 < min(j + blockSize, MAXN); j0++)
                        for (int k0 = k; k0 < min(k + blockSize, MAXN); k0++)
                            C[i0][j0] += A[i0][k0] * B[k0][j0];
}

int main()
{
    srand(time(NULL));
    A.assign(MAXN, vector<int>(MAXN, 0));
    B.assign(MAXN, vector<int>(MAXN, 0));
    C.assign(MAXN, vector<int>(MAXN, 0));
    C0.assign(MAXN, vector<int>(MAXN, 0));
    // Inicializa A
    for(auto& v : A) for(int& i : v) i = (rand() % 50) + 1;
    // Inicializa B
    for(auto& v : B) for(int& i : v) i = (rand() % 50) + 1;
    double startTime, endTime;

    startTime = clock();
    M1(C,A,B);
    endTime = clock();
    cout << "1era Multiplicacion: " << (double)((endTime - startTime)/(1000.0)) << " ms\n";

    startTime = clock();
    M2(C0,A,B);
    endTime = clock();
    cout << "2da Multiplicacion: " << (double)((endTime - startTime)/(1000.0)) << " ms\n";

    // Matrices iguales al terminar 
    (C == C0) ? cout << "YES\n" : cout << "NO\n";

    return 0;
}