#include <iterator>
#include <algorithm>
#include <stdexcept>


template <typename It>
int FindMaxSubarray(It begin, It end, size_t length_of_subarray) { 
    size_t size = std::distance(begin, end);
    if(size < length_of_subarray) {
        throw std::logic_error("The array is smaller than subarray!");
    }

    bool is_updtd {};
    int max_value {};
    int cur_value {};

    for (It it {begin}; it < end; ++it) {
        cur_value += *it;
        if(std::distance(begin, it) >= length_of_subarray - 1u) {
            if (!is_updtd) {                                       // when we first enter the if-statement above 
                max_value = cur_value;                             // we need to update max_value with valid value 
                is_updtd = true;                                   // update flag to make it once
            }
            max_value = std::max(max_value, cur_value);
            cur_value -= *(it - (length_of_subarray - 1));
        }
    }

    return max_value;
}
