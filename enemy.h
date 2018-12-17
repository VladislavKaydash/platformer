#ifndef ENEMY_H
#define ENEMY_H


//#include "player.h"
#include "map.h"
//#include "mainer.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;


class Enemy{
private:
  const int LINE =6;
  float currentFrame;
  float x,y,dxx,dy,Setright,Setleft;
  int w,h,shealth;
  bool slife,ground;
  Image image;
  Texture texture;
    enum stater {rey,ley};
    stater stay;
    Sprite sprite;
public:

    Enemy(float X, float Y,int W,int H){
        x = X; y = Y; w = W; h = H;
         shealth = 100; dy = 0;currentFrame = 0;Setright=0;Setleft=0;
        slife = true;
        image.loadFromFile("E:/WithQt/image/enem.png");
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w / 2, h / 2);
        sprite.setTextureRect(sf::IntRect(0, 160, w, h));
        dxx=0.1;
    }

    ~Enemy(){

    }
    void SettingAI();
    void checkCollisionWithMap(float Dx, float Dy);
    void updater(float time);

friend class Mainer;
};


void Enemy::SettingAI(){
    ifstream readSetting("E:/WithQt/Setting.txt");
    string s;

    if(!readSetting.is_open()){
        cout<<"Error! Setting non open!30"<<endl;
    }
    for (int i = 1; i <= LINE; i++){
           getline(readSetting, s);
}
    readSetting.close();
    if (s=="1"){
        Setright = 0.1;
        Setleft = - 0.1;
}
    else if(s=="2"){
        Setright = 0.5;
        Setleft = - 0.2;
    }
    else if (s=="3"){
        Setright = 0.85;
        Setleft = - 0.25;
    }
    else{
        Setright = 0.1;
        Setleft = - 0.1;
    }

}

void Enemy::checkCollisionWithMap(float Dx, float Dy)//ф ция проверки столкновений с картой
{
    SettingAI();
    for (int i = y / 32; i < (y + h) / 32; i++)
    for (int j = x / 32; j<(x + w) / 32; j++)
    {
        if (TileMap[i][j] == '0')
        {
            if (Dy>0){ y = i * 32 - h;}
            if (Dy<0){ y = i * 32 + 32; }
            if (Dx>0){ x = j * 32 - w; dxx = Setleft; sprite.scale(-1, 1);stay = ley; }
            if (Dx<0){ x = j * 32 + 32;dxx = Setright; sprite.scale(-1, 1);stay=rey; }
        }

    }
}

void Enemy::updater(float time)
{
        currentFrame += 0.007*time;
        if (currentFrame > 4) currentFrame -= 4;
          sprite.setTextureRect(IntRect(80 * int(currentFrame), 160,80,80));

        checkCollisionWithMap(dxx, 0);
        x += dxx*time;
        y += dy*time;
        checkCollisionWithMap(0, dy);
        sprite.setPosition(x + w / 2, y + h / 2);

        if (slife == false){ ;
        sprite.setColor(Color::Cyan);
        if(stay==ley){sprite.setRotation(110);}
        if(stay==rey){sprite.setRotation(-110);}
        sprite.setPosition(x + w / 2, (y + h / 2)+20);
        dxx=0;
        }


}

#endif
