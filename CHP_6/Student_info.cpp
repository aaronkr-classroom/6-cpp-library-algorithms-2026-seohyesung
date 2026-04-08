// Student_info.cpp
#include "Student_info.h"

// 이름 비교하기
bool compare(const Student_info& a, const Student_info& b) {
	return a.name < b.name;
}

// 한 학생의 정보 읽기
istream& read(istream& in, Student_info& s) {
	// 학생의 이름, 중간고사 점수, 기말고사 점수 읽기
	in >> s.name >> s.midterm >> s.final;
	read_hw(in, s.homework); // 과제 점수 읽기
	return in;
}

 // 모든 과제 점수 읽기
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		// 이전 내용 제거
		hw.clear();

		// 과제 점수를 읽어서 벡터에 저장
		double x;

		while (in >> x) {
			hw.push_back(x);
		}

		// 다음 학생의 점수 입력 작업을 고려해 스트림을 지움
		in.clear();
	}
	return in;
}
