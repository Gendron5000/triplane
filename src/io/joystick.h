/* 
 * Triplane Classic - a side-scrolling dogfighting game.
 * Copyright (C) 1996,1997,2009  Dodekaedron Software Creations Oy
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * tjt@users.sourceforge.net
 */

#ifndef JOYSTICK_H
#define JOYSTICK_H

// Vakiom��rittelyt eri tietojen bittimaskeille
#define JOY1X 0x01              // Akselibitit ovat aina 1 jos joystick
#define JOY1Y 0x02              // ei ole kytkettyn�.
#define JOY2X 0x04
#define JOY2Y 0x08

struct joystick_action {
    char type;                  /* 0 = none, 1 = button, 2 = axis */
    char n;                     /* nth button or axis */
    Sint16 threshold;           /* threshold for axis */
    char threshold_dir;         /* 0 = lower bound, 1 = upper bound */
};

struct joystick_configuration {
    /* "brake" action presses up and down simultaneously */
    /* if roll.type = 0, use autoroll */
    joystick_action up, down, roll, power, guns, bombs, brake, turbo;
};
extern joystick_configuration joystick_config[2];

short init_joysticks(void);
int load_joysticks_data(const char *filename);
void save_joysticks_data(const char *filename);
void open_close_joysticks(int joy1, int joy2);
int joystick_has_roll_button(int t);
void get_joystick_action(int t, int inmenu, int *down, int *up, int *power, int *roll, int *guns, int *bombs);
Sint16 *allocate_axis_state(int joy);
void save_axis_state(Sint16 * axes, int joy);
void find_changed_axis(struct joystick_action *act, Sint16 * idle, Sint16 * current, int joy);
int find_changed_button(struct joystick_action *act, int joy);
void set_disabled_action(struct joystick_action *act);
char *get_joy_action_string(struct joystick_action *act);

#endif
