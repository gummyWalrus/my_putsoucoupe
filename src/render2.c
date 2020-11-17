/*
** EPITECH PROJECT, 2020
** myHunter
** File description:
** render funcs 2
*/

#include "graf.h"
#include "my.h"

void do_render_filant(time *tim, sfSprite *spr, filanvec *filant)
{
    if (tim->menu_sec > 100 && tim->menu_sec < 2000)
        render_filant(tim, filant, spr);
    if (tim->menu_sec > 2000 && tim->menu_sec < 4000)
        render_filant1(tim, filant, spr);
    if (tim->menu_sec > 4000 && tim->menu_sec < 6000)
        render_filant2(tim, filant, spr);
    if (tim->menu_sec > 6000) {
        init_filant(filant);
        sfClock_restart(tim->clock_menu);
    }
}

void draw_menu(sfRenderWindow *window, sprites *spr)
{
    sfRenderWindow_drawSprite(window, spr->bg_menu, NULL);
    sfRenderWindow_drawSprite(window, spr->filant, NULL);
    sfRenderWindow_drawSprite(window, spr->play, NULL);
    sfRenderWindow_drawSprite(window, spr->title, NULL);
    sfRenderWindow_drawSprite(window, spr->easy, NULL);
    sfRenderWindow_drawSprite(window, spr->medium, NULL);
    sfRenderWindow_drawSprite(window, spr->hard, NULL);
    sfRenderWindow_drawSprite(window, spr->pointer, NULL);
}

void ptr(sfRenderWindow *window, sprites *spr)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    sfVector2f mouse_f;
    float temp;

    temp = (float)mouse.x / 3;
    temp *= 3;
    mouse_f.x = temp;
    temp = (float)mouse.y / 3;
    temp *= 3;
    mouse_f.y = temp;
    sfSprite_setPosition(spr->pointer, mouse_f);
}

void game_over(t_all *all, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(all->spr->screamer);
    int fla;
    sfSprite_setPosition(all->spr->gameover, all->vec->title);
    sfRenderWindow_drawSprite(window, all->spr->bg_menu, NULL);
    if (pos.y > -800.0) {
        fla = 0;
        pos.y -= 5.0;
        sfSprite_setPosition(all->spr->screamer, pos);
    }
    if (pos.y <= 50.0) {
        fla = render_game_over(all, window, fla);
    }
    fla == 0 ? sfRenderWindow_drawSprite(window, all->spr->screamer, NULL) : 0;
    sfRenderWindow_drawSprite(window, all->spr->gameover, NULL);
}

void my_print_usage(char const *str)
{
    if (str[0] == '-' && str[1] == 'h')
    {
        my_putstr("DESCRIPTION\n");
        my_putstr("    Yet another my_hunter project.\n");
        my_putstr("    The my_hunter project is a game were you can \n");
        my_putstr("    hunt ducks by shooting them using the mouse.\n");
        my_putstr("    It is inspired from a NES game called 'Duck Hunt'.\n");
        my_putstr("INPUTS\n");
        my_putstr("    Only the mouse can be used to interact.\n");
        my_putstr("NOTE\n");
        my_putstr("    this version has special enemies, red enemies will\n");
        my_putstr("    heal you of 1 heart when killed, green ones will\n");
        my_putstr("    give you 1 ammo and the purple ones take 2 shots\n");
        my_putstr("     die but worth 25 points.\n");
    }
}