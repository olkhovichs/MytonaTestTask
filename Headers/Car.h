#pragma once

#include <cstdlib>
#include <vector>
#include <iostream>

#include "Geometric.h"

struct sCar {
    sRect rect;
    eDirection dir;
    int speed;
    void move() {
        switch (dir) {
        case eDirection::UP:
        rect.pos.y += speed; case eDirection::DOWN: rect.pos.y -= speed;
        case eDirection::RIGHT: rect.pos.x += speed; case eDirection::LEFT:
            rect.pos.x -= speed;
        }
    }
    sRect getFuturePos() {
        switch (dir) {
        case eDirection::UP: // синтаксическа€ ошибка 
            return sRect(rect.pos.x, rect.pos.y + speed, rect.size.width, rect.size.height);
        case eDirection::DOWN:
            return sRect(rect.pos.x, rect.pos.y - speed, rect.size.width, rect.size.height);
        case eDirection::RIGHT:
            return sRect(rect.pos.x + speed, rect.pos.y, rect.size.width, rect.size.width);
        case eDirection::LEFT:
            return sRect(rect.pos.x - speed, rect.pos.y, rect.size.width, rect.size.height); // 
        }
    }

    bool needPassOtherCar(sCar* otherCar) { 
        bool result;
        switch (dir) {
        case eDirection::UP: { // —2371 исправлена добавлением фигурных скобок
            auto otherdir = otherCar->dir;
            if (otherdir == eDirection::LEFT)
                result = true;
            break;
        }
        case eDirection::DOWN: {
            auto otherdir = otherCar->dir;
            if (otherdir == eDirection::RIGHT)
                result = true;
            break;
        }

        case eDirection::RIGHT: {
            auto otherdir = otherCar->dir;
            if (otherdir == eDirection::UP)
                result = true;
            break;
        }
        case eDirection::LEFT: {
            auto otherdir = otherCar->dir;
            if (otherdir == eDirection::LEFT)
                result = false;
            else
                result = false;
            break;
        }
        default:
            std::cerr << "Error" << std::endl; // добавление вывода ошибки
        }
        return result;
    }
    virtual int getFuel() = 0;
    virtual void refill(int count) = 0;
};

struct sGasEngine : virtual sCar { // добавление виртуального наследовани€
    int getFuel() {
        return fuel;
    }
    void refill(int count) {
        fuel += count;
    } void move() {
        fuel--; sCar::move();
    }
    int fuel;
};

struct sElectroCar : virtual sCar { // добавление виртуального наследовани€
    int getFuel() {
        return charge;
    }
    void refill(int count) {
        charge += count;
    }
    void move() {
        charge--;
        sCar::move();
    }
    int charge;
};

struct sHybrid : virtual sGasEngine, virtual sElectroCar { // добавление виртуального наследовани€
    void refill(int count) {
        charge += count / 2; fuel += count / 2;
    }
    int getFuel() {
        return charge + fuel;
    }
    void move() {
        if (rand() % 2 == 0)
            charge--;
        else
            fuel--;
        sCar::move();
    }
};

static const int initialCarsCount = 10;
static std::vector<sCar*> asdasd(initialCarsCount); // добавление €вного указани€ размера контейнера
