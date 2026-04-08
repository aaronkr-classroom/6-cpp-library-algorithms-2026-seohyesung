// split_str.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cctype> // isspace 함수 // 자료형의 함수 여러개 있다.
// isspace 함수는 a가 공백이면 참 값을 반환

using namespace std;

// 인수가 공백일 때는 false, 
// 공백이 아닐 때는 true를 반환하는 함수
bool not_space(char c) {
	return isspace(c);
}

// 인수가 공백일 때는 true, 
// 공백이 아닐 때는 false를 반환하는 함수
bool space(char c) {
	return isspace(c);
}

vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type str_sz;
	str_sz i = 0;

	// 불변성 : 지금까지 [원래의 i, 현재의 i) 범위에 있는 요소들은 공백이 아닌 문자들
	// 문자들을 처리
	while (i != s.size()) {
		// 공백 무시
		// 불변성 : 지금까지 [원래의 i, 현재의 i) 범위에 있는 요소들은 공백이 아닌 문자들
	// 문자들은 모두 공백 (isspace())
		while (i != s.size() && isspace(s[i])) {
			++i;
		}

		// 순서상 다음 단어의 끝을 찾음
		str_sz j = i;

		// 불변성 : 지금까지 [원래의 i, 현재의 i) 범위에 있는 요소들은 공백이 아닌 문자들
		// 문자들은 공백이 아님 (!isspace())

		while (j != s.size() && !isspace(s[j])) {
			j++;
		}

		// 공백이 아닌 문자들을 찾았을 때
		if (i != j) {
			// i에서 부터 j-1개의 문자들을 s에 복사
			ret.push_back(s.substr(i, j - 1));
			i = j; // j 인덱스가 i 인덱스로 이동
		}
	}
	return ret;
}

vector<string> lib_split(const string& s) {
	vector<string> ret;
	typedef string::const_iterator iter;
	iter i = s.begin(); /// 첫 요소에 가리키는 포인터 (개념)

	// 불변성 : 지금까지 [원래의 i, 현재의 i) 범위에 있는 요소들은 공백이 아닌 문자들
	// 문자들을 처리
	while (i != s.end()) {
		// 선행 공백을 무시
		i = find_if(i, s.end(), not_space);

		// 순서상 다음 단어의 끝을 찾음
		iter j = find_if(i, s.end(), space);

		// [원래의 i, 현재의 i) 범위에 있는
		// 문자들을 복사

		if (i != s.end()) {
			// i에서 부터 j-1개의 문자들을 s에 복사
			ret.push_back(string(i, j));
		}

		i = j; // j 인덱스가 i 인덱스로 이동
	}
	return ret;
}

int main(void) {
	string s;
	while (getline(cin, s)) {
		vector<string> v1 = split(s);
		vector<string> v2 = lib_split(s);

		cout << "Original split(): " << endl;
		for (vector<string>::size_type i = 0; 
			i != v1.size(); ++i) {
			cout << v1[i] << endl;
		}

		cout << endl << "New lib_split(): " << endl;
		for (vector<string>::size_type i = 0;
			i != v2.size(); ++i) {
			cout << v2[i] << endl;
		}

		return 0;
	}
}

