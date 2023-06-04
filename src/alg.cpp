// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int Obj(int n) {
    if (n <= 1) return 1;
    return Obj(n - 1) * n;
}

std::vector<char> getPerm(const Tree& tree, int n) {
    if (tree.getSize() == 0 || n > Obj(tree.getSize()))
        return {};

    if (tree.getSymb() == '*')
        n--;

    std::vector<char> result;
    int work = Obj(tree.getSize() - 1);

    result.push_back(tree[n / work].getSymb());
    std::vector<char> a = getPerm(tree[n / work], n % work);
    result.insert(result.end(), a.begin(), a.end());

    return result;
}
