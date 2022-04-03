void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*,const void*)){
   for (int i = 0; i < n; i++){
       for (int j = 0; j < (n-i-1) * size; j += size){
           if (comp(arr + j, arr + j + size) > 0){
              swapg(arr + j, arr + j + size, size);
             
           }
       }
   }
}

int compareInt(const void* num1, const void* num2){
    
    if (num1 == num2) {
        return 0;
    } else if (num1 > num2){
        return 1;
    } else {
        return -1;
    }
}

void swapNums(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}