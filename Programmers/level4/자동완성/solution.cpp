#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
1. 전체 단어를 트리로 만든다.
	a. 끝까지 만든다.
2. 각 단어를 타고 끝까지 내려간다.
	a. 자식이 1개 이상이다 하나가 되는 순간을 기록한다.
*/

struct Node {
    char c;
    unordered_map<char, Node*>	child;
};

int solution(vector<string> words) {
    int answer = 0;
    Node*	head;
    Node*	tmp, *node;
    string	word;
    
    // 0. Init
    head = new Node();
    for (char c = 'a'; c <= 'z'; c++) {
        tmp = new Node();
        tmp->c = c;
        head->child[c] = tmp;
    }
    for (int i_word = 0, i = 0; i_word < words.size(); i_word++, i = 0) {
        word = words[i_word];
        node = head->child[word[0]];
        for (i = 1; i < word.length(); i++) {
            if (node->child.count(word[i])) {
                node = node->child[word[i]];
            }
            else {
                tmp = new Node();
                tmp->c = word[i];
                node->child[word[i]] = tmp;
                node = node->child[word[i]];
            }
        }
        tmp = new Node();
        tmp->c = '\0';
        node->child[word[i]] = tmp;
    }
    
    // 1. Calculate
    int num_child, n_min;
    for (int i_word = 0, i = 0; i_word < words.size(); i_word++, i = 0) {
        word = words[i_word];
        node = head->child[word[i]];
        num_child = node->child.size();
        n_min = 1;
        for (i = 1; i < word.length(); i++) {
            node = node->child[word[i]];
            
            if (num_child != 1 && node->child.size() == 1) {
                num_child = node->child.size();
                n_min = i + 1;
            }
            else if (node->child.size() != 1)
                num_child = node->child.size();
        }
        
        if (node->child.size() > 1)
            n_min = i;
        answer += n_min;
    }
    
    return answer;
}