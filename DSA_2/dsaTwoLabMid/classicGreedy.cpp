/*
 * GREEDY ALGORITHM - ACTIVITY SELECTION PROBLEM
 * 
 * WHAT IS A GREEDY ALGORITHM?
 * - Makes the locally optimal choice at each step
 * - Hopes to find a global optimum
 * - Never reconsiders its choices
 * 
 * KEY CHARACTERISTICS:
 * 1. Greedy Choice Property: A global optimum can be reached by making locally optimal choices
 * 2. Optimal Substructure: An optimal solution contains optimal solutions to subproblems
 * 
 * ACTIVITY SELECTION PROBLEM:
 * Given N activities with their start and finish times.
 * Select the maximum number of activities that can be performed by a single person,
 * assuming that a person can only work on a single activity at a time.
 * 
 * GREEDY STRATEGY:
 * Always pick the activity that finishes earliest (and is compatible with previously selected activities)
 * 
 * WHY THIS WORKS:
 * - By choosing the activity that ends first, we leave the maximum time for remaining activities
 * - This maximizes our opportunities for scheduling more activities
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
    int index;  // To keep track of original position
    
    Activity(int s, int f, int i) : start(s), finish(f), index(i) {}
};

// Comparator function to sort activities by finish time
bool compareByFinish(const Activity &a, const Activity &b) {
    return a.finish < b.finish;  // Sort in ascending order of finish time
}

// Function to print selected activities
void printActivities(const vector<Activity> &selected) {
    cout << "\nSelected Activities:\n";
    cout << "Activity\tStart\tFinish\n";
    for (const auto &act : selected) {
        cout << "A" << act.index << "\t\t" << act.start << "\t" << act.finish << "\n";
    }
}

// GREEDY ALGORITHM: Activity Selection
vector<Activity> activitySelection(vector<Activity> &activities) {
    // Step 1: Sort activities by finish time (GREEDY CHOICE)
    sort(activities.begin(), activities.end(), compareByFinish);
    
    vector<Activity> selected;
    
    // Step 2: Always select the first activity (it finishes earliest)
    selected.push_back(activities[0]);
    int lastFinishTime = activities[0].finish;
    
    cout << "\n--- Selection Process ---\n";
    cout << "Selected A" << activities[0].index << " (Start: " << activities[0].start 
         << ", Finish: " << activities[0].finish << ")\n";
    
    // Step 3: For remaining activities, select if start time >= last finish time
    for (int i = 1; i < activities.size(); i++) {
        // GREEDY CHOICE: If current activity starts after the last selected activity ends
        if (activities[i].start >= lastFinishTime) {
            selected.push_back(activities[i]);
            lastFinishTime = activities[i].finish;
            cout << "Selected A" << activities[i].index << " (Start: " << activities[i].start 
                 << ", Finish: " << activities[i].finish << ")\n";
        } else {
            cout << "Skipped A" << activities[i].index << " (Overlaps with previous activity)\n";
        }
    }
    
    return selected;
}

int main() {
    cout << "=== GREEDY ALGORITHM: ACTIVITY SELECTION PROBLEM ===\n\n";
    
    // Example 1: Classic case
    cout << "EXAMPLE 1:\n";
    vector<Activity> activities1;
    activities1.push_back(Activity(1, 4, 1));
    activities1.push_back(Activity(3, 5, 2));
    activities1.push_back(Activity(0, 6, 3));
    activities1.push_back(Activity(5, 7, 4));
    activities1.push_back(Activity(3, 9, 5));
    activities1.push_back(Activity(5, 9, 6));
    activities1.push_back(Activity(6, 10, 7));
    activities1.push_back(Activity(8, 11, 8));
    activities1.push_back(Activity(8, 12, 9));
    activities1.push_back(Activity(2, 14, 10));
    activities1.push_back(Activity(12, 16, 11));
    
    cout << "Given Activities:\n";
    cout << "Activity\tStart\tFinish\n";
    for (const auto &act : activities1) {
        cout << "A" << act.index << "\t\t" << act.start << "\t" << act.finish << "\n";
    }
    
    vector<Activity> result1 = activitySelection(activities1);
    printActivities(result1);
    cout << "\nMaximum number of activities: " << result1.size() << "\n";
    
    // Example 2: Simple case to understand the concept
    cout << "\n\n=== EXAMPLE 2 (Simple Case) ===\n";
    vector<Activity> activities2;
    activities2.push_back(Activity(1, 3, 1));
    activities2.push_back(Activity(2, 4, 2));
    activities2.push_back(Activity(3, 5, 3));
    activities2.push_back(Activity(4, 6, 4));
    
    cout << "Given Activities:\n";
    cout << "Activity\tStart\tFinish\n";
    for (const auto &act : activities2) {
        cout << "A" << act.index << "\t\t" << act.start << "\t" << act.finish << "\n";
    }
    
    vector<Activity> result2 = activitySelection(activities2);
    printActivities(result2);
    cout << "\nMaximum number of activities: " << result2.size() << "\n";
    
    // Key insights
    cout << "\n\n=== KEY INSIGHTS ===\n";
    cout << "1. TIME COMPLEXITY: O(n log n) - dominated by sorting\n";
    cout << "2. SPACE COMPLEXITY: O(n) - for storing selected activities\n";
    cout << "3. GREEDY CHOICE: Always pick activity with earliest finish time\n";
    cout << "4. WHY GREEDY WORKS: Finishing early leaves maximum time for other activities\n";
    cout << "5. COMPARED TO BRUTE FORCE: Greedy is O(n log n) vs Brute Force O(2^n)\n";
    
    return 0;
}

/*
 * EXERCISE FOR YOU:
 * Try modifying this to solve similar problems:
 * 1. Fractional Knapsack Problem
 * 2. Huffman Coding
 * 3. Job Sequencing Problem
 * 4. Minimum Coins Problem
 * 
 * WHEN TO USE GREEDY:
 * ✓ When local optimal choices lead to global optimum
 * ✓ When problem has optimal substructure
 * ✓ When you can prove the greedy choice is safe
 * 
 * WHEN NOT TO USE GREEDY:
 * ✗ 0/1 Knapsack (use Dynamic Programming instead)
 * ✗ Shortest Path with negative weights (use Bellman-Ford)
 * ✗ Problems where local optimum doesn't guarantee global optimum
 */
