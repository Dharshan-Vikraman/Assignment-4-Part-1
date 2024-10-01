#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

volatile int isRunning = 1;

void* runCount(void* arg) {
    for (int i = 1; i <= 100; i++) {
        if (!isRunning) break;
        printf("Count: %d\n", i);
        fflush(stdout);
        sleep(1);  // Simulate work
    }
    return NULL;
}

int main() {
    pthread_t thread;

    // Start the thread
    pthread_create(&thread, NULL, runCount, NULL);

    // Simulate waiting for user input to stop
    printf("Press Enter to stop...\n");
    getchar();
    isRunning = 0;  // Signal the thread to stop

    // Wait for the thread to finish
    pthread_join(thread, NULL);
    printf("Thread stopped.\n");

    return 0;
}
