#ifndef ENTITY_H
#define ENTITY_H


#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;


class Entity {
public:
    float dx, dy, x, y, speed,moveTimer;
    int w,h,health;
    bool life, onGround;

    Texture texture;
    Sprite sprite;
    String name;
    Entity(Image &image, float X, float Y,int W,int H,String Name)
    {
        x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
        speed = 0; health = 100; dx = 0; dy = 0;
        life = true; onGround = false;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w / 2, h / 2);
    }
};


#endif
