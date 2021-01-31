#include "view.hxx"

static int const pac_radius = 10;
static ge211::Color const pac_color = ge211::Color::medium_yellow();

View::View()
        : pacman_sprite(pac_radius, pac_color)
        , white_square({30, 30},ge211::Color::white())
        , white_circle(2, ge211::Color::white())
        , red_ghost(10, ge211::Color::medium_red())
        , blue_ghost(10, ge211::Color::medium_blue())
{}

void View::draw(ge211::Sprite_set& set, Model const& model)
{
    set.add_sprite(pacman_sprite, model.pac_pos());
    set.add_sprite(red_ghost, model.red_ghost_pos());
    set.add_sprite(blue_ghost, model.blue_ghost_pos());

    food_l = 127;

// Draw the map with block and white dots
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++) {
            if(model.blockMap[i][j] == 2){
                set.add_sprite(white_square, {i * 30, j * 30});
            } else if(model.blockMap[i][j] == 1){
                set.add_sprite(white_circle, { i * 30 + 15, j * 30 + 15});
            } else if(model.blockMap[i][j] == 3){
                --food_l;
                count_block.reconfigure(ge211::Text_sprite::Builder(font) << "Left Food: " << food_l);
                set.add_sprite(count_block, {460, 100});
            }
        }
    }

    if(food_l == 0){
        set.add_sprite(game_win, {500,200});
    }

    if (model.pacman_pos_.x + 15 >= model.red_ghost_pos_.x
        && model.pacman_pos_.x - 15 <= model.red_ghost_pos_.x
        && model.pacman_pos_.y + 15 >= model.red_ghost_pos_.y
        && model.pacman_pos_.y - 15 <= model.red_ghost_pos_.y){
        set.add_sprite(game_over, {500,500});
    }

    if (model.pacman_pos_.x + 15 >= model.blue_ghost_pos_.x
        && model.pacman_pos_.x - 15 <= model.blue_ghost_pos_.x
        && model.pacman_pos_.y + 15 >= model.blue_ghost_pos_.y
        && model.pacman_pos_.y - 15 <= model.blue_ghost_pos_.y){
        set.add_sprite(game_over, {500,500});
    }
}

