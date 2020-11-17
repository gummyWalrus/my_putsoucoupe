/*
** EPITECH PROJECT, 2020
** MyHunter
** File description:
** the style maker > John Cena
*/

#include "graf.h"

void stage1(t_all *all, sfRenderWindow *window)
{
    init_stage(all, window);
    if (!(all->souc1.isalive) && !(all->souc2.isalive)) {
        if (all->grafik->count == 7)
            all->souc1 = my_putspecial(all->spr, all->vec, all->grafik, 0);
        else
            all->souc1 = my_putsouc(all->spr, all->vec, all->grafik);
        all->souc2 = my_putsouc(all->spr, all->vec, all->grafik);
        all->grafik->n_duck = 2;
        sfSprite_setTexture(all->souc1.soucoupe, all->text->souc, sfTrue);
        sfSprite_setTexture(all->souc2.soucoupe, all->text->souc, sfTrue);
    }
    if (all->souc1.isalive == 1) {
        souc_gesture(all->tim, all->rec, &all->souc1, all->grafik);
        sfRenderWindow_drawSprite(window, all->souc1.soucoupe, NULL);
    }
    if (all->souc2.isalive == 1) {
        souc_gesture(all->tim, all->rec, &all->souc2, all->grafik);
        sfRenderWindow_drawSprite(window, all->souc2.soucoupe, NULL);
    }
}

void init_struct(t_all *all)
{
    all->spr = malloc(2048);
    all->vec = malloc(2048);
    all->rec = malloc(2048);
    all->text = malloc(4096);
    all->tim = malloc(2048);
    all->filant = malloc(2048);
    all->grafik = malloc(500);
}

void do_menu(t_all *all, sfRenderWindow *window)
{
    all->tim->menu_time = sfClock_getElapsedTime(all->tim->clock_menu);
    all->tim->menu_sec = all->tim->menu_time.microseconds / 1000;
    render_menu(all->vec, all->grafik, all->text, all->spr);
    do_render_filant(all->tim, all->spr->filant, all->filant);
    draw_menu(window, all->spr);
}

void event_handler(t_all *all, sfRenderWindow *window, sfEvent event)
{
    analyse_events(window, event, all);
    if (all->grafik->playing && all->souc1.isalive)
        soucoupe_click(&event, &all->souc1, all->grafik);
    if (all->grafik->playing && all->souc2.isalive)
        soucoupe_click(&event, &all->souc2, all->grafik);
    if (all->grafik->playing && all->souc3.isalive)
        soucoupe_click(&event, &all->souc3, all->grafik);
}

void init_all(sprites *spr, textures *text, graf *grafik, time *tim)
{
    init_sprites(spr);
    init_texture(spr, text);
    init_texture2(spr, text);
    init_game(grafik);
    init_game2(grafik);
    init_time(tim);
}