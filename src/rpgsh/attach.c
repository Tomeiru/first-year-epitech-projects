/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** attach script
*/

#include "my.h"
#include "rpgsh/rpgsh.h"
#include "elements/entities/interactable.h"

void rpgsh_attach_script(interactable_t *interactable, char ***script)
{
    char **args = split_into_args(*(*script + 1));

    if (!my_strcmp(args[0], "ACTION")) {
        interactable->action_script = *script + 2;
        rpgsh_reach_end(script);
        free_args(args);
        if (!**script || !*(*script + 1))
            return;
        args = split_into_args(*(*script + 1));
    }
    if (!my_strcmp(args[0], "UPDATE")) {
        interactable->update_script = *script + 2;
        rpgsh_reach_end(script);
    }
    free_args(args);
}

void rpgsh_reach_end(char ***script)
{
    char **args = NULL;

    for (; **script; *script += 1) {
        args = split_into_args(**script);
        if (!my_strcmp(args[0], "END")) {
            free_args(args);
            break;
        }
        free_args(args);
    }
}