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

using namespace std;

vector<int>    conv_num_to_vec(int num) {
    vector<int> reverse;
    vector<int> normal;

    // 1. reverse
    while(num) {
        reverse.push_back(num % 10);
        num /= 10;
    }

    // 2. normal
    for (int i = reverse.size() - 1; i >= 0; i--) {
        normal.push_back(reverse[i]);
    }

    return (normal);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int num, n_transaction; // inputs
    vector<int> v_num, origin;
    int tmp;
    int mostBig;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // 0. init info
        cin >> num >> n_transaction;
            // convert num to vector
        v_num = conv_num_to_vec(num);
        origin = v_num;

//        for (int i = 0; i < v_num.size(); i++)
//            cout << v_num[i];
        
        // 1. Sequential Comparison
        for (int i = 0; i < v_num.size(); i++) {
            // stop condition
            if (n_transaction == 0)
                break ;

            // a. compare
            mostBig = i;
            for (int cmp = i + 1; cmp < v_num.size(); cmp++) {
                if (v_num[mostBig] <= v_num[cmp])
                    mostBig = cmp;
            }

            // b. swap 
            if (mostBig != i) {
                n_transaction--;
                tmp = v_num[mostBig];
                v_num[mostBig] = v_num[i];
                v_num[i] = tmp;
            }
        }

        // 2. 교환한 번호가 같은경우 내림차순으로 바꾸기
        for (int i = 0; i < v_num.size(); i++) {
            if (v_num[i] == origin[i])
                continue ;

            mostBig = i;
            for (int cmp = i + 1; cmp < v_num.size(); cmp++) {
                if (origin[mostBig] == origin[cmp] && v_num[mostBig] < v_num[cmp])
                    mostBig = cmp;
            }

            if (mostBig != i) {
                n_transaction--;
                tmp = v_num[mostBig];
                v_num[mostBig] = v_num[i];
                v_num[i] = tmp;
            }
        }

        // 3. 남은 n_transaction 사용하기
        if (n_transaction) {
            // a. 같은 자리 수가 있다면 교환하기
            int flag = 0;
            for (int i = 0; i < v_num.size(); i++) {
                for (int cmp = i + 1; cmp < v_num.size(); cmp++) {
                    if (v_num[i] == v_num[cmp]) {
                        flag = 1;
                        break ;
                    }
                }
                if (flag)
                    break ;
            }

            // b. 교환해야 하는 횟수가 홀수라면 끝 2자리 바꾸기
            if (flag == 0 && n_transaction % 2 == 1) {
                tmp = v_num[v_num.size() - 1];
                v_num[v_num.size() - 1] = v_num[v_num.size() - 2];
                v_num[v_num.size() - 2] = tmp;
            }
        }

        // 4. print result
        cout << "#" << test_case << " ";
        for (int i = 0; i < v_num.size(); i++)
            cout << v_num[i];
        cout << "\n";
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}