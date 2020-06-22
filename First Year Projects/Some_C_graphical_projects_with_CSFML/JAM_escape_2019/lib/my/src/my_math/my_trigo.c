/*
** EPITECH PROJECT, 2019
** MY_TRIGO
** File description:
** My trigo functions * 1000
*/

const int COS[] = {1000, 1000, 999, 999, 998, 996, 995, 993, 990, 988, 985, 982,
    978, 974, 970, 966, 961, 956, 951, 946, 940, 934, 927, 921, 914, 906, 899,
    891, 883, 875, 866, 857, 848, 839, 829, 819, 809, 799, 788, 777, 766, 755,
    743, 731, 719, 707, 695, 682, 669, 656, 643, 629, 616, 602, 588, 574, 559,
    545, 530, 515, 500, 485, 469, 454, 438, 423, 407, 391, 375, 358, 342, 326,
    309, 292, 276, 259, 242, 225, 208, 191, 174, 156, 139, 122, 105, 87, 70,
    52, 35, 17, 0};

int my_cos(int degrees)
{
    degrees = (degrees % 360 + 360) % 360;

    if (degrees <= 180) {
        if (degrees < 90)
            return (COS[degrees]);
        else
            return (COS[180 - degrees] * -1);
    }
    return (my_cos(360 - degrees));
}

int my_sin(int degrees)
{
    return (my_cos(degrees - 90));
}