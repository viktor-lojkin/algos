#include <vector>
#include <iostream>

#include <iterator>


template <typename It>
void Heapify(It begin, It end, It node) {

    auto left  = std::next(begin, (2 * std::distance(begin, node)) + 1);
    auto right = std::next(begin, (2 * std::distance(begin, node)) + 2);
    
    auto large = node;

    if(left  < end && *left > *large) {
        large = left;
    }

    if(right < end && *right > *large) {
        large = right;
    }

    if(large != node) {
        std::swap(*large, *node);
        Heapify(begin, end, large);
    }

}

template <typename It>
void BuildHeap(It begin, It end) {
    for (auto it = std::next(begin, std::distance(begin, end) / 2 - 1); it >= begin; --it) {
        Heapify(begin, end, it);    
    }
}

template <typename It>
void HeapSort(It begin, It end) {
    BuildHeap(begin, end);
    for(auto it = std::next(end, -1); it >= begin; --it) {
        std::swap(*begin, *it);
        Heapify(begin, it, begin);
    }
}



int main() {

    int32_t N;
    int32_t X;
    std::vector<int32_t> A;
    std::cin >> N;
    for (int32_t i = 0; i != N; ++i) {
        std::cin >> X;
        A.push_back(X);
    }

    if (N == 0) {
        return 0;
    }

    if (A.size() == 0) {
        return 0;
    }



//    std::vector<int32_t> A = {2, 5, 7, 3, 9, 8, 1};

    HeapSort(A.begin(), A.end());

    for (size_t i = 0; i < A.size(); ++i) {
        std::cout << A[i] << " ";
    }

    return 0;

}