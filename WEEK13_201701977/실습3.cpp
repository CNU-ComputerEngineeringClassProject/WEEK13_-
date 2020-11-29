/* Functor */

#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	//비교하고 조건(내림차순/올림차순)에 맞게 값을 찾아 배열의 제일 마지막 인덱스부터 차례로 저장한다.
	for (auto sorted = first; first != last; last = sorted) { 
		sorted = first; 
		for (auto cur = first, prev = first; ++cur != last; ++prev) { 
		
		//단항연산자 연산 후
		//cur는 prev의 원소값과 비교할 원소값을 가지고 있다. 
		//prev는 first위치부터 prev위치까지 원소 들 중 가장 조건에 맞는 원소값(내림차순일 경우 min값,오름차순일 경우 max값)을 가지고 있다.
		
			if (comp(*cur, *prev)) { //cur의 원소값과 prev의 원소값을 비교하여 조건을 만족하면 두 원소의 위치를 바꾼다.
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}
	}
}

//내림차순 - 두 인자를 비교해 첫번째 인자가 더 크면 true반환, 아닐경우 false반환 
class compGreater {
public:
	bool operator()(int firstOperand, int secondOperand) const {
		return firstOperand > secondOperand;
	}
};

//오름차순 - 두 인자를 비교해 첫번째 인자가 더 작으면 true반환, 아닐경우 false반환
class compLess {
public:
	bool operator()(int firstOperand, int secondOperand) const {
		return firstOperand < secondOperand;
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
	std::cout << "오름차순 정렬" << std::endl;
	compLess compLess; //Functor 생성
	bubble_sort(values.begin(), values.end(), compLess);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	std::cout << "내림차순 정렬" << std::endl;
	compGreater compGreater; //Functor 생성
	bubble_sort(values.begin(), values.end(), compGreater);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	getchar();
}
