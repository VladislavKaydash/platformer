#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "map.h"


using namespace sf;
using namespace std;

class Player{
private:
    float dx, dy, x, y, speed;
    int w,h,health;
    bool life, onGround;
    float current;
    Image heroImage;
    Texture heroTex;
    Sprite shero;
    SoundBuffer buf;
    Sound sound;
    Clock gameTimeClock;
    int gameTime;
    enum stateObject{ left,right,up,down,jump,stay };
    stateObject state;
    int playerScore;
public:


 friend class Mainer;


   Player(){
       speed = 0; health = 100; dx = 0; dy = 0;current=0;gameTime=0;
       w=47.0;
       h=62.5;
       x=60.0;
       y=400.0;
       life = true; onGround = false;
        state=stay;
        heroImage.loadFromFile("E:/WithQt/image/player.png");
        heroTex.loadFromImage(heroImage);
        shero.setTexture(heroTex);
        shero.setPosition(x+w / 2,y+h / 2);
        shero.setTextureRect(IntRect(0, 131,47,62.5));
       buf.loadFromFile("E:/WithQt/Music/4.wav");
       sound.setBuffer(buf);
       sound.setVolume(500);
        playerScore = 0;
   }

   ~Player(){

   }

   float getplayercoordinateX(){
           return x;
       }
   float getplayercoordinateY(){
           return y;
       }
    void control(float time);
   void update(float time);
   void checkCollisionWithMap(float Dx,float Dy);
};

void Player::control(float time){
    if(life){
    if (Keyboard::isKeyPressed(Keyboard::Left)) {

        state = left;
        speed = 0.1;
        current += 0.007*time;
        if (current > 4) current -= 4;
          shero.setTextureRect(IntRect(49.75 * int(current), 65.5,47,62.5));

    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {

        state = right;
        speed = 0.1;
        current += 0.007*time;
        if (current > 4) current -= 4;
          shero.setTextureRect(IntRect(49.75 * int(current), 131,43,62.5));

    }

    if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {

        state = jump; dy = -0.7; onGround = false;

    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {

        state = down;
        current += 0.007*time;
        if (current > 4) current -= 4;
          shero.setTextureRect(IntRect(49.75 * int(current), 0,47,62.5));

    }
    }
}


void Player::update(float time)
{

    control(time);
   switch (state)
      {
         case right: dx = speed;break;
         case left: dx = -speed;break;
         case up: break;
         case down: dx=0;break;
         case jump: break;
         case stay: break;
       }
   x += dx*time;
  checkCollisionWithMap(dx, 0);
   y += dy*time;
   checkCollisionWithMap(0, dy);
    speed = 0;
    shero.setPosition(x+w/2, (y+h/2)-28);
if(health>100){health=100;}
if (health <= 0){ life = false;
 shero.setColor(Color::Red);
 if(state==right){shero.setRotation(-110);shero.setPosition(x+w/2, (y+h/2)+50);}
 if(state==left){shero.setRotation(110);shero.setPosition(x+w/2, (y+h/2)+10);}
}
if(!onGround){dy = dy + 0.0015*time;}
}

void Player::checkCollisionWithMap(float Dx,float Dy)//ф ция проверки столкновений с картой
{

    for (int i = y / 32; i < (y + h) / 32; i++)
    for (int j = x / 32; j<(x + w) / 32; j++)
    {
        if (TileMap[i][j] == '0')
        {
            if (Dy>0){ y = i * 32 - h;  dy = 0; onGround = true; }
            if (Dy<0){y = i * 32 + 32;  dy = 0;}
            if (Dx>0){x = j * 32 - w;dx=0;}
            if (Dx<0){x = j * 32 + 32;dx=0;}
        } else {onGround=false;}

        if (TileMap[i][j] == 's')
        {
            playerScore +=1;
            TileMap[i][j] = '1';

        }

        if (TileMap[i][j] == 'g')
        {
            TileMap[i][j] = '2';
            health -=25;
        }
        if (TileMap[i][j] == 'h')
        {
             health +=25;

            TileMap[i][j] = '3';
        }

        if (TileMap[i][j] == 'f')
        {
             life=false;

            TileMap[i][j] = '4';
        }

        }

}

#endif
