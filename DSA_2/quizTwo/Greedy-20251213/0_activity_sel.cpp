#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sort_asc_finish_comparator(pair<int, int> a, pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    // take the scheduled times {start, end}
    vector<pair<int, int>> scheduled = {{1, 2}, {3, 4}, {5, 7}, {0, 6}, {8, 9}, {5, 9}};

    // sort according to descending scheduled time
    sort(scheduled.begin(), scheduled.end(), sort_asc_finish_comparator);

    // keep a store for selected times
    vector<pair<int, int>> selected;
    selected.push_back(scheduled[0]);      // add the first time here
    int last_finish = scheduled[0].second; // add the current tasks last finish time

    for (auto i : scheduled) // for all scheduled time
    {
        int start = i.first, end = i.second; // take the start and end times
        if (start >= last_finish)            // if the current tasks start time is greater than the last_finish time (i.e current task is after the prev task not overlapping)
        {
            selected.push_back(i); // add the current task to queue
            last_finish = end;     // updated
        }
    }

    // print all the activities
    cout << selected.size() << " activities:\n";
    for (auto i : selected)
    {
        cout << i.first << " to " << i.second << "\n";
    }
}