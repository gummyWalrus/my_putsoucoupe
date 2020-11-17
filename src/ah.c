/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** ah funcs
*/

#include "graf.h"

void init_bounds(sprites *spr, bounds *bounds, sfMouseButtonEvent eve)
{
    bounds->mouse.x = eve.x;
    bounds->mouse.y = eve.y;
    bounds->play = sfSprite_getGlobalBounds(spr->play);
    bounds->quit = sfSprite_getGlobalBounds(spr->quit);
    bounds->eas = sfSprite_getGlobalBounds(spr->easy);
    bounds->med = sfSprite_getGlobalBounds(spr->medium);
    bounds->har = sfSprite_getGlobalBounds(spr->hard);
    bounds->alien = sfSprite_getGlobalBounds(spr->screamer);
}

void init_spots(vectors *vec)
{
    vec->sps[0] = vec->spot1;
    vec->sps[1] = vec->spot2;
    vec->sps[2] = vec->spot3;
    vec->sps[3] = vec->spot4;
    vec->sps[4] = vec->spot5;
    vec->sps[5] = vec->spot6;
    vec->sps[6] = vec->spot7;
    vec->sps[7] = vec->spot8;
    vec->sps[8] = vec->spot9;
    vec->sps[9] = vec->spot10;
    vec->sps[10] = vec->spot11;
    vec->sps[11] = vec->spot12;
}

void init_souc(t_all *all)
{
    all->souc1 = my_putsouc(all->spr, all->vec, all->grafik);
    if (all->grafik->count == 2 || all->grafik->count == 9)
        all->souc2 = my_putspecial(all->spr, all->vec, all->grafik, 1);
    else if (all->grafik->count == 11 || all->grafik->count == 5)
        all->souc2 = my_putspecial(all->spr, all->vec, all->grafik, 2);
    else
        all->souc2 = my_putsouc(all->spr, all->vec, all->grafik);
    if (all->grafik->count == 7 || all->grafik->count == 1)
        all->souc3 = my_putspecial(all->spr, all->vec, all->grafik, 0);
    else
        all->souc3 = my_putsouc(all->spr, all->vec, all->grafik);
}

void init_souc2(t_all *all)
{
    all->souc1 = my_putsouc(all->spr, all->vec, all->grafik);
    if (all->grafik->count == 2)
        all->souc3 = my_putspecial(all->spr, all->vec, all->grafik, 1);
    else
        all->souc2 = my_putsouc(all->spr, all->vec, all->grafik);
    if (all->grafik->count == 7)
        all->souc3 = my_putspecial(all->spr, all->vec, all->grafik, 0);
    else
        all->souc3 = my_putsouc(all->spr, all->vec, all->grafik);
}

soucoupe my_putspecial(sprites *spr, vectors *vec, graf *g, int type)
{
    soucoupe souc;
    sfColor colors[3] = {sfRed, sfMagenta, sfCyan};
    souc.soucoupe = sfSprite_copy(spr->duck);
    for (int i = 0; i < 12; i++)
    {
        g->count == i+1 ? sfSprite_setPosition(souc.soucoupe, vec->sps[i]) : 0;
    }
    souc.spot = g->count;
    souc.isalive = 1;
    souc.type = type;
    sfSprite_setColor(souc.soucoupe, colors[type]);
    (souc.type == 1) ? (souc.hp = 2) : (souc.hp = 1);
    (g->count >= 12) ? (g->count = 1) : (g->count++);
    return (souc);
}