#include "controller.hxx"


void Controller::draw(ge211::Sprite_set &set) {
    view_.draw(set, model_);
}


void Controller::on_frame(double last_frame_seconds) {
    model_.move_pacman();
    model_.move_ghosts();
    model_.move_blue_ghost();
    model_.update();

// End game if ghost eat the pacman
    if (model_.pacman_pos_.x + 15 >= model_.red_ghost_pos_.x
        && model_.pacman_pos_.x - 15 <= model_.red_ghost_pos_.x
        && model_.pacman_pos_.y + 15 >= model_.red_ghost_pos_.y
        && model_.pacman_pos_.y - 15 <= model_.red_ghost_pos_.y){
        quit();
    }

    if (model_.pacman_pos_.x + 15 >= model_.blue_ghost_pos_.x
        && model_.pacman_pos_.x - 15 <= model_.blue_ghost_pos_.x
        && model_.pacman_pos_.y + 15 >= model_.blue_ghost_pos_.y
        && model_.pacman_pos_.y - 15 <= model_.blue_ghost_pos_.y){
        quit();
    }
}

void Controller::on_key(ge211::Key key)
{
            if (key == ge211::Key::code('w')
                &&(model_.blockMap[model_.pacman_pos_.x/30][model_.pacman_pos_.y/30 ] != 2)) {
                model_.pacman_vel = {0, -5};
                model_.move_pacman();
                model_.pacman_vel = {0, 0};
                model_.move_pacman();
            }
            if (key == ge211::Key::code('a')
                &&(model_.blockMap[model_.pacman_pos_.x/30][model_.pacman_pos_.y/30 ] != 2)) {
                model_.pacman_vel = {-5, 0};
                model_.move_pacman();
                model_.pacman_vel = {0, 0};
                model_.move_pacman();
            }
            if (key == ge211::Key::code('s')
                &&(model_.blockMap[model_.pacman_pos_.x/30][model_.pacman_pos_.y/30 + 1] != 2)) {
                model_.pacman_vel = {0, 5};
                model_.move_pacman();
                model_.pacman_vel = {0, 0};
                model_.move_pacman();
            }
            if (key == ge211::Key::code('d')
                &&(model_.blockMap[model_.pacman_pos_.x/30 + 1][model_.pacman_pos_.y/30] != 2)) {
                model_.pacman_vel = {5, 0};
                model_.move_pacman();
                model_.pacman_vel = {0, 0};
                model_.move_pacman();
            }

// Press "q" to quit the game
    if (key == ge211::Key::code('q')) {
        quit();
    }
}
