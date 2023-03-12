#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a text phrase to Morse code
void text_to_morse(char *text) {
    char *morse_codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    char *alpha_codes = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i, j;
    char c;

    for (i = 0; text[i] != '\0'; i++) {
        c = toupper(text[i]);  // Convert the character to uppercase

        if (c == ' ') {
            printf(" ");
            continue;
        }

        j = strchr(alpha_codes, c) - alpha_codes;  // Find the index of the character in the alpha_codes string

        if (j >= 0 && j <= 35) {
            printf("%s ", morse_codes[j]);  // Print the Morse code for the character
        }
    }
    printf("\n");
}

// Function to convert a Morse code phrase to text
void morse_to_text(char *morse) {
    char *morse_codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    char *alpha_codes = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char *token;
    char *rest = morse;
    int i, j;

    while ((token = strtok_r(rest, " ", &rest))) {
        for (i = 0; i < 36; i++) {
            if (strcmp(token, morse_codes[i]) == 0) {  // Compare the Morse code with the codes in the array
                printf("%c", alpha_codes[i]);  // Print the corresponding character
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    char input[100];
    int choice;

    printf("Enter a text phrase or a Morse code phrase:\n");
    fgets(input, sizeof(input), stdin);

    printf("Enter your choice:\n");
    printf("1. Text to Morse code\n");
    printf("2. Morse code to Text\n");
    scanf("%d", &choice);

    if (choice == 1) {
        text_to_morse(input);
    } else if (choice == 2) {
        morse_to_text(input);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
