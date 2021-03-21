/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** shop
*/

#include "../include/my_defender.h"

void check_scrolls(game_t *game, mouse_t * m_i, entity_t **entities)
{
    if (game->game_scene->gold >= 10) {
        if (m_i->rpos.x >= entities[4]->position.x && m_i->rpos.x
            <= entities[4]->position.x + entities[4]->texture_rect.width)
            game->game_scene->phase = 1;
        if (m_i->rpos.x >= entities[5]->position.x && m_i->rpos.x
            <= entities[5]->position.x + entities[5]->texture_rect.width)
            game->game_scene->phase = 2;
        if (m_i->rpos.x >= entities[6]->position.x && m_i->rpos.x
            <= entities[6]->position.x + entities[6]->texture_rect.width)
            game->game_scene->phase = 3;
    }
    if (game->game_scene->gold >= 50)
        if (m_i->rpos.x >= entities[7]->position.x && m_i->rpos.x
            <= entities[7]->position.x + entities[7]->texture_rect.width)
            game->game_scene->phase = 4;
    if (game->game_scene->gold >= 100)
        if (m_i->rpos.x >= entities[8]->position.x && m_i->rpos.x
            <= entities[8]->position.x + entities[8]->texture_rect.width)
            game->game_scene->phase = 5;
}

void check_shop(game_t *game, mouse_t *m_i, entity_t **entities)
{
    if (!(m_i->rpos.y >= entities[4]->position.y && m_i->rpos.y <=
    entities[4]->position.y + entities[4]->texture_rect.height))
        return;
    check_scrolls(game, m_i, entities);
}
