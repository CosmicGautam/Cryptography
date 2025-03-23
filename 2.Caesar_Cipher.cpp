#include <stdio.h>
#include <string.h>
void encrypt(char *plaintext) {
	int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = (plaintext[i] - 'A' + 3) % 26 + 'A';
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = (plaintext[i] - 'a' + 3) % 26 + 'a';
        }
    }
}
void decrypt(char *ciphertext) {
	int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = (ciphertext[i] - 'A' - 3 + 26) % 26 + 'A';
        }
        else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            ciphertext[i] = (ciphertext[i] - 'a' - 3 + 26) % 26 + 'a';
        }
    }
}

int main() {
    char text[100];
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    encrypt(text);
    printf("Encrypted text: %s\n", text);
    decrypt(text);
    printf("Decrypted text: %s\n", text);
    printf("Name:Cosmic Gautam\tRoll no.:07");
    return 0;
}

