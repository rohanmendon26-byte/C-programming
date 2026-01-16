#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct Job {
    int jobId;
    char jobName[30];
    int priority;
};

struct Job heap[MAX];
int size = 0;

/* Swap two jobs */
void swap(struct Job *a, struct Job *b) {
    struct Job temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify Up */
void heapifyUp(int index) {
    while (index > 0 &&
           heap[(index - 1) / 2].priority < heap[index].priority) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

/* Heapify Down */
void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].priority > heap[largest].priority)
        largest = left;

    if (right < size && heap[right].priority > heap[largest].priority)
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

/* Check if Job ID already exists */
int isJobIdExists(int id) {
    for (int i = 0; i < size; i++) {
        if (heap[i].jobId == id)
            return 1;   // Exists
    }
    return 0;           // Unique
}

/* Insert Job */
void insertJob() {
    if (size == MAX) {
        printf("\nQueue Overflow! Cannot insert more jobs.\n");
        return;
    }

    struct Job newJob;

    printf("\nEnter Job ID: ");
    scanf("%d", &newJob.jobId);

    if (isJobIdExists(newJob.jobId)) {
        printf("\nJob ID already exists! Please enter a unique Job ID.\n");
        return;
    }

    printf("Enter Job Name: ");
    scanf("%s", newJob.jobName);

    printf("Enter Job Priority (Higher value = Higher priority): ");
    scanf("%d", &newJob.priority);

    heap[size] = newJob;
    heapifyUp(size);
    size++;

    printf("\nJob inserted successfully.\n");
}

/* Delete Highest Priority Job */
void deleteJob() {
    if (size == 0) {
        printf("\nQueue Underflow! No jobs to execute.\n");
        return;
    }

    printf("\nExecuting Job:");
    printf("\nJob ID: %d", heap[0].jobId);
    printf("\nJob Name: %s", heap[0].jobName);
    printf("\nPriority: %d\n", heap[0].priority);

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

/* Display Jobs */
void displayJobs() {
    if (size == 0) {
        printf("\nNo jobs in the queue.\n");
        return;
    }

    printf("\nScheduled Jobs:\n");
    printf("ID\tName\t\tPriority\n");
    printf("---------------------------------\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%d\n",
               heap[i].jobId,
               heap[i].jobName,
               heap[i].priority);
    }
}

/* Main */
int main() {
    int choice;

    do {
        printf("\n\n==== JOB SCHEDULING SYSTEM (B-SECTION SMVITM) ====");
        printf("\n1. Add Job");
        printf("\n2. Execute Highest Priority Job");
        printf("\n3. Display All Jobs");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insertJob();
            break;
        case 2:
            deleteJob();
            break;
        case 3:
            displayJobs();
            break;
        case 4:
            printf("\nExiting Program...\n");
            break;
        default:
            printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
