#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    char player = 'o'; // caractere que representa o jogador
    int x = 5, y = 5; // coordenadas iniciais do jogador
    char move; // variavel para armazenar o movimento

    while (true) {
        system("cls"); // limpa a tela a cada iteracao
        
        // desenha o campo de jogo
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == y && j == x) cout << player; // imprime o jogador na posicao atual
                else cout << '.'; // imprime um ponto para representar o espaco vazio
            }
            cout << endl;
        }
        
        move = _getch(); // captura a tecla pressionada sem precisar de enter
        
        // move o jogador de acordo com a tecla pressionada
        if (move == 'a' && x > 0) x--; // move para a esquerda
        if (move == 'd' && x < 9) x++; // move para a direita
        if (move == 'w' && y > 0) y--; // move para cima
        if (move == 's' && y < 9) y++; // move para baixo
    }
    return 0;
}
