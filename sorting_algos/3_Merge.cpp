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
void MergeSort(LegacyRandomAccessIterator begin, LegacyRandomAccessIterator end) {
	
    if (begin < end) {
    	
    	int32_t pivot = *begin;
    	if ((end - begin) > 2) {
        	pivot = *(begin + (end - begin)/3 - 1);
        }
    	
    	//auto result = Partition(pivot, begin, end);
        auto [E, G] = Partition(pivot, begin, end);
        
        MergeSortImpl(begin, --E);
	    MergeSortImpl(G, end);
        
        
    }

}


int main() {

/*
*** Задача ***
// Базовый алгоритм для сортировки слиянием — алгоритм слияния двух упорядоченных массивов
// в один упорядоченный массив. Эта операция выполняется за линейное время с линейным потреблением памяти.
// Реализуйте слияние двух массивов в качестве первого шага для написания сортировки слиянием.

// *** Ввод ***
// В первой строке входного файла содержится число N — количество элементов первого массива
// (0 ≤ N ≤ 10^6).
// Во второй строке содержатся N целых чисел ai, разделенных пробелами, отсортированные по неубыванию
// (-10^9 ≤ ai ≤ 10^9).
// В третьей строке входного файла содержится число M — количество элементов второго массива
// (0 ≤ M ≤ 10^6).
// В третьей строке содежатся M целых чисел bi, разделенных пробелами, отсортированные по неубыванию
// (-10^ ≤ bi ≤ 10^9).

// *** Вывод ***
// Выведите результат слияния этих двух массивов, то есть M + N целых чисел, разделенных пробелами,
// в порядке неубывания.

// *** Примечания ***
// Для решения этой задачи советуем реализовать функцию, которая принимает на вход две пары итераторов,
// задающие два массива, и итератор на начало буфера, в который необходимо записывать результат.
// Итераторы можно заменить на передачу массивов и индексов в них. В таком виде вам будет удобно использовать
// эту функцию для реализации сортировки.

*/

    int32_t N;
    int32_t M;
    std::vector<int32_t> A;
    std::vector<int32_t> B;

    std::cin >> N;
    for (int32_t i = 0; i != N; ++i) {
        int32_t X;
        std::cin >> X;
        A.push_back(X);
    }
    
    std::cin >> M;
    for (int32_t i = 0; i != M; ++i) {
        int32_t X;
        std::cin >> X;
        B.push_back(X);
    }

    if (N == 0 && M == 0) {
        return 0;
    }

    if (N == 0) {
        for (size_t i = 0; i < B.size(); ++i) {
            std::cout << B[i] << " ";
        }
        return 0;
    }

    if (M == 0) {
        for (size_t i = 0; i < A.size(); ++i) {
            std::cout << A[i] << " ";
        }
        return 0;
    }
    
    std::vector<int32_t> result;
    result.resize(N + M);
    Merge(A.begin(), A.end(), B.begin(), B.end(), result.begin());

    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return 0;

}