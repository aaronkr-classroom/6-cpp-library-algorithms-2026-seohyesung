// median.cpp

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "median.h"

using namespace std; // domain_error를 사용하기 위해

//vector<double>의 중앙값을 구함
// 함수를 호출하면 인수로 제공된 벡터를 통째로 복사
double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0) {
		throw domain_error("median of empty vector!");
		// return 1; // 
	}

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0
		? (vec[mid] + vec[mid - 1]) / 2 // 참일 때 반환
		: vec[mid]; // 거짓일 때 반환
}

