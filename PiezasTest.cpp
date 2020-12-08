/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, init_board)
{
    Piezas p;
	ASSERT_TRUE(true);
}

TEST(PiezasTest, clears_board)
{
    Piezas p;
    p.dropPiece(0);
    p.reset();
	ASSERT_FALSE(p.pieceAt(0, 0) == X);
}

TEST(PiezasTest, drop_piece_out_bounds)
{
	ASSERT_TRUE(Piezas().dropPiece(4) == Invalid);
}

TEST(PiezasTest, drop_piece_in_bounds)
{
	ASSERT_TRUE(Piezas().dropPiece(0) == X);
}

TEST(PiezasTest, drop_pieces_in_same_col)
{
    Piezas p;
    p.dropPiece(1);
	ASSERT_TRUE(p.dropPiece(1) == O);
}

TEST(PiezasTest, overflow_col)
{
    Piezas p;
    p.dropPiece(2);
    p.dropPiece(2);
    p.dropPiece(2);
	ASSERT_FALSE(p.dropPiece(2) == O);
}

TEST(PiezasTest, get_out_bounds_piece)
{
	ASSERT_TRUE(Piezas().pieceAt(-1, -1) == Invalid);
}

TEST(PiezasTest, get_dropped_piece)
{
    Piezas p;
    p.dropPiece(0);
	ASSERT_TRUE(p.pieceAt(0, 0) == X);
}

TEST(PiezasTest, get_winner_of_incomplete_game)
{
    Piezas p;

    p.dropPiece(0);
    p.dropPiece(1);

    p.dropPiece(0);
    p.dropPiece(1);

    Piece winner = p.gameState();
	ASSERT_FALSE(winner == X || winner == O);
}

TEST(PiezasTest, get_winner_of_tie)
{
    Piezas p;

    p.dropPiece(0);
    p.dropPiece(1);

    p.dropPiece(0);
    p.dropPiece(1);

    p.dropPiece(0);
    p.dropPiece(1);

    p.dropPiece(2);
    p.dropPiece(3);

    p.dropPiece(2);
    p.dropPiece(3);

    p.dropPiece(2);
    p.dropPiece(3);

    Piece winner = p.gameState();
	ASSERT_FALSE(winner == X || winner == O);
}

TEST(PiezasTest, x_horizontal_win)
{
    Piezas p;
    p.dropPiece(0);
    p.dropPiece(0);

    p.dropPiece(1);
    p.dropPiece(1);

    p.dropPiece(2);
    p.dropPiece(3);

    p.dropPiece(3);
    p.dropPiece(3);

    p.dropPiece(2);
    p.dropPiece(2);

    p.dropPiece(1);
    p.dropPiece(0);

	ASSERT_TRUE(p.gameState() == X);
}

TEST(PiezasTest, o_vertical_win)
{
    Piezas p;
    
    p.dropPiece(0);
    p.dropPiece(1);

    p.dropPiece(0);
    p.dropPiece(1);

    p.dropPiece(2);
    p.dropPiece(1);

    p.dropPiece(3);
    p.dropPiece(2);

    p.dropPiece(3);
    p.dropPiece(3);

    p.dropPiece(2);
    p.dropPiece(0);

	ASSERT_TRUE(p.gameState() == O);
}
