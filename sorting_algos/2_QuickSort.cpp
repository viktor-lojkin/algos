#include <vector>
#include <iostream>

template <class LegacyRandomAccessIterator, typename Predicat>
std::pair<LegacyRandomAccessIterator, LegacyRandomAccessIterator>
Partition(Predicat p, LegacyRandomAccessIterator begin, LegacyRandomAccessIterator end) {
	
    auto E = begin; auto G = begin; auto N = begin;
    auto buff = p;

    while (N <= end) {

        if (*N == p) {
            std::swap(*N, *G);
            ++G;
        }
    	else if (*N < p) {
            
            buff = *N;
            *N = *G;
            *G = *E;
            *E = buff;
            
            ++E; ++G;
        }
        
            	
        ++N;

    }

    return {E, G};

}

template <class LegacyRandomAccessIterator>
void QuickSortImpl(LegacyRandomAccessIterator begin, LegacyRandomAccessIterator end);

template <class LegacyRandomAccessIterator>
void QuickSort(LegacyRandomAccessIterator begin, LegacyRandomAccessIterator end) {
    QuickSortImpl(begin, std::next(end, -1));
}

template <class LegacyRandomAccessIterator>
void QuickSortImpl(LegacyRandomAccessIterator begin, LegacyRandomAccessIterator end) {
	
    if (begin < end) {
    	
    	int32_t pivot = *begin;
    	if ((end - begin) > 2) {
        	pivot = *(begin + (end - begin)/3 - 1);
        }
    	
    	//auto result = Partition(pivot, begin, end);
        auto [E, G] = Partition(pivot, begin, end);
        
        QuickSortImpl(begin, --E);
	    QuickSortImpl(G, end);
        
        
    }

}

int main() {

/*
*** Задача ***
// Реализуйте быструю сортировку, используя алгоритм Partition из предыдущей задачи.
// На каждом шаге выбирайте опорный элемент и выполняйте partition относительно него.
// Затем рекурсивно запуститесь от двух частей, на которые разбился исходный массив.

// *** Ввод ***
// В первой строке входного файла содержится число N — количество элементов массива (0 ≤ N ≤ 10^6).
// Во второй строке содержатся N целых чисел ai, разделенных пробелами (-10^9 ≤ ai ≤ 10^9).

// *** Вывод ***
// Выведите результат сортировки, то есть N целых чисел, разделенных пробелами.

// *** Примечания ***
// 

*/

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

    QuickSort(A.begin(), A.end());

    for (size_t i = 0; i < A.size(); ++i) {
        std::cout << A[i] << " ";
    }

    return 0;

}
