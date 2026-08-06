#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum {
    CPP = 0,
    JAVA = 1,
    PYTHON = 2,
    BACKEND = 0,
    FRONTEND = 1,
    JUNIOR = 0,
    SENIOR = 1,
    CHICKEN = 0,
    PIZZA = 1,
    NVM = -1,
};

/*
가장 쉽게 푸는 방법은
query를 최외각 for문으로 잡고 info를 처음부터 계속 순회하는 방법
-> 그런데 info를 계속 순회하는건 맞는데 이들을 숫자로 치환해두는건 어떤가?
*/

void	sep_info(const string & info, vector<vector<vector<vector<vector<int>>>>> & v) {
    int lang, dev, exp, food;
    int 		i = 0;
    
    // a. set lang
    if (info[i] == 'c') lang = CPP;
    else if (info[i] == 'j') lang = JAVA;
    else if (info[i] == 'p') lang = PYTHON;
    
    // b. set department
    while (info[i] != ' ') i++;
    i++;
    if (info[i] == 'b') dev = BACKEND;
    else if (info[i] == 'f') dev = FRONTEND;
    
    // c. set exp
    while (info[i] != ' ') i++;
    i++;
    if (info[i] == 'j') exp = JUNIOR;
    else if (info[i] == 's') exp = SENIOR;
    
    // d. set soul food
    while (info[i] != ' ') i++;
    i++;
    if (info[i] == 'c') food = CHICKEN;
    else if (info[i] == 'p') food = PIZZA;
    
    // e. set score
    while (info[i] != ' ') i++;
    i++;
    v[lang][dev][exp][food].push_back(atoi(info.c_str() + i));
}

vector<int>	sep_query(const string & info) {
    vector<int>	ret(5, 0);
    int 		i = 0;
    
    // a. set lang
    if (info[i] == 'c') ret[0] = CPP;
    else if (info[i] == 'j') ret[0] = JAVA;
    else if (info[i] == 'p') ret[0] = PYTHON;
    else if (info[i] == '-') ret[0] = NVM;
    
    // b. set department
    while (info[i] != ' ') i++;
    i++;
    while (info[i] != ' ') i++;
    i++;
    if (info[i] == 'b') ret[1] = BACKEND;
    else if (info[i] == 'f') ret[1] = FRONTEND;
    else if (info[i] == '-') ret[1] = NVM;
    
    // c. set exp
    while (info[i] != ' ') i++;
    i++;
    while (info[i] != ' ') i++;
    i++;
    if (info[i] == 'j') ret[2] = JUNIOR;
    else if (info[i] == 's') ret[2] = SENIOR;
    else if (info[i] == '-') ret[2] = NVM;
    
    // d. set soul food
    while (info[i] != ' ') i++;
    i++;
    while (info[i] != ' ') i++;
    i++;
    if (info[i] == 'c') ret[3] = CHICKEN;
    else if (info[i] == 'p') ret[3] = PIZZA;
    else if (info[i] == '-') ret[3] = NVM;
    
    // e. set score
    while (info[i] != ' ') i++;
    i++;
    ret[4] = atoi(info.c_str() + i);
    
    // f. return
    return (ret);
}

int	bns(int s, int e, int cmp, const vector<int> & v) {
    int	m = (s + e) / 2;
    
    if (s > e)
        return (v.size() - e - 1);
    
    if (v[m] < cmp)
        return(bns(m + 1, e, cmp, v));
    else
        return(bns(s, m - 1, cmp, v));
}

int	find_range(const vector<int> & q, int depth, int lang, int dev, int exp, int food,
              const vector<vector<vector<vector<vector<int>>>>>	& v) {
    int	total = 0;
    
    if (depth == 0) {
        if (q[depth] == NVM) {
            for (int i = 0; i < 3; i++)
                total += find_range(q, depth + 1, i, dev, exp, food, v);
            return (total);
        }
        else
            return (find_range(q, depth + 1, q[depth], dev, exp, food, v));
    }
    else if (depth == 1) {
		if (q[depth] == NVM) {
            for (int i = 0; i < 2; i++)
                total += find_range(q, depth + 1, lang, i, exp, food, v);
            return (total);
        }
        else
            return (find_range(q, depth + 1, lang, q[depth], exp, food, v));
    }
    else if (depth == 2) {
        if (q[depth] == NVM) {
            for (int i = 0; i < 2; i++)
                total += find_range(q, depth + 1, lang, dev, i, food, v);
            return (total);
        }
        else
            return (find_range(q, depth + 1, lang, dev, q[depth], food, v));
    }
    else { // depth >= 3
		if (q[depth] == NVM) {
            for (int i = 0; i < 2; i++)
                total += bns(0, v[lang][dev][exp][i].size() - 1, q[4], v[lang][dev][exp][i]);
            return (total);
        }
        else
            return (bns(0, v[lang][dev][exp][q[depth]].size() - 1, q[4], v[lang][dev][exp][q[depth]]));
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<vector<vector<vector<int>>>>>	v;
    vector<int>	v_q;
    vector<int>	v_size = {3, 2, 2, 2};
    
    // 0. Init
    	// a. resize v
    v.resize(v_size[0]);
    for (int i = 0; i < 3; i++) {
        v[i].resize(v_size[1]);
        for (int j = 0; j < 2; j++) {
            v[i][j].resize(v_size[2]);
            for (int r = 0; r < 2; r++) {
                v[i][j][r].resize(v_size[3]);
            }
        }
    }
    	// b. set info to v
    for (int i = 0; i < info.size(); i++)
        sep_info(info[i], v);
    
    	// c. sort
     for (int i = 0; i < v_size[0]; i++) {
        for (int j = 0; j < v_size[1]; j++) {
            for (int r = 0; r < v_size[2]; r++) {
                for (int k = 0; k < v_size[3]; k++) {
                    sort(v[i][j][r][k].begin(), v[i][j][r][k].end(), less<int>());
                }
            }
        }
    }   
    
    // 1. Calculate
    for (int cur_query = 0; cur_query < query.size(); cur_query++) {
        v_q = sep_query(query[cur_query]);
        
        // consider NVM Codintion when 
        // 재귀를 타고 들어가면서 leaf node를 만났을 때 bns를 하도록 처리
        answer.push_back(find_range(v_q, 0, -1, -1, -1, -1, v));
    }
    
    // 2. Return Answer
    return answer;
}