//
// Created by Duarte Matias on 17/10/2026.
//

#include "Ecra.h"

Ecra::Ecra(){
  limparEcra();
}
bool Ecra::limparEcra()noexcept{
  for(int i = 0; i < Settings::ecra_max_linhas ; i++){
    for(int j = 0; j < Settings::ecra_max_colunas ; j++){
      buffer[i][j] = ' ';
    }
  }
  return true;
}

bool Ecra::posicionarCursor(int linha, int coluna)noexcept{

 return true;
}
bool Ecra::escreverEcra(const string palavra, int linha, int coluna) noexcept {
  if (linha < 0 || linha >= Settings::ecra_max_linhas || coluna < 0 || coluna >= Settings::ecra_max_colunas) {
    return false;
  }
  int i = 0;
  int lin = linha;
  int col = coluna;

  while (i < palavra.length()) {

    if (col >= Settings::ecra_max_colunas) {
      col = 0;
      lin++;
    }

    if (lin >= Settings::ecra_max_linhas) {
      break;
    }

    buffer[lin][col] = palavra[i];

    col++;
    i++;
  }

  return true;
}

bool Ecra::desenharMoldura(int linha, int coluna, int largura, int altura) noexcept {
  for (int i = 0; i < altura; ++i) {
    for (int j = 0; j < largura; ++j) {
      int l = linha + i;
      int c = coluna + j;

      if (l >= 0 && l < Settings::ecra_max_linhas && c >= 0 && c < Settings::ecra_max_colunas) {
        if ((i == 0 && j == 0) || (i == 0 && j == largura - 1) ||
            (i == altura - 1 && j == 0) || (i == altura - 1 && j == largura - 1)) {
          buffer[l][c] = '+';
            }
        else if (i == 0 || i == altura - 1) {
          buffer[l][c] = '-';
        }
        else if (j == 0 || j == largura - 1) {
          buffer[l][c] = '|';
        }
      }
    }
  }
  return true;
}

bool Ecra::mostra() const noexcept {
  int ultimaLinhaComConteudo = 0;

  for (int i = 0; i < Settings::ecra_max_linhas; ++i) {
    bool linhaVazia = true;
    for (int j = 0; j < Settings::ecra_max_colunas; ++j) {
      if (buffer[i][j] != ' ') {
        linhaVazia = false;
        break;
      }
    }
    if (!linhaVazia) {
      ultimaLinhaComConteudo = i;
    }
  }

  for (int i = 0; i <= ultimaLinhaComConteudo && i < Settings::ecra_max_linhas; ++i) {
    int ultimaColunaComConteudo = 0;
    for (int j = 0; j < Settings::ecra_max_colunas; ++j) {
      if (buffer[i][j] != ' ') {
        ultimaColunaComConteudo = j;
      }
    }

    for (int j = 0; j <= ultimaColunaComConteudo; ++j) {
      cout << buffer[i][j];
    }
    cout << '\n';
  }
  return true;
}
Ecra::~Ecra(){

}