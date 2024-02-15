#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h> 
#include <sys/wait.h>

struct process  
{  
    char pname[20];  
    int arrivalTime;  
    int executionTime;
    int finished;
    int arrived;
};


void bubble_sort(struct process *Processes) {
	struct process t;
	int i, j;
	int n = 4;
	for (i = 1; i < n; i++)
		for (j = 0; j < n - i; j++) {
			if (Processes[j].arrivalTime > Processes[j + 1].arrivalTime) {
				t = Processes[j];
				Processes[j] = Processes[j + 1];
				Processes[j + 1] = t;
			}
		}
}



int processesFinished(struct process *Processes){
	int finished = 1;
	for(int i =0; i<4; i++){
		if(Processes[i].finished = 0){
			return 0;
		}
	}
	return finished;
}

void roundRobin(struct process *Processes){
	printf("\nYou have chosen Round Robin\n");

	int timeQuantum;

	printf("Enter time quantum:\n");

	scanf("%d", &timeQuantum);

	// printf("Length :%d\n", len);
	int queue[5] = {0};
	int elementsInQueue = 1;
	int time=0;
	int front_queue=0;

	while(elementsInQueue > 0){
		
		printf("\nelementsInQueue: %d\n", elementsInQueue);


		int i = queue[front_queue]; 
		elementsInQueue-=1;
		Processes[i].arrived=1;

		if(elementsInQueue > 1){
			front_queue+=(front_queue+1)%4;
		}else {
			front_queue=0;
		}

		if(!Processes[i].finished){
			if(time >= Processes[i].arrivalTime){
				printf(" %s (at time %d) ---> \n", Processes[i].pname, time);
				Processes[i].executionTime = Processes[i].executionTime + Processes[i].arrivalTime - timeQuantum;
			}
		}

		if(Processes[i].executionTime <= 0){
			Processes[i].finished = 1;
		}

		Processes[i].arrivalTime = 0; // So that executionTime calculation isnt affected and also process has already arrived once

		time += timeQuantum;

		// add to queue
		for(int j=i+1;j<4;j++){

			if(!Processes[j].arrived && Processes[j].arrivalTime <= time){
				printf(" %s (arives at %d) and adding to queue\n ", Processes[j].pname, Processes[j].arrivalTime);
				queue[elementsInQueue] = j;
				elementsInQueue++;
			}

		}

		if(!Processes[i].finished){
			queue[elementsInQueue] = i;
			elementsInQueue++;
		}

		if(elementsInQueue > 4){
			break;
		}

		printf("ELEMENTS IN QUEUE AFTERWARDS: %d\n", elementsInQueue);
	}
}

int readTxtFile(const char *filename, struct process *Processes) {
  
  FILE *fin = fopen(filename, "r");
  
  if (!fin) {
    printf("Can't open file: %s\n", filename);
    return 0;
  }

  int i = 0;
  while (fscanf(fin, "%s %d %d",
                Processes[i].pname,
                &Processes[i].arrivalTime,
                &Processes[i].executionTime) >= 3){
                	Processes[i].finished = 0;
                	Processes[i].arrived = 0;

                    ++i;
                
  }
  fclose(fin);
  return i;
}



int main(int argc, char *argv[]){

	struct process Processes[4];

	readTxtFile("rr.txt", Processes);

	bubble_sort(Processes);

	printf("Initialized processes:\n| Process name | Arrival Time | Execution Time | Finished? |\n");
	for(int i =0; i<4; i++){
		printf("| %s | %d | %d | %d |\n", Processes[i].pname, Processes[i].arrivalTime, Processes[i].executionTime, Processes[i].finished);
	}

	int exit = 0;

	while(!exit){
		printf("===========================");
		printf("\nWelcome to scheduling program\n");
		printf("1] Round Robin\n");
		printf("Choose an option\n");

		int opt;

		scanf("%d", &opt);

		printf("===========================");


		switch(opt){
			case 1:
			roundRobin(Processes);

			break;
			default:
			exit=1;
			break;
		}
	}
}