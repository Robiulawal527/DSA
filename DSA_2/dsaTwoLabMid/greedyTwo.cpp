/*
 * GREEDY ALGORITHM - FRACTIONAL KNAPSACK PROBLEM
 * 
 * PROBLEM:
 * Given a knapsack of capacity W and N items with their weights and values,
 * maximize the total value we can carry (we can take fractions of items).
 * 
 * DIFFERENCE FROM ACTIVITY SELECTION:
 * - Activity Selection: Choose NON-OVERLAPPING activities (binary choice: pick or skip)
 * - Fractional Knapsack: Choose items to maximize VALUE (can take partial items)
 * 
 * GREEDY STRATEGY:
 * 1. Calculate value-to-weight ratio (value/weight) for each item
 * 2. Sort items in descending order of this ratio
 * 3. Greedily pick items with highest value/weight ratio first
 * 4. When capacity runs out, take fraction of next best item
 * 
 * WHY THIS WORKS:
 * - By picking items with highest "bang for buck" (value/weight), we maximize value
 * - Taking the most efficient items first ensures optimal packing
 * 
 * NOTE: This greedy approach does NOT work for 0/1 Knapsack (use DP for that)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// Structure to represent an item
struct Item {
    int id;
    double weight;
    double value;
    double ratio;  // value/weight ratio
    
    Item(int i, double w, double v) : id(i), weight(w), value(v) {
        ratio = value / weight;
    }
};

// Comparator to sort by value/weight ratio in descending order
bool compareByRatio(const Item &a, const Item &b) {
    return a.ratio > b.ratio;
}

// Function to display item details
void displayItems(const vector<Item> &items, const string &title) {
    cout << "\n" << title << "\n";
    cout << "Item\tWeight\tValue\tValue/Weight Ratio\n";
    cout << "---\t------\t-----\t------------------\n";
    for (const auto &item : items) {
        cout << "I" << item.id << "\t" << fixed << setprecision(2) 
             << item.weight << "\t" << item.value << "\t" << item.ratio << "\n";
    }
}

// GREEDY ALGORITHM: Fractional Knapsack
struct KnapsackResult {
    double maxValue;
    vector<pair<int, double>> selectedItems;  // (item_id, fraction_taken)
    double totalWeight;
};

KnapsackResult fractionalKnapsack(vector<Item> items, double capacity) {
    // Step 1: Sort items by value/weight ratio in descending order (GREEDY CHOICE)
    sort(items.begin(), items.end(), compareByRatio);
    
    KnapsackResult result;
    result.maxValue = 0;
    result.totalWeight = 0;
    
    cout << "\n--- Fractional Knapsack Selection Process ---\n";
    cout << "Knapsack Capacity: " << capacity << "\n\n";
    
    double remainingCapacity = capacity;
    
    // Step 2: Greedily pick items with highest ratio
    for (const auto &item : items) {
        if (remainingCapacity <= 0) break;
        
        if (item.weight <= remainingCapacity) {
            // We can fit the entire item
            result.maxValue += item.value;
            result.totalWeight += item.weight;
            remainingCapacity -= item.weight;
            result.selectedItems.push_back({item.id, 1.0});
            
            cout << "✓ Take FULL Item I" << item.id 
                 << " (Weight: " << item.weight << ", Value: " << item.value 
                 << ", Ratio: " << fixed << setprecision(2) << item.ratio << ")\n";
            cout << "  Remaining capacity: " << remainingCapacity << "\n";
        } else {
            // We can only take a fraction
            double fraction = remainingCapacity / item.weight;
            double valueGained = fraction * item.value;
            
            result.maxValue += valueGained;
            result.totalWeight += remainingCapacity;
            result.selectedItems.push_back({item.id, fraction});
            
            cout << "◐ Take FRACTION (" << fixed << setprecision(3) << fraction * 100 
                 << "%) of Item I" << item.id 
                 << " (Weight taken: " << remainingCapacity << ", Value gained: " << valueGained << ")\n";
            cout << "  Knapsack is now FULL\n";
            
            remainingCapacity = 0;
        }
    }
    
    return result;
}

int main() {
    cout << "=== GREEDY ALGORITHM: FRACTIONAL KNAPSACK PROBLEM ===\n\n";
    
    // EXAMPLE 1: Standard case
    cout << "EXAMPLE 1: Standard Fractional Knapsack\n";
    cout << "=========================================\n";
    
    vector<Item> items1;
    items1.push_back(Item(1, 10, 60));
    items1.push_back(Item(2, 20, 100));
    items1.push_back(Item(3, 30, 120));
    
    double capacity1 = 50;
    
    displayItems(items1, "Items before sorting:");
    
    vector<Item> sortedItems1 = items1;
    sort(sortedItems1.begin(), sortedItems1.end(), compareByRatio);
    displayItems(sortedItems1, "Items sorted by value/weight ratio:");
    
    KnapsackResult result1 = fractionalKnapsack(items1, capacity1);
    
    cout << "\n--- RESULT ---\n";
    cout << "Selected Items:\n";
    cout << "Item\tFraction\n";
    for (const auto &[itemId, fraction] : result1.selectedItems) {
        cout << "I" << itemId << "\t" << fixed << setprecision(3) << fraction * 100 << "%\n";
    }
    cout << "Total Weight Used: " << result1.totalWeight << " / " << capacity1 << "\n";
    cout << "Maximum Value: " << fixed << setprecision(2) << result1.maxValue << "\n";
    
    // EXAMPLE 2: Another case with more items
    cout << "\n\n\nEXAMPLE 2: More Complex Case\n";
    cout << "=============================\n";
    
    vector<Item> items2;
    items2.push_back(Item(1, 5, 30));
    items2.push_back(Item(2, 10, 40));
    items2.push_back(Item(3, 15, 45));
    items2.push_back(Item(4, 20, 77));
    items2.push_back(Item(5, 25, 90));
    
    double capacity2 = 60;
    
    displayItems(items2, "Items before sorting:");
    
    vector<Item> sortedItems2 = items2;
    sort(sortedItems2.begin(), sortedItems2.end(), compareByRatio);
    displayItems(sortedItems2, "Items sorted by value/weight ratio:");
    
    KnapsackResult result2 = fractionalKnapsack(items2, capacity2);
    
    cout << "\n--- RESULT ---\n";
    cout << "Selected Items:\n";
    cout << "Item\tFraction\n";
    for (const auto &[itemId, fraction] : result2.selectedItems) {
        cout << "I" << itemId << "\t" << fixed << setprecision(3) << fraction * 100 << "%\n";
    }
    cout << "Total Weight Used: " << result2.totalWeight << " / " << capacity2 << "\n";
    cout << "Maximum Value: " << fixed << setprecision(2) << result2.maxValue << "\n";
    
    // Key insights
    cout << "\n\n=== KEY INSIGHTS ===\n";
    cout << "1. TIME COMPLEXITY: O(n log n) - dominated by sorting\n";
    cout << "2. SPACE COMPLEXITY: O(n) - for storing items\n";
    cout << "3. GREEDY CHOICE: Always pick item with highest value/weight ratio\n";
    cout << "4. FRACTIONAL APPROACH: Can take partial items for optimal packing\n";
    cout << "5. DIFFERENCE FROM 0/1 KNAPSACK: Greedy doesn't work for 0/1 (use DP)\n";
    
    cout << "\n\n=== WHY GREEDY WORKS FOR FRACTIONAL BUT NOT 0/1 ===\n";
    cout << "Fractional: We can always fill remaining capacity with a fraction\n";
    cout << "0/1: We can only take complete items - greedy can miss optimal solution\n";
    cout << "Example: Capacity=10, Items: (W:6,V:30), (W:3,V:25), (W:4,V:25)\n";
    cout << "  Greedy (0/1): Takes item 1 (value=30) - can't fit others → Total=30\n";
    cout << "  Optimal (0/1): Takes items 2,3 (value=50) → Total=50\n";
    cout << "  Fractional: Takes item 1 + 4/3 of item 2 → Total=53.33\n";
    
    cout << "\n\n=== ALGORITHM COMPARISON ===\n";
    cout << "Problem Type          | Strategy           | Time    | Works?\n";
    cout << "---------------------+--------------------+---------+---------\n";
    cout << "Activity Selection    | Pick earliest end  | O(n*logn) | YES ✓\n";
    cout << "Fractional Knapsack   | Pick highest ratio | O(n*logn) | YES ✓\n";
    cout << "0/1 Knapsack          | Greedy by ratio    | O(n*logn) | NO ✗\n";
    cout << "0/1 Knapsack (DP)     | Dynamic Programming| O(n*W)   | YES ✓\n";
    
    return 0;
}

/*
 * PRACTICE PROBLEMS:
 * 1. Modify to track which items are taken
 * 2. Compare greedy vs optimal for 0/1 knapsack
 * 3. Implement for negative weights/values
 * 
 * SIMILAR GREEDY PROBLEMS:
 * - Huffman Coding: Build optimal binary tree by merging lowest frequency nodes
 * - Job Sequencing: Schedule jobs by deadline to maximize profit
 * - Egyptian Fractions: Express 1 as sum of unit fractions greedily
 * - Minimum Coins: Make change using fewest coins (greedy doesn't always work!)
 */
