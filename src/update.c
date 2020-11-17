/*
** EPITECH PROJECT, 2020
** myhunter update funcs
** File description:
** update
*/

#include "graf.h"

void update_stage(time *tim, sprites *spr, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, spr->bg, NULL);
    sfRenderWindow_drawSprite(window, spr->life, NULL);
    tim->time = sfClock_getElapsedTime(tim->clock_anim);
    tim->duck_time = sfClock_getElapsedTime(tim->clock_duck);
    tim->duck_sec = tim->duck_time.microseconds / 1000000.0;
    tim->milisec = tim->time.microseconds / 1000.0;
}

void update_hp(rects *rec, graf *g, sprites *spr, vectors *vec)
{
    sfSprite_setPosition(spr->easy, vec->spot4);
    sfSprite_setPosition(spr->medium, vec->spot4);
    sfSprite_setPosition(spr->hard, vec->spot4);
    if (g->life == 1)
        rec->life.width = 33;
    if (g->life == 2)
        rec->life.width = 66;
    if (g->life == 3)
        rec->life.width = 100;
    if (g->life == 0)
        rec->life.width = 0;
    sfSprite_setTextureRect(spr->life, rec->life);
}

void init_all2(sprites *spr, vectors *vec, rects *rec, int offset)
{
    init_vector(vec, spr);
    init_vector2(vec, spr);
    init_spots(vec);
    init_rect(spr, rec, offset);
}

void init_spot(vectors *vec, soucoupe *souc1, soucoupe *souc2)
{
    vec->spot5.x = -150;
    vec->spot5.y = 250;
    vec->spot6.x = -150;
    vec->spot6.y = 450;
    vec->spot7.x = 350.0;
    vec->spot7.y = 601.0;
    vec->spot8.x = 350;
    vec->spot8.y = 601;
    vec->spot9.x = 350;
    vec->spot9.y = 0;
    vec->spot10.x = 450;
    vec->spot10.y = 0;
    vec->spot11.x = 801;
    vec->spot11.y = 250;
    vec->spot12.x = 801;
    vec->spot12.y = 450;
    vec->pos_alien.x = 200;
    vec->pos_alien.y = 601;
    souc1->isalive = 0;
    souc2->isalive = 0;
}

soucoupe my_putsouc(sprites *spr, vectors *vec, graf *g)
{
    soucoupe souc;

    g->ammo += 1;
    souc.soucoupe = sfSprite_copy(spr->duck);
    for (int i = 0; i < 12; i++)
    {
        g->count == i+1 ? sfSprite_setPosition(souc.soucoupe, vec->sps[i]) : 0;
    }
    souc.spot = g->count;
    souc.isalive = 1;
    souc.type = 5;
    (g->count >= 12) ? (g->count = 1) : (g->count++);
    return (souc);
}