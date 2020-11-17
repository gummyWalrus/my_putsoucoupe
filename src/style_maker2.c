/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** the Style maker > John Wick
*/

#include "graf.h"
#include "my.h"

void destroy_textures(t_all *all)
{
    sfTexture_destroy(all->text->play_texture);
    sfTexture_destroy(all->text->souc);
    sfTexture_destroy(all->text->title);
    sfTexture_destroy(all->text->bg);
    sfTexture_destroy(all->text->bg_menu);
    sfTexture_destroy(all->text->hover);
    sfTexture_destroy(all->text->filant);
    sfTexture_destroy(all->text->pointer);
    sfTexture_destroy(all->text->quit);
    sfTexture_destroy(all->text->quit_hover);
    sfTexture_destroy(all->text->gameover);
    sfTexture_destroy(all->text->life);
    sfTexture_destroy(all->text->screamer);
    sfTexture_destroy(all->text->easy);
    sfTexture_destroy(all->text->medium);
    sfTexture_destroy(all->text->hard);
    sfTexture_destroy(all->text->ammo);
    sfTexture_destroy(all->text->easy_co);
    sfTexture_destroy(all->text->medium_co);
    sfTexture_destroy(all->text->hard_co);
}

void destroy_music(t_all *all)
{
    sfSoundBuffer_destroy(all->grafik->explode);
    sfSoundBuffer_destroy(all->grafik->select);
    sfSoundBuffer_destroy(all->grafik->shoot);
    sfSoundBuffer_destroy(all->grafik->empty);
    sfSoundBuffer_destroy(all->grafik->damage);
    sfSound_destroy(all->grafik->explode_sound);
    sfSound_destroy(all->grafik->select_sound);
    sfSound_destroy(all->grafik->shoot_sound);
    sfSound_destroy(all->grafik->empty_sound);
    sfSound_destroy(all->grafik->damage_sound);
}

void init_global(t_all *all, int offset)
{
    init_all(all->spr, all->text, all->grafik, all->tim);
    init_all2(all->spr, all->vec, all->rec, offset);
    init_spot(all->vec, &all->souc1, &all->souc2);
    init_filant(all->filant);
}

int render_game_over(t_all *all, sfRenderWindow *window, int flag)
{
    sfText_setPosition(all->spr->score, all->vec->medium);
    sfText_setString(all->spr->score, \
    my_strcat(my_strdup("Score : "), int_read(all->grafik->score)));
    if (all->tim->over_create == 0) {
        all->tim->clock_over = sfClock_create();
        all->tim->over_create = 1;
    }
    all->tim->over_time = sfClock_getElapsedTime(all->tim->clock_over);
    all->tim->over_sec = all->tim->over_time.microseconds / 1000000;
    if (all->tim->over_sec > 0.5) {
        flag = 1;
        if (all->grafik->hover == 1)
            sfSprite_setTexture(all->spr->quit, all->text->quit_hover, 0);
        else
            sfSprite_setTexture(all->spr->quit, all->text->quit, sfFalse);
        sfSprite_setPosition(all->spr->quit, all->vec->pos_play);
        sfRenderWindow_drawSprite(window, all->spr->quit, NULL);
        sfRenderWindow_drawText(window, all->spr->score, NULL);
    }
    return (flag);
}

void render_diff(int diff, sprites *spr, textures *text)
{
    if (diff == 0) {
        sfSprite_setTexture(spr->easy, text->easy_co, sfFalse);
        sfSprite_setTexture(spr->medium, text->medium, sfFalse);
        sfSprite_setTexture(spr->hard, text->hard, sfFalse);
    }
    if (diff == 1) {
        sfSprite_setTexture(spr->easy, text->easy, sfFalse);
        sfSprite_setTexture(spr->medium, text->medium_co, sfFalse);
        sfSprite_setTexture(spr->hard, text->hard, sfFalse);
    }
    if (diff == 2) {
        sfSprite_setTexture(spr->easy, text->easy, sfFalse);
        sfSprite_setTexture(spr->medium, text->medium, sfFalse);
        sfSprite_setTexture(spr->hard, text->hard_co, sfFalse);
    }
}