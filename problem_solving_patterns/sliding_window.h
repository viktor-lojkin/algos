#include <vector>
#include <algorithm>
#include <stdexcept>

int FindMaxSubarray(std::vector<int> input, size_t length_of_subarray) {   // i'm gonna improve it with comparator
    if(input.size() < length_of_subarray) {
        throw std::logic_error("The array is smaller than subarray!");
    }

    int max_value = 0;
    int cur_value = 0;

    for (size_t i = 0; i < input.size(); ++i) {
        cur_value += input[i];
        if(i >= length_of_subarray - 1u) {
            max_value = std::max(max_value, cur_value);
            cur_value -= input[i - (length_of_subarray - 1)];   // (length_of_subarray - 1) is index from which we can check our window
        }
    }

    return max_value;
}
