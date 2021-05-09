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
    "assets/maps/mansion/",
};

const sfVector2f MAPS_SPAWN[][8] = {
    {{770, 1200}, {2030, 850}, {1660, 70},
        {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{70, 1670}, {1450, 150}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{423, 1160}, {1270, 70}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{1015, 3160}, {1240, 80}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{1240, 3130}, {970, 170}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{1060, 1520}, {1050, 840}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    {{1050, 940}, {970, 170}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
};

#endif /* !MAPS_H_ */
