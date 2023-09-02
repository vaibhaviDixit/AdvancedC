/*
You are given a set of n types of rectangular 3-D boxes, where the i^th box has height h(i), width w(i) and depth d(i) (all real numbers).
You want to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of
the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so
that any side functions as its base. It is also allowable to use multiple instances of the same type of box.

Input:
Box= { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }

Output: The maximum possible height of stack is 60

*/


/* Dynamic Programming implementation of Box Stacking problem */
#include<stdio.h>
#include<stdlib.h>

/* Representation of a box */
struct Box
{
// h --> height, w --> width, d --> depth
    int h, w, d; // for simplicity of solution, always keep w <= d
};

// A utility function to get minimum of two integers
int min (int x, int y)
{
    return (x < y)? x : y;
}

// A utility function to get maximum of two integers
int max (int x, int y)
{
    return (x > y)? x : y;
}

/* Following function is needed for library function qsort(). We use qsort() to sort boxes in decreasing order of base area.*/

int compare (const void *a, const void * b)
{
    return ( (*(Box *)b).d * (*(Box *)b).w ) -
           ( (*(Box *)a).d * (*(Box *)a).w );
}

/* Returns the height of the tallest stack that can be
formed with give type of boxes */
int maxStackHeight( Box arr[], int n )
{
    /* Create an array of all rotations of given boxes
    	For example, for a box {1, 2, 3}, we consider three
    	instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
    Box rot[3*n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        // Copy the original box
        rot[index].h = arr[i].h;
        rot[index].d = max(arr[i].d, arr[i].w);
        rot[index].w = min(arr[i].d, arr[i].w);
        index++;

        // First rotation of box
        rot[index].h = arr[i].w;
        rot[index].d = max(arr[i].h, arr[i].d);
        rot[index].w = min(arr[i].h, arr[i].d);
        index++;

        // Second rotation of box
        rot[index].h = arr[i].d;
        rot[index].d = max(arr[i].h, arr[i].w);
        rot[index].w = min(arr[i].h, arr[i].w);
        index++;
    }

// Now the number of boxes is 3n
    n = 3*n;

    /* Sort the array 'rot[]' in non-increasing order of base area */
    qsort (rot, n, sizeof(rot[0]), compare);

// Uncomment following two lines to print all rotations for (int i = 0; i < n; i++ )
// printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].d);

    /* Initialize msh values for all indexes msh[i] --> Maximum possible Stack Height with box i on top */
    int msh[n];
    for (int i = 0; i < n; i++ )
        msh[i] = rot[i].h;

    /* Compute optimized msh values in bottom up manner */
    for (int i = 1; i < n; i++ )
        for (int j = 0; j < i; j++ )
            if ( rot[i].w < rot[j].w &&
                    rot[i].d < rot[j].d &&
                    msh[i] < msh[j] + rot[i].h
               )
            {
                msh[i] = msh[j] + rot[i].h;
            }


    /* Pick maximum of all msh values */
    int max = -1;
    for ( int i = 0; i < n; i++ )
        if ( max < msh[i] )
            max = msh[i];

    return max;
}

int main()
{
    Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The maximum possible height of stack is %d\n",
           maxStackHeight (arr, n) );

    return 0;
}

/*

Struct Box: Defines a structure Box representing a box with its height (h), width (w), and depth (d).

Utility Functions min and max: These functions are used to calculate the minimum and maximum of two integers, respectively.

Utility Function compare: This function is used as a comparison function for the qsort library function. It compares two boxes based on their base area in descending order.

Function maxStackHeight:

This function takes an array of boxes (arr) and the number of boxes (n) as input.
It calculates and returns the maximum possible height of the stack that can be formed using the given boxes.
It first creates an array rot of all possible rotations of the given boxes. Each box is rotated three times to consider all dimensions.
The rot array is then sorted in non-increasing order of base area using the compare function as the comparison criterion.
The function initializes an array msh to store the maximum possible stack height with box i on top.
It iterates through the boxes to calculate the msh values in a bottom-up manner, taking into account the width and depth constraints for stacking.
Finally, it picks the maximum value from the msh array, which represents the maximum possible height of the stack.
Main Function:

The main function initializes an array of boxes arr with their dimensions.
It calculates the number of boxes n based on the size of the array.
It calls the maxStackHeight function with the array and n to find the maximum possible height of the stack using the given boxes.
The result is printed using the printf function.

*/

