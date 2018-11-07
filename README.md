# ft_printf

## DESCRIPTION

The goal of this project was to creat a executable libftprintf.a who are my owner printf

## OBJECTIF AND DIFFICULTY

This project is the first who asked to me a good reflection before started him, because i have some objectifs :

* Do not use malloc on all of project, optimise the call of write, for having the best speed rate.
* Learned and started to use bits filds for optimise memory, and speed.
* Gestion of all undefined beavore, a best comportement even if user use wrong flags or other

All this points increase the difficulty of project but i have succed all of this.

My printf handle all option like the real printf except float and 2 or 3 things.
Power of wilcard are present.

## MORE INFO OF USED FT_PRINTF

* `%flags{couleur/text,couleur/background}`

| FLAGS | UTILITY |
| --- | --- |
| + | highlight |
| 0 | underline |
| # | bold |

* %b or %`flags`b
| FLAGS | LENGHT BITS |
| hh | char |
| h | short |
| l | int |
| ll | unsigned |
