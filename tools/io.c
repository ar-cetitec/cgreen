#include "io.h"

/* Adapter to C I/O functions */

#include <string.h>


FILE *open_file(const char *filename, const char *mode) {
    return fopen(filename, mode);
}

FILE *open_process(const char *command, const char *mode) {
    return popen(command, mode);
}


/*
  read_line()   - read characters from a FILE
                - behaves like fgets() except will return
                - number of characters read and
                - EOF if at end of file
*/
int read_line(FILE *file, char *buffer, int max_length) {
    char *result = fgets(buffer, max_length, file);
    return result==NULL? EOF : strlen(result);
}
