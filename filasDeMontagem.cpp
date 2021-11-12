#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int inicio1 = 2, inicio2 = 4, saida1 = 3, saida2 = 2;
    int linha = 2, coluna = 6;
    int estacao = 0, peso = 0;

    int *utilizados = new int[coluna];

    int** matriz = new int* [linha];
    for (int i = 0; i < linha; i++) {
        matriz[i] = new int[coluna];
    }

    pair<int, int>** matrizPair = new pair<int, int>*[linha];
    for (int i = 0; i < linha; i++) {
        matrizPair[i] = new pair<int, int>[coluna];
    }

    for (int j = 0; j < coluna; j++) {
        for (int i = 0; i < linha; i++) {
            cin >> estacao >> peso;
            matrizPair[i][j].first = estacao;
            matrizPair[i][j].second = peso;
        }
    }

    matriz[0][0] = inicio1 + matrizPair[0][0].first;
    matriz[1][0] = inicio2 + matrizPair[1][0].first;

    if (matriz[0][0] < matriz[1][0]) {
        utilizados[0] = 1;
    }
    else {
        utilizados[0] = 2;
    }

    for (int j = 1; j < coluna; j++) {
        for (int i = 0; i < linha; i++) {
            if (i==0) {
                matriz[i][j] = min(matriz[0][j - 1], (matriz[1][j - 1] + matrizPair[1][j - 1].second)) + matrizPair[i][j].first;
                if (matriz[0][j - 1] + matrizPair[i][j].first != matriz[i][j]) {
                    utilizados[j] = 2;
                }
                else {
                    utilizados[j] = 1;
                }
            }
            else {
                matriz[i][j] = min(matriz[1][j - 1], (matriz[0][j - 1] + matrizPair[0][j - 1].second)) + matrizPair[i][j].first;
                if (matriz[1][j - 1] + matrizPair[i][j].first != matriz[i][j]) {
                    utilizados[j] = 1;
                }
                else {
                    utilizados[j] = 2;
                }
            }
        }
    }

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i < coluna; i++) {
        cout << utilizados[i] << " ";
    }
    if (matriz[0][coluna-1]+saida1 < matriz[1][coluna-1]+saida2) {
        cout << '1';
    }
    else {
        cout << '2';
    }
    cout << endl;
}