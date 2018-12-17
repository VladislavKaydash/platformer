#ifndef MAINER_H
#define MAINER_H

#include "player.h"
#include "enemy.h"
//#include "map.h"
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include "view.h"
#include <string>
#include <sstream>
#include <fstream>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QFile>
#include <QStandardItem>
#include <QFileDialog>
#include <QMessageBox>


using namespace std;
using namespace sf;


class Mainer:Enemy,Player,Camera{

private:
    Image map_image,icon;
    Texture map;
    Sprite s_map;
    Clock clock;
    float time;
    float currents=0;
    bool isMenu = true;
    bool    aboutMenu=false;
     Font font1;
     Music fon,found;
     sf::RenderWindow win;
     bool FullScreen,FrameLimit,VerticalSync;

     QJsonDocument doc;
     QJsonArray docAr;
     QJsonParseError docError;
     QFile file;

public:

    Mainer(float X, float Y,int W,int H):Enemy(X,Y,W,H){
        icon.loadFromFile("E:/WithQt/image/small.png");
        FullScreen=false;FrameLimit=false;VerticalSync=false;
    }
    ~Mainer(){

    }
void Mfunc();
void perec(Enemy &en);
void resmaper();
void TotalRecord();
void GetSetting();
};


void Mainer::Mfunc(){

    GetSetting();
if(FullScreen){
    win.create(sf::VideoMode::getDesktopMode(),"Platformer",sf::Style::Fullscreen);}
if(!FullScreen){
    win.create(sf::VideoMode(1000,750),"Platformer");}
    view.reset(sf::FloatRect(0, 0, 640, 480));
    win.setMouseCursorVisible(false);


    if(FrameLimit){win.setFramerateLimit(0);}
    if(VerticalSync){win.setVerticalSyncEnabled(true);}
    win.setIcon(32,24,icon.getPixelsPtr());
    resmaper();

    found.openFromFile("E:/WithQt/Sound.ogg");
    found.play();
    found.setLoop(true);
    found.setVolume(200);


    font1.loadFromFile("E:/WithQt/Shrift/fairy_tale.ttf");
    Text text1("", font1, 100);
    text1.setColor(Color::Red);
    text1.setStyle(sf::Text::Bold);


    Text text2("", font1, 100);
    text2.setColor(Color::Green);
    text2.setStyle(sf::Text::Bold);


     Text text("", font1, 30);
     text.setColor(Color::Blue);
     text.setStyle(sf::Text::Bold);


   Enemy en(900,688,80.0,80.0);
   Enemy en1(96,688,80.0,80.0);
   Enemy en2(1600,688,80.0,80.0);
   Enemy en3(2000,688,80.0,80.0);
   Enemy en4(3000,688,80.0,80.0);
   Enemy en5(3500,688,80.0,80.0);
   Enemy en6(900,400,80.0,80.0);
   Enemy en7(2200,495,80.0,80.0);
   Enemy en8(3000,365,80.0,80.0);


    map_image.loadFromFile("E:/WithQt/image/1.jpg");
    map.loadFromImage(map_image);
    s_map.setTexture(map);


    while (win.isOpen()){
        time = clock.getElapsedTime().asMicroseconds();
        if (life){ gameTime=gameTimeClock.getElapsedTime().asSeconds();}

        clock.restart();
        time=time/900;

        Event event;
        while(win.pollEvent(event)){
            if(event.type==Event::Closed){
                win.close();
            }
            if(event.type==Event::KeyPressed){
                if(event.key.code==Keyboard::Escape){
                     win.close();

                }
            }
            if(event.type==Event::KeyPressed){
                if ((event.key.code ==Keyboard::Right)||(event.key.code ==Keyboard::Left)){
                    sound.play();
                    sound.setLoop(true);
                    sound.setVolume(300);
                }
            }
            if(event.type==Event::KeyReleased){
                if ((event.key.code ==Keyboard::Right)||(event.key.code ==Keyboard::Left)){
                sound.pause();}

            }
        }
        float coordinatePlayerX, coordinatePlayerY = 0;
                    coordinatePlayerX = getplayercoordinateX();
                    coordinatePlayerY = getplayercoordinateY();

        if (life) {
         getplayercoordinateforview(coordinatePlayerX, coordinatePlayerY);
        }

       en.updater(time);
       en1.updater(time);
       en2.updater(time);
       en3.updater(time);
       en4.updater(time);
       en5.updater(time);
       en6.updater(time);
       en7.updater(time);
       en8.updater(time);

        update(time);

        changeview();
        win.setView(view);
        win.clear(Color(80,40,30));

        perec(en);
        perec(en1);
        perec(en2);
        perec(en3);
        perec(en4);
        perec(en5);
        perec(en6);
        perec(en7);
        perec(en8);


        for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(322,0, 32, 32));
            if (TileMap[i][j] == 's')  {s_map.setTextureRect(IntRect(322, 35, 32, 32));}
            if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(132, 291, 32, 32));
            if ((TileMap[i][j] == 'g')) s_map.setTextureRect(IntRect(150, 241, 32, 32));
            if ((TileMap[i][j] == 'h')) s_map.setTextureRect(IntRect(95, 0, 32, 32));
            if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(424, 0, 32, 32));

            s_map.setPosition(j * 32, i * 32);

            win.draw(s_map);
}
        win.draw(shero);
        win.draw(en.sprite);
        win.draw(en1.sprite);
        win.draw(en2.sprite);
        win.draw(en3.sprite);
        win.draw(en4.sprite);
        win.draw(en5.sprite);
        win.draw(en6.sprite);
        win.draw(en7.sprite);
        win.draw(en8.sprite);

        std::ostringstream playerScoreString;
        playerScoreString << playerScore;

        std::ostringstream gameTimeString;
        gameTimeString << gameTime;

        std::ostringstream playerHealthString;
        playerHealthString << health;
        text.setString("Your points: " + playerScoreString.str()+"   Health: " + playerHealthString.str()+"\n            Time: "+gameTimeString.str());
        text.setPosition(view.getCenter().x - 235, view.getCenter().y - 220);

                     if(!life)
                     {
                         if(health==0)
                        { text1.setString("Game over");
                         text1.setPosition(view.getCenter().x - 270, view.getCenter().y - 50);
                     win.draw(text1);


                         }
                         else
                         {
                             text2.setString("You win");
                             text2.setPosition(view.getCenter().x - 270, view.getCenter().y - 50);
                     win.draw(text2);

                      }

                     }

                     win.draw(text);
                       win.display();
    }

TotalRecord();




   }


void Mainer::perec(Enemy &en)
{
    if ( shero.getGlobalBounds().intersects( en.sprite.getGlobalBounds() ) )
    {
        if (state ==down){
           en.slife=false;
        }
        else if (en.slife ==true){health=0;}
    }
}


void Mainer::resmaper(){
 for (int i = 0; i < HEIGHT_MAP; i++)
 for (int j = 0; j < WIDTH_MAP; j++)
 {
     if (TileMap[i][j] == '1')  {TileMap[i][j] = 's';}
     if (TileMap[i][j] == '2')  {TileMap[i][j] = 'g';}
     if ((TileMap[i][j] == '3')) {TileMap[i][j] = 'h';}
     if ((TileMap[i][j] == '4')) {TileMap[i][j] = 'f';}

}
}
void Mainer::TotalRecord(){
 file.setFileName("E://WithQt//JsonBasaData.json");

 try
 {
     if(!file.open(QIODevice::ReadOnly|QFile::Text)){
         throw 1;
     }

 }
 catch(int i)
 {
     cout<<"Error #"<<i<<" - base don't open"<<endl;
 }


 file.open(QIODevice::ReadOnly|QFile::Text);

     doc = QJsonDocument::fromJson(QByteArray(file.readAll()),&docError);
     file.close();




 file.open(QIODevice::WriteOnly|QFile::Text);

     QVariantMap map;
    // map.insert("name",ui->lineEdit->text());
     map.insert("Score",playerScore);
     map.insert("Health",health);
     map.insert("Time",gameTime);

     QJsonObject json = QJsonObject::fromVariantMap(map);

     QJsonArray docToWrite = doc.object().value("Platformer").toArray();
     docToWrite.append(json);
     doc.setArray(docToWrite);

     file.write("{\"Platformer\":"+doc.toJson()+"}");
     file.close();

   }

void Mainer::GetSetting(){
 ifstream readSetting("E:/WithQt/Setting.txt");
 string s1,s2,s3,s4,s5;


 if(!readSetting.is_open()){
     cout<<"Error! Base non open!11"<<endl;
 }
getline(readSetting, s1);
getline(readSetting, s2);
getline(readSetting, s3);
getline(readSetting, s4);
getline(readSetting, s5);
 readSetting.close();

 if(s1=="1"){
     FullScreen =true;
 }
 else if(s1=="0"){
     FullScreen =false;
 }
 if(s2=="1"){
     FrameLimit =true;
 }
 else if(s2=="0"){
     FrameLimit =false;
 }
 if(s3=="1"){
     VerticalSync =true;
 }
 else if(s3=="0"){
     VerticalSync =false;

}
}


#endif // MAINER_H
