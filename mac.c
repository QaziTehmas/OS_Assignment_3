#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void encrypt_file(const char* filename, const char* data) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0600);
    if (fd == -1) {
        perror("Failed to open file");
        return;
    }
    write(fd, data, strlen(data));
    close(fd);
}

int main() {
    const char* filename = "securefile.txt";
    const char* data = "Sensitive information";

    encrypt_file(filename, data);
    printf("Data written to %s\n", filename);

    return 0;
}