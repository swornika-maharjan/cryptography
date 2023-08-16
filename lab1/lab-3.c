#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenere_encrypt(char *text, char *key) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    
    for (int i = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            char shift = isupper(text[i]) ? 'A' : 'a';
            int key_index = i % key_length;
            int key_shift = isupper(key[key_index]) ? 'A' : 'a';
            
            text[i] = (text[i] - shift + key[key_index] - key_shift) % 26 + shift;
        }
    }
}

void vigenere_decrypt(char *text, char *key) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    
    for (int i = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            char shift = isupper(text[i]) ? 'A' : 'a';
            int key_index = i % key_length;
            int key_shift = isupper(key[key_index]) ? 'A' : 'a';
            
            text[i] = (text[i] - shift - (key[key_index] - key_shift) + 26) % 26 + shift;
        }
    }
}

int main() {
    char name[100];
    char key[50];

    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove trailing newline

    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove trailing newline

    vigenere_encrypt(name, key);
    printf("Encrypted Name: %s\n", name);

    vigenere_decrypt(name, key);
    printf("Decrypted Name: %s\n", name);

    return 0;
}
