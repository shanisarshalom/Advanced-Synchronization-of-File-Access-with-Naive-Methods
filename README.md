# Advanced Synchronization of File Access with Naive Methods

The objective is to explore the challenges of synchronizing file access between parent and child processes using naive methods like `wait` or `sleep` in a multi-process scenario. The program is designed to handle input parameters for testing and ensures proper sequence of file writes.

## Implementation Steps

1. Create a file named `output.txt` to store the output of all processes.
2. Fork two child processes from the parent process.
3. Ensure each process writes to the file a specific number of times without interleaving their outputs.
4. Use naive synchronization methods like `wait` or `sleep` to coordinate file writes.
5. Implement error handling for system calls (`fork`, `wait`, `sleep`) using `perror`.
6. Accept command-line arguments to define the messages and the number of times each process writes to the file.

### 2. Input Parameters

The program accepts the following command-line arguments:

1. Parent process message
2. Child process 1 message
3. Child process 2 message
4. Number of writes per process

### 3. Expected Output 

The program accepts the following command-line arguments:
`Child1 message\n
Child1 message\n
Child1 message\n
Child2 message\n
Child2 message\n
Child2 message\n
Parent message\n
Parent message\n
Parent message`
