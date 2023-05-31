//
// Created by JoachimWagner on 31.05.2023.
//

#ifndef BLANKCMAKEPROJECT_STAPEL_H
#define BLANKCMAKEPROJECT_STAPEL_H
class Stapel {

    bool empty{true};
public:
    bool is_empty() {
        return empty;
    }

    void push(int value) {
        empty = false;
    }
};

#endif //BLANKCMAKEPROJECT_STAPEL_H
