/* This file contain the Einstein's enigm subject in Prolog language.*/
/* subject of the riddle, below ↓

1    the Brit lives in the red house
2    the green house is on the left of the white house
3    the Dane drinks tea
4    the man who smokes "Blends" lives next to the one who keeps cats
5    the owner of the yellow house smokes Dunhill
6    the German smokes Prince
7    the man living in the center house drinks milk
8    the man who smokes blend has a neighbor who drinks water
9    the person who smokes Pall Mall rears birds
10   the Swede keeps dogs as pets
11   the Norwegian lives next to the blue house
12   the man who keeps horses lives next to the man who smokes Dunhill
13   the owner who smokes BlueMaster drinks beer
14   the green house's owner drinks coffee
15   the Norwegian lives in the first house

    who had a fish ?
*/

/* usage_funtion, below ↓*/
usage :-
    write("    The possible nationalities are:
        norway / england / sweden / denmark / germany

    The possible colors are:
        red / green / white / yellow / blue

    The possible beverages are:
        tea / coffee / milk / beer / water

    The possible cigars are:
        pallMall / dunhill / blends / lueMaster / prince

    The possible pets are:
        dog / bird / cat / horse / fish

    Usage → cross(color, country, animal, drink, smoke).
        example : cross(X, Y, fish, Z, G).

        then press [space] until 'false.' appear.").

/* properties → to trad positions in the list */
first(H,[H|_]).

on_the_left(X,Y,[X,Y|_]).
on_the_left(X,Y,[_|HouseList]) :- on_the_left(X,Y,HouseList).

next_to(X,Y,[X,Y|_]).
next_to(X,Y,[Y,X|_]).
next_to(X,Y,[_|HouseList]) :- next_to(X,Y,HouseList).

middle(X,[_,_,X,_,_]).

/* contraints → to trad elements know in the list*/
cross(Color, Country, Animal, Drink, Smoke) :-
    HouseList = [
        house(_Col1, _Con1, _Ani1, _Dri1, _Smo1),
        house(_Col2, _Con2, _Ani2, _Dri2, _Smo2),
        house(_Col3, _Con3, _Ani3, _Dri3, _Smo3),
        house(_Col4, _Con4, _Ani4, _Dri4, _Smo4),
        house(_Col5, _Con5, _Ani5, _Dri5, _Smo5) ],
    %-- 1
    member(house(red, england, _, _, _), HouseList),
    %-- 2
    on_the_left(house(green, _, _, _, _), house(white, _, _, _, _), HouseList),
    %-- 3 - on_the_left
    member(house(_, denmark, _, tea, _), HouseList),
    %-- 4
    next_to(house(_, _, _, _, blends), house( _, _, cat, _, _), HouseList),
    %-- 5 - next_to
    member(house(yellow, _, _, _, dunhill), HouseList),
    %-- 6
    member(house(_, germany, _, _, prince), HouseList),
    %-- 7
    middle(house(_, _, _, milk, _), HouseList),
    %-- 8
    next_to(house(_, _, _, _, blends), house(_, _, _, water, _), HouseList),
    %-- 9 - next_to
    member(house(_, _, bird, _, pallMall), HouseList),
    %-- 10
    member(house(_, sweden, dog, _, _), HouseList),
    %-- 11
    next_to(house(_, norway, _, _, _), house(blue, _, _, _, _), HouseList),
    %-- 12 - next_to
    next_to(house(_, _, horse, _, _), house(_, _, _, _, dunhill), HouseList),
    %-- 13 - next_to
    member(house(_, _, _, beer, blueMaster), HouseList),
    %-- 14
    member(house(green, _, _, coffee, _), HouseList),
    %-- 15
    first(house(_, norway, _, _, _), HouseList),
    %--
    member(house(Color, Country, Animal, Drink, Smoke), HouseList),
    write(HouseList), nl.
/* nl → newline */