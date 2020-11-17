/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** game funcs
*/

#include "my.h"
#include "graf.h"

void init_sprites(sprites *sprites)
{
    sprites->duck = sfSprite_create();
    sprites->play = sfSprite_create();
    sprites->title = sfSprite_create();
    sprites->bg = sfSprite_create();
    sprites->bg_menu = sfSprite_create();
    sprites->filant = sfSprite_create();
    sprites->pointer = sfSprite_create();
    sprites->life = sfSprite_create();
    sprites->screamer = sfSprite_create();
    sprites->quit = sfSprite_create();
    sprites->gameover = sfSprite_create();
    sprites->easy = sfSprite_create();
    sprites->medium = sfSprite_create();
    sprites->hard = sfSprite_create();
    sprites->ammo = sfSprite_create();
    sprites->score = sfText_create();
    sprites->font = sfFont_createFromFile("assets/font.ttf");
    sfText_setFont(sprites->score, sprites->font);
    sfText_setColor(sprites->score, sfRed);
    sfText_setCharacterSize(sprites->score, 30);
}

void init_game(graf *grafik)
{
    grafik->playing = 0;
    grafik->difficulty = 1;
    grafik->hover = 0;
    grafik->n_duck = 0;
    grafik->n_kill = 0;
    grafik->life = 3;
    grafik->music = 0;
    grafik->played = 0;
    grafik->speed = 5.0;
    grafik->shoot = sfSoundBuffer_createFromFile("assets/sound/shoo.wav");
    grafik->explode = sfSoundBuffer_createFromFile("assets/sound/expode.wav");
    grafik->select = sfSoundBuffer_createFromFile("assets/sound/select.wav");
    grafik->select_sound = sfSound_create();
    grafik->shoot_sound = sfSound_create();
    grafik->explode_sound = sfSound_create();
    sfSound_setBuffer(grafik->select_sound, grafik->select);
    sfSound_setBuffer(grafik->shoot_sound, grafik->shoot);
    sfSound_setBuffer(grafik->explode_sound, grafik->explode);
}

void launch_game(t_all *all)
{
    init_spot(all->vec, &all->souc1, &all->souc2);
    init_spots(all->vec);
    all->grafik->playing = 1;
    all->grafik->stage = 1;
    all->grafik->count = 1;
    all->grafik->playing_over = 0;
    all->grafik->score = 0;
    all->grafik->ammo = 4;
    sfSound_play(all->grafik->ufo_sound);
    if (all->grafik->difficulty == 0)
        all->grafik->speed = 3.0;
    else if (all->grafik->difficulty == 1)
        all->grafik->speed = 5.0;
    else {
        all->grafik->speed = 5.0;
        all->grafik->life = 1;
    }
}

void analyse_events(sfRenderWindow *window, sfEvent eve, t_all *all)
{
    switch (eve.type)
    {
    case sfEvtClosed:
        sfRenderWindow_close(window);
        break;
    case sfEvtMouseButtonPressed:
        manage_mouse_click(eve.mouseButton, all);
        break;
    case sfEvtMouseMoved:
        manage_mouse_move(eve.mouseMove, all->spr, all->grafik);
        break;
    default:
        break;
    }
}

void move_rect(sfIntRect *rect, int max_v, int offset)
{
    rect->left = 0;
    rect->width = offset;
    rect->height = offset;
    if (rect->top + offset < max_v)
        rect->top = rect->top + offset;
    else
        rect->top = 0;
}