/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** funcs
*/

#include "graf.h"

void case7(sfVector2f *pos, soucoupe *souc, float speed, graf *g)
{
    pos->x = pos->x - speed;
    pos->y = pos->y - (pos->y / 20);
    if (pos->x < -128) {
        g->life -= 1;
        souc->isalive = 0;
        sfSound_play(g->damage_sound);
    }
}

void case8(sfVector2f *pos, soucoupe *souc, float speed, graf *g)
{
    pos->x = pos->x + speed;
    pos->y = pos->y - (pos->y / 20);
    if (pos->x > 800) {
        g->life -= 1;
        souc->isalive = 0;
        sfSound_play(g->damage_sound);
    }
}

void case9(sfVector2f *pos, soucoupe *souc, float speed, graf *g)
{
    if (pos->y < 300)
        pos->y = pos->y + speed;
    else
        pos->x = pos->x - speed;
    if (pos->x < -128) {
        g->life -= 1;
        souc->isalive = 0;
        sfSound_play(g->damage_sound);
    }
}

void case10(sfVector2f *pos, soucoupe *souc, float speed, graf *g)
{
    if (pos->y < 300)
        pos->y = pos->y + speed;
    else
        pos->x = pos->x + speed;
    if (pos->x > 800) {
        g->life -= 1;
        souc->isalive = 0;
        sfSound_play(g->damage_sound);
    }
}

void destroy_sprites(t_all *all)
{
    sfSprite_destroy(all->spr->duck);
    sfSprite_destroy(all->spr->play);
    sfSprite_destroy(all->spr->title);
    sfSprite_destroy(all->spr->bg);
    sfSprite_destroy(all->spr->bg_menu);
    sfSprite_destroy(all->spr->filant);
    sfSprite_destroy(all->souc1.soucoupe);
    sfSprite_destroy(all->souc2.soucoupe);
    sfSprite_destroy(all->spr->pointer);
    sfSprite_destroy(all->spr->screamer);
    sfSprite_destroy(all->spr->easy);
    sfSprite_destroy(all->spr->medium);
    sfSprite_destroy(all->spr->hard);
    sfSprite_destroy(all->spr->ammo);
    sfText_destroy(all->spr->score);
    sfFont_destroy(all->spr->font);
}