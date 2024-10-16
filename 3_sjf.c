#include<stdio.h>
//3_sjf
int main() {
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;

    // Get the number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Get the burst times for each process
    printf("\nEnter Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;  // Store process number
    }

    // Sort the processes based on burst time using selection sort
    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i + 1; j < n; j++) {
            if(bt[j] < bt[pos]) {
                pos = j;
            }
        }

        // Swap burst time
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        // Swap process number
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    // Calculate waiting time for each process
    wt[0] = 0;  // Waiting time for the first process is 0
    for(i = 1; i < n; i++) {
        wt[i] = 0;
        for(j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        total += wt[i];  // Add up total waiting time
    }

    avg_wt = (float)total / n;  // Average waiting time
    total = 0;

    // Display results
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];  // Turnaround time = burst time + waiting time
        total += tat[i];  // Add up total turnaround time
        printf("p%d\t %d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    avg_tat = (float)total / n;  // Average turnaround time

    // Display averages
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}

