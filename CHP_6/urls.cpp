// urls.cpp
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef string::const_iterator iter; 
typedef vector<string>::const_iterator v_iter;


bool not_url_char(char c) {
    // URL에 들어갈 수 있는 알파벳과 숫자 이외의 문자
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    // c가 URL에 들어갈 수 있는 문자인지 확인하면 음수를 반환
	return !(
        isalnum(c) || 
        find(url_ch.begin(), url_ch.end(), c) != url_ch.end()
        );
}

iter url_end(iter b, iter e) {
        return find_if(b, e, not_url_char);
	}   

iter url_beg(iter b, iter e) {
		static const string sep = "://";


		// i는 구분 기호를 발견한 위치를 가리킴
        iter i = b;
		while ((i = search(i, e, sep.begin(), sep.end())) != e)
        {
			// 구분 기호 앞에 알파벳이 있는지 확인
			if (i != b && i + sep.size() != e) {   
                // beg은 프로토콜 이름의 시작위치를 표시
				iter beg = i; //  ;위치부터 시작
                while (beg != b && isalpha(beg[-1])) {
					--beg; // beg이 b보다 크고, beg의 바로 앞 문자가 알파벳이면 beg을 앞으로 이동

                }

                // 구분 기호 앞뒤로 URL의 일부에서
                // 유효한 문자가 하나라도 있는지 확인
				if (beg != i && !not_url_char(i[sep.size()])) {
                    return beg; // URL의 시작 위치 반환
                }
                // 발견한 구분 기호는 URL 일부가 아니므로
                // 해당 구분 기호 이후를 표시하도록 i를 증가시킴
            }
            // 발견한 구분 기호는 URL 일부가 아니므로
                // 해당 구분 기호 이후를 표시하도록 i를 증가시킴
			
        }
		return e; // URL이 발견되지 않음
    }

    vector<string> find_urls(const string& s) {
        vector<string> urls;
		iter b = s.begin(), 
            e = s.end();

        // 인수로 전달받은 문자열 전체를 탐색
        while (b != e) {
			// b가 가리키는 위치에서 URL의 시작을 찾음
            b = url_beg(b, e);
			// URL이 발견되지 않으면 탐색 종료

            if (b != e) {
            // 해당 문자를 찾았다면 URL의 나머지 부분을 탐색
                iter after = url_end(b, e); // 프로토콜 이름 후

                // URL을 찾았으면 저장
                urls.push_back(string(b, after)); 

                // 인수로 전달받은 문자열에서 또
				// 다른 URL을 찾기 위해 after 위치에서 탐색 시작
				b = after;
            }
    }
    return urls;
}

    int main() {
    string s;
    while (getline(cin, s)) {
        vector<string> v = find_urls(s);

        for (v_iter i = v.begin(); i != v.end(); ++i) {
            cout << *i << endl;
        }
    }
    return 0;
}
