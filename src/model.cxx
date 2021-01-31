#include "model.hxx"

ge211::Position pac_pos0{50,280};
ge211::Position const ghost_pos0{395,190};
ge211::Dimensions const ghost_moveleft{-1,0};
ge211::Dimensions const ghost_moveright{1,0};
ge211::Dimensions const ghost_moveup{0,-1};
ge211::Dimensions const ghost_movedown{0,1};
ge211::Dimensions ghost_blue_path{1,0};

Model::Model()
        : pacman_pos_(pac_pos0)
        , red_ghost_pos_(ghost_pos0)
        , blue_ghost_pos_{40, 160}

{
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            food.push_back({i * 10, j * 10,2,2});
        }
    }
}

void Model::move_pacman()
{
    pacman_pos_ += pacman_vel;
}

void Model::move_ghosts() {

    if (red_ghost_pos_.y != 400
        && red_ghost_pos_.x != 160
        && red_ghost_pos_.y != 100
        && red_ghost_pos_.x != 280
        && red_ghost_pos_.y != 35
        && red_ghost_pos_.x != 35
        && red_ghost_pos_.y != 150){
        red_ghost_pos_ += ghost_movedown;
    }

    if(red_ghost_pos_.y == 400
        && red_ghost_pos_.x != 160){
        red_ghost_pos_ += ghost_moveleft;
    }

    if(red_ghost_pos_.x == 160
        && red_ghost_pos_.y != 100
        && red_ghost_pos_.y != 35){
        red_ghost_pos_ += ghost_moveup;
    }

    if(red_ghost_pos_.y == 100
        && red_ghost_pos_.x != 280
        && red_ghost_pos_.x != 35){
        red_ghost_pos_ += ghost_moveright;
    }

    if(red_ghost_pos_.x == 280
        && red_ghost_pos_.y != 400){
        red_ghost_pos_ += ghost_moveup;
    }

    if(red_ghost_pos_.y == 35
        && red_ghost_pos_.x != 35){
        red_ghost_pos_ += ghost_moveleft;
    }

    if(red_ghost_pos_.x == 35
        && red_ghost_pos_. y != 150){
        red_ghost_pos_ += ghost_movedown;
    }

    if(red_ghost_pos_.y == 150){
        red_ghost_pos_ += ghost_moveright;
    }
}

void Model::move_blue_ghost(){
    blue_ghost_pos_ += ghost_blue_path;

    if (blue_ghost_pos_.x == 300
        || blue_ghost_pos_.x == 25){
        ghost_blue_path.width *= -1;
    }
}

ge211::Position Model::pac_pos() const
{
    return pacman_pos_;
}

void Model::update()
{
    if (blockMap[pacman_pos_.x/30][pacman_pos_.y/30] == 1) {
        blockMap[pacman_pos_.x / 30][pacman_pos_.y / 30] = 3;
    }
}

ge211::Position Model::red_ghost_pos() const {
    return red_ghost_pos_;
}
ge211::Position Model::blue_ghost_pos() const {
    return blue_ghost_pos_;
}


