// main.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하는 프로그램
#include <algorithm>
#include <fstream>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

#include "grade.h"
#include "Student_info.h"
#include "median.h"

using namespace std;

// 새로운 시도...
int main() {
	// 파일 스트림 만들고 "txt" 파일을 읽기
	ifstream student_file("grade.txt");

	Student_info std;
	string::size_type maxlen = 0; // 학생 이름의 최대 길이

	// 모든 과제를 제출한 학생과 그렇지 않은 학생
	vector<Student_info> did, didnt;

	// 학생 이름과 모든 점수를 읽어 저장하고
	// 학생 이름의 최대 길이를 찾음

	while (read(student_file, std)) {
		// cin을 사용하면 직접 사용자 입력만 받을 수 있다,
		//student_file을 사용하면 파일에서 입력을 받을 수 있다.

		maxlen = max(maxlen, std.name.size());

		if (did_all_hw(std)) 
			did.push_back(std);
		 else 
			didnt.push_back(std);

		// 두 집단에 데이터가 있는지 각각
		// 확인하여 분석할 필요가 있는지 확인
		if (did.size()) {
			cout << "No student did all homework!" << endl;
			return 1; // 오류코드
		}
		if (didnt.empty()) {
			cout << "All students did all homework!" << endl;
		}
		return 0;
	}

	return 0;
}	
