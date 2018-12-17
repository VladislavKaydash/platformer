#ifndef VIEW_H
#define VIEW_H


#include <SFML/Graphics.hpp>
using namespace sf;

class Camera{
private:
View view;
public:


void getplayercoordinateforview(float x, float y);
void changeview();

friend class Mainer;
};

#endif
