/*
** EPITECH PROJECT, 2022
** MY_READ_FILE_C
** File description:
** my_read_file
*/

#include "my.h"

char *my_alloc_sizeof_file(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    size_t file_size = 0;
    ssize_t read_size;
    size_t n = 0;
    char *buffer;

    if (file == NULL)
        return NULL;
    do {
        buffer = NULL;
        read_size = getline(&buffer, &n, file);
        free(buffer);
        file_size += read_size;
    } while (read_size != -1);
    return malloc(sizeof(char) * (file_size + 2));
}

char *my_read_file(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *result = my_alloc_sizeof_file(filepath);
    char *buffer;
    ssize_t read_size = 0;
    size_t n = 0;

    if (file == NULL || result == NULL)
        return NULL;
    result[0] = '\0';
    while (read_size != -1) {
        buffer = NULL;
        read_size = getline(&buffer, &n, file);
        if (read_size > 0)
            my_strcat(result, buffer);
        free(buffer);
    }
    return result;
}
