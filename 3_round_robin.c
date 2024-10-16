#include<stdio.h>
//3_rr
void main()
{
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);
    y = NOP; // Assign the number of process to variable y

    // Enter the details of the process: Arrival time and Burst Time
    for(i = 0; i < NOP; i++)
    {
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // Store burst time in temp array
    }

    // Accept Time Quantum
    printf("Enter the Time Quantum: ");
    scanf("%d", &quant);

    printf("\n Process No \t Burst Time \t TAT \t Waiting Time");

    for(sum = 0, i = 0; y != 0;)
    {
        if(at[i] <= sum && temp[i] > 0) // Process has arrived and needs execution
        {
            if(temp[i] <= quant && temp[i] > 0) // Process will complete in this round
            {
                sum += temp[i];
                temp[i] = 0;
                count = 1;
            }
            else if(temp[i] > 0) // Process needs more rounds to complete
            {
                temp[i] -= quant;
                sum += quant;
            }

            if(temp[i] == 0 && count == 1)
            {
                y--; // Decrease process count
                printf("\nProcess[%d] \t %d \t\t %d \t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
                wt += sum - at[i] - bt[i];
                tat += sum - at[i];
                count = 0;
            }
        }

        // Move to the next process, considering circular nature
        if(i == NOP - 1)
            i = 0;
        else if(at[i + 1] <= sum)
            i++;
        else
            i = 0;
    }

    // Calculate average waiting time and Turn Around time
    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;

    printf("\nAverage Turn Around Time: %f", avg_tat);
    printf("\nAverage Waiting Time: %f", avg_wt);

    getchar(); // Use this to pause the program before exiting
}

