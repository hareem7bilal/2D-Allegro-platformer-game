#ifndef ARENA_H
#define ARENA_H

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

class Arena :public Player //child class of Player, inherited publically
{
private:
    //data members
    int window_width = 800; //determines the screen width
    int window_height = 700; //determines the screen height
    int background3_width = 1024; //width of the background bitmap for level 3
    int background3_height = 574; //height of the background bitmap for level 3
    int background1_width = 626; //width of the background bitmap for level 1
    int background1_height = 417; //height of the background bitmap for level 1
    int background2_width = 1280; //width of the background bitmap for level 2
    int background2_height = 760; //height of the background bitmap for level 2
    float spikes_width = 229.2; //width of one frame in spikes spritesheet
    float spikes_height = 620;  //height of one frame in spikes spritesheet
    //width and height of frames of the jungle spritesheets used in level 1
    float jungle1_width = 114.6;
    float jungle1_height = 116;
    float jungle2_width = 122.4;
    float jungle2_height = 263;
public:
    //colours of sprites, initialised to transparent
    float r = 255;
    float g = 255;
    float b = 255;
public:
    //functions for drawing the levels
    void level1(ALLEGRO_BITMAP*, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*, Arena&);
    void level2(ALLEGRO_BITMAP*, Arena&);
    void level3(ALLEGRO_BITMAP*, ALLEGRO_BITMAP*, Arena&);

    void init_purplemist(Arena&, int, int, int, float, float);//initialising variables for the purple mist in level 2
    void draw_purplemist(Arena&, ALLEGRO_BITMAP*, int, int); //drawing the mist sprite
    void init_skull(Arena&, int, int, int, float, float);//initialising variables for the skulls in level 3
    void draw_skull(Arena&, ALLEGRO_BITMAP*, int, int);//drawing the skulls
};

class Points :public Player //child class of Player, inherited publically
{
private:
    //frame width and height for the blue gem in level 2
    float bluegem_width;
    float bluegem_height;
    //frame width and height for the green gem in level 2
    float greengem_width;
    float greengem_height;
    //frame width and height for the yellow gem in level 2
    float yellowgem_width;
    float yellowgem_height;
    //frame width and height for the red gem in level 2
    float redgem_width;
    float redgem_height;
    //frame width and height for the pink gem in level 2
    float pinkgem_width;
    float pinkgem_height;
    //frame width and height for the coins in level 3
    float coin_width;
    float coin_height;
    //frame width and height for the stars in level 1
    float star_width;
    float star_height;
public:
    //colours of points, initialised to transparent
    float r = 255;
    float g = 255;
    float b = 255;

    int frameCount = 0;
    float frameDelay = 12;
public:
    void init_pinkgem(Points&, int, int, int, float, float);//initialising variables for the pink gem
    void init_bluegem(Points&, int, int, int, float, float);//initialising variables for the blue gem
    void init_greengem(Points&, int, int, int, float, float);//initialising variables for the green gem
    void init_yellowgem(Points&, int, int, int, float, float);//initialising variables for the yellow gem
    void init_coins(Points&, int, int, int, float, float);//initialising variables for coins
    void init_redgem(Points&, int, int, int, float, float);//initialising variables for the red gem
    void init_stars(Points&, int, int, int, float, float);//initialising variables for stars
    //the following functions draw the points initialised above
    void draw_pinkgem(Points&, ALLEGRO_BITMAP*, int, int);
    void draw_bluegem(Points&, ALLEGRO_BITMAP*, int, int);
    void draw_greengem(Points&, ALLEGRO_BITMAP*, int, int);
    void draw_yellowgem(Points&, ALLEGRO_BITMAP*, int, int);
    void draw_redgem(Points&, ALLEGRO_BITMAP*, int, int);
    void draw_coins(Points&, ALLEGRO_BITMAP*, int, int);
    void draw_stars(Points&, ALLEGRO_BITMAP*, int, int);
};

#endif // !ARENA_H
