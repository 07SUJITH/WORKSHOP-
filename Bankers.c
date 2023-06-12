#include <stdio.h>

// Function to check if the system is in a safe state

int is_safe_state(int n, int m, int available[], int allocation[], int max[], int need[]) {

  // Initialize finish array to false

  int finish[n];

  for (int i = 0; i < n; i++) {

    finish[i] = 0;

  }

  // Initialize work array with available resources

  int work[m];

  for (int i = 0; i < m; i++) {

    work[i] = available[i];

  }

  // Iterate through all processes

  for (int i = 0; i < n; i++) {

    // Find a process that is not finished and that can be allocated resources

    bool found = false;

    for (int j = 0; j < n; j++) {

      if (!finish[j] && need[j] <= work) {

        found = true;

        // Update the work array

        for (int k = 0; k < m; k++) {

          work[k] -= need[j][k];

        }

        // Mark the process as finished

        finish[j] = true;

        break;

      }

    }

    // If no such process is found, the system is not in a safe state

    if (!found) {

      return 0;

    }

  }

  // If all processes are finished, the system is in a safe state

  return 1;

}

int main() {

  // Number of processes

  int n = 5;

  // Number of resources

  int m = 3;

  // Available resources

  int available[] = {3, 3, 2};

  // Allocation of resources to processes

  int allocation[][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

  // Maximum resources that can be used by processes

  int max[][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};

  // Need of processes

  int need[n][m];

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < m; j++) {

      need[i][j] = max[i][j] - allocation[i][j];

    }

  }

  // Check if the system is in a safe state

  if (is_safe_state(n, m, available, allocation, max, need)) {

    printf("The system is in a safe state\n");

  } else {

    printf("The system is not in a safe state\n");

  }

  return 0;

}
