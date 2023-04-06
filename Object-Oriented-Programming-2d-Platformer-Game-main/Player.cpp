#include "Player.h"

void Player::setboundlvl3(Player& Player1) {
    boundlvl3 = (((Player1.y >= 550 && !(Player1.y >= 600)) && (Player1.x <= 660 && Player1.x >= 540)) || ((Player1.y >= 315 && !(Player1.y >= 345)) && (Player1.x <= 160 && Player1.x >= 50)) || ((Player1.y >= 510 && !(Player1.y >= 540)) && (Player1.x <= 460 && Player1.x >= 330)) || ((Player1.y >= 470 && !(Player1.y >= 500)) && (Player1.x <= 280 && Player1.x >= 200)) || ((Player1.y >= 525 && !(Player1.y >= 560)) && (Player1.x <= 120)) || ((Player1.y >= 390 && !(Player1.y >= 430)) && ((Player1.x <= 150))) || ((Player1.y >= 350 && !(Player1.y >= 390)) && ((Player1.x >= 250 && Player1.x <= 480))) || (Player1.y >= 415 && !(Player1.y >= 445)) && (Player1.x >= 500 && Player1.x <= 630) || (Player1.y >= 470 && !(Player1.y >= 510)) && (Player1.x >= 680) || (Player1.y >= 345 && !(Player1.y >= 375)) && (Player1.x >= 630 && Player1.x <= 665) || (Player1.y >= 270 && !(Player1.y >= 300)) && (Player1.x >= 690) || (Player1.y >= 200 && !(Player1.y >= 235)) && (Player1.x >= 450 && Player1.x <= 665) || (Player1.y >= 230 && !(Player1.y >= 260)) && (Player1.x >= 150 && Player1.x <= 380) || (Player1.y >= 140 && !(Player1.y >= 170)) && (Player1.x <= 300) || (Player1.y >= 120 && !(Player1.y >= 150)) && (Player1.x >= 600) || (Player1.y >= 90 && !(Player1.y >= 120)) && (Player1.x >= 400 && Player1.x <= 570));
}
void Player::setboundlvl2(Player& a) {
    boundlvl2 = (((a.y >= 605 && !(a.y >= 650)) && (a.x >= 715)) || ((a.y >= 570 && !(a.y >= 600)) && (a.x <= 680 && a.x >= 550)) || ((a.y >= 530 && !(a.y >= 560)) && ((a.x <= 510 && a.x >= 370) || (a.x <= 150))) || ((a.y >= 470 && !(a.y >= 500)) && ((a.x <= 330 && a.x >= 200) || (a.x >= 650))) || ((a.y >= 400 && !(a.y >= 430)) && ((a.x <= 600 && a.x >= 450) || (a.x <= 175))) || ((a.y >= 350 && !(a.y >= 380)) && ((a.x <= 400 && a.x >= 250)))) || (((a.y >= 340 && !(a.y >= 370)) && (a.x >= 650)) || (((a.y >= 290 && !(a.y >= 320)) && ((a.x <= 600 && a.x >= 480) || (a.x <= 220 && a.x >= 80)))) || (((a.y >= 240 && !(a.y >= 270)) && (a.x <= 435 && a.x >= 300))) || (((a.y >= 200 && !(a.y >= 230)) && (a.x <= 650 && a.x >= 500))) || (((a.y >= 140 && !(a.y >= 170)) && (a.x <= 160))) || (((a.y >= 120 && !(a.y >= 150)) && ((a.x >= 650) || (a.x >= 250 && a.x <= 380)))) || (((a.y >= 90 && !(a.y >= 120)) && (a.x <= 570 && a.x >= 455))));
}
void Player::setboundlvl1(Player& a) {
    boundlvl1 = (((a.y >= 550 && !(a.y >= 600)) && ((a.x >= 600) || (a.x <= 500))) || ((a.y >= 460 && !(a.y >= 490)) && (a.x <= 610 && a.x >= 485)) || ((a.y >= 305 && !(a.y >= 335)) && (a.x <= 600 && a.x >= 490)) || ((a.y >= 130 && !(a.y >= 160)) && (a.x <= 600 && a.x >= 500)) || ((a.y >= 490 && !(a.y >= 550)) && (a.x <= 230 && a.x >= 150)) || ((a.y >= 425 && !(a.y >= 455)) && (a.x <= 390 && a.x >= 300)) || ((a.y >= 323 && !(a.y >= 350)) && (a.x <= 400 && a.x >= 270)) || ((a.y >= 125 && !(a.y >= 155)) && (a.x <= 390 && a.x >= 300)) || ((a.y >= 392 && !(a.y >= 422)) && (a.x <= 555 && a.x >= 410)) || ((a.y >= 375 && !(a.y >= 405)) && (a.x <= 240 && a.x >= 150)) || ((a.y >= 217 && !(a.y >= 247)) && ((a.x <= 300 && a.x >= 100) || (a.x <= 495 && a.x >= 380) || (a.x >= 605))) || ((a.y >= 140 && !(a.y >= 170)) && (a.x <= 120)) || ((a.y >= 60 && !(a.y >= 90)) && ((a.x <= 245 && a.x >= 155) || (a.x <= 485 && a.x >= 400))));
}
bool Player::getboundlvl3() {
    return boundlvl3;
}
bool Player::getboundlvl2() {
    return boundlvl2;
}
bool Player::getboundlvl1() {
    return boundlvl1;
}
void Player::initPlayer(Player& p)
{
    p.scale = 1.35;
    p.frameWidth = 34.9;
    p.frameHeight = 38.25;
    p.frameWidthlives = 800;
    p.frameHeightlives = 500;
    p.frameDelay = 12;
    p.x = 630;
    p.y = 500;
    p.r = 255;
    p.g = 255;
    p.b = 255;
    p.health = 100;
    p.lives = 3;
    p.speed = 5;

}
void Player::draw(Player& p, ALLEGRO_BITMAP* image, int curFrame, int frame_y)
{
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * p.frameWidth, frame_y * p.frameHeight, p.frameWidth, p.frameHeight, al_map_rgb(p.r, p.g, p.b), frameHeight / 2, frameWidth / 2, p.x, p.y, p.scale, p.scale, 0, 0);
}
void Player::playerfall(Player& p, ALLEGRO_SAMPLE* sound) {
    if (p.y > 700) {
        p.y = 500;
        p.x = 630;
        p.lives--;
        p.frameWidthlives -= 270;
        al_play_sample(sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
}
void Player::setlives(int a) {
    lives = a;
}
int Player::getlives() {
    return lives;
}
void Player::drawlives(Player& p, ALLEGRO_BITMAP* heart) {
    al_draw_tinted_scaled_rotated_bitmap_region(heart, 0, 0, p.frameWidthlives, p.frameHeightlives, al_map_rgb(p.r, p.g, p.b), 740, 750, 750, 150, 0.15, 0.15, p.angle, 0);
}
void Player::set_direction(bool dir)
{
    direction = dir;
}
bool Player::get_direction()
{
    return direction;
}