// This script converts a given Windows file path into a Unix-compatible file path.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN 1024

char* convert(char* path);

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: unify <windows path with single quotes>\n");
        return 1;
    }

    char* path = argv[1];
    char* result = convert(path);

    printf("Windows file path: %s\n", result);

    free(result);
}

char* convert(char* path) {
    char* result = malloc(strnlen(path, MAXLEN) + 6);
    // Store the original pointer to the start of the string so it can be returned
    char* resultStart = result;

    // Add the opening quotes and the first slash
    result[0] = '\'';
    result[1] = '\"';
    result[2] = '/';

    result += 3;
    
    while(*path) {
        // Replace backslashes with forwardslashes
        if(*path == '\\') {
            *result = '/';
        // Otherwise, just copy the characters
        } else {
            *result = *path;
        }

        result++;
        path++;
    }

    // Add the closing quotes
    result[0] = '\"';
    result[1] = '\'';
    result[2] = '\0';

    return resultStart;
}
