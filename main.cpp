#include <algorithm>
#include <vector>
#include <iostream>

void print(int first, int last) {
    if (first == last) {
        std::cout << first;
    } else {
        std::cout << first << " - " << last;
    }
}

void print_short_array(std::vector<int>& v) {
    if (v.size() == 0) {
        return;
    }
    std::sort(v.begin(), v.end());
    bool was_printed = false;
    int first = v.front();
    int last = first;
    for(auto x: v) {
        if (x <= last + 1) {
            last = x;
        } else {
            if (was_printed) { std::cout << ", "; }
            print(first, last);
            was_printed = true;
            first = last = x;
        }
    }
    if (was_printed) { std::cout << ", "; }
    print(first, last);
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = {1, 9, 7, 4, 2, 3, 5, 11};
    print_short_array(v);
}
