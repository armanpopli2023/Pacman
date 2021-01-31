#pragma once

#include <ge211.hxx>
#include "model.hxx"

class View
{

public:
    View();
    void draw(ge211::Sprite_set& set, Model const& model);

private:

// How many food dots left so far
    int food_l;

// Those functions are initialize the appearance fo pacman and ghosts
// And also the block and white dots that contain in the map
    ge211::Circle_sprite pacman_sprite;
    ge211::Circle_sprite red_ghost;
    ge211::Circle_sprite blue_ghost;
    ge211::Rectangle_sprite white_square;
    ge211::Circle_sprite white_circle;

//Text to show either player won the game or lose the game
    ge211::Font font {"sans.ttf", 40};
    ge211::Text_sprite  game_over = ge211::Text_sprite("Game Over",font);
    ge211::Text_sprite  game_win = ge211::Text_sprite("You Win!",font);

// Text to record how many dots left
    ge211::Font font2 {"sans.ttf", 1};
    ge211::Text_sprite  count_block = ge211::Text_sprite("Total Left food: ",font2);
};

