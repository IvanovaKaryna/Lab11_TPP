#include <cstddef>
#include <iostream>
#include <optional>
#include <ranges>

template <std::ranges::input_range R>
std::optional<double> average(R&& r) {
    double sum = 0.0;
    std::size_t n = 0;

    for (auto x : r) {
        sum += x;
        ++n;
    }

    if (n == 0) {
        return std::nullopt;
    }
    return sum / static_cast<double>(n);
}

int main() {
    auto r = std::views::iota(1, 31)
           | std::views::filter([](int x) { return x % 3 == 0; })
           | std::views::transform([](int x) { return x * x; });

    auto result = average(r);
    if (result) {
        std::cout << *result << std::endl;
    } else {
        std::cout << "Діапазон порожній" << std::endl;
    }

    auto empty = std::views::iota(1, 3)
               | std::views::filter([](int x) { return x > 100; });
    auto result2 = average(empty);
    if (result2) {
        std::cout << *result2 << std::endl;
    } else {
        std::cout << "Порожній діапазон: результату немає" << std::endl;
    }
}
