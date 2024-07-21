DMA

1. Define a function to input variable length string and store it in an array without
memory wastage.
2. Write a program to ask the user to input a number of data values he would like to
enter then create an array dynamically to accommodate the data values. Now take
the input from the user and display the average of data values.
3. Write a program to calculate the sum of n numbers entered by the user using malloc
and free.
4. Write a program to input and print text using dynamic memory allocation.
5. Write a program to read a one dimensional array, print sum of all elements along with
inputted array elements using dynamic memory allocation.
6. Write a program in C to find the largest element using Dynamic Memory Allocation.
7. Write a program to demonstrate memory leak in C.
8. Write a program to demonstrate dangling pointers in C.
9. Write a program to allocate memory dynamically of the size in bytes entered by the
user. Also handle the case when memory allocation is failed.
10. Find out the maximum and minimum from an array using dynamic memory allocation
in C.

Solution:-

1. #include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inputString() {
    char *str;
    int ch, i = 0;
    int size = 10; // initial size
    str = malloc(size * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    printf("Enter a string: ");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
        if (i == size) {
            size *= 2;
            str = realloc(str, size * sizeof(char));
            if (str == NULL) {
                printf("Memory reallocation failed\n");
                exit(1);
            }
        }
    }
    str[i] = '\0';
    
    // Resize to exact length
    str = realloc(str, (i + 1) * sizeof(char));
    return str;
}

int main() {
    char *str = inputString();
    printf("Entered string: %s\n", str);
    free(str);
    return 0;
}

2. #include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of data values: ");
    scanf("%d", &n);
    
    float *data = (float*)malloc(n * sizeof(float));
    if (data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter the data values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &data[i]);
    }
    
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    
    printf("Average of data values: %.2f\n", sum / n);
    free(data);
    return 0;
}

3. #include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int *numbers = (int*)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    
    printf("Sum of numbers: %d\n", sum);
    free(numbers);
    return 0;
}

4. #include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int size = 100;

    str = (char*)malloc(size * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    printf("Entered string: %s\n", str);
    free(str);
    return 0;
}

5. #include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];
    }
    printf("\nSum of elements: %d\n", sum);

    free(arr);
    return 0;
}

6. #include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Largest element: %d\n", max);
    free(arr);
    return 0;
}

7. #include <stdio.h>
#include <stdlib.h>

void memoryLeak() {
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    *ptr = 42;
    // Memory leak as there is no free(ptr)
}

int main() {
    memoryLeak();
    // Memory allocated inside memoryLeak() is not freed
    return 0;
}

8. #include <stdio.h>
#include <stdlib.h>

int* createDanglingPointer() {
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    *ptr = 42;
    free(ptr); // Now ptr is a dangling pointer
    return ptr;
}

int main() {
    int *danglingPtr = createDanglingPointer();
    // Accessing danglingPtr leads to undefined behavior
    printf("Value at dangling pointer: %d\n", *danglingPtr);
    return 0;
}

9. #include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter the number of bytes to allocate: ");
    scanf("%d", &size);

    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory allocated successfully\n");
    free(ptr);
    return 0;
}

10. #include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    free(arr);
    return 0;
}
s