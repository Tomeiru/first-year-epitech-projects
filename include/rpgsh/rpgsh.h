/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH
*/

#ifndef RPGSH_H_
#define RPGSH_H_

typedef struct infos_s infos_t;
typedef struct element_s element_t;
typedef struct interactable_s interactable_t;

void execute_rpgsh(char **script, infos_t *infos,
element_t *element);
void execute_rpgsh_single_instruction(char **script,
int *instruction, infos_t *infos, element_t *element);

void execute_instruction(char ***line, char **args,
infos_t *infos, element_t *element);
void execute_condition(char ***line, char **args,
infos_t *infos, element_t *element);
void execute_command(char ***line, char **args,
infos_t *infos, element_t *element);
void skip_condition(char ***line);
void skip_else(char ***line);

char **open_rpgsh_file(char *filename);
void add_line(char ***lines, char *line, int size);

void rpgsh_attach_script(interactable_t *interactable, char ***script);
void rpgsh_reach_end(char ***script);

char **split_into_args(char *line);
void add_arg(char ***args, int size, char *start, int len);
void free_args(char **args);

#endif /* !RPGSH_H_ */
