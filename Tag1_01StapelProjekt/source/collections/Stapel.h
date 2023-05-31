//
// Created by JoachimWagner on 31.05.2023.
//

#pragma once
#include "StapelException.h"
#include "../../source/collections/Stapel.h"
namespace collections {

    class Stapel {

        int data[10];
        size_t index{0};

    public:
        Stapel() = default;
        void push(int value);
        int pop();
        bool is_empty() const;
        bool is_full() const ;

    };

} // collections
