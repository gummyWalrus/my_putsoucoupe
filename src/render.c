/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** render funcs
*/
#include "graf.h"
#include "my.h"

void init_filant(filanvec *vec)
{
    vec->vec1.x = 850;
    vec->vec1.y = 10;
    vec->vec2.x = 850;
    vec->vec2.y = 20;
    vec->vec3.x = 850;
    vec->vec3.y = 100;
    vec->vec4.x = 850;
    vec->vec4.y = 400;
    vec->vec5.x = 850;
    vec->vec5.y = 200;
}

void render_menu(vectors *vec, graf *grafik, textures *text, sprites *spr)
{
    if (grafik->hover == 1)
        sfSprite_setTexture(spr->play, text->hover, sfFalse);
    else
        sfSprite_setTexture(spr->play, text->play_texture, sfFalse);
    render_diff(grafik->difficulty, spr, text);
    if (grafik->music == 0) {
        grafik->music = 1;
    }
    sfSprite_setPosition(spr->play, vec->pos_play);
    sfSprite_setPosition(spr->title, vec->title);
}

void render_filant(time *tim, filanvec *vecs, sfSprite *sprite)
{
    tim->filant_time = sfClock_getElapsedTime(tim->clock_filant);
    tim->filant_sec = tim->filant_time.microseconds / 1000;
    if (tim->filant_sec > 10) {
        vecs->vec1.x = vecs->vec1.x - 10;
        vecs->vec1.y = vecs->vec1.y + vecs->vec1.y / 20;
        sfSprite_setPosition(sprite, vecs->vec1);
        sfClock_restart(tim->clock_filant);
    }
}

void render_filant1(time *tim, filanvec *vecs, sfSprite *sprite)
{
    tim->filant_time = sfClock_getElapsedTime(tim->clock_filant);
    tim->filant_sec = tim->filant_time.microseconds / 1000;
    if (tim->filant_sec > 10) {
        vecs->vec2.x = vecs->vec2.x - 10;
        vecs->vec2.y = vecs->vec2.y + vecs->vec2.y / 20;
        sfSprite_setPosition(sprite, vecs->vec2);
        sfClock_restart(tim->clock_filant);
    }
}

void render_filant2(time *tim, filanvec *vecs, sfSprite *sprite)
{
    tim->filant_time = sfClock_getElapsedTime(tim->clock_filant);
    tim->filant_sec = tim->filant_time.microseconds / 1000;
    if (tim->filant_sec > 10) {
        vecs->vec3.x = vecs->vec3.x - 10;
        vecs->vec3.y = vecs->vec3.y + vecs->vec3.y / 20;
        sfSprite_setPosition(sprite, vecs->vec3);
        sfClock_restart(tim->clock_filant);
    }
}