# Advanced Synchronization of File Access with Naive Methods

The objective is to explore the challenges of synchronizing file access between parent and child processes using naive methods like `wait` or `sleep` in a multi-process scenario. The program handles input parameters for testing and ensures a proper sequence of file writes.

## Implementation Steps

1. **Create the Output File**: Create a file named `output.txt` to store the output of all processes.
2. **Fork Processes**: Fork two child processes from the parent process.
3. **File Write Synchronization**: Ensure each process writes to the file a specific number of times without interleaving their outputs.
4. **Naive Synchronization**: Use naive synchronization methods like `wait` or `sleep` to coordinate file writes.
5. **Error Handling**: Implement error handling for system calls (`fork`, `wait`, `sleep`) using `perror`.
6. **Command-Line Input**: Accept command-line arguments to define the messages and the number of times each process writes to the file.

## Input Parameters

The program accepts the following command-line arguments:

1. **Parent Process Message**: The message that the parent process writes to the file.
2. **Child Process 1 Message**: The message that the first child process writes to the file.
3. **Child Process 2 Message**: The message that the second child process writes to the file.
4. **Number of Writes**: The number of times each process writes its message to the file.

## Expected Output

The file `output.txt` will contain messages written in the following sequence:

