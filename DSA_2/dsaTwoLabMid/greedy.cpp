/*
===========================================
    GREEDY ALGORITHM BASICS
===========================================

WHAT IS GREEDY ALGORITHM?
- Makes the locally optimal choice at each step
- Hopes to find the global optimum
- Does NOT always guarantee the optimal solution
- Very efficient (usually O(n log n) or O(n))

WHEN TO USE GREEDY?
1. Greedy Choice Property: Local optimal leads to global optimal
2. Optimal Substructure: Optimal solution contains optimal solutions to subproblems

KEY STRATEGY:
1. Sort the data (if needed)
2. Make the best choice at each step
3. Never reconsider previous choices
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===========================================
// PROBLEM 1: ACTIVITY SELECTION
// ===========================================
// Problem: Select maximum number of non-overlapping activities
// Input: Start times and finish times of activities
// Output: Maximum number of activities that can be performed

struct Activity {
    int start, finish;
};

// Compare function to sort by finish time
bool compareByFinish(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection() {
    cout << "\n=== ACTIVITY SELECTION ===\n";
    
    // Example activities
    vector<Activity> activities = {
        {1, 3}, {2, 5}, {4, 7}, {1, 8}, {5, 9}, {8, 10}
    };
    
    cout << "Activities (start, finish):\n";
    for (auto act : activities) {
        cout << "(" << act.start << ", " << act.finish << ") ";
    }
    cout << "\n";
    
    // GREEDY APPROACH: Sort by finish time, pick earliest finishing
    sort(activities.begin(), activities.end(), compareByFinish);
    
    vector<int> selected;
    selected.push_back(0); // Select first activity
    int lastFinish = activities[0].finish;
    
    for (int i = 1; i < activities.size(); i++) {
        // If current activity starts after last selected finishes
        if (activities[i].start >= lastFinish) {
            selected.push_back(i);
            lastFinish = activities[i].finish;
        }
    }
    
    cout << "Selected " << selected.size() << " activities:\n";
    for (int idx : selected) {
        cout << "(" << activities[idx].start << ", " << activities[idx].finish << ") ";
    }
    cout << "\n";
}

// ===========================================
// PROBLEM 2: FRACTIONAL KNAPSACK
// ===========================================
// Problem: Maximize value in knapsack (can take fractions)
// Greedy works here! (Unlike 0/1 knapsack)

struct Item {
    int value, weight;
    
    // Value per unit weight
    double ratio() const {
        return (double)value / weight;
    }
};

bool compareByRatio(Item a, Item b) {
    return a.ratio() > b.ratio(); // Descending order
}

void fractionalKnapsack() {
    cout << "\n=== FRACTIONAL KNAPSACK ===\n";
    
    vector<Item> items = {
        {60, 10}, {100, 20}, {120, 30}
    };
    int capacity = 50;
    
    cout << "Items (value, weight):\n";
    for (auto item : items) {
        cout << "($" << item.value << ", " << item.weight << "kg) ";
    }
    cout << "\nKnapsack capacity: " << capacity << "kg\n";
    
    // GREEDY: Sort by value/weight ratio
    sort(items.begin(), items.end(), compareByRatio);
    
    double totalValue = 0;
    int remainingCapacity = capacity;
    
    cout << "\nPicking items by value/weight ratio:\n";
    for (auto item : items) {
        cout << "Item: $" << item.value << "/" << item.weight << "kg"
             << " (ratio: " << item.ratio() << ")\n";
        
        if (remainingCapacity >= item.weight) {
            // Take whole item
            totalValue += item.value;
            remainingCapacity -= item.weight;
            cout << "  -> Took entire item\n";
        } else {
            // Take fraction
            double fraction = (double)remainingCapacity / item.weight;
            totalValue += item.value * fraction;
            cout << "  -> Took " << fraction * 100 << "% of item\n";
            remainingCapacity = 0;
            break;
        }
    }
    
    cout << "Total value: $" << totalValue << "\n";
}

// ===========================================
// PROBLEM 3: COIN CHANGE (GREEDY VERSION)
// ===========================================
// Problem: Make change using minimum number of coins
// NOTE: Greedy works for standard coin systems (1,5,10,25)
// But NOT guaranteed for arbitrary coin systems!

void coinChange() {
    cout << "\n=== COIN CHANGE (GREEDY) ===\n";
    
    vector<int> coins = {25, 10, 5, 1}; // Already sorted descending
    int amount = 67;
    
    cout << "Make change for: " << amount << " cents\n";
    cout << "Available coins: ";
    for (int c : coins) cout << c << " ";
    cout << "\n\n";
    
    vector<int> result;
    int remaining = amount;
    
    // GREEDY: Use largest coin first
    for (int coin : coins) {
        while (remaining >= coin) {
            result.push_back(coin);
            remaining -= coin;
        }
    }
    
    cout << "Coins used (" << result.size() << " coins): ";
    for (int c : result) cout << c << " ";
    cout << "\n";
}

// ===========================================
// PROBLEM 4: MINIMUM PLATFORMS
// ===========================================
// Problem: Find minimum platforms needed at railway station
// Input: Arrival and departure times of trains

void minimumPlatforms() {
    cout << "\n=== MINIMUM PLATFORMS ===\n";
    
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};
    
    cout << "Train schedules:\n";
    for (int i = 0; i < arrival.size(); i++) {
        cout << "Train " << i+1 << ": " << arrival[i] 
             << " - " << departure[i] << "\n";
    }
    
    // GREEDY: Sort both arrays, use two pointers
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    
    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;
    
    while (i < arrival.size() && j < departure.size()) {
        if (arrival[i] <= departure[j]) {
            platforms++; // Train arrived, need platform
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        } else {
            platforms--; // Train departed, free platform
            j++;
        }
    }
    
    cout << "Minimum platforms needed: " << maxPlatforms << "\n";
}

// ===========================================
// PROBLEM 5: JOB SEQUENCING
// ===========================================
// Problem: Schedule jobs to maximize profit
// Each job has: deadline and profit

struct Job {
    char id;
    int deadline, profit;
};

bool compareByProfit(Job a, Job b) {
    return a.profit > b.profit; // Descending
}

void jobSequencing() {
    cout << "\n=== JOB SEQUENCING ===\n";
    
    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };
    
    cout << "Jobs (ID, Deadline, Profit):\n";
    for (auto job : jobs) {
        cout << job.id << ": Day " << job.deadline 
             << ", $" << job.profit << "\n";
    }
    
    // GREEDY: Sort by profit (highest first)
    sort(jobs.begin(), jobs.end(), compareByProfit);
    
    // Find max deadline
    int maxDeadline = 0;
    for (auto job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    
    // Schedule jobs
    vector<char> schedule(maxDeadline + 1, '-');
    int totalProfit = 0;
    
    for (auto job : jobs) {
        // Find latest available slot before deadline
        for (int slot = job.deadline; slot > 0; slot--) {
            if (schedule[slot] == '-') {
                schedule[slot] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }
    
    cout << "\nSchedule: ";
    for (int i = 1; i <= maxDeadline; i++) {
        cout << "Day " << i << ":" << schedule[i] << " ";
    }
    cout << "\nTotal profit: $" << totalProfit << "\n";
}

// ===========================================
// MAIN FUNCTION
// ===========================================

int main() {
    cout << "========================================\n";
    cout << "    GREEDY ALGORITHMS - TUTORIAL\n";
    cout << "========================================\n";
    
    // Run all examples
    activitySelection();
    fractionalKnapsack();
    coinChange();
    minimumPlatforms();
    jobSequencing();
    
    cout << "\n========================================\n";
    cout << "KEY TAKEAWAYS:\n";
    cout << "1. Greedy makes best local choice\n";
    cout << "2. Often involves sorting first\n";
    cout << "3. Efficient but not always optimal\n";
    cout << "4. Test if greedy choice property holds\n";
    cout << "========================================\n";
    
    return 0;
}

/*
PRACTICE PROBLEMS TO TRY:
1. Huffman Coding
2. Minimum Spanning Tree (Prim's/Kruskal's)
3. Dijkstra's Shortest Path
4. Egyptian Fraction
5. Minimum number of jumps
6. Candy distribution
*/
