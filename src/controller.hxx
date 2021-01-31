#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

//Control the game with key
class Controller : public ge211::Abstract_game
{

public:
    Controller() = default;

protected:
    void draw(ge211::Sprite_set& set) override;

//Update the appearance of pacman and ghost on screen
    void on_frame(double) override;

// Control the movement of pacman by keyboard
    void on_key(ge211::Key) override;

private:
    Model model_;
    View view_;
};