/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH
*/

#ifndef RPGSH_H_
#define RPGSH_H_

typedef struct infos_s infos_t;

void execute_rpgsh(char **script, infos_t *infos);
void execute_instruction(char ***line, char **args, infos_t *infos);
void execute_condition(char ***line, char **args, infos_t *infos);
void execute_command(char **args, char *cmd, int len, infos_t *infos);
void skip_condition(char ***line);

char **open_rpgsh_file(char *filename);
void add_line(char ***lines, char *line, int size);

char **split_into_args(char *line);
void add_arg(char ***args, int size, char *start, int len);
void free_args(char **args);

#endif /* !RPGSH_H_ */
