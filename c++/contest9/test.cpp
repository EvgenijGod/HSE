#include <string>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

class Animal {
public:
    virtual std::string voice() const {
        return "Not implemented yet";
    }
    virtual ~Animal() {
    }
};


class Tiger: public Animal {
    std::string voice() const override {
        return "Rrrr";
    }
};


class Wolf: public Animal {
    std::string voice() const override {
        return "Wooo";
    }
};


class Fox: public Animal {
    std::string voice() const override {
        return "Tyaf";
    }
};

using Zoo = std::vector<std::unique_ptr<Animal>>;

Zoo CreateZoo() {
    Zoo zoo;
    std::string word;
    while (std::cin >> word) {
        if (word == "Tiger") {
            auto tiger_ptr = new Tiger;
            try {
                zoo.emplace_back(tiger_ptr);
            } catch (...) {
            //    delete tiger_ptr;
            }
        } else if (word == "Wolf") {
            auto wolf_ptr = new Wolf;
            try {
                zoo.emplace_back(wolf_ptr);
            } catch (...) {
            //    delete wolf_ptr;
            }
        } else if (word == "Fox") {
            auto fox_ptr = new Fox;
            try {
                zoo.emplace_back(fox_ptr);
            } catch (...) {
            //    delete fox_ptr;
            }
        } else {
            throw std::runtime_error("Unknown animal!");
        }
    }
    return zoo;
}

void Process(const Zoo &zoo) {
    for (const auto &animal : zoo) {
        std::cout << animal->voice() << "\n";
    }
}

int main() {}
