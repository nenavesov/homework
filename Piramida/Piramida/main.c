#include <stdio.h>
#include <stdlib.h>



void sortheap(int* numbers, int root, int bottom){
    int indexMax; 
    int flag = 0; 
    while ((root * 2 <= bottom) && (!flag)){
        if (root * 2 == bottom) {  
            indexMax = root * 2;
        }
        else if (numbers[root * 2] > numbers[root * 2 + 1]) {
            indexMax = root * 2;
        }
        else {
            indexMax = root * 2 + 1;
        }
        if (numbers[root] < numbers[indexMax]){
            int temp = numbers[root]; 
            numbers[root] = numbers[indexMax];
            numbers[indexMax] = temp;
            root = indexMax;
        }
        else {
            flag = 1; 
        }
    }
}

void heapSort(int* numbers, int array_size){
    for (int i = (array_size / 2); i >= 0; i--) {
        sortheap(numbers, i, array_size - 1);
    }
    for (int i = array_size - 1; i >= 1; i--){
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        sortheap(numbers, 0, i - 1);
    }
}

int main(){
    int mass[10];
    for (int i = 0; i < 10; i++) {
        mass[i] = rand() % 100;
    }
    printf_s("Mass not Sort: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", mass[i]);
    }
    printf("\n");
    heapSort(mass, 10); 
    printf_s("Mass Sort: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", mass[i]);
    }
    printf("\n");
    getchar();
    return 0;
}