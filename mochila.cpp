#include <iostream>

using namespace std;

struct Item{
    int valor;
    int peso;
};

int main(){
    int n, capacidade;
    cin >> n >> capacidade;

    Item *itens = new Item[n+1];

    int **matriz = new int *[n];
    for(int i=0; i<=n; i++){
        matriz[i] = new int[capacidade+1];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacidade;j++){
            matriz[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        int valor, peso;

        cin >> valor >> peso;

        itens[i].valor = valor;
        itens[i].peso = peso;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacidade; j++){
            if(j<itens[i-1].peso){
                matriz[i][j] = matriz[i-1][j];
            }
            else{
                matriz[i][j] = max(matriz[i-1][j], matriz[i-1][j-itens[i-1].peso]+itens[i-1].valor);
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacidade;j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nItens na mochila: ";
    int j, i;
    for(j=capacidade, i=n; i>0 && j>0; i--){
        if(matriz[i][j] != matriz[i-1][j]){
            cout << i << " ";
            i--;
            j=j-itens[j].peso;
        }
    }
    cout << i << endl;

    cout << "Maior Valor Possivel: " << matriz[n][capacidade] << endl;
}