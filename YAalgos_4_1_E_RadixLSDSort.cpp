#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>
#include <iostream>

/*
*** Задача ***
Поразрядная сортировка является одним из видов сортировки, которые работают
практически за линейное от размера сортируемого массива время.
Такая скорость достигается за счет того, что эта сортировка использует
внутреннюю структуру сортируемых объектов. Изначально этот алгоритм использовался
для сортировки перфокарт. Первая его компьютерная реализация была создана
в университете MIT Гарольдом Сьюардом (Harold Н. Seward).

Опишем алгоритм подробнее.
Пусть задан массив строк s1 , ..., si причём все строки имеют одинаковую длину m.
Работа алгоритма состоит из m фаз. На i -ой фазе строки сортируются па i -ой с конца букве.

Происходит это следующим образом.
Будем, для простоты, в этой задаче рассматривать строки из цифр от 0 до 9.
Для каждой цифры создается «корзина» («bucket»), после чего строки si распределяются
по «корзинам» в соответствии с i-ой цифрой с конца. Строки, у которых i-ая с конца цифра
равна j попадают в j-ую корзину. Например, строка 123 на первой фазе попадет в третью корзину,
на второй — во вторую, на третьей — в первую. После этого элементы извлекаются из корзин
в порядке увеличения номера корзины. Таким образом, после первой фазы строки отсортированы
по последней цифре, после двух фаз — по двум последним, ..., после m фаз — по всем.
Причём важно, чтобы элементы в корзинах сохраняли тот же порядок, что и в исходном массиве
(до начала этой фазы). Например, если массив до первой фазы имеет вид: 111, 112, 211, 311,
то элементы по корзинам распределятся следующим образом: в первой корзине будет 111, 211, 311,
а второй: 112.

Напишите программу, детально показывающую работу этого алгоритма на заданном массиве.

*** Ввод ***
Первая строка входного файла содержит целое число n (1 ≤ n ≤ 1000).
Последующие n строк содержат каждая по одной строке si .
Длины всех si , одинаковы и не превосходят 20.
Все si состоят только из цифр от 0 до 9.

*** Вывод ***
В выходной файл выведите исходный массив строк,
состояние «корзин» после распределения элементов по ним для каждой фазы
и отсортированный массив.

Следуйте формату, приведенному в примере.

Initial array:
12, 32, 45, 67, 98, 29, 61, 35, 09
**********
Phase 1
Bucket 0: empty
Bucket 1: 61
Bucket 2: 12, 32
Bucket 3: empty
Bucket 4: empty
Bucket 5: 45, 35
Bucket 6: empty
Bucket 7: 67
Bucket 8: 98
Bucket 9: 29, 09
**********
Phase 2
Bucket 0: 09
Bucket 1: 12
Bucket 2: 29
Bucket 3: 32, 35
Bucket 4: 45
Bucket 5: empty
Bucket 6: 61, 67
Bucket 7: empty
Bucket 8: empty
Bucket 9: 98
**********
Sorted array:
09, 12, 29, 32, 35, 45, 61, 67, 98
*/

template <typename Container>
void Print(std::ostream& out, const Container& container) {
    bool is_first = true;
    for (const auto& term : container) {
        if (!is_first) {
            out << ", ";
        }
        is_first = false;
        out << term;
    }
}

template <typename Term>
std::ostream& operator<<(std::ostream& out, const std::vector<Term>& container) {
    Print(out, container);
    return out;
}

void PrintPhase(const std::map<int, std::vector<std::string>>& count, size_t phase) {
    std::cout << "Phase " << phase << "\n";
    for (auto [bucket, some_digits] : count) {
        std::cout << "Bucket " << bucket << ": ";
        if (some_digits.empty()) std::cout << "empty" << "\n";
        else std::cout << some_digits << "\n";
    }
    std::cout <<   "**********"   << "\n";
}

/*
template <class LegacyRandomAccessIterator, typename T>
std::unordered_map<std::hash<T>, size_t> CountElems (LegacyRandomAccessIterator begin, LegacyRandomAccessIterator end) {

    std::unordered_map<std::hash<std::string>, size_t> count;

    while (begin < end) {
        count[*begin] += 1;
        ++begin;
    }

    return count;

}
template <typename T>
std::unordered_map<std::hash<T>, size_t> CountToPositions (const std::unordered_map<std::hash<T>, size_t>& count) {

    std::unordered_map<std::hash<T>, size_t> positions;

    size_t pos = 0;
    for (auto [hash, x] : count) {
        positions[hash] = pos;
        pos += x;
    }

    return positions;
}
*/

template <class LegacyRandomAccessIterator>
void RadixLSDSortImpl(const std::map<int, std::vector<std::string>>& init_buckets,
                      LegacyRandomAccessIterator begin,
                      LegacyRandomAccessIterator end,
                      int radix_pos_l,
                      int radix_pos_r,
                      int phase);

template <class LegacyRandomAccessIterator>
void RadixLSDSort(LegacyRandomAccessIterator begin,
                   LegacyRandomAccessIterator end) {
    
    auto str = *begin;
    int radix_pos_l = str.size() - 1;
    int radix_pos_r = 1;

    std::map<int, std::vector<std::string>> init_buckets = {
        {0, {}},
        {1, {}},
        {2, {}},
        {3, {}},
        {4, {}},
        {5, {}},
        {6, {}},
        {7, {}},
        {8, {}},
        {9, {}},
    };  

    int phase = 1;

    RadixLSDSortImpl(init_buckets, begin, end, radix_pos_l, radix_pos_r, phase);

}

template <class LegacyRandomAccessIterator>
void RadixLSDSortImpl(const std::map<int, std::vector<std::string>>& init_buckets,
                      LegacyRandomAccessIterator begin,
                      LegacyRandomAccessIterator end,
                      int radix_pos_l,
                      int radix_pos_r,
                      int phase) {
    
    if (radix_pos_l >= 0) {

    std::map<int, std::vector<std::string>> buckets = init_buckets;

    auto b = begin; auto e = end;
    for (; b < e; ++b) {
        
        std::string digit = *b;
        std::string ch_radix = digit.substr(radix_pos_l, radix_pos_r);
        int radix = std::stoi(ch_radix);
        buckets[radix].push_back(*b);
    }
    

    b = begin;
    for (auto [radix, digits] : buckets) {
        for (auto digit : digits) {
            *b = digit;
            ++b;
        }
    }

    PrintPhase(buckets, phase);
    ++phase;

    --radix_pos_l;
    
    RadixLSDSortImpl(init_buckets, begin, end, radix_pos_l, radix_pos_r, phase);
    
    } else {
        return;
    }


}

// Как добавлять ведущие нули к строкам разной длины?

int main() {

    int32_t N;
    std::vector<std::string> digits;

    std::cin >> N;
    for (int32_t i = 0; i != N; ++i) {
        std::string X;
        std::cin >> X;
        digits.push_back(X);
    }    
    
    /*
    std::vector<std::string> digits = {
        "12", "32", "45", "67", "98", "29", "61", "35", "09"
    };
    */
    std::cout << "Initial array:" << "\n";
    std::cout <<      digits      << "\n";
    std::cout <<   "**********"   << "\n";

    RadixLSDSort(digits.begin(), digits.end());
    
    std::cout << "Sorted array:" << "\n";
    std::cout <<    digits       << "\n";

	return 0;

}