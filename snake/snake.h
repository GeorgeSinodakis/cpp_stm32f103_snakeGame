#include <vector>
#include <utility>      // std::pair, std::make_pair

#define cube_size	        (int)16
#define backgroundColor 	(uint16_t)0b0011000110000110
#define appleColor          (uint16_t)0b1111100000000000

class Game
{
public:
	std::pair <int, int> UP;
	std::pair <int, int> DOWN;
	std::pair <int, int> LEFT;
	std::pair <int, int> RIGHT;
	std::vector <std::pair<int, int>> snake;
	std::pair <int, int> apple;
	std::pair <int, int> dir;
	std::pair <int, int> last;
public:
	Game();
	void init();
	void draw();
	void move();
	void loss_check();
	void new_apple();
	void loss_message();
	void goUp();
	void goDown();
	void goLeft();
	void goRight();
};