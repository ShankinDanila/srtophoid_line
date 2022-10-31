//
// Created by danila on 22.09.2021.
//

#ifndef UNTITLED_DIALOG_H
#define UNTITLED_DIALOG_H

#include "iostream"
#include "Errors.h"
#include "Strophoid.h"

namespace lab2{
    template <typename T>
    int getNum(T &elem) {
        std::cin >> elem;
        if (!std::cin.good()) {
            return -1;
        }
        return 1;
    }

    int D_SetTop(Strophoid& line);
    int D_value(const Strophoid& line);
    int D_distant(const Strophoid& line);
    int D_radius(const Strophoid& line);
    int D_squareLoop(const Strophoid& line);
    int D_volume(const Strophoid& line);
    int D_squareBranches(const Strophoid& line);
    int Choice(const char* msgs[], int n);
    void Dialog();
}

#endif //UNTITLED_DIALOG_H
