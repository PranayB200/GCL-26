#include<bits/stdc++.h>
using namespace std;

class job {
    public:
    int id, deadline, profit;

    job(int id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool custom_comp(job &a, job &b) {
    return a.profit > b.profit;
}

pair<int, int> job_sequencing(vector<job> jobs) {

    int n = jobs.size();

    // Sorting the jobs in decreasing order of profits.
    sort(jobs.begin(), jobs.end(), custom_comp);

    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        max_deadline = max(max_deadline, jobs[i].deadline);
    }

    // -1 denotes an empty time-slot. Intially all time-slots are empty. 
    vector<int> time_slots(max_deadline, -1);

    int tot_jobs = 0, max_profit = 0;
    for (int i = 0; i < n; i++) {

        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (time_slots[j] == -1) { // If time-slot (j -> (j + 1)) is empty.
                time_slots[j] = jobs[i].id;
                tot_jobs++;
                max_profit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Jobs are sequenced as follows:\n";
    for (int i = 0; i < max_deadline; i++) {
        cout << i << "->" << i + 1 << ": " << time_slots[i] << endl;
    }

    return {tot_jobs, max_profit};
}

int main() {
    pair<int, int> res1 = job_sequencing({{1, 4, 20},
                                         {2, 1, 10},
                                         {3, 1, 40},
                                         {4, 1, 30}});
    cout << res1.first << " " << res1.second << endl << endl;

    pair<int, int> res2 = job_sequencing({{1, 2, 100},
                                          {2, 1, 19},
                                          {3, 2, 27},
                                          {4, 1, 25},
                                          {5, 1, 15}});
    cout << res2.first << " " << res2.second << endl;
}