#include <vector>
#include <iostream>
#include <iterator>

template <class LegacyRandomAccessIterator, typename Predicat>
std::pair<LegacyRandomAccessIterator, LegacyRandomAccessIterator>
Partition(Predicat p, LegacyRandomAccessIterator begin, LegacyRandomAccessIterator end) {
	
    if (begin == end) return begin;

    auto E = begin; auto G = begin; N = begin;
    auto buff = p;

    while (N <= end) {

        if (*N < p) {
            
            buff = *N;
            *N = *G;
            G* = *E;
            *E = buff;

            ++E; ++G; ++N;
        }

        if (*N == p) {
            std::swap(*N, *G);
            ++G; ++N;
        }

        if (*N > p) {
            ++N;
        }

    }

    return {E, G};

}

int main() {

/*
// *** Ввод ***
// В первой строке входного файла содержится число N — количество элементов массива (0 ≤ N ≤ 10^6).
// Во второй строке содержатся N целых чисел ai, разделенных пробелами (-10^9 ≤ ai ≤ 10^9).
// В третьей строке содержится опорный элемент x (-10^9 ≤ x ≤ 10^9).
// Заметьте, что x не обязательно встречается среди ai.

// *** Вывод ***
// Выведите результат работы вашего алгоритма при использовании предиката «меньше x»:
// в первой строке выведите число элементов массива, меньших x,
// а во второй — количество всех остальных.

// *** Примечания ***
// Чтобы решить задачу, советуем реализовать функцию,
// которая принимает на вход предикат и пару итераторов, задающих массив (или массив и два индекса в нём),
// и возвращает точку разбиения, то есть итератор (индекс) на конец части, которая содержащит элементы,
// удовлетворяющие заданному предикату.
// В таком виде вам будет удобно использовать эту функцию для реализации сортировки.
*/
/*
for (size_t i = 0; i < A.size(); ++i) {
    std::cout << A[i] << "\t";
}
std::cout << "\n";

auto p = [](int32_t a){ return a < 3; };
std::vector<int32_t> A {1, 9, 4, 2, 3};  
auto p = [](int32_t a){ return a < 0; };
std::vector<int32_t> A {};
*/

    int32_t N;
    int32_t X;
    std::vector<int32_t> A;
    std::cin >> N;
    for (int32_t i = 0; i != N; ++i) {
        std::cin >> X;
        A.push_back(X);
    }
    std::cin >> X;

    if (N <= 0) {
        std::cout << 0 << "\n" << 0 << "\n";
        return 0;
    }

    auto it = Partition(p, A.begin(), --A.end());

    int32_t less = std::distance(A.begin(), it);
    int32_t other = std::distance(it, A.end());

    std::cout << less << "\n" << other << "\n";

    return 0;

}
