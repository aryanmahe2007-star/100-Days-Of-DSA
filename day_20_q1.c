#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int prefixSum = 0;

    // Using a simple large frequency array
    // Shift index to handle negative prefix sums
    int size = 20001;
    int offset = 10000;

    int freq[size];
    for(int i = 0; i < size; i++)
        freq[i] = 0;

    freq[offset] = 1;  // Important: prefix sum = 0 initially

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(freq[prefixSum + offset] > 0) {
            count += freq[prefixSum + offset];
        }

        freq[prefixSum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}