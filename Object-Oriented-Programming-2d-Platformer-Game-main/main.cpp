#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>

#include"Arena.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Player.h"

//Player collision functions
void collide(Enemy&, Player&);
void collidept(Points&, Player&, ALLEGRO_SAMPLE*);
//functions for changing the frames of enemies when player comes to their platform
void skel_attack(Enemy&);
void necro_attack(Enemy&);
void monster_attack1(Enemy&);
void monster_attack2(Enemy&);

bool keys[3] = { false, false, false };
bool done = false;
int points = 0, maxpoints = 5;

const int NUM_BULLETS = 10;

enum STATE { TITLE, ADV_SELECT, INSTRUCTIONS, ADV_1, ADV_2, ADV_3, LOST1, LOST2, LOST3, WIN }; //game states

//Player, Enemy, Arena, Bullet, Points and Attack class objects
Player Player1;
Arena level1, level2, level3, purplemist[9], skull[8];
Enemy Enemy1, Enemy2, Enemy3, Enemy4, Enemy5, Enemy6, Enemy7, Enemy8, Enemy9, Enemy10, Enemy11, Enemy12, Enemy13, Enemy14, Enemy15, Enemy16, Enemy17, Enemy18, Enemy19, Enemy20, Enemy21, Enemy22, Enemy23, Enemy24, Enemy25, Enemy26, Enemy27, Enemy28, Enemy29, Enemy30, Enemy31, Enemy32, Enemy33, Enemy34;
Bullet bullets[NUM_BULLETS];
Points point1, point2, point3, point4, point5, point16, point7, point8, point9, point10, point11, point12, point13, point14, point15;
Attack bluefire[3];

//changing game states
void ChangeState(int& state, int new_state, ALLEGRO_SAMPLE_INSTANCE* ins1, ALLEGRO_SAMPLE_INSTANCE* ins2, ALLEGRO_SAMPLE_INSTANCE* ins3);

int main()
{
    //initialising player
    Player1.initPlayer(Player1);
    //initialising position and frames of the enemies
    Enemy1.init_skeleton(Enemy1, 8, 0, 0, 395, 505);
    Enemy2.init_skeleton(Enemy2, 8, 0, 4, 550, 200);
    Enemy3.init_skeleton(Enemy3, 8, 0, 4, 150, 150);
    Enemy4.init_skeleton(Enemy4, 8, 0, 0, 350, 350);
    Enemy5.init_skeleton(Enemy5, 8, 0, 0, 250, 230);
    Enemy6.init_skeleton(Enemy6, 8, 0, 4, 700, 130);
    Enemy7.init_skeleton(Enemy7, 8, 0, 0, 80, 400);
    Enemy8.init_skeleton(Enemy8, 11, 8, 0, 485, 90);
    Enemy9.init_skeleton(Enemy9, 8, 0, 3, 750, 480);
    Enemy10.init_skeleton(Enemy10, 11, 8, 0, 770, 270);
    Enemy11.init_skeleton(Enemy11, 11, 8, 0, 45, 525);
    Enemy12.init_necromancer(Enemy12, 7, 0, 2, 60, 530);
    Enemy13.init_necromancer(Enemy13, 7, 0, 2, 80, 140);
    Enemy14.init_necromancer(Enemy14, 12, 8, 0, 720, 120);
    Enemy15.init_necromancer(Enemy15, 7, 0, 0, 100, 400);
    Enemy16.init_necromancer(Enemy16, 7, 0, 0, 310, 125);
    Enemy17.init_necromancer(Enemy17, 7, 0, 0, 570, 200);
    Enemy18.init_necromancer(Enemy18, 7, 0, 0, 745, 340);
    Enemy19.init_necromancer(Enemy19, 7, 0, 3, 320, 360);
    Enemy20.init_necromancer(Enemy20, 7, 0, 0, 520, 400);
    Enemy21.init_necromancer(Enemy21, 7, 0, 0, 435, 528);
    Enemy22.init_necromancer(Enemy22, 7, 0, 1, 730, 470);
    Enemy23.init_monster(Enemy23, 4, 0, 0, 200, 200);
    Enemy24.init_monster(Enemy24, 4, 0, 0, 70, 535);
    Enemy25.init_monster(Enemy25, 4, 0, 0, 730, 210);
    Enemy26.init_monster(Enemy26, 4, 0, 0, 470, 535);
    Enemy27.init_monster(Enemy27, 4, 0, 0, 60, 120);
    Enemy28.init_monster(Enemy28, 4, 0, 0, 550, 290);
    Enemy29.init_monster(Enemy29, 4, 0, 0, 450, 200);
    Enemy30.init_monster(Enemy30, 4, 0, 0, 540, 450);

    //initialising position and frames of points
    point1.init_pinkgem(point1, 3, 0, 0, 510, 90);
    point2.init_bluegem(point2, 6, 0, 0, 360, 230);
    point3.init_greengem(point3, 2, 0, 0, 150, 500);
    point4.init_redgem(point4, 2, 0, 0, 720, 300);
    point5.init_yellowgem(point5, 4, 0, 0, 400, 450);
    point16.init_coins(point16, 0, 0, 0, 100, 95);
    point7.init_coins(point7, 0, 0, 0, 400, 230);
    point8.init_coins(point8, 0, 0, 2, 120, 500);
    point9.init_coins(point9, 0, 0, 2, 720, 250);
    point10.init_coins(point10, 0, 0, 0, 400, 450);
    point11.init_stars(point11, 6, 0, 0, 200, 470);
    point12.init_stars(point12, 0, 0, 0, 550, 220);
    point13.init_stars(point13, 0, 0, 0, 430, 370);
    point14.init_stars(point14, 0, 0, 1, 700, 150);
    point15.init_stars(point15, 0, 0, 1, 150, 150);

    //initialising position and frames for the purple fire attack (the bluefire sprite was tinted purple)
    bluefire[0].init_bluefire(bluefire[0], 6, 0, 0, Enemy12.x + 60, Enemy12.y - 50);
    bluefire[1].init_bluefire(bluefire[1], 6, 0, 0, Enemy13.x + 60, Enemy13.y - 50);
    bluefire[2].init_bluefire(bluefire[2], 6, 0, 0, Enemy22.x - 10, Enemy22.y - 50);

    //initialising position and frames for the purple mist in level 2
    purplemist[0].init_purplemist(purplemist[0], 6, 0, 0, 0, 680);
    purplemist[1].init_purplemist(purplemist[1], 6, 0, 1, 100, 680);
    purplemist[2].init_purplemist(purplemist[2], 3, 0, 2, 200, 680);
    purplemist[3].init_purplemist(purplemist[3], 6, 0, 0, 300, 680);
    purplemist[4].init_purplemist(purplemist[4], 6, 0, 1, 400, 680);
    purplemist[5].init_purplemist(purplemist[5], 3, 0, 2, 500, 680);
    purplemist[6].init_purplemist(purplemist[6], 6, 0, 1, 600, 680);
    purplemist[7].init_purplemist(purplemist[7], 6, 0, 0, 700, 680);
    purplemist[8].init_purplemist(purplemist[8], 6, 0, 1, 800, 680);

    //initialising position and frames for the skulls in level 3
    skull[0].init_skull(skull[0], 5, 0, 0, 70, 660);
    skull[1].init_skull(skull[1], 5, 0, 1, 170, 660);
    skull[2].init_skull(skull[2], 5, 0, 0, 270, 660);
    skull[3].init_skull(skull[3], 5, 0, 1, 370, 660);
    skull[4].init_skull(skull[4], 5, 0, 0, 470, 660);
    skull[5].init_skull(skull[5], 5, 0, 1, 570, 660);
    skull[6].init_skull(skull[6], 5, 0, 0, 670, 660);
    skull[7].init_skull(skull[7], 5, 0, 1, 770, 660);

    bullets->init_bullet(bullets, NUM_BULLETS); //initalising bullets

    //initializing allegro addons
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_init_primitives_addon();
    al_init_acodec_addon();
    al_install_audio();

    //variables
    int x = 800, y = 700, posx = x / 2, posy = y / 2, FPS = 60;
    bool redraw = true;

    //initialising frames for the players bullet
    for (int i = 0; i < NUM_BULLETS; i++) {
        bullets[i].maxFrame = 3;
        bullets[i].curFrame = 0;
        bullets[i].frame_y = 0;
    }

    //initialising position and frames for the player
    Player1.maxFrame = 10;
    Player1.curFrame = 0;
    Player1.frame_y = 4;
    Player1.frameCount = 0;

    //for gravity
    const float gravity = 1;
    float vely = 0, velx = 0;
    float jumpspeed = 13;
    bool jump = false;
    bool boundleft = true, boundright = true, ground = true;//not letting character go out of screen

    //game state
    int state = -1;

    //allegro variables
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_DISPLAY* display = al_create_display(x, y); //creating window
    ALLEGRO_FONT* font = al_load_ttf_font("score_display_font.ttf", 32, 1); //declaring a font for displaying score on the game screen
    ALLEGRO_FONT* score_display = al_load_ttf_font("digital_dream.ttf", 60, NULL);//declaring a font for displaying score on the lose screen
    ALLEGRO_TIMER* timer = NULL; //declaring a timer

    //declaring bitmaps that have been used in the levels
    ALLEGRO_BITMAP* image;
    ALLEGRO_BITMAP* level3_background;
    ALLEGRO_BITMAP* level2_background;
    ALLEGRO_BITMAP* level1_background;
    ALLEGRO_BITMAP* jungle_3;
    ALLEGRO_BITMAP* jungle_1;
    ALLEGRO_BITMAP* jungle_2;
    ALLEGRO_BITMAP* jungle_4;
    ALLEGRO_BITMAP* skeleton1;
    ALLEGRO_BITMAP* necromancer1;
    ALLEGRO_BITMAP* monster_1;
    ALLEGRO_BITMAP* monster_2;
    ALLEGRO_BITMAP* spikes;
    ALLEGRO_BITMAP* heart;
    ALLEGRO_BITMAP* pink_gem;
    ALLEGRO_BITMAP* blue_gem;
    ALLEGRO_BITMAP* green_gem;
    ALLEGRO_BITMAP* yellow_gem;
    ALLEGRO_BITMAP* red_gem;
    ALLEGRO_BITMAP* blast_1;
    ALLEGRO_BITMAP* blast_2;
    ALLEGRO_BITMAP* coins;
    ALLEGRO_BITMAP* stars;
    ALLEGRO_BITMAP* blue_fire;
    ALLEGRO_BITMAP* purple_mist;
    ALLEGRO_BITMAP* _skull;

    ALLEGRO_KEYBOARD_STATE keystate;

    //declaring bitmaps for game states
    ALLEGRO_BITMAP* title = NULL;
    ALLEGRO_BITMAP* adv_select = NULL;
    ALLEGRO_BITMAP* win = NULL;
    ALLEGRO_BITMAP* lose1 = NULL;
    ALLEGRO_BITMAP* lose2 = NULL;
    ALLEGRO_BITMAP* lose3 = NULL;
    ALLEGRO_BITMAP* ins = NULL;

    //declaring allegro variables for sound
    ALLEGRO_SAMPLE* point_sound = NULL;
    ALLEGRO_SAMPLE* bomb = NULL;
    ALLEGRO_SAMPLE* music = NULL;
    ALLEGRO_SAMPLE* victory = NULL;
    ALLEGRO_SAMPLE* lost = NULL;
    ALLEGRO_SAMPLE* scream = NULL;
    ALLEGRO_SAMPLE* _jump = NULL;
    ALLEGRO_SAMPLE* buttons = NULL;
    ALLEGRO_SAMPLE* playerfall = NULL;
    ALLEGRO_SAMPLE_INSTANCE* music_instance = NULL;
    ALLEGRO_SAMPLE_INSTANCE* victory_instance = NULL;
    ALLEGRO_SAMPLE_INSTANCE* losing_instance = NULL;


    //loading bitmaps for levels
    image = al_load_bitmap("player.png");
    level3_background = al_load_bitmap("level3_background.jpg");
    level2_background = al_load_bitmap("level2_background.png");
    level1_background = al_load_bitmap("level1_background.jpg");
    skeleton1 = al_load_bitmap("skeleton.png");
    necromancer1 = al_load_bitmap("necro.png");
    monster_1 = al_load_bitmap("monster_1.png");
    monster_2 = al_load_bitmap("monster_2.png");
    spikes = al_load_bitmap("spikes.png");
    jungle_3 = al_load_bitmap("jungle_3.png");
    jungle_1 = al_load_bitmap("jungle_1.png");
    jungle_2 = al_load_bitmap("jungle_2.png");
    jungle_4 = al_load_bitmap("jungle_4.png");
    heart = al_load_bitmap("lives.png");
    pink_gem = al_load_bitmap("pink_gem.png");
    blue_gem = al_load_bitmap("blue_gem.png");
    green_gem = al_load_bitmap("green_gem.png");
    yellow_gem = al_load_bitmap("yellow_gem.png");
    red_gem = al_load_bitmap("red_gem.png");
    blast_1 = al_load_bitmap("blast_1.png");
    blast_2 = al_load_bitmap("blast_2.png");
    coins = al_load_bitmap("coins.png");
    stars = al_load_bitmap("stars.png");
    blue_fire = al_load_bitmap("bluefire.png");
    purple_mist = al_load_bitmap("purple_mist.png");
    _skull = al_load_bitmap("skull.png");

    //loading bitmaps for gamestates
    title = al_load_bitmap("title.png");
    adv_select = al_load_bitmap("adv_select.png");
    win = al_load_bitmap("win.jpg");
    lose1 = al_load_bitmap("lvl1_lose.png");
    lose2 = al_load_bitmap("lvl2_lose.png");
    lose3 = al_load_bitmap("lvl3_lose.png");
    ins = al_load_bitmap("ins.jpg");

    //loading sound samples
    point_sound = al_load_sample("points.wav");
    bomb = al_load_sample("bomb.wav");
    music = al_load_sample("music.ogg");
    victory = al_load_sample("victory.wav");
    lost = al_load_sample("losing.wav");
    scream = al_load_sample("scream.wav");
    _jump = al_load_sample("jump.wav");
    buttons = al_load_sample("buttons.wav");
    playerfall = al_load_sample("playerfall.wav");

    al_reserve_samples(9); //reserves 9 sound samples 

    //sound instances
    music_instance = al_create_sample_instance(music);
    victory_instance = al_create_sample_instance(victory);
    losing_instance = al_create_sample_instance(lost);
    al_set_sample_instance_playmode(music_instance, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(victory_instance, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_playmode(losing_instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(music_instance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(victory_instance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(losing_instance, al_get_default_mixer());

    ChangeState(state, TITLE, music_instance, losing_instance, victory_instance); //calling the title

    timer = al_create_timer(1.0 / FPS);
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_start_timer(timer);

    //main  game loop
    while (!done) {

        ALLEGRO_EVENT ev;//catching events
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }

        //animating the enemies 
        if (++Enemy1.frameCount >= Enemy1.frameDelay)
        {
            if (++Enemy1.curFrame >= Enemy1.maxFrame)
                Enemy1.curFrame = 0;

            Enemy1.frameCount = 0;
        }

        if (++Enemy2.frameCount >= Enemy2.frameDelay)
        {
            if (++Enemy2.curFrame >= Enemy2.maxFrame)
                Enemy2.curFrame = 0;

            Enemy2.frameCount = 0;
        }
        if (++Enemy3.frameCount >= Enemy3.frameDelay)
        {
            if (++Enemy3.curFrame >= Enemy3.maxFrame)
                Enemy3.curFrame = 0;

            Enemy3.frameCount = 0;
        }

        if (++Enemy4.frameCount >= Enemy4.frameDelay)
        {
            if (++Enemy4.curFrame >= Enemy4.maxFrame)
                Enemy4.curFrame = 0;

            Enemy4.frameCount = 0;
        }

        if (++Enemy5.frameCount >= Enemy5.frameDelay)
        {
            if (++Enemy5.curFrame >= Enemy5.maxFrame)
                Enemy5.curFrame = 0;

            Enemy5.frameCount = 0;
        }
        if (++Enemy6.frameCount >= Enemy6.frameDelay)
        {
            if (++Enemy6.curFrame >= Enemy6.maxFrame)
                Enemy6.curFrame = 0;

            Enemy6.frameCount = 0;
        }
        if (++Enemy7.frameCount >= Enemy7.frameDelay)
        {
            if (++Enemy7.curFrame >= Enemy7.maxFrame)
                Enemy7.curFrame = 0;

            Enemy7.frameCount = 0;
        }
        if (++Enemy8.frameCount >= Enemy8.frameDelay)
        {
            if (++Enemy8.curFrame >= Enemy8.maxFrame)
                Enemy8.curFrame = 8;

            Enemy8.frameCount = 0;
        }
        if (++Enemy9.frameCount >= Enemy9.frameDelay)
        {
            if (++Enemy9.curFrame >= Enemy9.maxFrame)
                Enemy9.curFrame = 0;

            Enemy9.frameCount = 0;
        }
        if (++Enemy10.frameCount >= Enemy10.frameDelay)
        {
            if (++Enemy10.curFrame >= Enemy10.maxFrame)
                Enemy10.curFrame = 8;

            Enemy10.frameCount = 0;
        }
        if (++Enemy11.frameCount >= Enemy11.frameDelay)
        {
            if (++Enemy11.curFrame >= Enemy11.maxFrame)
                Enemy11.curFrame = 8;

            Enemy11.frameCount = 0;
        }
        if (++Enemy12.frameCount >= Enemy12.frameDelay)
        {
            if (++Enemy12.curFrame >= Enemy12.maxFrame)
                Enemy12.curFrame = 0;

            Enemy12.frameCount = 0;
        }
        if (++Enemy13.frameCount >= Enemy13.frameDelay)
        {
            if (++Enemy13.curFrame >= Enemy13.maxFrame)
                Enemy13.curFrame = 0;

            Enemy13.frameCount = 0;
        }
        if (++Enemy14.frameCount >= Enemy14.frameDelay)
        {
            if (++Enemy14.curFrame >= Enemy14.maxFrame)
                Enemy14.curFrame = 8;

            Enemy14.frameCount = 0;
        }
        if (++Enemy15.frameCount >= Enemy15.frameDelay)
        {
            if (++Enemy15.curFrame >= Enemy15.maxFrame)
                Enemy15.curFrame = 0;

            Enemy15.frameCount = 0;
        }
        if (++Enemy16.frameCount >= Enemy16.frameDelay)
        {
            if (++Enemy16.curFrame >= Enemy16.maxFrame)
                Enemy16.curFrame = 0;

            Enemy16.frameCount = 0;
        }
        if (++Enemy17.frameCount >= Enemy17.frameDelay)
        {
            if (++Enemy17.curFrame >= Enemy17.maxFrame)
                Enemy17.curFrame = 0;

            Enemy17.frameCount = 0;
        }
        if (++Enemy18.frameCount >= Enemy18.frameDelay)
        {
            if (++Enemy18.curFrame >= Enemy18.maxFrame)
                Enemy18.curFrame = 0;

            Enemy18.frameCount = 0;
        }
        if (++Enemy19.frameCount >= Enemy19.frameDelay)
        {
            if (++Enemy19.curFrame >= Enemy19.maxFrame)
                Enemy19.curFrame = 0;

            Enemy19.frameCount = 0;
        }
        if (++Enemy20.frameCount >= Enemy20.frameDelay)
        {
            if (++Enemy20.curFrame >= Enemy20.maxFrame)
                Enemy20.curFrame = 0;

            Enemy20.frameCount = 0;
        }
        if (++Enemy21.frameCount >= Enemy21.frameDelay)
        {
            if (++Enemy21.curFrame >= Enemy21.maxFrame)
                Enemy21.curFrame = 0;

            Enemy21.frameCount = 0;
        }
        if (++Enemy22.frameCount >= Enemy22.frameDelay)
        {
            if (++Enemy22.curFrame >= Enemy22.maxFrame)
                Enemy22.curFrame = 0;

            Enemy22.frameCount = 0;
        }
        if (++Enemy23.frameCount >= Enemy23.frameDelay)
        {
            if (++Enemy23.curFrame >= Enemy23.maxFrame)
                Enemy23.curFrame = 0;

            Enemy23.frameCount = 0;
        }
        if (++Enemy24.frameCount >= Enemy24.frameDelay)
        {
            if (++Enemy24.curFrame >= Enemy24.maxFrame)
                Enemy24.curFrame = 0;

            Enemy24.frameCount = 0;
        }
        Enemy24.x += 1;     //movement of enemy in level 1
        if (Enemy24.x > 490)
            Enemy24.x = 50;

        if (++Enemy25.frameCount >= Enemy25.frameDelay)
        {
            if (++Enemy25.curFrame >= Enemy25.maxFrame)
                Enemy25.curFrame = 0;

            Enemy25.frameCount = 0;
        }

        if (++Enemy26.frameCount >= Enemy26.frameDelay)
        {
            if (++Enemy26.curFrame >= Enemy26.maxFrame)
                Enemy26.curFrame = 0;

            Enemy26.frameCount = 0;
        }

        Enemy26.x -= 1;  //movement of enemy in level 1
        if (Enemy26.x < 50)
            Enemy26.x = 490;

        if (++Enemy27.frameCount >= Enemy27.frameDelay)
        {
            if (++Enemy27.curFrame >= Enemy27.maxFrame)
                Enemy27.curFrame = 0;

            Enemy27.frameCount = 0;
        }
        if (++Enemy28.frameCount >= Enemy28.frameDelay)
        {
            if (++Enemy28.curFrame >= Enemy28.maxFrame)
                Enemy28.curFrame = 0;

            Enemy28.frameCount = 0;
        }
        if (++Enemy29.frameCount >= Enemy29.frameDelay)
        {
            if (++Enemy29.curFrame >= Enemy29.maxFrame)
                Enemy29.curFrame = 0;

            Enemy29.frameCount = 0;
        }
        if (++Enemy30.frameCount >= Enemy30.frameDelay)
        {
            if (++Enemy30.curFrame >= Enemy30.maxFrame)
                Enemy30.curFrame = 0;

            Enemy30.frameCount = 0;
        }

        //animating the purple fire attack
        for (int i = 0; i < 3; i++) {
            if (++bluefire[i].frameCount >= bluefire[i].frameDelay)
            {
                if (++bluefire[i].curFrame >= bluefire[i].maxFrame)
                    bluefire[i].curFrame = 0;

                bluefire[i].frameCount = 0;
            }
        }
        //translating the purple fire attack
        bluefire[0].x += 2;
        if (bluefire[0].x > (Player1.x + 20))
            bluefire[0].x = Enemy12.x + 60;

        bluefire[1].x += 2;
        if (bluefire[1].x > (Player1.x + 20))
            bluefire[1].x = Enemy13.x + 60;

        bluefire[2].x -= 2;
        if (bluefire[2].x < (Player1.x + 30))
            bluefire[2].x = Enemy22.x - 10;

        //animating the purple mist
        for (int i = 0; i < 9; i++) {
            if (++purplemist[i].frameCount >= purplemist[i].frameDelay)
            {
                if (++purplemist[i].curFrame >= purplemist[i].maxFrame)
                    purplemist[i].curFrame = 0;

                purplemist[i].frameCount = 0;
            }
        }
        //animating the skulls
        for (int i = 0; i < 8; i++) {
            if (++skull[i].frameCount >= skull[i].frameDelay)
            {
                if (++skull[i].curFrame >= skull[i].maxFrame)
                    skull[i].curFrame = 0;

                skull[i].frameCount = 0;
            }
        }
        //animating the points in level 2 so that they sparkle
        if (++point1.frameCount >= point1.frameDelay) {
            if (point1.frame_y++ < 2) {
                if (++point1.frameCount >= point1.frameDelay)
                {
                    if (++point1.curFrame >= point1.maxFrame)
                        point1.curFrame = 0;
                    point1.frameCount = 0;
                }
                if (point1.frame_y == 2)
                    point1.frame_y = 0;
            }
            point1.frameCount = 0;
        }

        if (++point2.frameCount >= point2.frameDelay) {
            if (point2.frame_y++ < 2) {
                if (++point2.frameCount >= point2.frameDelay)
                {
                    if (++point2.curFrame >= point2.maxFrame)
                        point2.curFrame = 0;
                    point2.frameCount = 0;
                }
                if (point2.frame_y == 2)
                    point2.frame_y = 0;
            }
            point2.frameCount = 0;
        }

        if (++point3.frameCount >= point3.frameDelay) {
            if (point3.frame_y++ < 7) {
                if (++point3.frameCount >= point3.frameDelay)
                {
                    if (++point3.curFrame >= point3.maxFrame)
                        point3.curFrame = 0;
                    point3.frameCount = 0;
                }
                if (point3.frame_y == 7)
                    point3.frame_y = 0;
            }
            point3.frameCount = 0;
        }

        if (++point4.frameCount >= point4.frameDelay) {
            if (point4.frame_y++ < 4) {
                if (++point4.frameCount >= point4.frameDelay)
                {
                    if (++point4.curFrame >= point4.maxFrame)
                        point4.curFrame = 0;
                    point4.frameCount = 0;
                }
                if (point4.frame_y == 4)
                    point4.frame_y = 0;
            }
            point4.frameCount = 0;
        }

        if (++point5.frameCount >= point5.frameDelay) {
            if (point5.frame_y++ < 3) {
                if (++point5.frameCount >= point5.frameDelay)
                {
                    if (++point5.curFrame >= point5.maxFrame)
                        point5.curFrame = 0;
                    point5.frameCount = 0;
                }
                if (point5.frame_y == 3)
                    point5.frame_y = 0;
            }
            point5.frameCount = 0;
        }

        //animating the players blast
        for (int i = 0; i < NUM_BULLETS; i++) {
            if (++bullets[i].frameCount >= bullets[i].frameDelay)
            {
                if (++bullets[i].curFrame >= bullets[i].maxFrame)
                    bullets[i].curFrame = 0;

                bullets[i].frameCount = 0;
            }
        }

        al_get_keyboard_state(&keystate);

        if (ev.type == ALLEGRO_EVENT_TIMER)//does stuff 60 times a second
        {

            if (al_key_down(&keystate, ALLEGRO_KEY_ENTER))
            {
                if (state == TITLE)
                {
                    al_play_sample(buttons, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    ChangeState(state, INSTRUCTIONS, music_instance, losing_instance, victory_instance);
                }
            }


            //updating stuff
            if (state == ADV_1 || state == ADV_2 || state == ADV_3)
            {
                if (!jump) {//if jump is false, it means that the player is not on the ground, and gravity works
                    vely += gravity;
                }
                else
                    vely = 0;

                Player1.y += vely;
                Player1.x += velx;

                if (state == ADV_1) {
                    Player1.setboundlvl1(Player1);
                    jump = (Player1.getboundlvl1());//checking if our player is on the ground, if true then jump is true
                    boundright = ((Player1.x <= 670 || Player1.y <= 250) && (Player1.x <= 750));
                    boundleft = (Player1.x >= 50);
                    bullets->update_bullet(bullets, NUM_BULLETS, Player1); //updating position of bullet
                    redraw = true;
                }
                else if (state == ADV_2) {
                    Player1.setboundlvl2(Player1);
                    jump = (Player1.getboundlvl2());//checking if our Player is on the ground, if true then jump is true
                    boundright = (Player1.x <= 770);
                    boundleft = (Player1.x >= 30);
                    bullets->update_bullet(bullets, NUM_BULLETS, Player1); //updating position of bullet
                    redraw = true;
                }
                else if (state == ADV_3) {
                    Player1.setboundlvl3(Player1);
                    jump = (Player1.getboundlvl3());//checking if our Player is on the ground, if true then jump is true
                    boundright = (Player1.x <= 750);
                    boundleft = (Player1.x >= 50);
                    bullets->update_bullet(bullets, NUM_BULLETS, Player1); //updating position of bullet
                    redraw = true;
                }
            }

            if (al_key_down(&keystate, ALLEGRO_KEY_UP) && jump)//UP key only works when player on ground(jump bool)
            {
                if (state == ADV_1 || state == ADV_2 || state == ADV_3)
                {
                    vely = -jumpspeed;
                    al_play_sample(_jump, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    jump = false;
                }
            }

            else if (al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
            {
                if (state == ADV_1 || state == ADV_2 || state == ADV_3)
                {
                    velx = Player1.speed * boundright;
                    Player1.frame_y = 3;
                    if (bullets->get_live() == 0) {
                        Player1.set_direction(1);
                    }
                }

            }

            else if (al_key_down(&keystate, ALLEGRO_KEY_LEFT))
            {
                if (state == ADV_1 || state == ADV_2 || state == ADV_3)
                {
                    velx = -Player1.speed * boundleft;
                    Player1.frame_y = 1;
                    if (bullets->get_live() == 0) {
                        Player1.set_direction(0);
                    }
                }
            }

            else if (al_key_down(&keystate, ALLEGRO_KEY_1)) //if 1 key is pressed 1st adventure selected
            {
                if (state == ADV_SELECT)
                {
                    al_play_sample(buttons, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    ChangeState(state, ADV_1, music_instance, losing_instance, victory_instance);
                }
            }

            else if (al_key_down(&keystate, ALLEGRO_KEY_2)) //if 1 key is pressed 1st adventure selected
            {
                if (state == ADV_SELECT)
                {
                    al_play_sample(buttons, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    ChangeState(state, ADV_2, music_instance, losing_instance, victory_instance);
                }
            }

            else if (al_key_down(&keystate, ALLEGRO_KEY_3)) //if 1 key is pressed 1st adventure selected
            {
                if (state == ADV_SELECT)
                {
                    al_play_sample(buttons, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    ChangeState(state, ADV_3, music_instance, losing_instance, victory_instance);
                }
            }


            else if (al_key_down(&keystate, ALLEGRO_KEY_SPACE)) //player shoots if key is down
            {
                if (state == ADV_1 || state == ADV_2 || state == ADV_3)
                {
                    bullets->fire_bullet(bullets, NUM_BULLETS, Player1, bomb);
                }
            }
            //if the player has 0 lives, then the lose state will be entered for the respective level
            else if (Player1.getlives() == 0)
            {
                if (state == ADV_1)
                    ChangeState(state, LOST1, music_instance, losing_instance, victory_instance);
                else if (state == ADV_2)
                    ChangeState(state, LOST2, music_instance, losing_instance, victory_instance);
                else if (state == ADV_3)
                    ChangeState(state, LOST3, music_instance, losing_instance, victory_instance);
            }
            //if the player has collected all 5 points, then the win state will be entered 
            else if (points == maxpoints) {
                ChangeState(state, WIN, music_instance, losing_instance, victory_instance);
            }

            else
            {
                Player1.curFrame = 0;
                Player1.frame_y = 0;

                velx = 0;
            }
            redraw = true;
        }

        if (redraw && al_is_event_queue_empty(event_queue))
        {
            //entering state
            if (state == TITLE)
            {
                al_draw_scaled_bitmap(title, 0, 0, 1024, 588, 0, 0, x, y, 0);
            }

            else if (state == INSTRUCTIONS)
            {
                al_draw_scaled_bitmap(ins, 0, 0, 1242, 768, 0, 0, x, y, 0);

                if (al_key_down(&keystate, ALLEGRO_KEY_4)) //if 4 then adv select
                {
                    al_play_sample(buttons, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    ChangeState(state, ADV_SELECT, music_instance, losing_instance, victory_instance);
                }
            }

            else if (state == ADV_SELECT)
            {
                al_draw_scaled_bitmap(adv_select, 0, 0, 1280, 794, 0, 0, x, y, 0);
            }
            else if (state == ADV_1)
            {
                redraw = false;
                //drawing level 1 with all its enemy sprites and player sprite
                level1.level1(level1_background, jungle_3, jungle_1, jungle_2, jungle_4, level1);
                Player1.drawlives(Player1, heart);
                Enemy23.draw(Enemy23, monster_1, Enemy23.curFrame, Enemy23.frame_y);
                Enemy24.draw(Enemy24, monster_1, Enemy24.curFrame, Enemy24.frame_y);
                Enemy25.draw(Enemy25, monster_2, Enemy25.curFrame, Enemy25.frame_y);
                Enemy26.draw(Enemy26, monster_2, Enemy26.curFrame, Enemy26.frame_y);
                Enemy27.draw(Enemy27, monster_1, Enemy27.curFrame, Enemy27.frame_y);
                Enemy28.draw(Enemy28, monster_2, Enemy28.curFrame, Enemy28.frame_y);
                Enemy29.draw(Enemy29, monster_1, Enemy29.curFrame, Enemy29.frame_y);
                Enemy30.draw(Enemy30, monster_2, Enemy30.curFrame, Enemy30.frame_y);
                point11.draw_stars(point11, stars, point11.curFrame, point11.frame_y);
                point12.draw_stars(point12, stars, point12.curFrame, point12.frame_y);
                point13.draw_stars(point13, stars, point13.curFrame, point13.frame_y);
                point14.draw_stars(point14, stars, point14.curFrame, point14.frame_y);
                point15.draw_stars(point15, stars, point15.curFrame, point15.frame_y);
                Player1.draw(Player1, image, Player1.curFrame, Player1.frame_y);

                //adding tints to the points
                point11.r = 0;
                point11.g = 255;
                point11.b = 127;

                point12.r = 255;
                point12.g = 140;
                point12.b = 0;

                point13.r = 255;
                point13.g = 0;
                point13.b = 255;

                point14.r = 32;
                point14.g = 178;
                point14.b = 170;

                point15.r = 255;
                point15.g = 0;
                point15.b = 255;

                //adding tints to the enemies
                Enemy27.r = 152;
                Enemy27.g = 251;
                Enemy27.b = 152;

                Enemy24.r = 255;
                Enemy24.g = 2;
                Enemy24.b = 0;

                Enemy26.r = 255;
                Enemy26.g = 1;
                Enemy26.b = 0;

                //changing frame of enemies when player is close
                monster_attack2(Enemy23);
                monster_attack2(Enemy24);
                monster_attack1(Enemy25);
                monster_attack1(Enemy26);
                monster_attack2(Enemy27);
                monster_attack1(Enemy28);
                monster_attack2(Enemy29);
                monster_attack1(Enemy30);

                //checking collision of player with points
                collidept(point11, Player1, point_sound);
                collidept(point12, Player1, point_sound);
                collidept(point13, Player1, point_sound);
                collidept(point14, Player1, point_sound);
                collidept(point15, Player1, point_sound);

                //checking players direction and drawing blasts accordingly
                if (Player1.get_direction())
                    bullets->draw_bullet_right(bullets, NUM_BULLETS, blast_1);
                else if (!Player1.get_direction())
                    bullets->draw_bullet_left(bullets, NUM_BULLETS, blast_2);

                //checking if player falls out of the screen
                Player1.playerfall(Player1, playerfall);

                //checking collision of player with enemies
                collide(Enemy23, Player1, scream);
                collide(Enemy24, Player1, scream);
                collide(Enemy25, Player1, scream);
                collide(Enemy26, Player1, scream);
                collide(Enemy27, Player1, scream);
                collide(Enemy28, Player1, scream);
                collide(Enemy29, Player1, scream);
                collide(Enemy30, Player1, scream);

                //checking collision of blast with enemies
                collideBt(Enemy23, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy24, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy25, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy26, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy27, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy28, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy29, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy30, bullets, NUM_BULLETS, bomb);

                //displaying score
                al_draw_textf(font, al_map_rgb(0, 128, 128), 300, 30, 0, "Score: %d", points);
            }
            else if (state == ADV_2)
            {
                redraw = false;
                //drawing level 2 with all its enemy sprites and player sprite
                level2.level2(level2_background, level2);
                Player1.drawlives(Player1, heart);
                Enemy12.draw(Enemy12, necromancer1, Enemy12.curFrame, Enemy12.frame_y);
                Enemy13.draw(Enemy13, necromancer1, Enemy13.curFrame, Enemy13.frame_y);
                Enemy14.draw(Enemy14, necromancer1, Enemy14.curFrame, Enemy14.frame_y);
                Enemy15.draw(Enemy15, necromancer1, Enemy15.curFrame, Enemy15.frame_y);
                Enemy16.draw(Enemy16, necromancer1, Enemy16.curFrame, Enemy16.frame_y);
                Enemy17.draw(Enemy17, necromancer1, Enemy17.curFrame, Enemy17.frame_y);
                Enemy18.draw(Enemy18, necromancer1, Enemy18.curFrame, Enemy18.frame_y);
                Enemy19.draw(Enemy19, necromancer1, Enemy19.curFrame, Enemy19.frame_y);
                Enemy20.draw(Enemy20, necromancer1, Enemy20.curFrame, Enemy20.frame_y);
                Enemy21.draw(Enemy21, necromancer1, Enemy21.curFrame, Enemy21.frame_y);
                Enemy22.draw(Enemy22, necromancer1, Enemy22.curFrame, Enemy22.frame_y);
                point1.draw_pinkgem(point1, pink_gem, point1.curFrame, point1.frame_y);
                point2.draw_bluegem(point2, blue_gem, point2.curFrame, point2.frame_y);
                point3.draw_greengem(point3, green_gem, point3.curFrame, point3.frame_y);
                point4.draw_redgem(point4, red_gem, point4.curFrame, point4.frame_y);
                point5.draw_yellowgem(point5, yellow_gem, point5.curFrame, point5.frame_y);
                Player1.draw(Player1, image, Player1.curFrame, Player1.frame_y);

                //adding tints to the enemies
                Enemy12.r = 126;
                Enemy12.g = 85;
                Enemy12.b = 211;

                Enemy13.r = 126;
                Enemy13.g = 85;
                Enemy13.b = 211;

                Enemy22.r = 126;
                Enemy22.g = 85;
                Enemy22.b = 211;

                //drawing the purple mist and adding tint to it
                for (int i = 0; i < 9; i++) {
                    purplemist[i].draw_purplemist(purplemist[i], purple_mist, purplemist[i].curFrame, purplemist[i].frame_y);
                    purplemist[i].r = 186;
                    purplemist[i].g = 85;
                    purplemist[i].b = 211;
                }

                //collsion of player with gems/points
                collidept(point1, Player1, point_sound);
                collidept(point2, Player1, point_sound);
                collidept(point3, Player1, point_sound);
                collidept(point4, Player1, point_sound);
                collidept(point5, Player1, point_sound);

                //checking players direction and drawing blasts accordingly
                if (Player1.get_direction())
                    bullets->draw_bullet_right(bullets, NUM_BULLETS, blast_1);
                else if (!Player1.get_direction())
                    bullets->draw_bullet_left(bullets, NUM_BULLETS, blast_2);

                //checking if player falls out of the screen
                Player1.playerfall(Player1, playerfall);

                //displaying score
                al_draw_textf(font, al_map_rgb(148, 0, 211), 300, 30, 0, "Score: %d", points);

                //drawing the purple mage fire
                for (int i = 0; i < 3; i++) {
                    bluefire[i].draw_attack(bluefire[i], blue_fire, bluefire[i].curFrame, bluefire[i].frame_y);
                }
                if (Enemy22.x == 1000)
                    bluefire[2].x = 1000;
                if (Enemy12.x == 1000)
                    bluefire[0].x = 1000;
                if (Enemy13.x == 1000)
                    bluefire[1].x = 1000;

                //changing frame of enemies when player is close
                necro_attack(Enemy14);
                necro_attack(Enemy15);
                necro_attack(Enemy16);
                necro_attack(Enemy17);
                necro_attack(Enemy18);
                necro_attack(Enemy19);
                necro_attack(Enemy20);
                necro_attack(Enemy21);

                //collision of enemies and player
                collide(Enemy12, Player1, scream);
                collide(Enemy13, Player1, scream);
                collide(Enemy14, Player1, scream);
                collide(Enemy15, Player1, scream);
                collide(Enemy16, Player1, scream);
                collide(Enemy17, Player1, scream);
                collide(Enemy22, Player1, scream);
                collide(Enemy18, Player1, scream);
                collide(Enemy19, Player1, scream);
                collide(Enemy20, Player1, scream);
                collide(Enemy21, Player1, scream);

                //collision of player with purple fire
                for (int i = 0; i < 3; i++) {
                    fire_collide(bluefire[i], Player1, scream);
                }

                //collision of enemies and bullet
                collideBt(Enemy12, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy13, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy14, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy15, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy16, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy17, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy18, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy19, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy20, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy21, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy22, bullets, NUM_BULLETS, bomb);


            }
            else if (state == ADV_3)
            {
                //drawing level 3 with all its enemy sprites and player sprite
                redraw = false;
                level3.level3(level3_background, spikes, level3);
                Player1.drawlives(Player1, heart);
                Enemy1.draw(Enemy1, skeleton1, Enemy1.curFrame, Enemy1.frame_y);
                Enemy2.draw(Enemy2, skeleton1, Enemy2.curFrame, Enemy2.frame_y);
                Enemy3.draw(Enemy3, skeleton1, Enemy3.curFrame, Enemy3.frame_y);
                Enemy4.draw(Enemy4, skeleton1, Enemy4.curFrame, Enemy4.frame_y);
                Enemy5.draw(Enemy5, skeleton1, Enemy5.curFrame, Enemy5.frame_y);
                Enemy6.draw(Enemy6, skeleton1, Enemy6.curFrame, Enemy6.frame_y);
                Enemy7.draw(Enemy7, skeleton1, Enemy7.curFrame, Enemy7.frame_y);
                Enemy8.draw(Enemy8, skeleton1, Enemy8.curFrame, Enemy8.frame_y);
                Enemy9.draw(Enemy9, skeleton1, Enemy9.curFrame, Enemy9.frame_y);
                Enemy10.draw(Enemy10, skeleton1, Enemy10.curFrame, Enemy10.frame_y);
                Enemy11.draw(Enemy11, skeleton1, Enemy11.curFrame, Enemy11.frame_y);
                Player1.draw(Player1, image, Player1.curFrame, Player1.frame_y);
                point16.draw_coins(point16, coins, point16.curFrame, point16.frame_y);
                point7.draw_coins(point7, coins, point7.curFrame, point7.frame_y);
                point8.draw_coins(point8, coins, point8.curFrame, point8.frame_y);
                point9.draw_coins(point9, coins, point9.curFrame, point9.frame_y);
                point10.draw_coins(point10, coins, point10.curFrame, point10.frame_y);

                //adding tints to the points
                point16.r = 255;
                point16.g = 165;
                point16.b = 0;

                point7.r = 255;
                point7.g = 215;
                point7.b = 0;

                point8.r = 255;
                point8.g = 140;
                point8.b = 0;

                point9.r = 218;
                point9.g = 165;
                point9.b = 32;

                point10.r = 255;
                point10.g = 255;
                point10.b = 0;

                //adding tints to the enemies
                Enemy6.r = 192;
                Enemy6.g = 192;
                Enemy6.b = 192;

                Enemy9.r = 192;
                Enemy9.g = 192;
                Enemy9.b = 192;

                Enemy1.r = 192;
                Enemy1.g = 192;
                Enemy1.b = 192;

                Enemy8.r = 192;
                Enemy8.g = 192;
                Enemy8.b = 192;

                Enemy11.r = 192;
                Enemy11.g = 192;
                Enemy11.b = 192;

                //drawing skulls
                for (int i = 0; i < 8; i++)
                    skull[i].draw_skull(skull[i], _skull, skull[i].curFrame, skull[i].frame_y);

                //collision of player with coins
                collidept(point16, Player1, point_sound);
                collidept(point7, Player1, point_sound);
                collidept(point8, Player1, point_sound);
                collidept(point9, Player1, point_sound);
                collidept(point10, Player1, point_sound);

                //checking players direction and drawing blasts accordingly
                if (Player1.get_direction())
                    bullets->draw_bullet_right(bullets, NUM_BULLETS, blast_1); //drawing a bullet
                else if (!Player1.get_direction())
                    bullets->draw_bullet_left(bullets, NUM_BULLETS, blast_2);

                Player1.playerfall(Player1, playerfall);

                //changing frame of enemies when player is close
                skel_attack(Enemy1);
                skel_attack(Enemy2);
                skel_attack(Enemy3);
                skel_attack(Enemy4);
                skel_attack(Enemy5);
                skel_attack(Enemy6);
                skel_attack(Enemy7);
                skel_attack(Enemy8);
                skel_attack(Enemy9);
                skel_attack(Enemy10);
                skel_attack(Enemy11);

                //collision of enemy and player
                collide(Enemy1, Player1, scream);
                collide(Enemy2, Player1, scream);
                collide(Enemy3, Player1, scream);
                collide(Enemy4, Player1, scream);
                collide(Enemy5, Player1, scream);
                collide(Enemy6, Player1, scream);
                collide(Enemy7, Player1, scream);
                collide(Enemy8, Player1, scream);
                collide(Enemy9, Player1, scream);
                collide(Enemy10, Player1, scream);
                collide(Enemy11, Player1, scream);

                //collision of enemy with bullets
                collideBt(Enemy1, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy2, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy3, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy4, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy5, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy6, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy7, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy8, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy9, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy10, bullets, NUM_BULLETS, bomb);
                collideBt(Enemy11, bullets, NUM_BULLETS, bomb);

                al_draw_textf(font, al_map_rgb(119, 136, 153), 300, 30, 0, "Score: %d", points); //displaying score

            }

            else if (state == WIN)
            {
                points = 0;
                al_draw_scaled_bitmap(win, 0, 0, 1242, 810, 0, 0, x, y, 0);


                if (al_key_down(&keystate, ALLEGRO_KEY_5))
                {
                    //if 5 then play again
                    al_play_sample(buttons, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    ChangeState(state, ADV_SELECT, music_instance, losing_instance, victory_instance);
                }
                else if (al_key_down(&keystate, ALLEGRO_KEY_1))
                {
                    al_play_sample(buttons, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    done = true;
                }
            }

            else if (state == LOST1 || state == LOST2 || state == LOST3)
            {
                //drawing bitmaps and text for lose states of each level
                if (state == LOST1)
                {
                    al_draw_scaled_bitmap(lose1, 0, 0, 1280, 1056, 0, 0, x, y, 0);
                    al_draw_textf(score_display, al_map_rgb(0, 100, 0), 460, 300, 0, "%d", points); //displaying points
                }

                else if (state == LOST2)
                {
                    al_draw_scaled_bitmap(lose2, 0, 0, 1242, 685, 0, 0, x, y, 0);
                    al_draw_textf(score_display, al_map_rgb(75, 0, 130), 460, 315, 0, "%d", points); //displaying points
                }

                else
                {
                    al_draw_scaled_bitmap(lose3, 0, 0, 1242, 708, 0, 0, x, y, 0);
                    al_draw_textf(score_display, al_map_rgb(100, 149, 237), 460, 290, 0, "%d", points); //displaying points
                }


                if (al_key_down(&keystate, ALLEGRO_KEY_5))  //if 5 then play again
                {
                    al_play_sample(buttons, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    ChangeState(state, ADV_SELECT, music_instance, losing_instance, victory_instance);

                }

                else if (al_key_down(&keystate, ALLEGRO_KEY_1))
                {
                    al_play_sample(buttons, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    done = true;
                    points = 0;
                }
            }

            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
        }
    }

    //destroying bitmaps
    al_destroy_bitmap(title);
    al_destroy_bitmap(win);
    al_destroy_bitmap(lose1);
    al_destroy_bitmap(lose3);
    al_destroy_bitmap(lose2);
    al_destroy_bitmap(ins);
    al_destroy_bitmap(adv_select);
    al_destroy_bitmap(image);
    al_destroy_bitmap(level1_background);
    al_destroy_bitmap(level3_background);
    al_destroy_bitmap(jungle_1);
    al_destroy_bitmap(jungle_2);
    al_destroy_bitmap(jungle_3);
    al_destroy_bitmap(jungle_4);
    al_destroy_bitmap(skeleton1);
    al_destroy_bitmap(spikes);
    al_destroy_bitmap(necromancer1);
    al_destroy_bitmap(monster_1);
    al_destroy_bitmap(monster_2);
    al_destroy_bitmap(heart);
    al_destroy_bitmap(pink_gem);
    al_destroy_bitmap(red_gem);
    al_destroy_bitmap(green_gem);
    al_destroy_bitmap(yellow_gem);
    al_destroy_bitmap(blue_gem);
    al_destroy_bitmap(blast_2);
    al_destroy_bitmap(blast_1);
    al_destroy_bitmap(coins);
    al_destroy_bitmap(stars);

    //destroying sound samples
    al_destroy_sample(victory);
    al_destroy_sample(lost);
    al_destroy_sample(music);
    al_destroy_sample(bomb);
    al_destroy_sample(point_sound);
    al_destroy_sample(_jump);
    al_destroy_sample(scream);
    al_destroy_sample(buttons);

    //destroying sound instances
    al_destroy_sample_instance(music_instance);
    al_destroy_sample_instance(victory_instance);
    al_destroy_sample_instance(losing_instance);

    al_destroy_display(display);
    al_destroy_font(font);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);

}

void ChangeState(int& state, int new_state, ALLEGRO_SAMPLE_INSTANCE* ins1, ALLEGRO_SAMPLE_INSTANCE* ins2, ALLEGRO_SAMPLE_INSTANCE* ins3)
{
    //entering state
    if (state == TITLE)
    {
    }
    else if (state == INSTRUCTIONS) {}
    else if (state == ADV_SELECT)
    {
        al_stop_sample_instance(ins1);
    }
    else if (state == ADV_1) {}
    else if (state == ADV_2) {}
    else if (state == ADV_3) {}
    else if (state == WIN)
    {
        //al_stop_sample_instance(ins3); 
    }
    else if (state == LOST1) { al_stop_sample_instance(ins2); }
    else if (state == LOST2) { al_stop_sample_instance(ins2); }
    else if (state == LOST3) { al_stop_sample_instance(ins2); }

    state = new_state; //leaving old state

    //entering new state
    if (state == TITLE)
    {
        al_play_sample_instance(ins1);
    }
    else if (state == INSTRUCTIONS) {}
    else if (state == ADV_SELECT) {}
    else if (state == ADV_1 || state == ADV_2 || state == ADV_3)
    {
        Player1.initPlayer(Player1);
        Enemy1.init_skeleton(Enemy1, 8, 0, 0, 395, 505);
        Enemy2.init_skeleton(Enemy2, 8, 0, 4, 550, 200);
        Enemy3.init_skeleton(Enemy3, 8, 0, 4, 150, 150);
        Enemy3.init_skeleton(Enemy4, 8, 0, 0, 350, 350);
        Enemy5.init_skeleton(Enemy5, 8, 0, 0, 250, 230);
        Enemy6.init_skeleton(Enemy6, 8, 0, 4, 700, 130);
        Enemy7.init_skeleton(Enemy7, 8, 0, 0, 80, 400);
        Enemy8.init_skeleton(Enemy8, 11, 8, 0, 485, 90);
        Enemy9.init_skeleton(Enemy9, 8, 0, 3, 750, 480);
        Enemy10.init_skeleton(Enemy10, 11, 8, 0, 770, 270);
        Enemy11.init_skeleton(Enemy11, 11, 8, 0, 45, 525);
        Enemy12.init_necromancer(Enemy12, 7, 0, 2, 60, 530);
        Enemy13.init_necromancer(Enemy13, 7, 0, 2, 80, 140);
        Enemy14.init_necromancer(Enemy14, 12, 8, 0, 720, 120);
        Enemy15.init_necromancer(Enemy15, 7, 0, 0, 100, 400);
        Enemy16.init_necromancer(Enemy16, 7, 0, 0, 310, 125);
        Enemy17.init_necromancer(Enemy17, 7, 0, 0, 570, 200);
        Enemy18.init_necromancer(Enemy18, 7, 0, 0, 745, 340);
        Enemy19.init_necromancer(Enemy19, 7, 0, 3, 320, 360);
        Enemy20.init_necromancer(Enemy20, 7, 0, 0, 520, 400);
        Enemy21.init_necromancer(Enemy21, 7, 0, 0, 435, 528);
        Enemy22.init_necromancer(Enemy22, 7, 0, 1, 730, 470);
        Enemy23.init_monster(Enemy23, 4, 0, 0, 200, 200);
        Enemy24.init_monster(Enemy24, 4, 0, 0, 70, 535);
        Enemy25.init_monster(Enemy25, 4, 0, 0, 730, 210);
        Enemy26.init_monster(Enemy26, 4, 0, 0, 470, 535);
        Enemy27.init_monster(Enemy27, 4, 0, 0, 60, 120);
        Enemy28.init_monster(Enemy28, 4, 0, 0, 550, 290);
        Enemy29.init_monster(Enemy29, 4, 0, 0, 450, 200);
        Enemy30.init_monster(Enemy30, 4, 0, 0, 540, 450);

        point1.init_pinkgem(point1, 3, 0, 0, 510, 90);
        point2.init_bluegem(point2, 6, 0, 0, 360, 230);
        point3.init_greengem(point3, 2, 0, 0, 150, 500);
        point4.init_redgem(point4, 2, 0, 0, 720, 300);
        point5.init_yellowgem(point5, 4, 0, 0, 400, 450);
        point16.init_coins(point16, 0, 0, 0, 100, 95);
        point7.init_coins(point7, 0, 0, 0, 400, 230);
        point8.init_coins(point8, 0, 0, 2, 120, 500);
        point9.init_coins(point9, 0, 0, 2, 720, 250);
        point10.init_coins(point10, 0, 0, 0, 400, 450);
        point11.init_stars(point11, 6, 0, 0, 200, 470);
        point12.init_stars(point12, 0, 0, 0, 550, 220);
        point13.init_stars(point13, 0, 0, 0, 430, 370);
        point14.init_stars(point14, 0, 0, 1, 700, 150);
        point15.init_stars(point15, 0, 0, 1, 150, 150);
        bullets->init_bullet(bullets, NUM_BULLETS); //initalising bullets
    }
    else if (state == WIN)
    {
        al_play_sample_instance(ins3);
    }
    else if (state == LOST1)
    {
        Player1.setlives(0);
        al_play_sample_instance(ins2);
    }
    else if (state == LOST2)
    {
        Player1.setlives(0);
        al_play_sample_instance(ins2);
    }
    else if (state == LOST3)
    {
        Player1.setlives(0);
        al_play_sample_instance(ins2);
    }
}

//attacking stance of skeletons
void skel_attack(Enemy& e) {
    if (Player1.y <= (e.y + 20) && Player1.y >= (e.y - 20)) {
        if (Player1.x < e.x)
            e.frame_y = 5;
        else {
            e.frame_y = 6;
            e.frameHeight = 68.7;
        }
    }
    else {
        e.frame_y = 0;
        e.frameHeight = 69.4;
    }
}

//changing mage direction in response to players movements
void necro_attack(Enemy& e) {
    if (Player1.y <= (e.y + 20) && Player1.y >= (e.y - 20)) {
        if (Player1.x < e.x)
            e.frame_y = 1;
        else {
            e.frame_y = 2;
        }
    }
    else {
        e.frame_y = 0;
    }
}

//changing ogre direction in response to players movements
void monster_attack1(Enemy& e) {
    if (Player1.y <= (e.y + 20) && Player1.y >= (e.y - 20)) {
        if (Player1.x < e.x)
            e.flag = 0;
        else
            e.flag = ALLEGRO_FLIP_HORIZONTAL;
    }
}
void monster_attack2(Enemy& e) {
    if (Player1.y <= (e.y + 20) && Player1.y >= (e.y - 20)) {
        if (Player1.x < e.x)
            e.flag = ALLEGRO_FLIP_HORIZONTAL;
        else
            e.flag = 0;
    }
}

//collision of player with purple fire
void fire_collide(Enemy& e, Player& p, ALLEGRO_SAMPLE* scream)
{
    if (((p.x >= (e.x - 40)) && (p.x <= (e.x + 3))) && ((p.y >= (e.y - 5)) && (p.y <= (e.y + 60)))) {
        p.lives--;
        p.frameWidthlives -= 270;
        p.x = 650;
        p.y = 500;
        al_play_sample(scream, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
}

//collision of player with enemy
void collide(Enemy& e, Player& p, ALLEGRO_SAMPLE* scream)
{
    if (((p.x >= (e.x - 25)) && (p.x <= (e.x + 30))) && ((p.y >= (e.y - 30)) && (p.y <= (e.y + 30)))) {
        p.lives--;
        p.frameWidthlives -= 270;
        p.x = 650;
        p.y = 500;
        al_play_sample(scream, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
}

//collision of player with points
void collidept(Points& po, Player& p, ALLEGRO_SAMPLE* point)
{
    if (((p.x >= (po.x - 30)) && (p.x <= (po.x + 30))) && ((p.y >= (po.y - 30)) && (p.y <= (po.y + 30))))
    {
        po.x = 1000;
        points++;

        al_play_sample(point, 30, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
}

//collision of enemies with bullets
void collideBt(Enemy& e, Bullet bullets[], int s, ALLEGRO_SAMPLE* bomb)
{
    for (int i = 0; i < s; i++) {
        if (((bullets[i].x >= (e.x - 30)) && (bullets[i].x <= (e.x + 30))) && ((bullets[i].y >= (e.y - 30)) && (bullets[i].y <= (e.y + 30))))
        {
            if (e.g == 2 || e.g == 1) {

                if (Player1.x <= e.x)
                    e.x += 6;
                else
                    e.x -= 6;
            }

            if ((e.g != 2) && (e.g != 1)) {
                al_rest(0.07);
                e.x = 1000;
                al_play_sample(bomb, 4, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                bullets[i].live = false;
            }
        }
    }
}