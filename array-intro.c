#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fun(int ptr[]){ // same as - int fun(int *ptr)

   int x = 10;

   // size of a pointer is printed
   printf("sizeof(ptr) = %d\n", sizeof(ptr));
   
   // This allowed because ptr is a pointer, not array
   ptr = &x;
   printf("*ptr = %d\n", *ptr);
   
   printf("Array size inside fun() is %d.\n", sizeof(ptr)/sizeof(ptr[0]));
   return 0;
}

int fun2(int arr[], unsigned int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int pfun(int a){
    printf("The value of a is %d.\n", a);
    return a+1;
}

void add(int a, int b)
{
    printf("Addition is %d\n", a+b);
}
void subtract(int a, int b)
{
    printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b)
{
    printf("Multiplication is %d\n", a*b);
}

void fun3() { printf("Fun3\n"); }
void fun4() { printf("Fun4\n"); }
 
// A function that receives a simple function
// as parameter and calls the function
void wrapper(void (*fun)())
{
    fun();
} 

int compare(const void * a, const void * b){
    return ( *(int *)a - *(int *)b );
}
 
// A compare function that is used for searching an integer
// array
bool validate(const void * a, const void * b){
    return  ( *(int *)a == *(int *)b );
}

// General purpose search() function that can be used
// for searching an element *x in an array arr[] of
// arr_size. Note that void pointers are used so that
// the function can be called by passing a pointer of
// any type.  ele_size is size of an array element
int search(void *arr, int arr_size, int ele_size, void *x, bool validate(const void *, const void *)){

    // Since char takes one byte, we can use char pointer
    // for any type to get pointer arithmetic correct,
    // we need to multiply index with size of an array
    // element ele_size
    char *ptr = (char *)arr;

    int i;
    for(i = 0; i < arr_size; i++){
        if(validate((ptr + i*ele_size), x))
            return i;
    }
    return -1;
}

int main(){

    // Array declaration by specifying size
    int arr[10], n, i, x;

    // Array declaration by initializing elements
    // int arr[] = {1, 2, 3, 54, 22, 4};
    // compiler creates an array of size 6.
    // above is same as "int arr[6] = {1, 2, 3, 54, 22, 4};"

    // Array declaration by specifying size and initializing elements
    // int arr[8] = {1, 2, 3, 54, 22, 4};
    // compiler creates an array of size 8, initializes first
    // 6 elements as specified by user and rest two elements as 0.
    // above is same as "int arr[] = {1, 2, 3, 54, 22, 4, 0, 0};"
    
    // Array declaration by initializing it with more
    // elements than specified size.
    // int arr[2] = {1, 2, 3, 4};
    
    arr[0] = 2;
    arr[2] = -22;
    arr[3/2] = 6; // this is same as arr[1] = 6;
    arr[3] = arr[0];

    printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[-4]);
    // Index out of bounds not checked in C - arr[-4]   

    for(i = 0; i < 5; i++){
        // The use of '&' before a variable name,
        // yields address of variable
        printf("Address of arr[%d] is %u\n", i, &arr[i]);
    }

    // ----------------------------------------------------- //

    // void arr[10];  // not allowed 
    void *newArr[10]; // allowed

    // ----------------------------------------------------- //

    // fun_ptr is pointer to function pfun()
    int (*fun_ptr)(int) = &pfun;
    // The above line is same as
    // int (*fun_ptr)(int);
    // fun_ptr = &pfun; or fun_ptr = pfun;

    // Involking pfun() using fun_ptr
    printf("fun_ptr return value %d.\n", (*fun_ptr)(10));
    // or fun_ptr(10)

    // fun_ptr_arr is an array of function pointers
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
    unsigned int ch = 2, a = 15, b = 10;
 
    printf("Enter Choice: 0 for add, 1 for subtract and 2 "
            "for multiply\n");
    // scanf("%d", &ch);
    
    if (ch > 2) return 0;
 
    (*fun_ptr_arr[ch])(a, b);

    wrapper(fun3);
    wrapper(fun4);

    int uarr[] = {11, 72, 3, 54, 22, 4};
    n = sizeof(uarr)/sizeof(uarr[0]);
    qsort(uarr, n, sizeof(n), compare);

    for(i = 0; i < n; i++)
        printf("%d ", uarr[i]);
    printf("\n");

    x = 22;
    printf ("Returned index is %d ", search(uarr, n, sizeof(int), &x, validate));

    // ----------------------------------------------------- //

    // Difference between array and pointer
    
    int *ptr = arr;

    // sizeof(int) * (number of elements in arr[]) is printed
    printf("size of arr[] is %d.\n", sizeof(arr));

    // sizeof a pointer is printed which is same for all 
    // type of pointers (void *, char *, etc)
    printf("size of ptr is %d.\n", sizeof(ptr));

    x = 10;
    ptr = &x; // This is fine
    // arr = &x; // Compiler Error

    // ----------------------------------------------------- //

    // Similarities between array and pointer
    
    ptr = arr; // assigns address of array to pointer ptr
    printf("Value of first element: %d.\n", *ptr);

    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr + 2) = %d\n", *(arr + 2));
    printf("ptr[2] = %d\n", ptr[2]);
    printf("*(ptr + 2) = %d\n", *(ptr + 2));

    fun(arr);

    n = sizeof(arr)/sizeof(arr[0]);
    printf("Array size inside main() is %d.\n", n);

    fun2(arr, n);
    
    // ----------------------------------------------------- //

    char akshay[] = "akshay"; // size of akshay[] is 7 as it is '\0' terminated
    char saini[5] = "saini";  // saini[] is not terminated with '\0' and its size is 5; Works in C, but compilation error in C++
    char anonyx[]= {'a', 'n', 'o', 'n', 'y', 'x'}; // anonyx[] is not terminated with '\0' and its size is 6
    printf("%d\n", sizeof(akshay));
    printf("%d\n", sizeof(saini));
    printf("%d\n", sizeof(anonyx));

    // int A[] = alloc_array(int, 10);
    // A[0] = 2;
    // printf("%d\n", A[0]);

    // [anonyxhappie@wire.local]$ gcc array-intro.c -o array-intro
    // [anonyxhappie@wire.local]$ size array-intro
    // text       data        bss        dec        hex    filename
    // 960        248          8       1216        4c0     array-intro

    return 0;
}
