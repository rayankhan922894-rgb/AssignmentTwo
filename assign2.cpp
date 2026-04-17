#include <iostream>
#include <algorithm>
using namespace std;

// Mahnoor Arif
// F2024376079

/*
=====================================================
Q1 – Arrays and Searching
=====================================================

Q1.A.1
Contiguous memory allocation means that all elements
of an array are stored in consecutive memory locations.
This allows direct access using index which results in O(1) time.

-----------------------------------------------------

Q1.A.2freed.
Example:
int* data = new int[10];
If we do not use delete[] data, memory is lost.

-----------------------------------------------------

Q1.A.3
Static array has fixed size defined at compile time.
Dynamic array is created at runtime using new.
Fixed size is important because it cannot be changed later.

-----------------------------------------------------

Q1.A.4
Array elements are accessed using direct formula (base + index),
so it is O(1). In linked lists, we must traverse nodes.
*/

// Linear Search Implementation
int linearSearchFunc(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Function to find minimum and maximum
void findExtremes(int arr[], int size, int &minimum, int &maximum)
{
    minimum = maximum = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minimum)
            minimum = arr[i];

        if (arr[i] > maximum)
            maximum = arr[i];
    }
}

/*
=====================================================
Q2 – Bubble Sort
=====================================================

Q2.A.1
Bubble sort works by comparing adjacent values and swapping them
if they are not in correct order. After each pass, the largest
value shifts to the end.

-----------------------------------------------------

Q2.A.2
Best Case = O(n)
Average Case = O(n^2)
Worst Case = O(n^2)
Optimized version stops when no swap happens.

-----------------------------------------------------

Q2.A.3
Selection sort reduces swaps.
Bubble sort is simpler and easy to implement.
*/

void showArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSortProcess(int arr[], int n, int &swapTotal)
{
    swapTotal = 0;

    cout << "Array before sorting:\n";
    showArray(arr, n);

    for (int pass = 0; pass < n - 1; pass++)
    {
        bool didSwap = false;

        for (int j = 0; j < n - pass - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapTotal++;
                didSwap = true;
            }
        }

        cout << "After pass " << pass + 1 << ": ";
        showArray(arr, n);

        if (!didSwap)
            break;
    }
}

/*
=====================================================
Q3 – Binary Search
=====================================================

Q3.A.1
Binary search requires sorted data.

-----------------------------------------------------

Q3.A.2
Iteration 1: low=0 high=7 mid=3 → 12
Iteration 2: low=4 high=7 mid=5 → 23 (found)

-----------------------------------------------------

Q3.A.3
Linear search takes O(n).
Binary search reduces search space → O(log n).
*/

int binarySearchIterative(int arr[], int n, int key, int &count)
{
    int low = 0;
    int high = n - 1;
    count = 0;

    while (low <= high)
    {
        count++;
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/*
=====================================================
Q4 – Complexity Analysis
=====================================================

Q4.A.1
Big O notation represents how an algorithm performs
as input size increases.

-----------------------------------------------------

Q4.A.2
Big O → worst case
Big Omega → best case
Big Theta → exact bound

-----------------------------------------------------

Q4.A.3
Order:
O(1), O(log n), O(n), O(n log n), O(n^2)

-----------------------------------------------------

Q4.A.4
Space complexity measures memory usage.
Array of size n → O(n)

-----------------------------------------------------

Q4.A.5
Hardware speed does not change complexity behavior.
Better algorithm always wins for large data.
*/

void nestedExample(int arr[], int n)
{
    // Outer loop runs n times
    // Inner loop runs n times
    // Total operations = n * n → O(n^2)

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i] + arr[j] << " ";
        }
    }
    cout << endl;
}

void simpleLoop(int arr[], int n)
{
    // Loop executes n times → O(n)

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
Time Complexity Explanation:
Each element of array A is checked against all elements of B.
So total comparisons = n * n = O(n^2)

Better solutions:
1. Sort and apply binary search → O(n log n)
2. Use hash table → O(n)
*/
bool verifyElements(int A[], int B[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool exists = false;

        for (int j = 0; j < n; j++)
        {
            if (A[i] == B[j])
            {
                exists = true;
                break;
            }
        }

        if (!exists)
            return false;
    }
    return true;
}

/*
=====================================================
Q5 – Linked List
=====================================================

Q5.A.1
A singly linked list consists of nodes linked using pointers.
Memory is not continuous.

-----------------------------------------------------

Q5.A.2
Insert at head → O(1)
Insert at tail → O(n)
Delete → O(n)

-----------------------------------------------------

Q5.A.3
If delete is not used, memory leak occurs.
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
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertFront(int val)
    {
        Node *node = new Node(val);
        node->next = head;
        head = node;
    }

    void insertBack(int val)
    {
        Node *node = new Node(val);

        if (head == nullptr)
        {
            head = node;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = node;
    }

    void deleteNode(int val)
    {
        if (head == nullptr)
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

        if (temp->next == nullptr)
        {
            cout << "Value not present\n";
            return;
        }

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void printList()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    // Q1
    int arr[10] = {4, 15, 7, 23, 1, 9, 42, 18, 6, 30};

    int idx = linearSearchFunc(arr, 10, 42);

    if (idx != -1)
        cout << "42 found at index: " << idx << endl;
    else
        cout << "42 not found\n";

    int minVal, maxVal;
    findExtremes(arr, 10, minVal, maxVal);

    cout << "Min value: " << minVal << endl;
    cout << "Max value: " << maxVal << endl;

    cout << endl;

    // Q2
    int arr2[7] = {64, 34, 25, 12, 22, 11, 90};
    int totalSwaps;

    bubbleSortProcess(arr2, 7, totalSwaps);
    cout << "Total swaps performed: " << totalSwaps << endl;

    cout << endl;

    // Q3
    int sortedArr[10] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int steps;

    cout << "Searching 56: Index = "
         << binarySearchIterative(sortedArr, 10, 56, steps)
         << ", Iterations = " << steps << endl;

    cout << "Searching 100: Index = "
         << binarySearchIterative(sortedArr, 10, 100, steps)
         << ", Iterations = " << steps << endl;

    cout << endl;

    // Q4
    int A[5] = {1, 2, 3, 4, 5};
    int B[5] = {5, 4, 3, 2, 1};

    if (verifyElements(A, B, 5))
        cout << "All elements of A exist in B\n";
    else
        cout << "Some elements are missing\n";

    cout << endl;

    // Q5
    LinkedList list;

    list.insertFront(10);
    list.insertBack(20);
    list.insertFront(5);
    list.insertBack(30);
    list.insertBack(40);

    cout << "Initial List:\n";
    list.printList();

    list.deleteNode(20);
    list.deleteNode(100);

    cout << "After Deletions:\n";
    list.printList();

    return 0;
}