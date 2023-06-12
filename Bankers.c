
// not completed . 

#include <stdio.h>
#include<stdbool.h>

// Function to check if the system is in a safe state

int is_safe_state(int np, int nr, int available[], int allocation[], int max[], int need[][]) {


  // Initialize finish array to false
  int one_more = np;
  int safe_sequence[50], safe = 0;
  int finish[np];
  for (int i = 0; i < np; i++)
    finish[i] = 0;
    
  // Initialize work array with available resources
  int work[nr];
  for (int i = 0; i < nr; i++) 
    work[i] = available[i];


  // Iterate through all processes
  for (int i = 0; i < n; i++) {
    // Find a process that is not finished and that can be allocated resources
    bool found = false;
    for (int j = 0; j < np; j++) {
    
      bool need_available = true;
      for(int k = 0;  k < nr ;k++)
      	if(need[i][k] > work[k]){
      		need_available = false;
      		break;
      	}
      
      if (!finish[j] && need_available) {
      	safe_sequence[safe++] = j;
        	found = true;
        	// Update the work array
        	for (int k = 0; k < nr; k++)
          	work[k] += allocation[j][k];
         	
        	// Mark the process as finished
        	finish[j] = true;
        	one_more--;
        	break;
      }
    }

    // If no such process is found, the system is not in a safe state
    if (!found)
      return 0;

  }
  // If all processes are finished, the system is in a safe state
  return 1;
}

int main() {
  int np,nr;
  printf("Enter the number of process: ");
  scanf("%d",&np);
	
  printf("Enter the number of process: ");
  scanf("%d",&nr);
  int available[nr];
  printf("Enter the available resource :")
  for(int i =0 ;i< nr ;i++)
  	scanf("%d",available[i]);
  	
   int max[np][nr],allocation[np][nr], need[np][nr];
   printf("Enter the allocation of resource to each process :");
   for(int i = 0; i< np ; i++)
   	for(int j = 0; j< nr ;j++)
   		scanf("%d",&allocation[i][j]);
   			
   printf("Enter the max of resource to each process :");
   for(int i = 0; i< np ; i++)
   	for(int j = 0; j< nr ;j++)
   		scanf("%d",&max[i][j]);

    for (int i = 0; i < np; i++)
    	for (int j = 0; j < nr; j++)
      		need[i][j] = max[i][j] - allocation[i][j];
   
  // Check if the system is in a safe state
  if (is_safe_state(n, m, available, allocation, max, need, safe_sequence)) {
    printf("The system is in a safe state\n");
    
  } else {
    printf("The system is not in a safe state\n");

  }

  return 0;

}
