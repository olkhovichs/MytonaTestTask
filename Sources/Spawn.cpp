#include "..//Headers/Spawn.h"

inline void spawnCar() { 
    if (rand() % 4 == 1)
        spawnCarFromRight();
    else if (rand() % 4 == 2)
        spawnCarFromTop();
    else if (rand() % 4 == 3)
        spawnCarFromBot();
    else if (rand() % 4 == 4)
        SpawnCarFromLeft();
}

inline void spawnCarFromTop() {
    sCar* car;
    int carType = rand();
    if (carType % 3 == 0) {
        car = new sGasEngine();
    }
    else if (carType % 3 == 1) {
        car = new sElectroCar();
    }
    else if (carType % 3 == 2) {
        car = new sHybrid();
    }
    else {
        car = new sGasEngine();
    } 
    car->rect = sRect(SCREEN_WIDTH / 2, 0, 100, 100);
    car->speed = 1;
    car->dir = eDirection::DOWN;
}

inline void spawnCarFromBot() {
    sCar* car;
    int carType = rand();
    if (carType % 3 == 0) {
        car = new sGasEngine();
    }
    else if (carType % 3 == 1) {
        car = new sElectroCar();
    }
    else if (carType % 3 == 2) {
        car = new sHybrid();
    }
    else { // добавлен еще один else во избежании по€влени€ —4703
        car = new sGasEngine();
    }
    car->rect = sRect(SCREEN_WIDTH / 2, SCREEN_HEIGHT, 100, 100);
    car->speed = 1;
}

inline void SpawnCarFromLeft() {
    sCar* car;
    int carType = rand();
    if (carType % 3 == 0) {
        car = new sGasEngine();
    }
    else if (carType % 3 == 1) {
        car = new sElectroCar();
    }
    else if (carType % 3 == 2) {
        car = new sHybrid();
    }
    else {
        car = new sGasEngine();
    }
    car->rect = sRect(0, SCREEN_HEIGHT / 2, 100, 100);
    car->speed = 1;
}
inline void spawnCarFromRight() {
    sCar* car;
    int carType = rand();
    if (carType % 3 == 0) {
        car = new sGasEngine();
    }
    else if (carType % 3 == 1) {
        car = new sElectroCar();
    }
    else if (carType % 3 == 2) {
        car = new sHybrid();
    }
    else {
        car = new sGasEngine();
    }
    car->rect = sRect(0, SCREEN_HEIGHT / 2, 100, 100);
    car->speed = 1;
}

