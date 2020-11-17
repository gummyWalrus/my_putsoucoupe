/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** init funcs
*/

#include "graf.h"

void init_texture(sprites *spr, textures *text)
{
    text->souc = sfTexture_createFromFile("assets/soucoupe.png", NULL);
    text->play_texture = sfTexture_createFromFile("assets/play.png", NULL);
    text->hover = sfTexture_createFromFile("assets/play2.png", NULL);
    text->title = sfTexture_createFromFile("assets/title.png", NULL);
    text->bg = sfTexture_createFromFile("assets/bg.jpg", NULL);
    text->bg_menu = sfTexture_createFromFile("assets/bg_menu.jpg", NULL);
    text->filant = sfTexture_createFromFile("assets/filante.png", NULL);
    text->pointer = sfTexture_createFromFile("assets/point.png", NULL);
    text->life = sfTexture_createFromFile("assets/heart.png", NULL);
    text->screamer = sfTexture_createFromFile("assets/ovni.png", NULL);
    sfSprite_setTexture(spr->play, text->play_texture, sfTrue);
    sfSprite_setTexture(spr->play, text->play_texture, sfTrue);
    sfSprite_setTexture(spr->pointer, text->pointer, sfTrue);
    sfSprite_setTexture(spr->title, text->title, sfTrue);
    sfSprite_setTexture(spr->bg, text->bg, sfTrue);
    sfSprite_setTexture(spr->bg_menu, text->bg_menu, sfTrue);
    sfSprite_setTexture(spr->filant, text->filant, sfTrue);
    sfSprite_setTexture(spr->life, text->life, sfTrue);
    sfSprite_setTexture(spr->screamer, text->screamer, sfTrue);
}

void init_texture2(sprites *spr, textures *text)
{
    text->quit = sfTexture_createFromFile("assets/quit.png", NULL);
    text->quit_hover = sfTexture_createFromFile("assets/quit_hover.png", NULL);
    text->gameover = sfTexture_createFromFile("assets/gameover.png", NULL);
    text->easy = sfTexture_createFromFile("assets/easy.png", NULL);
    text->medium = sfTexture_createFromFile("assets/medium.png", NULL);
    text->hard = sfTexture_createFromFile("assets/hard.png", NULL);
    text->easy_co = sfTexture_createFromFile("assets/easy_co.png", NULL);
    text->medium_co = sfTexture_createFromFile("assets/medium_co.png", NULL);
    text->hard_co = sfTexture_createFromFile("assets/hard_co.png", NULL);
    text->ammo = sfTexture_createFromFile("assets/ammo.png", NULL);
    sfSprite_setTexture(spr->ammo, text->ammo, sfTrue);
    sfSprite_setTexture(spr->gameover, text->gameover, sfTrue);
    sfSprite_setTexture(spr->quit, text->quit, sfTrue);
    sfSprite_setTexture(spr->easy, text->easy, sfTrue);
    sfSprite_setTexture(spr->medium, text->medium, sfTrue);
    sfSprite_setTexture(spr->hard, text->hard, sfTrue);
}

void init_time(time *tim)
{
    tim->clock_anim = sfClock_create();
    tim->clock_duck = sfClock_create();
    tim->clock_filant = sfClock_create();
    tim->clock_menu = sfClock_create();
    tim->clock_up = sfClock_create();
    tim->clock_back = sfClock_create();
    tim->clock_ufo = sfClock_create();
    tim->over_create = 0;
}

void init_vector(vectors *vec, sprites *spr)
{
    vec->pos_play.x = 360;
    vec->pos_play.y = 250;
    vec->duck_scale.x = 0.7f;
    vec->duck_scale.y = 0.7f;
    vec->spot1.x = -150;
    vec->spot1.y = 100;
    vec->spot2.x = 150;
    vec->spot2.y = 601;
    vec->spot3.x = 650;
    vec->spot3.y = 601;
    vec->spot4.x = 801;
    vec->spot4.y = 100;
    vec->title.x = 150;
    vec->title.y = 50;
    vec->life.x = 50;
    vec->life.y = 550;
    sfSprite_setScale(spr->duck, vec->duck_scale);
    sfSprite_setScale(spr->filant, vec->duck_scale);
    sfSprite_setPosition(spr->life, vec->life);
}

void init_rect(sprites *spr, rects *rec, int offset)
{
    rec->rect.top = 0;
    rec->rect.left = 0;
    rec->rect.width = offset;
    rec->rect.height = offset;
    rec->life.top = 0;
    rec->life.left = 0;
    rec->life.width = 100;
    rec->life.height = 41;
    sfSprite_setTextureRect(spr->duck, rec->rect);
    sfSprite_setTextureRect(spr->life, rec->life);
}