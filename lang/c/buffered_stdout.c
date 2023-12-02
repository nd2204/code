#include <stdio.h>
#include <unistd.h>

int main() {
    // Print some data to stdout
    printf("This is some data");

    // The following line ensures that the data is immediately displayed by flushing the buffer
    fflush(stdout);

    // Sleep for a while to observe the buffering effect

    sleep(2);

    // Print more data
    printf("More data\n");

    // No need to fflush(stdout) here; the program will automatically flush the buffer when it exits

    return 0;
}

