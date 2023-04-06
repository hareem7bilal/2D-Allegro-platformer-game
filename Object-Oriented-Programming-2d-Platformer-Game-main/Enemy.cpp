#include"Enemy.h"
#include"Player.h"

void Enemy::draw(Enemy& e, ALLEGRO_BITMAP* image, int curFrame, int frame_y)
{
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * e.frameWidth, frame_y * e.frameHeight, e.frameWidth, e.frameHeight, al_map_rgb(e.r, e.g, e.b), frameHeight / 2, frameWidth / 2, e.x, e.y, e.scale, e.scale, e.angle, e.flag);
}
void Enemy::init_skeleton(Enemy& s, int mf, int cf, int fy, float posx, float posy) {
    s.frameDelay = 14;
    s.scale = 1.2;
    s.frameWidth = 65.4;
    s.frameHeight = 69.4;
    s.frameCount = 0;
    s.r = 255;
    s.g = 255;
    s.b = 255;
    s.maxFrame = mf;
    s.curFrame = cf;
    s.frame_y = fy;
    s.x = posx;
    s.y = posy;
}
void Enemy::init_necromancer(Enemy& n, int mf, int cf, int fy, float posx, float posy) {
    n.frameDelay = 14;
    n.scale = 1.2;
    n.frameWidth = 763 / 12;
    n.frameHeight = 67.5;
    n.frameCount = 0;
    n.r = 255;
    n.g = 255;
    n.b = 255;
    n.maxFrame = mf;
    n.curFrame = cf;
    n.frame_y = fy;
    n.x = posx;
    n.y = posy;
}
void Enemy::init_monster(Enemy& m, int mf, int cf, int fy, float posx, float posy) {
    m.frameDelay = 14;
    m.scale = 0.65;
    m.frameWidth = 142.8;
    m.frameHeight = 153;
    m.frameCount = 0;
    m.r = 255;
    m.g = 255;
    m.b = 255;
    m.flag = 0;
    m.maxFrame = mf;
    m.curFrame = cf;
    m.frame_y = fy;
    m.x = posx;
    m.y = posy;
}
void Attack::init_bluefire(Attack& a, int mf, int cf, int fy, float posx, float posy) {
    a.frameDelay = 9;
    a.scale = 0.4;
    a.frameWidth = 527 / 6;
    a.frameHeight = 219;
    a.frameCount = 0;
    a.r = 128;
    a.g = 0;
    a.b = 128;
    a.maxFrame = mf;
    a.curFrame = cf;
    a.frame_y = fy;
    a.x = posx;
    a.y = posy;
}
void Attack::draw_attack(Attack& e, ALLEGRO_BITMAP* image, int curFrame, int frame_y)
{
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * e.frameWidth, frame_y * e.frameHeight, e.frameWidth, e.frameHeight, al_map_rgb(e.r, e.g, e.b), frameHeight / 2, frameWidth / 2, e.x, e.y, e.scale, e.scale, 0, e.flag);
}