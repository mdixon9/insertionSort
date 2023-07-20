#include <stdio.h>

/**
 * @brief Implements an insertion sort for an array of integers
 * 
 * @param array - points to address of first elem in array
 * @param numItems - number of elements in array
 */
void insertionSort(int *array, int numItems)
{

    // tracks the number of inner loop items
    int innerLoopItems = numItems + 1;    

    // checks if there was a switch
    bool IterationHadASwitch = false;     

    // -----------------------------------------------------------------
    // outer loop: controls each iteration to check if the first iteration 
    //  as safety measure to check if array is already sorted
    // -----------------------------------------------------------------
    for (int i = 0; i < numItems; i++)
    {
        // decrements the # of iterations because greatest # is sorted
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
        } // END of inner loop

        // 47 - 55 For debugging and stepping through each iteration
        printf("Iteration %d ::: ", i + 1);

        for(int m = 0; m < numItems; m++)
        {
            printf("%d ", array[m]);
        }

        printf("\n");
    } // END of outer loop

    // exits early if array is already sorted
    if (IterationHadASwitch == false)
    {
        printf("Early exit as array is sorted\n");
        return;
    }
} // END of insertionSort

int main()
{
    // 72, 35, 38, 73, 35, 83, 27, 16, 85
    int arr1[] = {72, 35, 38, 73, 35, 83, 27, 16, 85};

    // gets the number of elems in array
    int arr1Items = sizeof(arr1) / sizeof(arr1[0]);

    // print unsorted array
    printf("The array is: ");
    for (int i = 0; i < arr1Items; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n\n");

    // sorts the array
    insertionSort(arr1, arr1Items);
    
    // prints the sorted array
    printf("\nThe sorted array is: ");
    for (int i = 0; i < arr1Items; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    return 0;
}