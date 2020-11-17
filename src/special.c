/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** special funcs
*/

#include "graf.h"

void classic_type(graf *g, soucoupe *souc)
{
    sfSound_play(g->explode_sound);
    g->score += 10;
    g->n_kill++;
    souc->isalive = 0;
    g->n_duck--;
    souc->type == 0 && g->life < 3 ? g->life++ : (0);
    souc->type == 0 && g->life < 3 ? sfSound_play(g->heal_sound) : (0);
    souc->type == 2 && g->ammo <= 4 ? g->ammo += 2 : (0);
    souc->type == 0 && g->ammo < 6 ? sfSound_play(g->empty_sound) : (0);
    souc->type == 2 && g->ammo == 5 ? g->ammo += 1 : (0);
}

void armor_type(graf *g, soucoupe *souc)
{
    souc->hp--;
    if (souc->hp == 0) {
        sfSound_play(g->explode_sound);
        g->score += 25;
        g->n_kill++;
        souc->isalive = 0;
        g->n_duck--;
    }
}

void play_ufo(t_all *all)
{
    if (all->grafik->playing > 0 && all->grafik->playing < 3) {
        all->tim->ufo_time = sfClock_getElapsedTime(all->tim->clock_ufo);
        all->tim->ufo_sec = all->tim->ufo_time.microseconds / 1000000.0;
        if (all->tim->ufo_sec > 6.0)
        {
            sfSound_play(all->grafik->ufo_sound);
            sfClock_restart(all->tim->clock_ufo);
        }
    }
}