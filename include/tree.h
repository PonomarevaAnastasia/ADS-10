#include <vector>
#include <iostream>
class Tree {
 private:
    std::vector<Tree*> root;
    char sum;
    explicit Tree(char ch) : sum(ch) {}
    void createNode(const std::vector<char>& vec) {
        for (int i = 0; i < vec.size(); i++) {
            std::vector<char> work = vec;
            root.push_back(new Tree(work[i]));
            work.erase(work.begin() + i);
            root[i]->createNode(work);
        }
    }
 public:
    explicit Tree(const std::vector<char>& vec) {
        sum = '*';
        createNode(vec);
    }
    
    int getSize() const {
        return root.size();
    }
    char getSymb() const {
        return sum;
    }
    Tree& operator[](int n) const {
        return *root[n];
    }
};
#endif  // INCLUDE_TREE_H_
