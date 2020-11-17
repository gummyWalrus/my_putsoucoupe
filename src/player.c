/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** player funcs
*/

#include "my.h"
#include "graf.h"

void manage_mouse_click(sfMouseButtonEvent event, t_all *all)
{
    bounds b;
    graf *g = all->grafik;
    init_bounds(all->spr, &b, event);
    all->grafik->ammo > 0 ? sfSound_play(all->grafik->shoot_sound) : \
    sfSound_play(all->grafik->empty_sound);
    manage_ammo(all->grafik);
    sfFloatRect_contains(&b.eas, event.x, event.y) ? g->difficulty = 0 : 0;
    sfFloatRect_contains(&b.med, event.x, event.y) ? g->difficulty = 1 : 0;
    sfFloatRect_contains(&b.har, event.x, event.y) ? g->difficulty = 2 : 0;
    if (sfFloatRect_contains(&b.play, event.x, event.y))
        launch_game(all);
    if (sfFloatRect_contains(&b.quit, event.x, event.y)) {
        free_all(all);
        init_struct(all);
        init_global(all, 128);
    }
}

void manage_mouse_move(sfMouseMoveEvent event, sprites *spr, graf *g)
{
    sfFloatRect bplay = sfSprite_getGlobalBounds(spr->play);
    sfFloatRect bquit = sfSprite_getGlobalBounds(spr->quit);

    if (sfFloatRect_contains(&bplay, event.x, event.y)
    || sfFloatRect_contains(&bquit, event.x, event.y)) {
        g->hover = 1;
        (g->played == 0) ? (sfSound_play(g->select_sound)) : (0);
        g->played = 1;
    }
    else {
        g->hover = 0;
        g->played = 0;
    }
    if (g->score == 100)
        g->playing = 2;
}

void soucoupe_click(sfEvent *event, soucoupe *souc, graf *g)
{
    sfMouseButtonEvent eve = event->mouseButton;
    sfFloatRect bsouc = sfSprite_getGlobalBounds(souc->soucoupe);

    if (event->type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&bsouc, eve.x, eve.y) && g->ammo > 0
        && souc->type != 1) {
            classic_type(g, souc);
        }
        else if (sfFloatRect_contains(&bsouc, eve.x, eve.y) && g->ammo > 0
        && souc->type == 1) {
            armor_type(g, souc);
        }
    }
}

void init_vector2(vectors *vec, sprites *spr)
{
    vec->easy.x = 200;
    vec->easy.y = 450;
    vec->medium.x = 350;
    vec->medium.y = 450;
    vec->hard.x = 500;
    vec->hard.y = 450;
    vec->ammo.x = 650;
    vec->ammo.y = 550;
    sfSprite_setPosition(spr->ammo, vec->ammo);
    sfSprite_setPosition(spr->easy, vec->easy);
    sfSprite_setPosition(spr->medium, vec->medium);
    sfSprite_setPosition(spr->hard, vec->hard);
    sfSprite_setPosition(spr->screamer, vec->pos_alien);
}

void stage2(t_all *all, sfRenderWindow *window)
{
    init_stage(all, window);
    if (!(all->souc1.isalive) && !(all->souc2.isalive)
    && !(all->souc3.isalive)) {
        init_souc(all);
        set_stage(all);
    }
    if (all->souc1.isalive == 1) {
        souc_gesture(all->tim, all->rec, &all->souc1, all->grafik);
        sfRenderWindow_drawSprite(window, all->souc1.soucoupe, NULL);
    }
    if (all->souc2.isalive == 1) {
        souc_gesture(all->tim, all->rec, &all->souc2, all->grafik);
        sfRenderWindow_drawSprite(window, all->souc2.soucoupe, NULL);
    }
    if (all->souc3.isalive == 1) {
        souc_gesture(all->tim, all->rec, &all->souc3, all->grafik);
        sfRenderWindow_drawSprite(window, all->souc3.soucoupe, NULL);
    }
}