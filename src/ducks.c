/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** ducks funcs
*/

#include "graf.h"
#include "my.h"
#include <unistd.h>
#include <stdio.h>

void move_duck(soucoupe *souc, float speed, char direction, graf *g)
{
    sfVector2f pos = sfSprite_getPosition(souc->soucoupe);
    if (direction == 'd') {
        pos.x += speed;
        pos.y += speed / 10.0;
        sfSprite_setPosition(souc->soucoupe, pos);
    }
    if (direction == 'h') {
        pos.x += speed;
        pos.y -= speed / 10.0;
        sfSprite_setPosition(souc->soucoupe, pos);
    }
    if (pos.x > 800)
    {
        g->life -= 1;
        souc->isalive = 0;
        sfSound_play(g->damage_sound);
    }
}

void move_back(time *tim, soucoupe *souc, float speed, graf *g)
{
        tim->back_time = sfClock_getElapsedTime(tim->clock_back);
        tim->back_sec = tim->back_time.microseconds / 1000000;
        sfVector2f pos = sfSprite_getPosition(souc->soucoupe);
        if (tim->back_sec > 0.8) {
            pos.x -= speed;
            pos.y -= speed / 10.0;
            sfSprite_setPosition(souc->soucoupe, pos);
        }
        else {
            pos.x -= speed;
            pos.y += speed / 10.0;
            sfSprite_setPosition(souc->soucoupe, pos);
        }
        if (tim->back_sec > 1.6)
            sfClock_restart(tim->clock_up);
        if (pos.x < -128) {
            g->life -= 1;
            souc->isalive = 0;
            sfSound_play(g->damage_sound);
        }
}

void souc_gesture(time *tim, rects *rec, soucoupe *souc, graf *g)
{
    int offset = 128;
    int spot = souc->spot;
    sfSprite_setTextureRect(souc->soucoupe, rec->rect);
    if (tim->milisec > 100.0) {
        move_rect(&rec->rect, offset * 6, offset);
        sfSprite_setTextureRect(souc->soucoupe, rec->rect);
        sfClock_restart(tim->clock_anim);
    }
    if (tim->duck_sec > 0.8 && (spot == 1 || spot == 5 || spot == 6))
        move_duck(souc, g->speed, 'h', g);
    else if (tim->duck_sec < 0.8 && (spot == 1 || spot == 5 || spot == 6))
        move_duck(souc, g->speed, 'd', g);
    if (tim->duck_sec > 1.6)
        sfClock_restart(tim->clock_duck);
    if (spot == 2 || spot == 3)
        move_up(tim, souc, g->speed, g);
    if (spot == 4 || spot == 11 || spot == 12)
        move_back(tim, souc, g->speed, g);
    if (spot > 6 && spot < 11)
        move_special(souc, g, 2.0);
}

void move_up(time *tim, soucoupe *souc, float speed, graf *g)
{
        tim->up_time = sfClock_getElapsedTime(tim->clock_up);
        tim->up_sec = tim->up_time.microseconds / 1000000;
        sfVector2f pos = sfSprite_getPosition(souc->soucoupe);
        if (tim->up_sec > 0.8) {
            pos.x += speed / 10.0;
            pos.y -= speed;
            sfSprite_setPosition(souc->soucoupe, pos);
        }
        else {
            pos.x -= speed / 10.0;
            pos.y -= speed;
            sfSprite_setPosition(souc->soucoupe, pos);
        }
        if (tim->up_sec > 1.6)
            sfClock_restart(tim->clock_up);
        if (pos.y < -50) {
            g->life -= 1;
            souc->isalive = 0;
            sfSound_play(g->damage_sound);
        }
}

void move_special(soucoupe *souc, graf *g, float speed)
{
    int spot = souc->spot;
    sfVector2f pos = sfSprite_getPosition(souc->soucoupe);
    switch(spot) {
        case 7:
            case7(&pos, souc, speed, g);
            sfSprite_setPosition(souc->soucoupe, pos);
            break;
        case 8:
            case8(&pos, souc, speed, g);
            sfSprite_setPosition(souc->soucoupe, pos);
            break;
        case 9:
            case9(&pos, souc, speed, g);
            sfSprite_setPosition(souc->soucoupe, pos);
            break;
        case 10:
            case10(&pos, souc, speed, g);
            sfSprite_setPosition(souc->soucoupe, pos);
            break;
    }
}