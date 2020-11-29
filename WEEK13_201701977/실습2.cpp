/* Template-variadic template */
// 마지막 sum 호출 시 파라미터가 하나만 남는다.
// sum 함수는 파라미터를 두개 받기때문에 호출될 수 없으므로 컴파일 에러가 발생한다.
// 그래서 파라미터를 하나 가지는 sum함수를 template으로 생성하고 정의한다.

#include <iostream>
#include <string>

template <typename T>
auto sum(T x) {
	return x;
}

template <typename T, typename...Args>
auto sum(T x, Args...args) {
	return x + sum(args...);
}

int main() {
	auto x = sum(42.5, 10, 11.1f);
	std::cout << x;

	getchar();
}
