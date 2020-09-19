#include "..//Headers/Start.h"

bool main_loop() {
    for (auto car : asdasd) {
        for (auto car22 : asdasd) {
            if (car->getFuturePos().intersects(car22->getFuturePos())) {
                if (car->needPassOtherCar(car22)) car->move();
            }
            else {
                car22->move();
            }
        }
        if (car->rect.pos.x <= 0 || car->rect.pos.x >= SCREEN_WIDTH || car->rect.pos.y <= 0 || car->rect.pos.y >= SCREEN_HEIGHT)
            spawnCar();
    }
    return main_loop();
}

void Start() {
    for (auto i = 0; i < initialCarsCount; ++i) {
        spawnCar();
    }
    main_loop();
}