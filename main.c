#include <stdio.h>

#define MAX_N 100

int heap[MAX_N];
int heapSize = 0;

void printHeap()
{
    printf("Heap: [");

    for (int i = 0; i < heapSize; i++)
        printf("%d%s", heap[i], (i == heapSize - 1) ? "" : ", ");

    printf("]\n");
}

int insertHeap(int value)
{
    int comparisons = 0;
    int i = heapSize;

    heap[i] = value;
    heapSize++;

    while (i > 0)
    {
        int parent = (i - 1) / 2;
        comparisons++;

        if (heap[i] > heap[parent])
        {
            int temp = heap[i];
            heap[i] = heap[parent];
            heap[parent] = temp;
            i = parent;
        }
        else
        {
            break;
        }
    }

    return comparisons;
}

int linearSearchMax(int arr[], int n, long *comparisons)
{
    int max = arr[0];
    *comparisons = 0;

    for (int i = 1; i < n; i++)
    {
        (*comparisons)++;

        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int main()
{
    int scores[] = {78, 92, 65, 88, 95, 72, 84, 90};
    int n = sizeof(scores) / sizeof(scores[0]);

    printf("===== MAX HEAP INSERTION TRACE =====\n");

    long heapComparisons = 0;

    for (int i = 0; i < n; i++)
    {
        int c = insertHeap(scores[i]);
        heapComparisons += c;

        printf("Insert %d -> comparisons: %d, ", scores[i], c);
        printHeap();
    }

    printf("\nMax Heap result:\n");
    printf("Maximum score (heap root) = %d\n", heap[0]);
    printf("Total comparisons to build heap = %ld\n", heapComparisons);

    printf("\n===== LINEAR SEARCH =====\n");

    long linearComparisons;
    int maxLinear = linearSearchMax(scores, n, &linearComparisons);

    printf("Maximum score (linear search) = %d\n", maxLinear);
    printf("Total comparisons = %ld\n", linearComparisons);

    printf("\n===== SUMMARY =====\n");

    printf("Max Heap : max = %d, comparisons = %ld\n",
           heap[0], heapComparisons);

    printf("Linear Search : max = %d, comparisons = %ld\n",
           maxLinear, linearComparisons);

    return 0;
}
