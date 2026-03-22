#include <iostream>
#include <vector>

long long  dfs(int cur_node, int cur_depth, int parent_node, std::vector<std::vector<int> > & tree) {
    long long ret = 0;

    // leaf node 일 경우 현재 depth 반환
    if (cur_node != 1 && tree[cur_node].size() == 1) {
        return (cur_depth);
    }

    // leaf node가 아닐 경우 자식 node로 재귀
    for (int i = 0; i < tree[cur_node].size() ; i++) {
        if (tree[cur_node][i] != parent_node) {
            ret += dfs(tree[cur_node][i], cur_depth + 1, cur_node, tree);
        }
    }

    return (ret);
}

int main(void) {
    int N;
    std::vector<std::vector<int> > tree;
    long long result; 

    // 0. Init
    std::cin >> N;
    tree.resize(N + 1);
    for (int i = 0, node1, node2; i < N - 1; i++) {
        std::cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
    result = 0;

    // 1. Calculate
    result = dfs(1, 0, 0, tree);

    // 2. Print result
    if (result % 2 == 0)
        std::cout << "No\n";
    else
        std::cout << "Yes\n";

    return (0);
}