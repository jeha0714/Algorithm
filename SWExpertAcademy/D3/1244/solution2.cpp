/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum {
    NONVISIT,
    VISIT
};

int     cal_digits(int num) {
    int digits = 1;

    while (num >= 10) {
        digits++;
        num /= 10;
    }

    return (digits);
}

int     swap_num(int num, int digits, int i, int j) {
    string  str;
    int tmp;

    str.resize(digits);
    for (int ith = digits - 1; ith >= 0; ith--) {
        str[ith] = (num % 10) + '0';
        num /= 10;
    }

    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;

    return (stoi(str, nullptr));
}

void    dfs(vector<vector<int> > & v_num, int num, int digits, int n_transaction) {
    int tmp;

    // 1. Degenerate Case
    if (n_transaction < 0 || v_num[num][n_transaction] == VISIT)
        return ;
    v_num[num][n_transaction] = VISIT;

    // 2. Divide Case
    for (int i = 0; i < digits; i++) {
        for (int j = i + 1; j < digits; j++) {
            tmp = swap_num(num, digits, i, j);
            dfs(v_num, tmp, digits, n_transaction - 1);
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int num, n_transaction; // inputs
    vector<vector<int> >    v_num(1000001, vector<int>(11, NONVISIT));
    int digits;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // 0. init info
        cin >> num >> n_transaction;
        for (int i = 0; i <= 1000000; i++) {
            for (int j = 0; j <= 10; j++) {
                v_num[i][j] = NONVISIT;
            }
        }
        digits = cal_digits(num);

        // 1. Do dfs
        dfs(v_num, num, digits, n_transaction);

        // 2. print result
        cout << "#" << test_case << " ";
        for (int i = 999999; i >= 1; i--) {
            if (v_num[i][0] == VISIT) {
                cout << i << "\n";
                break ;
            }
        }
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}