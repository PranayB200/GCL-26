#include<bits/stdc++.h>
using namespace std;

/*
meetings[i][0] -> starting time of the ith meeting
meetings[i][1] -> ending time of the ith meeting
*/
int min_rooms(vector<vector<int>> meetings) {

    int n = meetings.size();

    /*
    arr[i].first -> time stamp
    arr[i].second -> (+1) if arr[i].first is the start time of a meeting and (-1) if it is the end time.
    */
    vector<pair<int,int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back({meetings[i][0], +1});
        arr.push_back({meetings[i][1], -1});
    }

    /*
    sorting the time stamps.
    If an ending and starting event occurs at the same time stamp, then
    the ending event will be reflected first in this sorted array as (-1 < +1).
    */
    sort(arr.begin(), arr.end());

    int current_meetings = 0;
    int max_meetings = 0;

    for (int i = 0; i < 2*n; i++) {
        current_meetings += arr[i].second;
        max_meetings = max(max_meetings, current_meetings);
    }
    
    return max_meetings;
}

int main() {

    cout << min_rooms({ {0, 30},
                        {5, 10},
                        {15, 20} }) << endl;

    cout << min_rooms({ {1, 18},
                        {18, 23},
                        {15, 29},
                        {4, 15},
                        {2, 11},
                        {5, 13} }) << endl;
}