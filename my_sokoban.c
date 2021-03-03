/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** my_sokoban
*/

#include "my_sokoban.h"

void help(void)
{
    write(1, "USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map  file ", 55);
    write(1, "representing the warehouse map, containing '#' for walls,\n", 58);
    write(1, "          'P' for the player, 'X' for boxes and 'O' for ", 56);
    write(1, "storage locations.\n", 19);
    exit(84);
}

void error_args(int ac, char **av)
{
    if (ac != 2)
        exit(84);
    if (strcmp(av[1], "-h") == 0)
        help();
}

char *file_reader(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat stats;
    char *file;

    if (fd == -1)
        return ("!");
    if (stat(filepath, &stats) != 0)
        return ("!");
    if (stats.st_size == 0)
        return ("empty");
    file = malloc(sizeof(char) * (stats.st_size + 1));
    if (file == NULL)
        return ("!");
    if (read(fd, file, stats.st_size) == -1)
        return ("!");
    file[stats.st_size] = '\0';
    close(fd);
    return (file);
}

void check_empty(char *file)
{
    if (file[0] == '\0')
        exit(84);
}

void check_format(char *file, struct game_struct *game)
{
    int P_count = 0;
    int X_count = 0;
    int O_count = 0;

    check_empty(file);
    for (int i = 0; file[i]; i++) {
        if (file[i] != 'P' && file[i] != '#' && file[i] != 'O'
        && file[i] != ' ' && file[i] != '\n' && file[i] != 'X')
            exit(84);
        if (file[i] == 'O')
            O_count++;
        if (file[i] == 'X')
            X_count++;
        if (file[i] == 'P')
            P_count++;
    }if (P_count != 1 || X_count != O_count || X_count == 0)
        exit(84);
    game->nb_of_boxes = X_count;
}

void error_file(char *file, struct game_struct *game)
{
    if (file[0] == '!' && file[1] == '\0')
        exit(84);
    check_format(file, game);
}

void get_window_info(struct game_struct *game)
{
    getmaxyx(stdscr, game->height_window, game->width_window);
    game->y_to_center = (game->height_window - game->height_map) / 2;
    game->x_to_center = (game->width_window - game->width_map) / 2;
    game->cursor_y = game->y_to_center;
    game->cursor_x = game->x_to_center;
}

void init_p(struct game_struct *game, int y, int x)
{
    if (game->map_arr[y][x] == 'P') {
        game->initial_p_y = y + game->y_to_center;
        game->initial_p_x = x + game->x_to_center;
    }
}

void print_map(struct game_struct *game)
{
    for (int y = 0; game->map_arr[y]; y++) {
        move(game->cursor_y++, game->x_to_center);
        for (int x = 0; game->map_arr[y][x]; x++) {
            addch(game->map_arr[y][x]);
            game->cursor_x++;
            init_p(game, y, x);
        }game->cursor_x = game->x_to_center;
    }move(game->initial_p_y, game->initial_p_x);
    game->cursor_x = game->initial_p_x;
    game->cursor_y = game->initial_p_y;
}

void key_up_gestion(struct game_struct *game, struct node *head_boxes)
{
    if (condition_up(game) == 1)
        return;
    is_it_O(game);
    if (game->map_arr[game->cursor_y - 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X') {
        change_linked_list_up(game, head_boxes);
        game->map_arr[game->cursor_y - 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] = ' ';
        game->map_arr[game->cursor_y - 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] = 'X';
        move(game->cursor_y - 2, game->cursor_x);
        addch('X');
    }game->cursor_y--;
    move(game->cursor_y, game->cursor_x);
    addch('P');
    move(game->cursor_y, game->cursor_x);
}

void key_down_gestion(struct game_struct *game, struct node *head_boxes)
{
    if (condition_down(game) == 1)
        return;
    is_it_O(game);
    if (game->map_arr[game->cursor_y + 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X') {
        change_linked_list_down(game, head_boxes);
        game->map_arr[game->cursor_y + 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] = ' ';
        game->map_arr[game->cursor_y + 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] = 'X';
        move(game->cursor_y + 2, game->cursor_x);
        addch('X');
    }game->cursor_y++;
    move(game->cursor_y, game->cursor_x);
    addch('P');
    move(game->cursor_y, game->cursor_x);
}

void key_left_gestion(struct game_struct *game, struct node *head_boxes)
{
    if (condition_left(game) == 1)
        return;
    is_it_O(game);
    if (game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 1 - game->x_to_center] == 'X') {
        change_linked_list_left(game, head_boxes);
        game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 1 -game->x_to_center] = ' ';
        game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 2 - game->x_to_center] = 'X';
        move(game->cursor_y, game->cursor_x - 2);
        addch('X');
    }game->cursor_x--;
    move(game->cursor_y, game->cursor_x);
    addch('P');
    move(game->cursor_y, game->cursor_x);
}

void is_it_O(struct game_struct *game)
{
    if (game->edited_map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'O')
        addch('O');
    else
        addch(' ');
}

void change_linked_list_down(struct game_struct *game, struct node *head_boxes)
{
    while (game->cursor_x - game->x_to_center != head_boxes->x &&
    game->cursor_y - game->y_to_center + 1 != head_boxes->y)
        head_boxes = head_boxes->next;
    head_boxes->y += 1;
}

void change_linked_list_up(struct game_struct *game, struct node *head_boxes)
{
    while (game->cursor_x - game->x_to_center != head_boxes->x &&
    game->cursor_y - game->y_to_center - 1 != head_boxes->y)
        head_boxes = head_boxes->next;
    head_boxes->y -= 1;
}

void change_linked_list_left(struct game_struct *game, struct node *head_boxes)
{
    while (game->cursor_x - 1 - game->x_to_center != head_boxes->x &&
    game->cursor_y - game->y_to_center != head_boxes->y)
        head_boxes = head_boxes->next;
    head_boxes->x -= 1;
}

void change_linked_list_right(struct game_struct *game, struct node *head_boxes)
{
    while (game->cursor_x + 1 - game->x_to_center != head_boxes->x &&
    game->cursor_y - game->y_to_center != head_boxes->y)
        head_boxes = head_boxes->next;
    head_boxes->x += 1;
}

void key_right_gestion(struct game_struct *game, struct node *head_boxes)
{
    if (condition_right(game) == 1)
        return;
    is_it_O(game);
    if (game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 1 - game->x_to_center] == 'X') {
        change_linked_list_right(game, head_boxes);
        game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 1 - game->x_to_center] = ' ';
        game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 2 - game->x_to_center] = 'X';
        move(game->cursor_y, game->cursor_x + 2);
        addch('X');
    }game->cursor_x++;
    move(game->cursor_y, game->cursor_x);
    addch('P');
    move(game->cursor_y, game->cursor_x);
}

int condition_up(struct game_struct *game)
{
    if ((game->map_arr[game->cursor_y - 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == '#') ||
    ((game->map_arr[game->cursor_y - 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X') &&
    ((game->map_arr[game->cursor_y - 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == '#') ||
    (game->map_arr[game->cursor_y - 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X'))))
        return (1);
    else
        return (0);
}

int condition_down(struct game_struct *game)
{
    if ((game->map_arr[game->cursor_y + 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == '#') ||
    ((game->map_arr[game->cursor_y + 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X') &&
    ((game->map_arr[game->cursor_y + 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == '#') ||
    (game->map_arr[game->cursor_y + 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X'))))
        return (1);
    else
        return (0);
}

int condition_left(struct game_struct *game)
{
    if ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 1 - game->x_to_center] == '#') ||
    ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 1 - game->x_to_center] == 'X') &&
    ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 2 - game->x_to_center] == '#' ||
    game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 2 - game->x_to_center] == 'X'))))
        return (1);
    else
        return (0);
}

int condition_right(struct game_struct *game)
{
    if ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 1 - game->x_to_center] == '#') ||
    ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 1 - game->x_to_center] == 'X') &&
    ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 2 - game->x_to_center] == '#') || 
    (game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 2 - game->x_to_center] == 'X'))))
        return (1);
    else
        return (0);
}

void input_gestion(struct game_struct *game, struct node *head_boxes)
{
    int ch = getch();

    switch (ch) {
        case KEY_UP :
            key_up_gestion(game, head_boxes);
            break;
        case KEY_DOWN :
            key_down_gestion(game, head_boxes);
            break;
        case KEY_LEFT :
            key_left_gestion(game, head_boxes);
            break;
        case KEY_RIGHT :
            key_right_gestion(game, head_boxes);
            break;
    }
}

int lose_condition(struct game_struct *game, struct node *head_boxes)
{
    if (game->map_arr[head_boxes->y][head_boxes->x - 1] == 'X' ||
    game->map_arr[head_boxes->y][head_boxes->x - 1] == '#'||
    game->map_arr[head_boxes->y][head_boxes->x + 1] == 'X' ||
    game->map_arr[head_boxes->y][head_boxes->x + 1] == '#')
        if (game->map_arr[head_boxes->y - 1][head_boxes->x] == 'X' ||
    game->map_arr[head_boxes->y - 1][head_boxes->x] == '#' ||
    game->map_arr[head_boxes->y + 1][head_boxes->x] == 'X' ||
    game->map_arr[head_boxes->y + 1][head_boxes->x] == '#')
            return (1);
    return (0);
}

void check_lose(struct game_struct *game, struct node *head_boxes)
{
    int idx = head_boxes->idx;

    if (lose_condition(game, head_boxes) == 0)
        return;
    head_boxes = head_boxes->next;
    while (head_boxes->idx != idx) {
        if (lose_condition(game, head_boxes) == 0)
            return;
        head_boxes = head_boxes->next;
    }endwin();
    exit(1);
}

void check_win_or_lose(struct game_struct *game, struct node *head_boxes,
struct node *head_storages)
{
    check_lose(game, head_boxes);
}

void run_game(struct game_struct *game, struct node *head_boxes,
struct node *head_storages)
{
    initscr();
    keypad(stdscr, TRUE);
    get_window_info(game);
    while (1) {
        if (game->reset == 0) {
            print_map(game);
            game->reset = 1;
        }input_gestion(game, head_boxes);
        check_win_or_lose(game, head_boxes, head_storages);
        refresh();
    }endwin();
}

struct game_struct *ini_struct(void)
{
    struct game_struct *game = malloc(sizeof(struct game_struct));

    game->height_map = 0;
    game->width_map = 0;
    game->height_window = 0;
    game->width_window = 0;
    game->need_resize = 0;
    game->cursor_x = 0;
    game->cursor_y = 0;
    game->x_to_center = 0;
    game->y_to_center = 0;
    game->initial_p_x = 0;
    game->initial_p_y = 0;
    game->nb_of_boxes = 0;
    return (game);
}

void set_heigth_and_width(struct game_struct *game)
{
    int width = 0;
    int height = 0;
    int stop = 0;

    for (int i = 0; game->map[i]; i++) {
        if (game->map[i] == '\n') {
            height++;
            stop = 1;
        }if (stop == 0)
            width++;
    }game->width_map = width;
    game->height_map = height;
}

void map_str_to_map_arr(struct game_struct *game)
{
    int idx = 0;

    game->map_arr = malloc(sizeof(char *) * (game->height_map + 1));
    game->edited_map_arr = malloc(sizeof(char *) * (game->height_map + 1));
    for (int i = 0; i < game->height_map; i++) {
        game->map_arr[i] = malloc(sizeof(char) * game->width_map + 1);
        game->edited_map_arr[i] = malloc(sizeof(char) * game->width_map + 1);
        for (int j = 0; j < game->width_map; j++) {
            game->map_arr[i][j] = game->map[idx];
            game->edited_map_arr[i][j] = game->map[idx++];
        }idx++;
        game->map_arr[i][game->width_map] = '\0';
        game->edited_map_arr[i][game->width_map] = '\0';
    }game->map_arr[game->height_map] = NULL;
    game->edited_map_arr[game->height_map] = NULL;
}

struct node *create_storage_linked_list(struct game_struct *game)
{
    struct node *head_storages = malloc(sizeof(struct node));
    struct node *back_up = head_storages;
    int idx = 1;
    
    head_storages->idx = idx++;
    assign_storage_coord(head_storages, head_storages->idx, game->map_arr);
    for (int i = 1; i < game->nb_of_boxes; i++) {
        back_up->next = malloc(sizeof(struct node));
        back_up = back_up->next;
        back_up->idx = idx++;
        assign_storage_coord(back_up, back_up->idx, game->map_arr);
    }back_up->next = head_storages;
    return (head_storages);
}

void assign_storage_coord(struct node *storage, int idx, char **arr)
{
    int j = 0;
    int stop = 0;
    int O_count = 0;

    for (int i = 0; arr[i]; i++) {
        for (j = 0; arr[i][j]; j++) {
            if (arr[i][j] == 'O')
                O_count++;
            if (O_count == idx) {
                storage->x = j;
                storage->y = i;
                stop = 1;
                break;
            }
        }if (stop == 1)
            break;
    }
}


void assign_box_coord(struct node *box, int idx, char **arr)
{
    int j = 0;
    int stop = 0;
    int X_count = 0;

    for (int i = 0; arr[i]; i++) {
        for (j = 0; arr[i][j]; j++) {
            if (arr[i][j] == 'X')
                X_count++;
            if (X_count == idx) {
                box->x = j;
                box->y = i;
                stop = 1;
                break;
            }
        }if (stop == 1)
            break;
    }
}

struct node *create_box_linked_list(struct game_struct *game)
{
    struct node *head_boxes = malloc(sizeof(struct node));
    struct node *back_up = head_boxes;
    int idx = 1;
    
    head_boxes->idx = idx++;
    assign_box_coord(head_boxes, head_boxes->idx, game->map_arr);
    for (int i = 1; i < game->nb_of_boxes; i++) {
        back_up->next = malloc(sizeof(struct node));
        back_up = back_up->next;
        back_up->idx = idx++;
        assign_box_coord(back_up, back_up->idx, game->map_arr);
    }back_up->next = head_boxes;
    return (head_boxes);
}

int my_sokoban(int ac, char **av)
{
    struct game_struct *game = ini_struct();
    struct node *head_boxes = NULL;
    struct node *head_storages = NULL;

    error_args(ac, av);
    game->map = file_reader(av[1]);
    error_file(game->map, game);
    set_heigth_and_width(game);
    map_str_to_map_arr(game);
    head_boxes = create_box_linked_list(game);
    head_storages = create_storage_linked_list(game);
    run_game(game, head_boxes, head_storages);
}