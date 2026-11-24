#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>

std::optional<int> maxAfterAdd(const std::vector<int>& data) {
    std::vector<int> negatives;
    std::copy_if(data.begin(), data.end(), std::back_inserter(negatives),
                 [](int x) { return x < 0; });

    std::vector<int> shifted(negatives.size());
    std::transform(negatives.begin(), negatives.end(), shifted.begin(),
                   [](int x) { return x + 10; });

    if (shifted.empty()) {
        return std::nullopt;
    }
    return *std::max_element(shifted.begin(), shifted.end());
}

int main() {
    std::vector<int> data{5, -3, 8, -15, 2, -1, -7, 10};

    auto result = maxAfterAdd(data);
    if (result) {
        std::cout << "Максимум (класично): " << *result << '\n';
    } else {
        std::cout << "Немає від'ємних чисел\n";
    }

    std::vector<int> noNegatives{1, 2, 3};
    auto result2 = maxAfterAdd(noNegatives);
    if (result2) {
        std::cout << "Максимум: " << *result2 << '\n';
    } else {
        std::cout << "Для {1, 2, 3}: немає від'ємних чисел\n";
    }
}
