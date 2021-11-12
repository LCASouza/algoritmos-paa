#include <iostream>
#include <stack>

using namespace std;

void hanoi(stack<int> *x, stack<int> *y, stack<int> *z, int n, int *cont){
    int aux;

    if(n==1){
        aux=x->top();
        x->pop();
        y->push(aux);
        *cont+=1;
        return;
    }

    hanoi(x, z, y, n-1, cont);
    aux=x->top();
    x->pop();
    y->push(aux);
    *cont+=1;
    hanoi(z, y, x, n-1, cont);
}

int main(){
    stack<int> x, y, z;
    int n=7, cont=0;//quantidade de discos e quantidade de chamadas.

    int *vet = new int[n];

    for(int i=1; i<=n; i++){
        x.push(i);
    }

    hanoi(&x, &y, &z, n, &cont);

    for(int i=0; i<n; i++){
        vet[i]=y.top();
        y.pop();
    }
    
    for(int i=0; i<n; i++){
        printf("%d\n", vet[i]);
    }
    printf("Chamadas: %d\n", cont);
}