#include <iostream>
using namespace std;
int main()
{

}
template <class Type>
void Perm(Type list[], int k, int m)
{
    if(k == m)
    {
        for(int i = 0; i <= m; i++)cout << list[i];
        cout << endl;
    }
    else for(int i = k; i <= m; i++)
        if(ok(list, k, i))
        {
            Swap(list[k], list[i]);
            Perm(list, k+1, m);
            Swap(list[k], list[i]);
        }
}
template <class Type>
int ok(Type list[], int k, int i)
{
    if(i > k)for(int t = k; t < i; t++)if(list[t] == list[i])return 0;
    return 1;
}