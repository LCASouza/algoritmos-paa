#include <iostream>
#include <iomanip>
#include <list>

using namespace std;
 
bool verifica(int a, int b, bool **mat) { 
    return mat[a][b];
}
 
int encontrarC(int n, bool **mat)
{
    if (n == 0){
        return -1;
    }
 
    int end = encontrarC(n - 1, mat);
 
    if (end == -1){
        return n - 1;
    }
    else if (verifica(n - 1, end, mat)) {
        return end;
        return end;
    }
 
    return -1;
}
 
int celebridade(int n, bool **mat)
{
    int end;
    end = encontrarC(n, mat);
 
    if (end == -1){
        return end;
    }
    else {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++){
            if (i != end) {
                c1 += verifica(end, i, mat);
                c2 += verifica(i, end, mat);
            }
        }

        if (c1==0 && c2==n-1){
            return end;
        }

        return -1;
    }
}
 
int main()
{
    int n = 4;
    bool **mat = new bool *[n];
    for(int i=0; i<n; i++)
        mat[i]=new bool[n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    int end = celebridade(n, mat);

    if(end==-1){
        printf("Nao ha celebridade!\n");
    }
    else{
        printf("A celebridade e a pessoa de posicao %d na matriz!\n", end);
    }
}