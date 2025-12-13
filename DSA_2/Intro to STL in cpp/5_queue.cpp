#include <bits/stdc++.h>

using namespace std;

int main()
{
    // init
    queue<int> q;

    // push means enqueue btw
    q.push(10); // add to back
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front: " << q.front() << "\n";
    cout << "Back: " << q.back() << "\n";
    cout << "Size: " << q.size() << "\n";
    cout << "Empty? " << q.empty() << "\n";

    q.pop();                                           // dequeue -> remove front element
    cout << "After pop, front: " << q.front() << "\n"; // 20

    cout << "Queue elements (front to back): ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    // PRIORITY QUEUE
    // automatically sorted (default: max heap - largest on top)
    // init
    priority_queue<int> maxHeap;

    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(20);
    // largest element (50) on top

    cout << "top: " << maxHeap.top() << "\n";
    maxHeap.pop();
    cout << "top: " << maxHeap.top() << "\n";

    // for min heap use the greater<int> comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(20);
    // smallest element (10) on top

    cout << "Min Heap top: " << minHeap.top() << "\n";
    minHeap.pop();
    cout << "After pop, top: " << minHeap.top() << "\n";

    // iteration
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    priority_queue<int> pq2;
    pq2.push(100);
    cout << "PQ size: " << pq2.size() << "\n";   // 1
    cout << "PQ empty? " << pq2.empty() << "\n"; // 0 (false)
}