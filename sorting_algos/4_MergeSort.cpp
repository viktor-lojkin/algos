#include <vector>
#include <iostream>

template <class LegacyRandomAccessIterator>
void Merge (LegacyRandomAccessIterator l_begin, LegacyRandomAccessIterator l_end,
            LegacyRandomAccessIterator r_begin, LegacyRandomAccessIterator r_end,
            LegacyRandomAccessIterator d_begin)                                    {
	

    if ((std::distance(l_begin, l_end) == 0) || (std::distance(r_begin, r_end) == 0)) {
    	return;
    }

    while (l_begin < l_end && r_begin < r_end) {  
        if (*l_begin <= *r_begin) {
            *d_begin = *l_begin;
            ++d_begin;
            ++l_begin;
        } else {
            *d_begin = *r_begin;
            ++d_begin;
            ++r_begin;
        }
    }

    while (l_begin < l_end) {
        *d_begin = *l_begin;
        ++d_begin;
        ++l_begin;
    }

    while (r_begin < r_end) {
        *d_begin = *r_begin;
        ++d_begin;
        ++r_begin;
    }

}

template <class LegacyRandomAccessIterator>
void MergeSort(LegacyRandomAccessIterator begin,
                   LegacyRandomAccessIterator end) {
    
    auto dist = std::distance(begin, end);
    
    if (dist < 2) {
        return;
    }

    std::vector<typename LegacyRandomAccessIterator::value_type> sort_me(begin, end);

    auto mid = sort_me.begin() + dist / 2;

    MergeSort(sort_me.begin(), mid);
    MergeSort(mid, sort_me.end());

    Merge(sort_me.begin(), mid, mid, sort_me.end(), begin);

}

int main() {

/*
*** Задача ***
// Реализуйте сортировку слиянием, используя алгоритм из предыдущей задачи.
// На каждом шаге делите массив на две части, сортируйте их независимо и сливайте с помощью
// уже реализованной функции.

// *** Ввод ***
// В первой строке входного файла содержится число N — количество элементов массива
// (0 ≤ N ≤ 10^6).
// Во второй строке содержатся N целых чисел ai, разделенных пробелами
// (-10^9 ≤ ai ≤ 10^9).

// *** Вывод ***
// Выведите результат сортировки, то есть N целых чисел, разделенных пробелами, в порядке неубывания.
*/

    int32_t N;
    std::vector<int32_t> A;

    std::cin >> N;
    for (int32_t i = 0; i != N; ++i) {
        int32_t X;
        std::cin >> X;
        A.push_back(X);
    }
    
    if (N == 0) {
        return 0;
    }

    MergeSort(A.begin(), A.end());

    for (size_t i = 0; i < A.size(); ++i) {
        std::cout << A[i] << " ";
    }

    return 0;

}