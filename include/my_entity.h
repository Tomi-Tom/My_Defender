/*
** EPITECH PROJECT, 2022
** MY_ENTITY_H
** File description:
** my_entity
*/

#ifndef MY_ENTITY_H_
    #define MY_ENTITY_H_

typedef struct entity_s {
    sfClock *anim;
    sfClock *move;
    vec_t vec;
    sfIntRect rect;
    sfSprite *sprite;
    int type;
    int tile;
    int moving;
    int spd;
    int life;
    struct entity_s *prev;
    struct entity_s *next;
} entity_t;

#endif /* !MY_ENTITY_H_ */
