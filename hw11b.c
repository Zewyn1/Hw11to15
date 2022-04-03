#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n, m, p;
    printf("Enter n: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }
    printf("Enter m: ");
    scanf("%d", &m);
    arr = (int *)realloc(arr, (n + m) * sizeof(int));
    for(int i = n; i < n + m; i++){
        arr[i] = i;
    }
    printf("Enter p: ");
    scanf("%d", &p);
    arr = (int *)realloc(arr, (n + m + p) * sizeof(int));
    for(int i = n + m; i < n + m + p; i++){
        arr[i] = i;
    }
    printf("Array: ");
    for(int i = 0; i < n + m + p; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
