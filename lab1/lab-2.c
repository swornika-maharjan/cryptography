#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int key[2][2]) {
    int len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        int x = text[i] - 'A';
        int y = (i + 1 < len) ? text[i + 1] - 'A' : 23; 
        int enc_x = (key[0][0] * x + key[0][1] * y) % 26;
        int enc_y = (key[1][0] * x + key[1][1] * y) % 26;
        text[i] = enc_x + 'A';
        text[i + 1] = enc_y + 'A';
    }
}

void decrypt(char *text, int key[2][2]) {
    int len = strlen(text);
    int det_inv = 0;
    
    
    for (int i = 1; i <= 25; ++i) {
        if ((key[0][0] * key[1][1] - key[0][1] * key[1][0]) * i % 26 == 1) {
            det_inv = i;
            break;
        }
    }
    
    for (int i = 0; i < len; i += 2) {
        int enc_x = text[i] - 'A';
        int enc_y = text[i + 1] - 'A';
        int dec_x = (det_inv * (key[1][1] * enc_x - key[0][1] * enc_y + 26)) % 26;
        int dec_y = (det_inv * (-key[1][0] * enc_x + key[0][0] * enc_y + 26)) % 26;
        text[i] = dec_x + 'A';
        text[i + 1] = dec_y + 'A';
    }
}

int main() {
    char name[100];
    int key[2][2];

    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  

    printf("Enter the 2x2 key matrix:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &key[i][j]);
        }
    }

    encrypt(name, key);
    printf("Encrypted Name: %s\n", name);

    decrypt(name, key);
    printf("Decrypted Name: %s\n", name);

    return 0;
}
