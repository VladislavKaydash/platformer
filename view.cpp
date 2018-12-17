#include "view.h"

void Camera::getplayercoordinateforview(float x, float y) { //функция для считывания координат игрока
    float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края

    if (x < 320) tempX = 320;//убираем из вида левую сторону
    if (y < 240) tempY = 240;//верхнюю сторону
    if (y > 554) tempY = 554;//нижнюю сторону

    view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты.

}

void Camera::changeview(){


    if (Keyboard::isKeyPressed(Keyboard::U)) {
        view.zoom(1.0001f);
    }




    if (Keyboard::isKeyPressed(Keyboard::I)) {
        view.setSize(640, 480);
    }



}
