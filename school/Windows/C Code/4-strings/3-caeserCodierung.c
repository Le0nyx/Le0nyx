#include <stdio.h>

void encode(char* message, int shift) {
    int i = 0;
    while (message[i] != '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        }
        i++;
    }
} 

void decode(char* message, int shift) {
    encode(message, 26 - shift);
}

int main() {
    char message[] = "abc";
    int shift = 3;

    printf("Original message: %s\n", message);

    encode(message, shift);
    printf("Encoded message: %s\n", message);

    decode(message, shift);
    printf("Decoded message: %s\n", message);

    return 0;
}
