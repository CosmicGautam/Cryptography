#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
// Function to prepare the key matrix
void prepareKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int i, j, k;
    char *keySet = (char *)calloc(26, sizeof(char));
    int len = strlen(key);
    // Fill the keySet with the key
    for (i = 0, k = 0; i < len; i++) {
        if (key[i] != 'j' && !keySet[toupper(key[i]) - 'A']) {
            keySet[toupper(key[i]) - 'A'] = 1;
            keyMatrix[k / SIZE][k % SIZE] = toupper(key[i]);
            k++;
        }
    }
    // Fill the rest of the matrix with the remaining letters
    for (i = 0; i < 26; i++) {
        if (keySet[i] == 0 && i != ('J' - 'A')) {
            keyMatrix[k / SIZE][k % SIZE] = 'A' + i;
            k++;
        }
    }

    free(keySet);
}
// Function to find the position of a character in the key matrix
void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // Treat 'J' as 'I'
	int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
// Function to encrypt a digraph using the Playfair cipher
void encryptDigraph(char keyMatrix[SIZE][SIZE], char a, char b) {
    int row1, col1, row2, col2;

    findPosition(keyMatrix, a, &row1, &col1);
    findPosition(keyMatrix, b, &row2, &col2);

    if (row1 == row2) {
        printf("%c%c", keyMatrix[row1][(col1 + 1) % SIZE], keyMatrix[row2][(col2 + 1) % SIZE]);
    } else if (col1 == col2) {
        printf("%c%c", keyMatrix[(row1 + 1) % SIZE][col1], keyMatrix[(row2 + 1) % SIZE][col2]);
    } else {
        printf("%c%c", keyMatrix[row1][col2], keyMatrix[row2][col1]);
    }
}
// Function to prepare the plaintext for encryption
void preparePlaintext(char *plaintext) {
    int i,len = strlen(plaintext);
    for (i = 0; i < len; i++) {
        plaintext[i] = toupper(plaintext[i]);
        if (plaintext[i] == 'J') plaintext[i] = 'I'; // Replace 'J' with 'I'
    }
    for (i = 0; i < len - 1; i += 2) {
        if (plaintext[i] == plaintext[i + 1]) {
            memmove(&plaintext[i + 1], &plaintext[i], len - i);
            plaintext[i + 1] = 'X';
            len++;
            plaintext[len] = '\0';
        }
    }
    if (len % 2 != 0) {
        plaintext[len] = 'X';
        plaintext[len + 1] = '\0';
    }
}
void encryptPlayfair(char keyMatrix[SIZE][SIZE], char *plaintext) {
    int i,len = strlen(plaintext);
    for (i = 0; i < len; i += 2) {
        encryptDigraph(keyMatrix, plaintext[i], plaintext[i + 1]);
    }
    printf("\n");
}

int main() {
    char key[100];
    char plaintext[100];
    char keyMatrix[SIZE][SIZE];
    printf("Enter the key: ");
    scanf("%s", key);
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    prepareKeyMatrix(key, keyMatrix);
    preparePlaintext(plaintext);
    printf("Encrypted text: ");
    encryptPlayfair(keyMatrix, plaintext);
    printf("Name:Cosmic Gautam\tRoll no.:07");
    return 0;
}
