#include <stdio.h>

/**
 * @brief Implements an insertion sort for an array of integers
 * 
 * @param array
 * @param numItems 
 */
void insertionSort(int *array, int numItems)
{

    int innerLoopItems = numItems + 1;     // tracks the inner loop items
    bool IterationHadASwitch = false;      // checks if there was a switch

    // -----------------------------------------------------------------
    // outer loop: controls each iteration to check if the first iteration 
    //  as safety measure to check if array is already sorted
    // -----------------------------------------------------------------
    for (int i = 0; i < numItems; i++)
    {

        innerLoopItems--;

        // -----------------------------------------------------------------
        // inner loop implements the insertion sort algorithm
        // -----------------------------------------------------------------
        for (int j = 1; j < innerLoopItems; j++)
        {
            if (array[j] < array[j-1])
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;

                IterationHadASwitch = true;
            }
            else
            {
                continue;
            }
        }

        printf("Iteration %d ::: ", i + 1);

        for(int m = 0; m < numItems; m++)
        {
            printf("%d ", array[m]);
        }

        printf("\n");
    }

    // exits early if array is already sorted
    if (IterationHadASwitch == false)
    {
        printf("Early exit as array is sorted\n");
        return;
    }
}

int main()
{

    // 72, 35, 38, 73, 35, 83, 27, 16, 85
    int arr1[] = {72, 35, 38, 73, 35, 83, 27, 16, 85};
    int arr1Items = sizeof(arr1) / sizeof(arr1[0]);

    printf("The array is: ");

    for (int i = 0; i < arr1Items; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n\n");


    insertionSort(arr1, arr1Items);
    
    printf("\nThe sorted array is: ");

    for (int i = 0; i < arr1Items; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n");
    return 0;
}
