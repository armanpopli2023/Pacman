#pragma once

#include <ge211.hxx>
#include <vector>

class Model {

public:
    Model();

// Movement function for pacman and ghosts
// Pacman movement
    void move_pacman();

// Red ghost movement
    void move_ghosts();

// Blue ghost movement
    void move_blue_ghost();

//update the white dot after pacman touched it
    void update();

// Initial position of pacman and ghosts
    ge211::Position pac_pos() const;
    ge211::Position red_ghost_pos() const;
    ge211::Position blue_ghost_pos() const;
    ge211::Position red_ghost_pos_;
    ge211::Position blue_ghost_pos_;
    ge211::Position pacman_pos_;
    ge211::Dimensions pacman_vel{0,0};

// The graph of map that based on a 2D array with type int
    int B = 2;
    int A = 1;
    int blockMap [15][15] =  {
            B, B, B, B, B, B, B, B, B, B, B, B, B, B, B,
            B, A, A, A, A, A, A, A, A, A, A, A, A, A, B,
            B, A, A, B, A, A, B, B, B, A, B, B, B, A, B,
            B, A, B, B, A, A, A, A, A, A, A, A, A, A, B,
            B, A, B, A, B, A, B, B, B, A, B, B, B, A, B,
            B, A, B, A, A, A, A, A, A, A, A, A, A, A, B,
            B, A, A, A, A, A, B, B, A, A, A, B, B, A, B,
            B, A, B, A, B, A, A, A, A, A, A, A, A, A, B,
            B, A, B, A, B, A, A, A, B, A, B, A, A, A, B,
            B, A, A, A, A, A, A, A, B, B, B, A, A, A, B,
            B, A, B, A, A, A, A, A, A, A, A, A, B, A, B,
            B, A, B, A, A, B, A, A, A, A, B, A, A, A, B,
            B, A, B, A, B, B, B, A, A, A, A, A, B, A, B,
            B, A, A, A, A, B, A, A, A, A, A, A, A, A, B,
            B, B, B, B, B, B, B, B, B, B, B, B, B, B, B,
    };

// Dot represents the food
    using Dot = ge211::Rectangle;
    std::vector<Dot> food;
};

