#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int shift) {
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift);
}

int main() {
    char name[100];
    int shift;

    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  

    printf("Enter the shift value (key): ");
    scanf("%d", &shift);
    getchar();  

    encrypt(name, shift);
    printf("Encrypted Name: %s\n", name);

    decrypt(name, shift);
    printf("Decrypted Name: %s\n", name);

    return 0;
}
