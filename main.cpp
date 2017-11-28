#include <algorithm>
#include <vector>
#include <iostream>

void print_range(int first, int last) {
    if (first == last) {
        std::cout << first;
    } else {
        std::cout << first << " - " << last;
    }
}

void print_array(std::vector<int>& v) {
    if (v.size() == 0) {
        return;
    }
    std::sort(v.begin(), v.end());
    bool no_first_time = false;
    int first = v.front();
    int last = first;
    for(auto x: v) {
        if (x <= last + 1) {
            last = x;
        } else {
            if (no_first_time) { std::cout << ", "; }
            print_range(first, last);
            no_first_time = true;
            first = last = x;
        }
    }
    if (no_first_time) { std::cout << ", "; }
    print_range(first, last);
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = {1, 9, 7, 4, 2, 3, 5, 11};
    print_array(v);
}
