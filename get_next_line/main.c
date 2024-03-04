#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    //     printf("benvenuto cojone\n");
    // free(leftover);
    // if(!leftover)
    //     printf("funziona ancora\n");
    int fd = open("./test.txt", O_RDONLY);
    // char *line;
    // printf("%d\n", OPEN_MAX);
    // line = get_next_line(fd);
    // printf("%s", line);
    // free(line);
    char *str;
    for (int i = 0; i < 6; i++)
    {
    str = get_next_line(fd);
    printf("%s", str);
    if(str != NULL)
        free(str);
    }
    // printf("%s", get_next_line(fd));
}