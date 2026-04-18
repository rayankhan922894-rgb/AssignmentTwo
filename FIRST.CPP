#include <iostream>
#include <algorithm>
using namespace std;

// Raheem Ullah Khan
// F2024376233

/*
=====================================================
Q1 – Arrays and Searching
=====================================================

Q1.A.1
What is contiguous memory allocation? Why do arrays use it?
What advantage does it provide?

Answer:
Contiguous memory allocation means elements are stored
in adjacent memory locations. Arrays use this so any
element can be accessed directly using index, giving O(1) access.

-----------------------------------------------------

Q1.A.2
What is a memory leak? Give an example.

Answer:
A memory leak occurs when allocated memory is not freed.
Example:
int* arr = new int[10];
If delete[] arr is not used, memory is wasted.

-----------------------------------------------------

Q1.A.3
Difference between static and dynamic array?

Answer:
Static array: fixed size at compile time.
Dynamic array: size decided at runtime using new.
Fixed size matters because it cannot grow/shrink.

-----------------------------------------------------

Q1.A.4
Why array access is O(1)? Why not for linked list?

Answer:
Array uses direct index calculation → O(1).
Linked list requires traversal → not O(1).
*/

// Q1.B.1 Linear Search
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;

    return -1;
}

// Q1.B.2 Min & Max in one loop
void findMinMax(int arr[], int size, int &minVal, int &maxVal)
{
    minVal = arr[0];
    maxVal = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minVal)
            minVal = arr[i];

        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
}

/*
=====================================================
Q2 – Bubble Sort
=====================================================

Q2.A.1
Explain Bubble Sort.

Answer:
Bubble Sort compares adjacent elements and swaps them
if they are in wrong order. After each pass, the largest
element moves to the end like a bubble.

-----------------------------------------------------

Q2.A.2
Time complexity?

Answer:
Best = O(n)
Average = O(n^2)
Worst = O(n^2)
Optimized version stops early if sorted.

-----------------------------------------------------

Q2.A.3
Compare Bubble and Selection Sort.

Answer:
Selection Sort uses fewer swaps.
Bubble Sort is easier to understand.
Selection Sort is better when swaps are expensive.
*/

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int arr[], int size, int &swapCount)
{
    swapCount = 0;

    cout << "Before Sorting: ";
    printArray(arr, size);

    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCount++;
                swapped = true;
            }
        }

        cout << "After Pass " << i + 1 << ": ";
        printArray(arr, size);

        if (!swapped)
            break;
    }
}

/*
=====================================================
Q3 – Binary Search
=====================================================

Q3.A.1
Prerequisite?

Answer:
Array must be sorted.

-----------------------------------------------------

Q3.A.2
Dry run:
low=0 high=7 mid=3 → 12
low=4 high=7 mid=5 → 23 FOUND

-----------------------------------------------------

Q3.A.3
Why faster than linear?

Answer:
Linear = O(n)
Binary = O(log n)
Binary halves the search space.
*/

int binarySearch(int arr[], int size, int key, int &iterations)
{
    int low = 0, high = size - 1;
    iterations = 0;

    while (low <= high)
    {
        iterations++;
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

/*
=====================================================
Q4 – Big O
=====================================================

Q4.A.1
What is Big O?

Answer:
It describes growth rate of algorithm.

-----------------------------------------------------

Q4.A.2
Difference?

Answer:
Big O = worst case
Omega = best case
Theta = exact

-----------------------------------------------------

Q4.A.3
Ranking:
O(1) < O(log n) < O(n) < O(n log n) < O(n^2)

-----------------------------------------------------

Q4.A.4
Space Complexity?

Answer:
Extra memory used.
Array of size n → O(n)

-----------------------------------------------------

Q4.A.5
Is faster computer better?

Answer:
No, algorithm complexity matters more.
*/

void nestedLoop(int arr[], int n)
{
    // Outer loop runs n times
    // Inner loop runs n times
    // Total = n * n = n^2 → O(n^2)

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << arr[i] + arr[j] << " ";
    cout << endl;
}

void singleLoop(int arr[], int n)
{
    // Runs n times → O(n)

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*
Time Complexity:
For each element in A → check all in B
Total = n * n = O(n^2)

Better:
Sorting + Binary Search → O(n log n)
Hashing → O(n)
*/
bool checkElements(int A[], int B[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool found = false;

        for (int j = 0; j < n; j++)
        {
            if (A[i] == B[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
            return false;
    }

    return true;
}

/*
=====================================================
Q5 – Linked List
=====================================================

Q5.A.1
What is linked list?

Answer:
Nodes connected using pointers.
Memory is non-contiguous.

-----------------------------------------------------

Q5.A.2
Time complexities?

Answer:
Insert head = O(1)
Insert tail = O(n)
Delete = O(n)

-----------------------------------------------------

Q5.A.3
Without delete?

Answer:
Memory leak occurs.
*/

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtHead(int val)
    {
        Node *n = new Node(val);
        n->next = head;
        head = n;
    }

    void insertAtTail(int val)
    {
        Node *n = new Node(val);

        if (!head)
        {
            head = n;
            return;
        }

        Node *temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = n;
    }

    void deleteByValue(int val)
    {
        if (!head)
            return;

        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;

        if (!temp->next)
        {
            cout << "Value not found\n";
            return;
        }

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    int arr1[10] = {4, 15, 7, 23, 1, 9, 42, 18, 6, 30};

    cout << "Searching 42...\n";
    int index = linearSearch(arr1, 10, 42);

    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found\n";

    int minVal, maxVal;
    findMinMax(arr1, 10, minVal, maxVal);

    cout << "Min: " << minVal << " Max: " << maxVal << endl;

    cout << endl;

    int arr2[7] = {64, 34, 25, 12, 22, 11, 90};
    int swaps;
    bubbleSort(arr2, 7, swaps);
    cout << "Total swaps: " << swaps << endl;

    cout << endl;

    int arr3[10] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int iter;

    cout << "Search 56: " << binarySearch(arr3, 10, 56, iter) << " Iter: " << iter << endl;
    cout << "Search 100: " << binarySearch(arr3, 10, 100, iter) << " Iter: " << iter << endl;

    cout << endl;

    int A[5] = {1, 2, 3, 4, 5};
    int B[5] = {5, 4, 3, 2, 1};

    cout << (checkElements(A, B, 5) ? "All exist\n" : "Not all exist\n");

    cout << endl;

    LinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtTail(30);
    list.insertAtTail(40);

    list.display();

    list.deleteByValue(20);
    list.deleteByValue(100);

    list.display();

    return 0;
}
//https://github.com/rayankhan922894-rgb/AssignmentTwo/blob/main/FIRST.CPP
