#include <iostream>
using namespace std;
int main()
{

}
void StirlingNumber2(int m, int n)
{
    int min;
    int S[100][100];
    S[0][0] = 1;
    for(int i = 1; i <= m; i++)S[i][0];
    for(int i = 0; i < m; i++)S[i][i - 1] = 0;
    for(int i = 1; i <= m; i++)
    {
        if(i < n)min = i;else min = n;
        for(int j = 1; j <= min; j++)
            S[i][j] = j * S[i - 1][j] + S[i - 1][j - 1];

    }
}

int computeB(int m)
{
    int B[100];
    int S[100][100];
    StirlingNumber2(m, m);
    for(int i = 0; i < m; i++) B[i] = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j <= i; j++) {
            B[i - 1] *= S[i][j];
        }
    }
    return B[m - 1];
}