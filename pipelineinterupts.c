#include <stdio.h>
#include <signal.h>
#include <unistd.h>
 
// Signal handler function
void handleInterrupt(int signum) {
    printf("Received interrupt signal (Ctrl+C) - exiting\n");
	// You can perform cleanup or additional actions here
	_exit(0);  // Terminate the program immediately
}
 
int main() {
	// Set up the signal handler
	if (signal(SIGINT, handleInterrupt) == SIG_ERR) {
        perror("Error setting up signal handler");
    	return 1;
	}
 
	// Run an infinite loop
	while (1) {
        printf("Program is running...\n");
    	sleep(1);  // Simulate some work
	}
 
    return 0;
}
