//
// Created by danila on 22.09.2021.
//

#include "include/Dialog.h"
#include <iostream>
#include "include/Errors.h"
#include "include/Strophoid.h"

namespace lab2 {
    const char* MSGS[] = { "0. Quit", "1. Set point", "2. Find value with x coordinate",
                           "3. Find distant with angle","4. Find radius", "5. Find square of the loop",
                           "6. Find volume", "7. Find square under the branches"};

    const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

    int D_SetTop(Strophoid& line){
        const char* pr = "";
        double top;
        do{
            std::cout << pr << std::endl;
            std::cout << "Enter coordinate of the top: --> " << std::endl;
            if (getNum(top) < 0) {
                pr = "You are wrong; repeat please!";
                return FAIL;
            }
            std::cout << std::endl;
        } while(top < 0);

        Point p;
        p.x = top;
        p.y = 0;

        line.setPoint(p);
        return SUCCESS;
    }

    int D_value(const Strophoid& line){
        const char* pr = "";
        double x;
        std::cout << pr << std::endl;
        std::cout << "Enter coordinate x: --> ";
        if (getNum(x) < 0) { // Use algorithm to compare doubles!!
            std::cout << "You are wrong; repeat please!";
            return FAIL;
        }
        std::cout << std::endl;

        if (std::abs(x) > std::abs(line.getPoint().x)){
            std::cout << "You are out of scope!" << std::endl;
            return SUCCESS;
        }

        Point p;
        p = line.value(x);

        if (p.x == 0 || p.x == line.getPoint().x){
            std::cout << "Coordinate is: (" << p.x << ";" << p.y << ")" << std::endl;
        }
        else{
            std::cout << "1st coordinate is: (" << p.x << ";" << std::abs(p.y) << ")" << std::endl;
            std::cout << "2nd coordinate is: (" << p.x << ";" << "-" << p.y << ")" << std::endl;
        }
        return SUCCESS;
    }

    int D_distant(const Strophoid& line){
        const char* pr = "";
        double angle;

        std::cout << pr << std::endl;
        std::cout << "Enter angle: --> ";
        do{
            if (getNum(angle) < 0) {
                std::cout << "You are wrong; repeat please!";
                return FAIL;
            }
            std::cout << std::endl;
        }while (angle <= 0 && angle >= 360);

        if (angle == 90 || angle == 270){
            std::cout << "This angle is the asymptote" << std::endl;
            return SUCCESS;
        }

        double dist;
        dist = line.distant(angle);
        std::cout << "The distance to the center for a given angle is: " << dist << std::endl;
        return SUCCESS;
    }

    int D_radius(const Strophoid& line){
        double radius = line.radius();
        std::cout << "Radius of curvature is equal to: " << radius << std::endl;
        return SUCCESS;
    }

    int D_squareLoop(const Strophoid& line){
        double square = line.squareLoop();
        std::cout << "Square of the loop is equal to: " << square << std::endl;
        return SUCCESS;
    }

    int D_volume(const Strophoid& line){
        double volume = line.volume();
        std::cout << "Volume is equal to: " << volume << std::endl;
        return SUCCESS;
    }

    int D_squareBranches(const Strophoid& line){
        double square = line.squareBranches();
        std::cout << "The square under the branches is equal to: " << square << std::endl;
        return SUCCESS;
    }

    int Choice(const char* msgs[], int n, int& choice) {
        const char* pr = "";
        do {
            std::cout << "Make your choice: ";
            std::cout << pr << std::endl;
            for (int i = 0; i < n; ++i) {
                std::cout << msgs[i] << std::endl;
            }
            if (getNum(choice) < 0) {
                std::cout << "You are wrong; repeat please!";
                return FAIL;
            }

        } while ((choice < 0) || (choice > n - 1));
        return SUCCESS;
    }

    void Dialog() {
        int choice;
        Strophoid line{};
        do {
            if (Choice(MSGS, MSGS_SIZE, choice) == FAIL){ return; }
            switch (choice) {
                case 0:
                    break;

                case 1:
                    D_SetTop(line);
                    break;

                case 2:
                    D_value(line);
                    break;

                case 3:
                    D_distant(line);
                    break;

                case 4:
                    D_radius(line);
                    break;

                case 5:
                    D_squareLoop(line);
                    break;

                case 6:
                    D_volume(line);
                    break;

                case 7:
                    D_squareBranches(line);
                    break;
            };
        } while (choice != 0);
    }
}
