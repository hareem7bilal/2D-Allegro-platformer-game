#include "Bullet.h"
#include "Player.h"


void Bullet::init_bullet(Bullet bullets[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bullets[i].live = false;
        bullets[i].speed = 6;
    }

}
void  Bullet::draw_bullet_right(Bullet bullets[], int size, ALLEGRO_BITMAP* blast_1)
{
    for (int i = 0; i < size; i++)
    {
        if (bullets[i].live)
            al_draw_tinted_scaled_rotated_bitmap_region(blast_1, curFrame * blast_width, frame_y * blast_height, blast_width, blast_height, al_map_rgb(255, 140, 0), blast_width / 2, blast_height / 2, x, y, scale, scale, 0, 0);

    }
}
void  Bullet::draw_bullet_left(Bullet bullets[], int size, ALLEGRO_BITMAP* blast_2)
{
    for (int i = 0; i < size; i++)
    {
        if (bullets[i].live)
            al_draw_tinted_scaled_rotated_bitmap_region(blast_2, curFrame * blast_width, frame_y * blast_height, blast_width, blast_height, al_map_rgb(255, 140, 0), blast_width / 2, blast_height / 2, x, y, scale, scale, 0, 0);
    }
}
void Bullet::fire_bullet(Bullet bullets[], int size, Player& Player, ALLEGRO_SAMPLE* bomb)
{
    for (int i = 0; i < size; i++)
    {
        if (!bullets[i].live)
        {
            bullets[i].x = Player.x + 10;
            bullets[i].y = Player.y;
            bullets[i].live = true;

            al_play_sample(bomb, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

            break; //one bullet shot at once
        }

        break;
    }
}


void  Bullet::update_bullet(Bullet bullets[], int size, Player& player) //updates the positioning of bullet
{
    for (int i = 0; i < size; i++)
    {
        if (bullets[i].live)
        {
            if (player.get_direction() == 1)
            {
                bullets[i].x += bullets[i].speed;
            }

            else if (player.get_direction() == 0)
            {
                bullets[i].x -= bullets[i].speed;
            }

            if (bullets[i].x > 800 || bullets[i].x < 0)
                bullets[i].live = false;
        }
    }
}
bool Bullet::get_live() {
    return live;
}