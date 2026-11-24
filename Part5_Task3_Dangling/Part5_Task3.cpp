#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

std::vector<int> make() {
    return {3, 1, 4};
}

int main() {
    std::vector<int> v = make();
    auto it = std::ranges::max_element(v);

    if (it != v.end()) {
        std::cout << *it << std::endl;
    }
}
