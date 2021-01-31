#include "model.hxx"
#include <catch.hxx>

// Test if the game can start
TEST_CASE("Construct Model")
{
    Model model;
    CHECK ( model.pacman_pos_.x == 50);
    CHECK ( model.pacman_pos_.y == 280);
    CHECK ( model.food.size() == 225 );





}


// Test if the pacman can move
TEST_CASE("MOVE PACMAN")
{
    Model m;
    ge211::Position before = m.pac_pos();
    m.move_pacman();
    ge211::Position after = m.pac_pos();

    CHECK ( after == before.down_by(m.pacman_vel.height).right_by(m.pacman_vel.width) );
}


TEST_CASE("Move Ghosts")
{
    Model m;
    ge211::Position before = m.red_ghost_pos_;
    m.move_ghosts();
    CHECK(before != m.red_ghost_pos_);

}


TEST_CASE("Pacman Eats Food")
{
    Model m;
    m.pacman_pos_ += {5,0};
    CHECK(m.food.size() == 225);
}

TEST_CASE("Move Blue Ghost")
{
    Model m;
    ge211::Position before = m.blue_ghost_pos_;
    m.move_blue_ghost();
    CHECK(before != m.blue_ghost_pos_);




}