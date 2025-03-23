#include <stdio.h>
#include <string.h>
void encrypt(char *plaintext, int shift) {
	int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = (plaintext[i] - 'A' + shift) % 26 + 'A';
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = (plaintext[i] - 'a' + shift) % 26 + 'a';
        }
    }
}
void decrypt(char *ciphertext, int shift) {
	int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = (ciphertext[i] - 'A' - shift + 26) % 26 + 'A';
        }
        else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            ciphertext[i] = (ciphertext[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

int main() {
    char text[100];
    int shift;
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter shift value: ");
    scanf("%d", &shift);
    encrypt(text, shift);
    printf("Encrypted text: %s\n", text);
    decrypt(text, shift);
    printf("Decrypted text: %s\n", text);
    printf("Name:Cosmic Guatam\tRoll no.:07");
    return 0;
}

