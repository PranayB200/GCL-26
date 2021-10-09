#include <bits/stdc++.h>
using namespace std;


// Check if the number of students required such that no student reads more than `mid`
// number of pages is less than or equal to `number_of_students`.
bool is_possible(vector<int> &pages, int number_of_students, int mid) {

    int student_count = 1;
    int current_pages = 0;

    for (int i = 0; i < pages.size(); i++) {
        
        // Current book cannot be allocated to the current student. So, start the 
        // allocation for the next student.
        if (current_pages + pages[i] > mid) {
            student_count++;
            current_pages = pages[i];
        }

        // Current book can be allocated to the current student only. So, no need to
        // start the next allocation.
        else {
            current_pages += pages[i];
        }
    }

    if (student_count <= number_of_students) {
        return true;
    }
    return false;
}

int find_pages(vector<int> &pages, int number_of_students) {
    
    int number_of_books = pages.size();
    if (number_of_books < number_of_students) {
        return -1;
    }

    int low = pages[0], high = pages[0];
    for (int i = 1; i < number_of_books; i++) {
        low = max(low, pages[i]);
        high += pages[i];
    }

    int result = high;
    while(low <= high) {
        int mid = (low + high) / 2;

        if (is_possible(pages, number_of_students, mid)) {
            result = min(result, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {

    vector<int> pages = {10, 20, 10, 30};
    cout << find_pages(pages, 2) << endl;

    pages = {12, 34, 67, 90};
    cout << find_pages(pages, 2) << endl;
}