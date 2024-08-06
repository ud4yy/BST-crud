#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char morseToEnglishChar(const char *morse) {
    if (strcmp(morse, ".-") == 0) return 'a';
    if (strcmp(morse, "-...") == 0) return 'b';
    if (strcmp(morse, "-.-.") == 0) return 'c';
    if (strcmp(morse, "-..") == 0) return 'd';
    if (strcmp(morse, ".") == 0) return 'e';
    if (strcmp(morse, "..-.") == 0) return 'f';
    if (strcmp(morse, "--.") == 0) return 'g';
    if (strcmp(morse, "....") == 0) return 'h';
    if (strcmp(morse, "..") == 0) return 'i';
    if (strcmp(morse, ".---") == 0) return 'j';
    if (strcmp(morse, "-.-") == 0) return 'k';
    if (strcmp(morse, ".-..") == 0) return 'l';
    if (strcmp(morse, "--") == 0) return 'm';
    if (strcmp(morse, "-.") == 0) return 'n';
    if (strcmp(morse, "---") == 0) return 'o';
    if (strcmp(morse, ".--.") == 0) return 'p';
    if (strcmp(morse, "--.-") == 0) return 'q';
    if (strcmp(morse, ".-.") == 0) return 'r';
    if (strcmp(morse, "...") == 0) return 's';
    if (strcmp(morse, "-") == 0) return 't';
    if (strcmp(morse, "..-") == 0) return 'u';
    if (strcmp(morse, "...-") == 0) return 'v';
    if (strcmp(morse, ".--") == 0) return 'w';
    if (strcmp(morse, "-..-") == 0) return 'x';
    if (strcmp(morse, "-.--") == 0) return 'y';
    if (strcmp(morse, "--..") == 0) return 'z';
    if (strcmp(morse, "-----") == 0) return '0';
    if (strcmp(morse, ".----") == 0) return '1';
    if (strcmp(morse, "..---") == 0) return '2';
    if (strcmp(morse, "...--") == 0) return '3';
    if (strcmp(morse, "....-") == 0) return '4';
    if (strcmp(morse, ".....") == 0) return '5';
    if (strcmp(morse, "-....") == 0) return '6';
    if (strcmp(morse, "--...") == 0) return '7';
    if (strcmp(morse, "---..") == 0) return '8';
    if (strcmp(morse, "----.") == 0) return '9';
    return '\0'; // Return null character for unknown Morse code
}

void morseToEnglish(const char *morsecode, char *result) {
    char *copy = strdup(morsecode);  // Duplicate the string to avoid modifying the original
    char *token = strtok(copy, " ");
    int resultIndex = 0;

    while (token != NULL) {
        if (strcmp(token, "") == 0) {
            result[resultIndex++] = ' ';
        } else {
            result[resultIndex++] = morseToEnglishChar(token);
        }
        token = strtok(NULL, " ");
    }
    result[resultIndex] = '\0';  // Null-terminate the result string
    free(copy);  // Free the duplicated string
}

int main() {
    const char *morsecode = "... --- ...";
    char result[100];  // Ensure this is large enough to hold the result

    morseToEnglish(morsecode, result);
    printf("%s\n", result);  // Should output "sos"

    return 0;
}
