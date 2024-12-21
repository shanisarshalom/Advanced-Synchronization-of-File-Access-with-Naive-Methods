#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

void write_message(const char *message, int count, const char *output_file) {
    // open the output_file in write-only and append mode.
    int fd = open(output_file, O_WRONLY | O_APPEND);
    // if opening the file fails, print error message and exit.
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    // write message to file count times.
    for (int i = 0; i < count; ++i) {
        if (write(fd, message, strlen(message)) == -1) {
            // if write to file fails, print error message and exit.
            perror("Error writing to file");
            close(fd);
            exit(EXIT_FAILURE);
        }
        // add newline after each message.
        if (write(fd, "\n", 1) == -1) {  
            // if write to file fails, print error message and exit.
            perror("Error writing to file");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }
    // close the file descriptor.
    close(fd);
}

int main(int argc, char *argv[]) {
    // ensure the program accepts four arguments: parent message, child1 message, child2 message, and the count of writes.
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <parent_message> <child1_message> <child2_message> <count>\n", argv[0]);
        return 1;
    }

    // assign the command-line arguments to variables.
    const char *parent_message = argv[1];
    const char *child1_message = argv[2];
    const char *child2_message = argv[3];
    // convert the count argument from a string to an integer.
    int count = atoi(argv[4]);

    // set output_file to "output.txt".
    const char *output_file = "output.txt";

    // create the file if it doesn't already exist.
    // O_TRUNC - if the file already exists, file content is cleared.
    int fd = open(output_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    close(fd);

    // declare two pid_t variables child1 and child2.
    pid_t child1, child2;

    // child 1 process.
    if ((child1 = fork()) == 0) {
        sleep(5);
        // call write_message to write child1_message to the file and exit.
        write_message(child1_message, count, output_file);
        return 0;
    // if fork returns -1, print error message and return 1.
    } else if (child1 == -1) {
        perror("Error forking child 1");
        return 1;
    }
    
    // child 2 process.
    if ((child2 = fork()) == 0) {
        sleep(10);
        write_message(child2_message, count, output_file);
        return 0;
    } else if (child2 == -1) {
        perror("Error forking child 2");
        return 1;
    }

    // parent process waits for both child processes to complete.
    if (waitpid(child1, NULL, 0) == -1) {
        perror("Error waiting for child 1");
    }
    if (waitpid(child2, NULL, 0) == -1) {
        perror("Error waiting for child 2");
    }

    // parent process writes its message.
    write_message(parent_message, count, output_file);

    return 0;
}
