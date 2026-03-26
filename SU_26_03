#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ex_1() {
    int len;
    char arr[len];
    printf("Enter length of the array: \n");
    scanf("%d", &len);

    for (int i = 0; i < len; i++) {
        printf("Enter array element: \n");
        scanf("%d", &arr[i]);
        printf("%d\n", arr[i]);

    }


        // int n;
        // printf("Enter N: ");
        // scanf("%d", &n);

        // Find the longest plateau
        int best_start = 0, best_len = 1;
        int cur_start = 0, cur_len = 1;

        for (int i = 1; i < len; i++) {
            if (arr[i] == arr[i - 1]) {
                cur_len++;
            } else {
                if (cur_len > best_len) {
                    best_len = cur_len;
                    best_start = cur_start;
                }
                cur_start = i;
                cur_len = 1;
            }
        }

        // Check the last plateau
        if (cur_len > best_len) {
            best_len = cur_len;
            best_start = cur_start;
        }

        if (best_len == 1) {
            printf("No plateau found (all elements are distinct).\n");
        } else {
            printf("Longest plateau starts at index %d, length %d (value: %d)\n",
                   best_start, best_len, arr[best_start]);
        }

    // printf("this tis the last one: %d", arr[len]);
}

void ex_2() {
    int len;
    int arr[len];
    printf("Enter length of the array: \n");
    scanf("%d", &len);

    for (int i = 0; i < len; i++) {
        printf("Enter array element: \n");
        scanf("%d", &arr[i]);
        printf("%d\n", arr[i]);

    }

    for (int i = 0; i < len; i++) {
        if (i > 0 && i < len - 1) {
            if (arr[i -1] < arr[i] && arr[i] > arr[i + 1]) {
                printf("Success!");
            }else {
                printf("Nope!");
            }
        }
    }
}

void ex_3() {
    int len;
    int n = 0;

    printf("Enter length of the array: \n");
    scanf("%d", &len);
    int arr[len];
    int l = len - 1;

    for (int i = 0; i < len; i++) {
        printf("Enter array element: \n");
        scanf("%d", &arr[i]);
        printf("%d\n", arr[i]);

    }

    while (n < l) {
        int temp = arr[n];
        arr[n] = arr[l];
        arr[l] = temp;
        n++;
        l--;

    }

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);


}



void ex_4() {
    int len, k;

    printf("Enter num of elements N: ");
    scanf("%d", &len);

    int arr[len];

    printf("Enter %d nums:\n", len);
    for (int i = 0; i < len; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter K (shift): ");
    scanf("%d", &k);

    // Normalize K in case it's larger than N or negative
    k = k % len;

    int result[len];

    for (int i = 0; i < len; i++) {
        result[(i + k) % len] = arr[i];
    }

    printf("\nArray after shift with %d:\n", k);
    for (int i = 0; i < len; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");


}

void ex_5() {
    int len;

    int k;
    int temp = 0;
    printf("Enter length of the array: \n");
    scanf("%d", &len);
    int arr[len];

    printf("Enter the scale of search: \n");
    scanf("%d", &k);

    for (int i = 0; i < len; i++) {
        printf("Enter array element: \n");
        scanf("%d", &arr[i]);
        printf("%d\n", arr[i]);

    }

    for (int i = 1; i < len; i++) {
        if (arr[i - 1] < arr[i]) {
            temp = arr[i - 1];
            k--;
        }
    }
    printf("%d", temp);;
}



int main() {
   // ex_3();
    return 0;
}
