/*
** EPITECH PROJECT, 2020
** Csfml bootstrap
** File description:
** test
*/

#include "graf.h"
#include "my.h"
#include <unistd.h>
#include <stdio.h>

sfRenderWindow *create_window(int hei, int wid, char const *title)
{
    sfVideoMode m = {hei, wid, 32};
    sfRenderWindow *window = sfRenderWindow_create(m, title, sfClose, NULL);
    return (window);
}

void destroy(t_all *all, sfRenderWindow *window)
{
    destroy_textures(all);
    destroy_sprites(all);
    destroy_music(all);
    free_all(all);
    destroy_clock(all);
    sfRenderWindow_destroy(window);
}

void free_all(t_all *all)
{
    free(all->spr);
    free(all->filant);
    free(all->grafik);
    free(all->text);
    free(all->rec);
    free(all->tim);
    free(all->vec);
}

void destroy_clock(t_all *all)
{
    sfClock_destroy(all->tim->clock_anim);
    sfClock_destroy(all->tim->clock_duck);
    sfClock_destroy(all->tim->clock_filant);
    sfClock_destroy(all->tim->clock_menu);
    sfClock_destroy(all->tim->clock_up);
    sfClock_destroy(all->tim->clock_back);
    sfClock_destroy(all->tim->clock_over);
}

int main(int ac, char const **av)
{
    sfRenderWindow *window = create_window(800, 600, "myHunter");
    sfEvent event;
    int offset = 128;
    t_all all;
    int i = 0;

    while (av[i] != NULL)
        i++;
    i > 1 ? my_print_usage(av[1]) : 0;
    init_struct(&all);
    init_global(&all, offset);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window) == sfTrue)
    {
        sfRenderWindow_clear(window, sfBlack);
        ptr(window, all.spr);
        while (sfRenderWindow_pollEvent(window, &event) == sfTrue) {
            event_handler(&all, window, event);
        }
        if (all.grafik->playing == 0)
            do_menu(&all, window);
        if (all.grafik->playing == 1) {
            stage1(&all, window);
            sfRenderWindow_drawSprite(window, all.spr->ammo, NULL);
        }
        if (all.grafik->playing == 2){
            stage2(&all, window);
            sfRenderWindow_drawSprite(window, all.spr->ammo, NULL);
        }
        if (all.grafik->life <= 0) {
            all.grafik->playing = 3;
            game_over(&all, window);
        }
        sfRenderWindow_drawSprite(window, all.spr->pointer, NULL);
        sfRenderWindow_display(window);
    }
    destroy(&all, window);
    return (0);
}
