#include <stdio.h>
#include <stdbool.h>

struct Player {
    char letter;
    int turn;
};

bool gameCheck(int boardState[3][3]);

int main() {
    char boardGraph[] = "|0|1|2|\n|3|4|5|\n|6|7|8|";
    int boardState[3][3];
    int toPlace;
    int turnNum = 0;
    int count = 0;
    bool gameOver = false;
    struct Player p1 = {'O', 0};
    struct Player p2 = {'X', 1};
    struct Player curr = p1;
    while(gameOver != 1) {
        printf("Turn %d\n", turnNum);
        printf(boardGraph);
        while(true) {
            printf("\nChoose a place to place a %c : ", curr.letter);
            scanf("%d", &toPlace);
            if (boardState[toPlace / 3][toPlace % 3] == 0 || boardState[toPlace / 3][toPlace % 3] == 1) {
                printf("\nCan't place there!");
            }
            else {
                break;
            }
        }
        boardState[toPlace / 3][toPlace % 3] = curr.turn;
        if (toPlace <= 2) {     //places tic in ttt 
            boardGraph[(toPlace * 2) + 1] = curr.letter;
        }
        else if (toPlace <= 5) {
            boardGraph[(toPlace * 2) + 3] = curr.letter;
        }
        else if (toPlace <= 8) {
            boardGraph[(toPlace * 2) + 5] = curr.letter;
        }
        if (gameCheck(boardState)) { //checks for win
            if (curr.letter == 'O') {
                printf(boardGraph);
                printf("\nO wins!");
                break;
            }
            else {
                printf(boardGraph);
                printf("\nX wins!");
                break;
            }
        }
        else {
            for (int i = 0; i < 3; i++) { //checks for tie
                for (int j = 0; j < 3; j++) {
                    if (boardState[i][j] == 0 || boardState[i][j] == 1) {
                        count++;
                    }
                }
            }
            if (count == 9) {
                printf(boardGraph);
                printf("\nTie!");
                break;
            }
            count = 0;
            turnNum++;
            if (turnNum % 2 == 0) {
                curr = p1;
            }
            else {
                curr = p2;
            }
        }
    }
    return 0;
}

bool gameCheck(int boardState[3][3]) {
    for (int i = 0; i < 3; i ++) {
        if (boardState[i][0] == boardState[i][1] && boardState[i][1] == boardState[i][2]) {
            return true;
        }
        if (boardState[0][i] == boardState[1][i] && boardState[1][i] == boardState[2][i]) {
            return true;
        }
    }
    if (boardState[0][0] == boardState[1][1] && boardState[1][1] == boardState[2][2]) {
        return true;
    }
    if (boardState[0][2] == boardState[1][1] && boardState[1][1] == boardState[2][0]) {
        return true;
    }
    return false;
}