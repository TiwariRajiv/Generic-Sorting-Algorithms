
//Generic funciton to sort elements of array using bubble sort
void bsort(void *arrr,const int size, const int ele_size, bool (*fun)(void*, void*), void (*func)(void*,void*)) {

    char *arr = (char*)arrr;
    for(int i = 0 ; i < size-1; i++)
        for(int j=0;j<size-i-1;j++)
            if(!fun(arr + j*ele_size,arr + (j+1)*ele_size))
                func(arr + j*ele_size, (arr + (j+1)*ele_size));
}


//Quick sort implementation starts
//Partition function to divide array in 2 parts, smaller and larger than pivot
int partition(char *arr, const int low, const int high, const int ele_size, bool (*fun)(void*, void*), void (*func)(void*, void*)) {
    //index of element which starts the later section of array having all elements greater than pivot after the partition is done.
    int pivot = low;
    for(int i=low; i<high; i++) {
        if(fun(arr+i*ele_size, arr+high*ele_size)) {
            func(arr+i*ele_size, arr+pivot*ele_size);
            pivot++;
        }
    }
    func(arr+pivot*ele_size,arr+high*ele_size);
    return pivot;
}

//Function to run quicksort, get partition index and call recursively on partitions
int qsortUtil(char *arr, const int low, const int high, const int ele_size, bool (*fun)(void*, void*), void (*func)(void*, void*)) {
    if(low < high) {
        int p = partition(arr, low, high, ele_size, fun, func);
        qsortUtil(arr, low, p-1, ele_size, fun, func);
        qsortUtil(arr, p+1, high, ele_size, fun, func);
    }
}

//Quick sort function, with fun as comparator and func as swap function passed by user
int qsort(void *arrr, const int size, const int ele_size, bool (*fun)(void*, void*), void (*func)(void*, void*)) {
    //Type casting to char because char has size of 1 byte which makes it easier to perform pointer arithmetic
    char *arr = (char*)arrr;
    return qsortUtil(arr, 0, size-1, ele_size, fun, func);
}

