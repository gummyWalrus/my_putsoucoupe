/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** div funcs
*/

#include "graf.h"
#include "my.h"

void manage_ammo(graf *grafik)
{
    if (grafik->ammo > 0)
        grafik->ammo--;
    else
        sfSound_play(grafik->empty_sound);
}

void render_ammo(graf *g, sprites *spr, t_all *all)
{
    sfIntRect rect;
    rect.height = 64;
    rect.top = 0;
    rect.width = 128;
    g->ammo > 6 ? g->ammo -= 2 : 0;
    g->ammo == 6 ? rect.left = 0 : (0);
    g->ammo == 5 ? rect.left = 128 : (0);
    g->ammo == 4 ? rect.left = 256 : (0);
    g->ammo == 3 ? rect.left = 384 : (0);
    g->ammo == 2 ? rect.left = 512 : (0);
    g->ammo == 1 ? rect.left = 640 : (0);
    g->ammo == 0 ? rect.left = 768 : (0);
    sfSprite_setPosition(spr->ammo, all->vec->ammo);
    sfSprite_setTextureRect(spr->ammo, rect);
}

void init_game2(graf *grafik)
{
    grafik->empty = sfSoundBuffer_createFromFile("assets/sound/empty.wav");
    grafik->empty_sound = sfSound_create();
    sfSound_setBuffer(grafik->empty_sound, grafik->empty);
    grafik->damage = sfSoundBuffer_createFromFile("assets/sound/damage.wav");
    grafik->damage_sound = sfSound_create();
    sfSound_setBuffer(grafik->damage_sound, grafik->damage);
    grafik->heal = sfSoundBuffer_createFromFile("assets/sound/heal.wav");
    grafik->heal_sound = sfSound_create();
    sfSound_setBuffer(grafik->heal_sound, grafik->heal);
    grafik->ufo = sfSoundBuffer_createFromFile("assets/sound/ufo.wav");
    grafik->ufo_sound = sfSound_create();
    sfSound_setBuffer(grafik->ufo_sound, grafik->ufo);
}

void init_stage(t_all *all, sfRenderWindow *window)
{
    sfSprite_setPosition(all->spr->play, all->vec->spot4);
    sfSprite_setPosition(all->spr->quit, all->vec->spot4);
    update_hp(all->rec, all->grafik, all->spr, all->vec);
    update_stage(all->tim, all->spr, window);
    render_ammo(all->grafik, all->spr, all);
    sfText_setString(all->spr->score, int_read(all->grafik->score));
    sfRenderWindow_drawText(window, all->spr->score, NULL);
    play_ufo(all);
}

void set_stage(t_all *all)
{
    all->grafik->n_duck = 2;
    sfSprite_setTexture(all->souc1.soucoupe, all->text->souc, sfTrue);
    sfSprite_setTexture(all->souc2.soucoupe, all->text->souc, sfTrue);
    sfSprite_setTexture(all->souc3.soucoupe, all->text->souc, sfTrue);
}