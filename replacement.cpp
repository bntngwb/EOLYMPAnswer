#include <iostream>
#include <set>
#include <vector>

class NextNearestLarger {
public:
    NextNearestLarger(const std::vector<int>& input) : arr(input) {}

    std::vector<int> CalculateNextNearestLarger() {
        std::vector<int> result(arr.size(), 0);
        std::set<std::pair<int, int>> elements; // Set of pairs (value, index)

        for (int i = arr.size() - 1; i >= 0; --i) {
            while (!elements.empty() && elements.begin()->first <= arr[i]) {
                elements.erase(elements.begin());
            }

            if (!elements.empty()) {
                result[i] = elements.begin()->first;
            }

            elements.insert({arr[i], i});
        }

        return result;
    }

private:
    std::vector<int> arr;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> input(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> input[i];
    }

    NextNearestLarger solver(input);
    std::vector<int> result = solver.CalculateNextNearestLarger();

    for (int i = 0; i < n; ++i) {
        std::cout << result[i];
        if (i < n - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}