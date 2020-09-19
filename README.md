# Test task for MYTONA
___
## Task
Программа решает очередность проезда машин на перекрестке:
+  Если есть помеха справа то машина должна пропустить машину
справа.
+  Если на перекрестке стоят машины со всех 4х сторон, то первой
проезжает машина, у которой минимальная координата по X.
+  Машины не должны наезжать друг на друга.
___
## Error correction
+   Исправлена синтаксическая ошибка в `sRect getFuturePos()` `case eDirection::up:` => `case eDirection::UP:`.
+   Исправление С2371 
```
bool needPassOtherCar(sCar* otherCar) { 
        bool result;
        switch (dir) {
        case eDirection::UP: { // С2371 исправлена добавлением фигурных скобок
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
```
+ Добавление виртуального наследования 
```
struct sGasEngine : virtual sCar { // добавление виртуального наследования
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

struct sElectroCar : virtual sCar { // добавление виртуального наследования
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

struct sHybrid : virtual sGasEngine, virtual sElectroCar { // добавление виртуального наследования
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
```
+ Добавление явного указания размера контейнера
```
static const int initialCarsCount = 10;
static std::vector<sCar*> asdasd(initialCarsCount); // добавление явного указания размера контейнера
```
+ Вынесение прототипов функций во избежании С3861
```
inline void spawnCarFromTop(); // вынесены прототипы функций во избежании С3861
inline void spawnCarFromRight();
inline void spawnCarFromBot();
inline void SpawnCarFromLeft();
```
+ Добавление еще одного `else` во избежании появления С4703
```
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
    else { // добавлен еще один else во избежании появления С4703
        car = new sGasEngine();
    }
    car->rect = sRect(SCREEN_WIDTH / 2, SCREEN_HEIGHT, 100, 100);
    car->speed = 1;
}
```
+ Добавление inline функций в Spawn во избежании ошибок линковки
+ Добавление функции `Start()` для вызова быстрого старта программы.
