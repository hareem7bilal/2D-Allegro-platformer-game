#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include "Player.h"
#include "Enemy.h"


using namespace std;

//class for bullets shot by the Player
class Bullet :public Player //child class of Player, inherited publically
{
protected:
    bool live; //x, y and speed are inherited
public:
    float blast_width = 232.75;
    float blast_height = 175;
    float scale = 0.3;
    float frameDelay = 8;
    void init_bullet(Bullet[], int); //initialising variables for the player's bullet
    void draw_bullet_right(Bullet[], int, ALLEGRO_BITMAP*); //draws the bullet shot towards the right
    void draw_bullet_left(Bullet[], int, ALLEGRO_BITMAP*);  //draws the bullet shot towards the left
    void fire_bullet(Bullet[], int, Player&, ALLEGRO_SAMPLE*); //firing of bullet
    friend void collideBt(Enemy&, Bullet[], int, ALLEGRO_SAMPLE*); //checks collision of bullets with enemies
    void update_bullet(Bullet[], int, Player&); //updates the position of bullet
    bool get_live(); //getter for the bullets life

};
#endif //