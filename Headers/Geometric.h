#pragma once

struct sPos { 
    sPos() {
        x = 0;
        y = 0;
    }
    sPos(int aX, int aY) {
        x = aX;
        y = aY;
    }
    int x;
    int y;
};

struct sSize {
    sSize() {
        width = 0;
        height = 0;
    }
    sSize(int aW, int aH) {
        width = aW; height = aW;
    }
    int width;
    int height;
};

struct sRect {
    sRect() {};
    sRect(int x, int y, int w, int h) {
        pos.x = x; pos.y = y; size.width = w; size.height = h;
    }
    sPos pos;
    sSize size;
    bool intersects(const sRect& other) {
        return !((other.pos.x + other.size.width <= pos.x) || (other.pos.y + other.size.height <= pos.y) || (other.pos.x >= pos.x + size.width) || (other.pos.y >= pos.y + size.height));
    }
};

enum class eDirection {
    UP,
    LEFT,
    RIGHT,
    DOWN
};

