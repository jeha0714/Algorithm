#include <string>
#include <stack>
#include <cmath>
#include <unordered_map>

using namespace std;

/*
모든 경우의 수를 파악해봐야 한다. -> 3! = 6
절대값을 구해야 한다.

해결방법
0. 우선순위를 어떻게 간편하게 정할 수 있을까?
-> 이중 for문 돌리자.

선언 - 숫자 n, 연산자 o
1. n / o 가 비었을 때는 일단 push
2. n / o 가 차있을 때 
- 숫자 : 계속 push, operator에 따라 pop하게 만듦
- 연산자
	a. top < new
        -> new push만?
    b. top == new
    	- 숫자 두개를 꺼내서 top을 수행하고 push & operator push
    c. top > new
    	- 숫자 두개를 꺼내서 top을 수행하고 push & operator push
	d. 전부 순회 후
    	- operator하나와 숫자 2개 pop해서 결과 push 반복
*/

long long	calc_op(char op, long long num1, long long num2) {
    long long	num;
    
    if (op == '+') num = num2 + num1;
    else if (op == '-') num = num2 - num1;
    else if (op == '*') num = num2 * num1;
    
    return (num);
}

long long	calc(string & exp, unordered_map<char, int> & pr) {
    long long	num, num1, num2;
    char		op;
    char *		next;
    stack<char>			ops;
    stack<long long>	nums;
    
    // 1. Calculate
    for (const char * i = exp.c_str(); *i != '\0';) {
        // a. if num
        if ('0' <= *i && *i <= '9') {
            num = strtoll(i, &next, 0);
            nums.push(num);
            i = next;
        }
		// b. operator
        else {
            op = *i;
            next += 1;
            // 0) ops is empty
            if (ops.empty()) ops.push(op);
            else {
                // 1) ops.top() < op
                if (pr[ops.top()] < pr[op]) {
                    ops.push(op);
                }
                // 2) ops.top() == op
                // 3) ops.top() > op
                else {
                    while (!ops.empty() && pr[ops.top()] >= pr[op]) {
                        num1 = nums.top(); nums.pop();
                        num2 = nums.top(); nums.pop();
                        op = ops.top(); ops.pop();
                        num = calc_op(op, num1, num2);
                        op = *i;
                        nums.push(num);
                    }
                    ops.push(op);
                }
            }
            i = next;
        }
    }
    
    // c. make ops to empty
    while (!ops.empty()) {
        num1 = nums.top(); nums.pop();
        num2 = nums.top(); nums.pop();
        op = ops.top(); ops.pop();
        num = calc_op(op, num1, num2);
        nums.push(num);       
    }
    
    // 2. Return Num
    return (nums.top());
}

long long solution(string expression) {
    long long answer = 0; 
    unordered_map<char, int>	pr;
    
    // 0. Init
    // -> set priority
    pr['+'] = 0;
    pr['-'] = 0;
    pr['*'] = 0;
    for (unordered_map<char, int>::iterator it1 = pr.begin(); it1 != pr.end(); it1++) {
        it1->second = 1;
        for (unordered_map<char, int>::iterator it2 = pr.begin(); it2 != pr.end(); it2++) {
            if (it2 != it1) {
                it2->second = 2;
                for (unordered_map<char, int>::iterator it3 = pr.begin(); it3 != pr.end(); it3++) {
                    if (it3 != it1 && it3 != it2) {
                        it3->second = 3;
                        // 1. Calculate
                        answer = max(answer, abs(calc(expression, pr)));
                    }
                }
            }
        }
    }
    
    // 2. Return Answer
    return answer;
}