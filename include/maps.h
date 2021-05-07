/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** maps
*/

#ifndef MAPS_H_
#define MAPS_H_

char *MAPS_PATH[] = {
    "assets/maps/test1/",
    "assets/maps/test2/",
    "assets/maps/forest/",
    "assets/maps/river/",
    "assets/maps/montains/",
    "assets/maps/top_montains/",
};

const sfVector2f MAPS_SPAWN[][8] = {
    {{1550, 1700}, {796, 340}, {1660, 70}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{920, 870}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{423, 1160}, {1270, 70}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{1015, 3160}, {1240, 80}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{1240, 3130}, {970, 170}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{1060, 1520}, {970, 170}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
};

#endif /* !MAPS_H_ */
