/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** maps
*/

#ifndef MAPS_H_
#define MAPS_H_

char *MAPS_PATH[] = {
    "assets/maps/village/",
    "assets/maps/market/",
    "assets/maps/forest/",
    "assets/maps/river/",
    "assets/maps/montains/",
    "assets/maps/top_montains/",
};

const sfVector2f MAPS_SPAWN[][8] = {
    {{1350, 1859}, {2015, 1450}, {1660, 70}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{70, 1670}, {1450, 150}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{423, 1160}, {1270, 70}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{1015, 3160}, {1240, 80}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{1240, 3130}, {970, 170}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{1060, 1520}, {970, 170}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
};

#endif /* !MAPS_H_ */
