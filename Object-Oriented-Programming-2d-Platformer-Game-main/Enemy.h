#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>

#include"Player.h"

using namespace std;
class Bullet;
class Enemy :public Player //child class of Player, inherited publically
{
public:
    void init_skeleton(Enemy&, int, int, int, float, float); //initialising variables for skeletons 
    void init_necromancer(Enemy&, int, int, int, float, float);//initialising variables for mages
    void init_monster(Enemy&, int, int, int, float, float); //initialising variables for ogres
    void draw(Enemy&, ALLEGRO_BITMAP*, int, int); //draws the enemy sprites
};

class Attack :public Enemy //child class of Enemy, inherited publically
{
public:
    void init_bluefire(Attack&, int, int, int, float, float); //initialising variables for fiery mage attack
    void draw_attack(Attack&, ALLEGRO_BITMAP*, int, int); //draws the purple fire sprites
};
#endif
