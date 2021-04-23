#include <iostream>
#include <memory>
#include <vector>

class TreeNode {
private:
    int value;
    TreeNode* root = nullptr;
    std::vector<TreeNode*> children;

public:
    TreeNode(int val): value(val) {
    }

    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;

    TreeNode* AddChild(int child_value) {
        auto node = new TreeNode(child_value);
        try {
            node->root = this;
        } catch (...) {
            delete this;
            delete root;
            for (auto ptr : children)
                delete ptr;
            delete node;
        }
        try {
            children.push_back(node);
        } catch (...) {
            delete this;
            delete root;
            for (auto ptr : children)
                delete ptr;
            delete node;
        }
        return node;
    }

    void Print(int depth = 0) const {
        for (int i = 0; i < depth; ++i)
            std::cout << " ";
        std::cout << "- " << value << "\n";
        for (const auto& child : children)
            child->Print(depth + 1);
    }
};

int main() {
    TreeNode root(1);

    auto left_son = root.AddChild(10);
    auto middle_son = root.AddChild(20);
    auto right_son = root.AddChild(30);

    left_son->AddChild(100);
    left_son->AddChild(200);

    root.Print();
}
