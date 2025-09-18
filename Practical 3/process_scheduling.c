#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct {
    char name[10];
    int AT, BT, CT, TAT, WT, RT;
    int remainingBT;
    int started;   // flag to check if process has started
    int PID;
} Process;

void input(Process p[], int *n) {
    printf("Enter number of processes: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("\nProcess %d name: ", i + 1);
        scanf("%s", p[i].name);
        printf("Arrival Time: ");
        scanf("%d", &p[i].AT);
        printf("Burst Time: ");
        scanf("%d", &p[i].BT);

        p[i].PID = i;
        p[i].remainingBT = p[i].BT;
        p[i].CT = p[i].TAT = p[i].WT = p[i].RT = 0;
        p[i].started = 0;
    }
}

void display(Process p[], int n) {
    printf("\n\nPName\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%-6s\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].name, p[i].AT, p[i].BT,
               p[i].CT, p[i].TAT, p[i].WT, p[i].RT);
    }
}

void avg(Process p[], int n) {
    float avgWT = 0, avgTAT = 0, avgRT = 0;
    for (int i = 0; i < n; i++) {
        avgWT += p[i].WT;
        avgTAT += p[i].TAT;
        avgRT += p[i].RT;
    }
    printf("\nAverage WT: %.2f", avgWT / n);
    printf("\nAverage TAT: %.2f", avgTAT / n);
    printf("\nAverage RT: %.2f\n", avgRT / n);
}

/* --------- ROUND ROBIN --------- */
void RoundRobin(Process p[], int n, int tq) {
    int time = 0, done = 0;

    while (done < n) {
        int progress = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].remainingBT > 0 && p[i].AT <= time) {
                if (!p[i].started) {
                    p[i].RT = time - p[i].AT;
                    p[i].started = 1;
                }

                int exec = (p[i].remainingBT > tq) ? tq : p[i].remainingBT;
                p[i].remainingBT -= exec;
                time += exec;
                progress = 1;

                if (p[i].remainingBT == 0) {
                    p[i].CT = time;
                    p[i].TAT = p[i].CT - p[i].AT;
                    p[i].WT = p[i].TAT - p[i].BT;
                    done++;
                }
            }
        }
        if (!progress) time++; // CPU idle
    }
}

/* --------- SJF Preemptive (SRTF) --------- */
void SJF_Preemptive(Process p[], int n) {
    int time = 0, done = 0;
    while (done < n) {
        int shortest = -1;
        int minBT = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].AT <= time && p[i].remainingBT > 0) {
                if (p[i].remainingBT < minBT) {
                    minBT = p[i].remainingBT;
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        if (!p[shortest].started) {
            p[shortest].RT = time - p[shortest].AT;
            p[shortest].started = 1;
        }

        p[shortest].remainingBT--;
        time++;

        if (p[shortest].remainingBT == 0) {
            p[shortest].CT = time;
            p[shortest].TAT = p[shortest].CT - p[shortest].AT;
            p[shortest].WT = p[shortest].TAT - p[shortest].BT;
            done++;
        }
    }
}

/* --------- MAIN --------- */
int main() {
    Process p[MAX];
    int n, choice, tq;

    input(p, &n);

    do {
        printf("\n--- CPU Scheduling Menu ---");
        printf("\n1. Round Robin");
        printf("\n2. Shortest Job First (Preemptive)");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        // Reset values for fresh calculation
        for (int i = 0; i < n; i++) {
            p[i].remainingBT = p[i].BT;
            p[i].CT = p[i].TAT = p[i].WT = p[i].RT = 0;
            p[i].started = 0;
        }

        switch (choice) {
            case 1:
                printf("Enter Time Quantum: ");
                scanf("%d", &tq);
                RoundRobin(p, n, tq);
                display(p, n);
                avg(p, n);
                break;
            case 2:
                SJF_Preemptive(p, n);
                display(p, n);
                avg(p, n);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
