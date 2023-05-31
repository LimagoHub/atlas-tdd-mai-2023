//
// Created by JoachimWagner on 31.05.2023.
//

#include "Stapel.h"

namespace collections {
    bool Stapel::is_empty() const {
        return index == 0;
    }

    bool Stapel::is_full() const {
        return index == 10;
    }

    void Stapel::push(int value) {
        if(is_full()) throw StapelException("Overflow");
        data[index++] = value;
    }

    int Stapel::pop() {
        if(is_empty()) throw StapelException("Underflow");
        return data[--index];
    }
}