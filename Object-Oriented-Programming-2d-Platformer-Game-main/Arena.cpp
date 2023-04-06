#include "Arena.h"

void Arena::level3(ALLEGRO_BITMAP* background, ALLEGRO_BITMAP* spikes, Arena& level3) {

    al_draw_tinted_scaled_bitmap(background, al_map_rgb(102, 205, 170), 0, 0, level3.background3_width, level3.background3_height, 0, 0, level3.window_width, level3.window_height, 0);

    al_draw_rounded_rectangle(0, 0, level3.window_width, level3.window_height, 0, 0, al_map_rgb(0, 0, 63), 40);
    for (int x = 30; x <= 800; x += 40) {
        al_draw_tinted_scaled_rotated_bitmap_region(spikes, level3.spikes_width, 0, level3.spikes_width, level3.spikes_height, al_map_rgb(0, 0, 0), level3.spikes_width / 2, level3.spikes_height / 2, x, 675, 0.15, 0.24, 0, 0);
    }
    //using primitives for drawing platforms 
    al_draw_filled_rectangle(600, 150, 780, 170, al_map_rgb(25, 25, 112));
    al_draw_filled_rectangle(400, 120, 570, 140, al_map_rgb(0, 0, 128));
    al_draw_filled_rectangle(150, 270, 380, 290, al_map_rgb(0, 0, 63));
    al_draw_filled_rectangle(450, 230, 650, 250, al_map_rgb(25, 25, 112));
    al_draw_filled_rectangle(50, 350, 160, 370, al_map_rgb(106, 90, 205));
    al_draw_filled_rectangle(240, 380, 470, 400, al_map_rgb(75, 0, 63));
    al_draw_filled_rectangle(500, 450, 630, 470, al_map_rgb(25, 25, 112));
    al_draw_filled_rectangle(620, 370, 670, 390, al_map_rgb(0, 0, 139));
    al_draw_filled_rectangle(690, 500, 780, 520, al_map_rgb(139, 0, 139));
    al_draw_filled_rectangle(20, 430, 150, 450, al_map_rgb(0, 0, 63));
    al_draw_filled_rectangle(200, 500, 280, 520, al_map_rgb(0, 0, 128));
    al_draw_filled_rectangle(330, 540, 460, 560, al_map_rgb(0, 0, 63));
    al_draw_filled_rectangle(700, 300, 780, 320, al_map_rgb(128, 0, 128));
    al_draw_filled_rectangle(20, 171, 290, 191, al_map_rgb(72, 61, 139));
    al_draw_filled_rectangle(20, 560, 110, 580, al_map_rgb(25, 25, 112));
    al_draw_filled_rectangle(540, 585, 640, 605, al_map_rgb(75, 0, 130));
}

void Arena::level2(ALLEGRO_BITMAP* background, Arena& level2) {
    al_draw_scaled_bitmap(background, 0, 0, level2.background2_width, level2.background2_height, 0, 0, level2.window_width, level2.window_height, 0);
    al_draw_rounded_rectangle(0, 0, level2.window_width, level2.window_height, 0, 0, al_map_rgb(205, 92, 92), 40);
    //using primitives for drawing platforms 
    al_draw_filled_rectangle(650, 150, 780, 170, al_map_rgb(240, 128, 128));
    al_draw_filled_rectangle(450, 120, 570, 140, al_map_rgb(70, 130, 180));
    al_draw_filled_rectangle(300, 270, 430, 290, al_map_rgb(86, 85, 211));
    al_draw_filled_rectangle(500, 230, 650, 250, al_map_rgb(32, 178, 170));
    al_draw_filled_rectangle(80, 320, 220, 340, al_map_rgb(147, 112, 219));
    al_draw_filled_rectangle(240, 380, 390, 400, al_map_rgb(100, 149, 237));
    al_draw_filled_rectangle(450, 430, 600, 450, al_map_rgb(255, 105, 180));
    al_draw_filled_rectangle(650, 370, 780, 390, al_map_rgb(30, 144, 255));
    al_draw_filled_rectangle(650, 500, 780, 520, al_map_rgb(138, 43, 226));
    al_draw_filled_rectangle(20, 430, 170, 450, al_map_rgb(65, 105, 225));
    al_draw_filled_rectangle(200, 500, 330, 520, al_map_rgb(72, 61, 139));
    al_draw_filled_rectangle(370, 560, 500, 580, al_map_rgb(0, 191, 255));
    al_draw_filled_rectangle(480, 320, 600, 340, al_map_rgb(144, 238, 144));
    al_draw_filled_rectangle(20, 171, 150, 191, al_map_rgb(60, 179, 113));
    al_draw_filled_rectangle(20, 560, 150, 580, al_map_rgb(154, 205, 50));
    al_draw_filled_rectangle(550, 595, 680, 615, al_map_rgb(127, 255, 0));
    al_draw_filled_rectangle(720, 640, 780, 660, al_map_rgb(127, 255, 212));
    al_draw_filled_rectangle(250, 150, 370, 170, al_map_rgb(0, 128, 128));
}

void Arena::level1(ALLEGRO_BITMAP* background, ALLEGRO_BITMAP* jungle_3, ALLEGRO_BITMAP* jungle_1, ALLEGRO_BITMAP* jungle_2, ALLEGRO_BITMAP* jungle_4, Arena& level1) {


    al_draw_tinted_scaled_bitmap(background, al_map_rgb(level1.r, level1.g, level1.b), 0, 0, level1.background1_width, level1.background1_height, 0, 0, level1.window_width, level1.window_height, 0);

    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 3, 0, level1.jungle1_width, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 645, 300, 0.9, 1, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 3, level1.jungle1_height, level1.jungle1_width - 2, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 647, 630, 0.9, 1, 0, 0);
    for (int y = 380; y <= 680; y += 100) {
        al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 2, level1.jungle1_height, level1.jungle1_width, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 740, y, 0.9, 1, 0, 0);
    }
    //using spritesheets for drawing platforms 
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 9, 0, level1.jungle1_width - 2, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 197.5, 380, 1, 1.8, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 7, 0, level1.jungle1_width - 2, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 450 - 15, 300, 0.9, 1, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 8, 0, level1.jungle1_width - 2, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 150, 300, 0.9, 1, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 7, level1.jungle1_height, level1.jungle1_width - 2, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 245, 303, 0.9, 1, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 3, level1.jungle1_height, level1.jungle1_width - 2, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 63, 630, 0.9, 1, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 4, level1.jungle1_height, level1.jungle1_width - 2, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 450, 630, 0.9, 1, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 6, level1.jungle1_height, level1.jungle1_width - 2, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 550, 530, 1.15, 0.8, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 2, level1.jungle1_height, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 335, 370, 1.15, 0.3, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 3, level1.jungle1_height, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 450, 440, 0.7, 0.3, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 4, level1.jungle1_height, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 510, 440, 0.7, 0.3, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, 0, level1.jungle1_height, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 340, 180, 0.8, 0.4, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 9, 0, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 545, 200, 0.8, 0.8, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 7, 0, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 70, 210, 0.8, 0.8, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 3, 0, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 520, 355, 0.5, 0.5, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 4, 0, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 573, 355, 0.5, 0.5, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 6, level1.jungle1_height, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 200, 450, 0.8, 0.8, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 9, 0, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 340, 500, 0.8, 0.8, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 5, 0, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 440, 125, 0.7, 0.6, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 5, 0, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 200, 125, 0.7, 0.6, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width * 5, 0, level1.jungle1_width - 4, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 195, 575, 0.8, 1.1, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_4, 0, 0, 121, 62, al_map_rgb(255, 255, 255), 121 / 2, 62 / 2, 700, 232, 0.6, 0.6, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_4, 0, 0, 121, 62, al_map_rgb(255, 255, 255), 121 / 2, 62 / 2, 230, 232, 0.6, 0.6, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_4, 242, 0, 121, 62, al_map_rgb(255, 255, 255), 121 / 2, 62 / 2, 240, 232, 0.6, 0.6, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_4, 121, 0, 121, 62, al_map_rgb(255, 255, 255), 121 / 2, 62 / 2, 300, 145, 0.6, 0.6, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_4, 121, 0, 121, 62, al_map_rgb(255, 255, 255), 121 / 2, 62 / 2, 400, 560, 0.8, 0.8, 0, 0);

    for (int x = 65; x <= 120; x += 40) {
        al_draw_tinted_scaled_rotated_bitmap_region(jungle_2, 0, 0, level1.jungle2_width, level1.jungle2_height, al_map_rgb(255, 255, 255), level1.jungle2_width / 2, level1.jungle2_height / 2, x, 475, 0.8, 0.8, 0, 0);
    }
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_2, level1.jungle2_width, 0, level1.jungle2_width, level1.jungle2_height, al_map_rgb(255, 255, 255), level1.jungle2_width / 2, level1.jungle2_height / 2, 250, 475, 0.8, 0.8, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_2, level1.jungle2_width * 3, 0, level1.jungle2_width, level1.jungle2_height, al_map_rgb(255, 255, 255), level1.jungle2_width / 2, level1.jungle2_height / 2, 220, 475, 0.8, 0.8, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_2, level1.jungle2_width * 2, 0, level1.jungle2_width, level1.jungle2_height, al_map_rgb(255, 255, 255), level1.jungle2_width / 2, level1.jungle2_height / 2, 110, 500, 0.6, 0.6, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_2, 0, 0, level1.jungle2_width, level1.jungle2_height, al_map_rgb(255, 255, 255), level1.jungle2_width / 2, level1.jungle2_height / 2, 650, 475, 0.8, 0.8, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_2, level1.jungle2_width, 0, level1.jungle2_width, level1.jungle2_height, al_map_rgb(255, 255, 255), level1.jungle2_width / 2, level1.jungle2_height / 2, 750, 170, 0.6, 0.6, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_2, level1.jungle2_width * 2, 0, level1.jungle2_width, level1.jungle2_height, al_map_rgb(255, 255, 255), level1.jungle2_width / 2, level1.jungle2_height / 2, 620, 525, 0.4, 0.4, 0, 0);
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_2, level1.jungle2_width * 3, 0, level1.jungle2_width, level1.jungle2_height, al_map_rgb(255, 255, 255), level1.jungle2_width / 2, level1.jungle2_height / 2, 400, 150, 0.8, 0.8, 0, 0);

    for (int x = 351; x >= 65; x -= 97) {
        al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width, 0, level1.jungle1_width - 2, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, x, 630, 0.9, 1, 0, 0);//
    }
    al_draw_tinted_scaled_rotated_bitmap_region(jungle_1, level1.jungle1_width, 0, level1.jungle1_width, level1.jungle1_height, al_map_rgb(255, 255, 255), level1.jungle1_width / 2, level1.jungle1_height / 2, 740, 300, 0.9, 1, 0, 0);
    for (int x = 0; x <= 800; x += 127) {
        al_draw_tinted_scaled_rotated_bitmap_region(jungle_3, 0, 0, 146.5, 133, al_map_rgb(102, 205, 170), 146.5 / 2, 66.5 / 2, x, 610, 1, 1.2, 0, 0);
    }
    al_draw_rounded_rectangle(0, 0, level1.window_width, level1.window_height, 0, 0, al_map_rgb(31, 63, 63), 40);
}
void Arena::init_purplemist(Arena& s, int mf, int cf, int fy, float posx, float posy) {
    s.frameDelay = 10;
    s.scale = 1.6;
    s.frameWidth = 359 / 6;
    s.frameHeight = 52;
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
void Arena::draw_purplemist(Arena& p, ALLEGRO_BITMAP* image, int curFrame, int frame_y) {
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * p.frameWidth, frame_y * p.frameHeight, p.frameWidth, p.frameHeight, al_map_rgb(p.r, p.g, p.b), p.frameHeight / 2, p.frameWidth / 2, p.x, p.y, 3, p.scale, 0, p.flag);
}

void Arena::init_skull(Arena& s, int mf, int cf, int fy, float posx, float posy) {
    s.frameDelay = 10;
    s.scale = 0.4;
    s.frameWidth = 97;
    s.frameHeight = 125;
    s.frameCount = 0;
    s.r = 128;
    s.g = 128;
    s.b = 128;
    s.maxFrame = mf;
    s.curFrame = cf;
    s.frame_y = fy;
    s.x = posx;
    s.y = posy;

}
void Arena::draw_skull(Arena& p, ALLEGRO_BITMAP* image, int curFrame, int frame_y) {
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * p.frameWidth, frame_y * p.frameHeight, p.frameWidth, p.frameHeight, al_map_rgb(p.r, p.g, p.b), p.frameHeight / 2, p.frameWidth / 2, p.x, p.y, p.scale, p.scale, 0, p.flag);
}

void Points::init_pinkgem(Points& p, int mf, int cf, int fy, float posx, float posy) {
    p.pinkgem_width = 112;
    p.pinkgem_height = 112;
    p.scale = 0.37;
    p.maxFrame = mf;
    p.curFrame = cf;
    p.frame_y = fy;
    p.x = posx;
    p.y = posy;
}
void Points::init_bluegem(Points& p, int mf, int cf, int fy, float posx, float posy) {
    p.bluegem_width = 112.5;
    p.bluegem_height = 113;
    p.scale = 0.37;
    p.maxFrame = mf;
    p.curFrame = cf;
    p.frame_y = fy;
    p.x = posx;
    p.y = posy;
}
void Points::init_yellowgem(Points& p, int mf, int cf, int fy, float posx, float posy) {
    p.yellowgem_width = 113.25;
    p.yellowgem_height = 114.25;
    p.scale = 0.37;
    p.maxFrame = mf;
    p.curFrame = cf;
    p.frame_y = fy;
    p.x = posx;
    p.y = posy;
}
void Points::init_greengem(Points& p, int mf, int cf, int fy, float posx, float posy) {
    p.greengem_width = 115;
    p.greengem_height = 815 / 7;
    p.scale = 0.37;
    p.maxFrame = mf;
    p.curFrame = cf;
    p.frame_y = fy;
    p.x = posx;
    p.y = posy;
}
void Points::init_redgem(Points& p, int mf, int cf, int fy, float posx, float posy) {
    p.redgem_width = 111;
    p.redgem_height = 113;
    p.scale = 0.37;
    p.maxFrame = mf;
    p.curFrame = cf;
    p.frame_y = fy;
    p.x = posx;
    p.y = posy;
}
void Points::init_coins(Points& c, int mf, int cf, int fy, float posx, float posy) {
    c.coin_width = 144;
    c.coin_height = 200;
    c.scale = 0.26;
    c.maxFrame = mf;
    c.curFrame = cf;
    c.frame_y = fy;
    c.x = posx;
    c.y = posy;
}
void Points::init_stars(Points& s, int mf, int cf, int fy, float posx, float posy) {
    s.star_width = 83;
    s.star_height = 99.5;
    s.scale = 0.55;
    s.maxFrame = mf;
    s.curFrame = cf;
    s.frame_y = fy;
    s.x = posx;
    s.y = posy;
}
void Points::draw_pinkgem(Points& p, ALLEGRO_BITMAP* image, int curFrame, int frame_y) {
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * p.pinkgem_width, frame_y * p.pinkgem_height, p.pinkgem_width, p.pinkgem_height, al_map_rgb(p.r, p.g, p.b), p.pinkgem_width / 2, p.pinkgem_height / 2, p.x, p.y, p.scale, p.scale, 0, 0);
}
void Points::draw_yellowgem(Points& p, ALLEGRO_BITMAP* image, int curFrame, int frame_y) {
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * p.yellowgem_width, frame_y * p.yellowgem_height, p.yellowgem_width, p.yellowgem_height, al_map_rgb(p.r, p.g, p.b), p.yellowgem_width / 2, p.yellowgem_height / 2, p.x, p.y, p.scale, p.scale, 0, 0);
}
void Points::draw_greengem(Points& p, ALLEGRO_BITMAP* image, int curFrame, int frame_y) {
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * p.greengem_width, frame_y * p.greengem_height, p.greengem_width, p.greengem_height, al_map_rgb(p.r, p.g, p.b), p.greengem_width / 2, p.greengem_height / 2, p.x, p.y, p.scale, p.scale, 0, 0);
}
void Points::draw_redgem(Points& p, ALLEGRO_BITMAP* image, int curFrame, int frame_y) {
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * p.redgem_width, frame_y * p.redgem_height, p.redgem_width, p.redgem_height, al_map_rgb(p.r, p.g, p.b), p.redgem_width / 2, p.redgem_height / 2, p.x, p.y, p.scale, p.scale, 0, 0);
}
void Points::draw_bluegem(Points& p, ALLEGRO_BITMAP* image, int curFrame, int frame_y) {
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * p.bluegem_width, frame_y * p.bluegem_height, p.bluegem_width, p.bluegem_height, al_map_rgb(p.r, p.g, p.b), p.bluegem_width / 2, p.bluegem_height / 2, p.x, p.y, p.scale, p.scale, 0, 0);
}
void Points::draw_coins(Points& c, ALLEGRO_BITMAP* image, int curFrame, int frame_y) {
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * c.coin_width, frame_y * c.coin_height, c.coin_width, c.coin_height, al_map_rgb(c.r, c.g, c.b), c.coin_width / 2, c.coin_height / 2, c.x, c.y, c.scale, c.scale, 0, 0);
}
void Points::draw_stars(Points& c, ALLEGRO_BITMAP* image, int curFrame, int frame_y) {
    al_draw_tinted_scaled_rotated_bitmap_region(image, curFrame * c.star_width, frame_y * c.star_height, c.star_width, c.star_height, al_map_rgb(c.r, c.g, c.b), c.star_width / 2, c.star_height / 2, c.x, c.y, c.scale, c.scale, 0, 0);
}