#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
using namespace std;

class Enemy;
class Points;
class Bullet;
class Player //Parent class of Enemy class, Bullet class and Points class. Grandparent class of the Attack class
{
protected:
    int lives;
    int health;
    bool direction;
    bool boundlvl1 = true;
    bool boundlvl2 = true;
    bool boundlvl3 = true;
public:
    //x and y coordinates of the player
    int x;
    int y;
    //speed of the player
    int speed;
    //r,g,b values indicate the colour of the sprite
    int r;
    int g;
    int b;
    //scale variable determines how big the sprite will be
    float scale;
    float frameWidth; //width of one frame in the player spritesheet
    float frameHeight; //height of one frame in the player spritesheet
    float frameWidthlives; //width of heart spritesheet
    float frameHeightlives; //height of heart spritesheet
    float frameDelay; //determines how fast the frames change during animation
    int frameCount;
    int curFrame; //the frame which the sprite is currently at
    int maxFrame;
    int frame_y;
    int flag; //used when bitmaps are drawn
    float angle = 0; //angle of rotation of the sprite
public:
    void initPlayer(Player&);  //initialising variables for player
    void draw(Player&, ALLEGRO_BITMAP*, int, int);
    void setboundlvl1(Player&);  //setting bounds for level 1
    void setboundlvl2(Player&);  //setting bounds for level 2
    void setboundlvl3(Player&);  //setting bounds for level 3
   //getters for bounds of the the 3 levels
    bool getboundlvl1();
    bool getboundlvl2();
    bool getboundlvl3();

    void playerfall(Player&, ALLEGRO_SAMPLE* sound); //checks if player falls out of the screen

    friend void fire_collide(Enemy&, Player&, ALLEGRO_SAMPLE*); //checks if the purple fire in level 2 collides with the player
    friend void collide(Enemy&, Player&, ALLEGRO_SAMPLE*); //checks if the player collides with an enemy
    friend void collidept(Points&, Player&, ALLEGRO_SAMPLE*); //checks if the player collides with a point

    void setlives(int); //setter for player lives
    int getlives(); //getter for player lives
    void drawlives(Player&, ALLEGRO_BITMAP*); //draws heart bitmap on the output screen
    //getter and setter for players direction
    void set_direction(bool);
    bool get_direction();
};

#endif // !PLAYER_H