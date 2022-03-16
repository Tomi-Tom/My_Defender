/*
** EPITECH PROJECT, 2022
** MY_READ_FILE_C
** File description:
** my_read_file
*/

#include "my.h"

char *my_read_file(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buf = NULL;
    struct stat st;
    int ret = 0;

    if (fd == -1)
        return NULL;
    ret = stat(file, &st);
    if (ret == -1)
        return NULL;
    buf = malloc(sizeof(char) * (st.st_size + 1));
    if (buf == NULL)
        return NULL;
    ret = read(fd, buf, st.st_size);
    if (ret == -1)
        return NULL;
    buf[st.st_size] = '\0';
    return buf;
}
