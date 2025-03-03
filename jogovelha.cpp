#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int currentPlayer = 1;
char currentMarker;

// desenha o tabuleiro do jogo
void drawBoard() {
    system("clear");
    cout << "\n jogo da velha" << endl;
    cout << "\n " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
}

// coloca o marcador no tabuleiro
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

// verifica se ha um vencedor
int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;

    return 0;
}

// alterna entre os jogadores
void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

int main() {
    int slot;
    cout << "jogador 1, escolha seu marcador (X ou O): ";
    cin >> currentMarker;
    
    if (currentMarker != 'X' && currentMarker != 'O') {
        cout << "marcador invalido!" << endl;
        return 0;
    }
    
    drawBoard();
    
    for (int i = 0; i < 9; i++) {
        cout << "jogador " << currentPlayer << ", escolha um numero: ";
        cin >> slot;
        
        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "jogada invalida! tente novamente." << endl;
            i--;
            continue;
        }
        
        drawBoard();
        if (checkWinner()) {
            cout << "parabens! o jogador " << currentPlayer << " venceu!" << endl;
            return 0;
        }
        
        switchPlayer();
    }
    
    cout << "o jogo terminou empatado!" << endl;
    return 0;
}
