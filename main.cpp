#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  vector<char> alfabeto = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                           'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                           'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int matrizChave[2][2] = {{2, 3}, {5, 8}};
  int matrizChaveInversa[2][2] = {{8, -3}, {-5, 2}};
  int determinante = (matrizChave[0][0] * matrizChave[1][1]) -
                     (matrizChave[0][1] * matrizChave[1][0]);
  string texto;
  int opcao;

  cout << "1 - Criptografar\n2 - Descriptografar" << endl;
  cout << "Digite a opção desejada: ";
  cin >> opcao;
  cin.ignore();

  switch (opcao) {
  case 1: {
    cout << "Digite um texto para criptografia: ";
    getline(std::cin, texto);

    if (texto.length() % 2 != 0) {
      texto += " ";
    }

    int tamanhoTexto = texto.length() / 2;
    vector<vector<int>> textoConvertido(tamanhoTexto, vector<int>(2));

    int indice = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < tamanhoTexto; j++) {

        for (int k = 0; k < alfabeto.size(); k++) {
          if (texto[indice] == alfabeto[k]) {
            textoConvertido[i][j] = (int)k;
            break;
          }
        }
        indice++;
      }
    }

    vector<vector<int>> matrizCriptografada(tamanhoTexto, vector<int>(2));
    for (int i = 0; i < tamanhoTexto; i++) {
      matrizCriptografada[0][i] = (matrizChave[0][0] * textoConvertido[0][i]) +
                                  (matrizChave[0][1] * textoConvertido[1][i]);
      matrizCriptografada[1][i] = (matrizChave[1][0] * textoConvertido[0][i]) +
                                  (matrizChave[1][1] * textoConvertido[1][i]);
    }

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < tamanhoTexto; j++) {
        cout << matrizCriptografada[i][j] << " ";
      }
      cout << endl;
    }
    break;
  }
  case 2: {
    int tamanhoMatriz;
    vector<vector<int>> matrizDescriptografada(tamanhoMatriz, vector<int>(2));

    cout << "Digite o tamanho j da matriz: ";
    cin >> tamanhoMatriz;
    vector<vector<int>> matrizCriptografada(tamanhoMatriz, vector<int>(2));

    cout << "Digite a linha 1 da matriz: ";
    for (int i = 0; i < tamanhoMatriz; i++) {
      cin >> matrizCriptografada[0][i];
    }

    cout << "Digite a linha 2 da matriz: ";
    for (int i = 0; i < tamanhoMatriz; i++) {
      cin >> matrizCriptografada[1][i];
    }
    for (int i = 0; i < tamanhoMatriz; i++) {
      matrizDescriptografada[0][i] =
          (matrizChaveInversa[0][0] * matrizCriptografada[0][i]) +
          (matrizChaveInversa[0][1] * matrizCriptografada[1][i]);
      matrizDescriptografada[1][i] =
          (matrizChaveInversa[1][0] * matrizCriptografada[0][i]) +
          (matrizChaveInversa[1][1] * matrizCriptografada[1][i]);
    }

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < tamanhoMatriz; j++) {
        cout << alfabeto[matrizDescriptografada[i][j]];
      }
    }
    break;
  }

  default:
    cout << "Opção inválida." << endl;
  }

  return 0;
}
