#include<iostream>
#include<cstdlib>
#include"algorithm.h"

#define DT student
using namespace std;

struct student{
    int roll_no;
    char name[20];
};

//give user this function to write compare statement, just update the DT with required data type or create a macro with name DT
bool compare(void *a, void *b) {
    return ((DT*)a)->roll_no <= ((DT*)b)->roll_no;
}

//give user this function to swap elements,just update the DT with required data type or create a macro with name DT
void swap(void *a, void *b) {
    DT temp = *(DT*)a;
    *(DT*)a = *(DT*)b;
    *(DT*)b = temp;
}


int main(int argc, char **argv) {

//To work with integer array just uncomment following lines and provide integer elements in command line
    //int arr[argc-1];\
    for(int i=1;i<argc;i++)\
        arr[i-1]=atoi(argv[i]);

    DT arr[] = {{3, "C" }, {1, "A"}, {2, "B"}, {5, "E"}, {4, "D"}, {9, "G"}, {6,"F"}};

    for(int i=0;i<sizeof(arr)/sizeof(DT);i++)
        cout<<arr[i].roll_no<<" "<<arr[i].name<<endl;
    cout<<endl;

    qsort(arr, sizeof(arr)/sizeof(DT), sizeof(DT), compare, swap);
    bsort(arr, sizeof(arr)/sizeof(DT), sizeof(DT), compare, swap);

    for(int i=0;i<sizeof(arr)/sizeof(DT);i++)
        cout<<arr[i].roll_no<<" "<<arr[i].name<<endl;
    cout<<endl;

    return 0;
}
