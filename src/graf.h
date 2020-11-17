/*
** EPITECH PROJECT, 2020
** bootstrap Graphical Prog
** File description:
** include for grafik
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>

typedef	struct s_my_framebuffer
{
    sfUint8 *pixels;
    int height;
    int width;
}t_my_framebuffer;

typedef struct
{
    sfSprite *duck;
    sfSprite *play;
    sfSprite *title;
    sfSprite *bg;
    sfSprite *bg_menu;
    sfSprite *filant;
    sfSprite *pointer;
    sfSprite *life;
    sfSprite *screamer;
    sfSprite *quit;
    sfSprite *gameover;
    sfSprite *easy;
    sfSprite *medium;
    sfSprite *hard;
    sfSprite *ammo;
    sfText *score;
    sfFont *font;
}sprites;

typedef struct
{
    int playing;
    int hover;
    int stage;
    int n_duck;
    int n_kill;
    int life;
    int count;
    int music;
    int played;
    int playing_over;
    int difficulty;
    int ammo;
    int score;
    float speed;
    sfSoundBuffer *shoot;
    sfSoundBuffer *select;
    sfSoundBuffer *explode;
    sfSoundBuffer *empty;
    sfSoundBuffer *damage;
    sfSoundBuffer *heal;
    sfSoundBuffer *ufo;
    sfSound *shoot_sound;
    sfSound *select_sound;
    sfSound *explode_sound;
    sfSound *empty_sound;
    sfSound *damage_sound;
    sfSound *heal_sound;
    sfSound *ufo_sound;
}graf;

typedef struct
{
    sfTexture *souc;
    sfTexture *play_texture;
    sfTexture *title;
    sfTexture *bg;
    sfTexture *hover;
    sfTexture *bg_menu;
    sfTexture *filant;
    sfTexture *pointer;
    sfTexture *life;
    sfTexture *screamer;
    sfTexture *quit;
    sfTexture *quit_hover;
    sfTexture *gameover;
    sfTexture *easy;
    sfTexture *medium;
    sfTexture *hard;
    sfTexture *easy_co;
    sfTexture *medium_co;
    sfTexture *hard_co;
    sfTexture *ammo;
}textures;

typedef struct
{
    sfClock *clock_anim;
    sfClock *clock_duck;
    sfClock *clock_filant;
    sfClock *clock_menu;
    sfClock *clock_up;
    sfClock *clock_back;
    sfClock *clock_over;
    sfClock *clock_ufo;
    sfTime over_time;
    sfTime time;
    sfTime duck_time;
    sfTime filant_time;
    sfTime menu_time;
    sfTime up_time;
    sfTime back_time;
    sfTime ufo_time;
    float over_sec;
    float menu_sec;
    float filant_sec;
    float milisec;
    float duck_sec;
    float up_sec;
    float back_sec;
    float ufo_sec;
    int over_create;
}time;

typedef struct
{
    sfVector2f duck_scale;
    sfVector2f filant_scale;
    sfVector2f pos_play;
    sfVector2f spot1;
    sfVector2f spot2;
    sfVector2f spot3;
    sfVector2f spot4;
    sfVector2f spot5;
    sfVector2f spot6;
    sfVector2f spot7;
    sfVector2f spot8;
    sfVector2f spot9;
    sfVector2f spot10;
    sfVector2f spot11;
    sfVector2f spot12;
    sfVector2f title;
    sfVector2f mouse;
    sfVector2f life;
    sfVector2f pos_alien;
    sfVector2f easy;
    sfVector2f medium;
    sfVector2f hard;
    sfVector2f ammo;
    sfVector2f sps[12];
}vectors;

typedef struct
{
    sfIntRect rect;
    sfIntRect life;
}rects;

typedef struct
{
    sfSprite *soucoupe;
    int isalive;
    int spot;
    int type;
    int hp;
}soucoupe;

typedef struct
{
    sfVector2f vec1;
    sfVector2f vec2;
    sfVector2f vec3;
    sfVector2f vec4;
    sfVector2f vec5;

}filanvec;

typedef struct s_all
{
    sprites *spr;
    graf *grafik;
    textures *text;
    time *tim;
    vectors *vec;
    rects *rec;
    filanvec *filant;
    soucoupe souc1;
    soucoupe souc2;
    soucoupe souc3;
}t_all;
typedef struct
{
    sfFloatRect play;
    sfFloatRect quit;
    sfFloatRect eas;
    sfFloatRect har;
    sfFloatRect med;
    sfFloatRect alien;
    sfVector2f mouse;
}bounds;

void launch_game(t_all *);
void my_print_usage(char const *str);
void event_handler(t_all *, sfRenderWindow *, sfEvent);
void analyse_events(sfRenderWindow *, sfEvent, t_all *);
void soucoupe_click(sfEvent *, soucoupe *, graf *);
void manage_mouse_click(sfMouseButtonEvent, t_all *);
void manage_mouse_move(sfMouseMoveEvent, sprites *, graf *);
void manage_ammo(graf *);
void init_bounds(sprites *, bounds *, sfMouseButtonEvent);
void init_game(graf *);
void init_game2(graf *);
void init_struct(t_all *);
void init_stage(t_all *, sfRenderWindow *);
void init_global(t_all *, int);
void init_sprites(sprites *);
void init_texture(sprites *, textures *);
void init_texture2(sprites *, textures *);
void init_time(time *);
void init_vector(vectors *, sprites *);
void init_vector2(vectors *, sprites *);
void init_rect(sprites *, rects *, int);
void init_filant(filanvec *);
void init_spot(vectors *, soucoupe *, soucoupe *);
void init_all(sprites *, textures *, graf *, time *);
void init_all2(sprites *, vectors *, rects *, int);
void init_spots(vectors *);
void init_souc(t_all *);
void render_menu(vectors *, graf *, textures *, sprites *);
void move_rect(sfIntRect *, int, int);
void move_duck(soucoupe *, float, char, graf *);
void move_up(time *, soucoupe *, float, graf *);
void move_special(soucoupe *, graf *, float);
void souc_gesture(time *, rects *, soucoupe *, graf *);
void render_filant(time *, filanvec *, sfSprite *);
void render_filant1(time *, filanvec *, sfSprite *);
void render_filant2(time *, filanvec *, sfSprite *);
void ptr(sfRenderWindow *, sprites *);
void render_diff(int, sprites *, textures *);
void render_ammo(graf *, sprites *, t_all *);
void do_render_filant(time *, sfSprite *, filanvec *);
void draw_menu(sfRenderWindow *, sprites *);
void update_stage(time *, sprites *, sfRenderWindow *);
void update_hp(rects *, graf *, sprites *, vectors *);
void stage1(t_all *, sfRenderWindow *);
void stage2(t_all *, sfRenderWindow *);
void do_menu(t_all *, sfRenderWindow *);
void destroy(t_all *, sfRenderWindow *window);
void destroy_textures(t_all *);
void destroy_sprites(t_all *);
void destroy_clock(t_all *);
void free_all(t_all *);
void destroy_music(t_all *);
void game_over(t_all *, sfRenderWindow *);
void case7(sfVector2f *, soucoupe *, float, graf *);
void case8(sfVector2f *, soucoupe *, float, graf *);
void case9(sfVector2f *, soucoupe *, float, graf *);
void case10(sfVector2f *, soucoupe *, float, graf *);
void set_stage(t_all *);
int render_game_over(t_all *, sfRenderWindow *, int);
void classic_type(graf *, soucoupe *);
void armor_type(graf *, soucoupe *);
void play_ufo(t_all *);
soucoupe my_putsouc(sprites *, vectors *, graf *);
soucoupe my_putspecial(sprites *, vectors *, graf *, int);




