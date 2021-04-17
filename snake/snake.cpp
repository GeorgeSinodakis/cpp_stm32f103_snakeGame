#include "snake.h"
#include <math.h>
#include <algorithm>
#include "st7735.h"
#include "delay.h"

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

Game::Game()
{
    UP = {0, -1};
    DOWN = {0, +1};
    LEFT = { -1, 0};
    RIGHT = { +1, 0};
}

void Game::init()
{
    snake.clear();
    snake.push_back(std::make_pair(7, 5));
    snake.push_back(std::make_pair(6, 5));
    snake.push_back(std::make_pair(5, 5));
    snake.push_back(std::make_pair(4, 5));
    snake.push_back(std::make_pair(3, 5));

    apple = {1, 1};

    dir = RIGHT;

    //clear the screen
    st7735_fill(backgroundColor);
}

void Game::draw()
{
    u16 color;
    u16 x, y;

    //erase last cube of the snake and redraw it
    x = last.first * cube_size;
    y = last.second * cube_size;
    st7735_rect(x, y, x + cube_size - 1, y + cube_size - 1, backgroundColor);

    for (int i = 0; i < snake.size(); i++)
    {
        color = ((snake.size() - i) * 0b111111 / snake.size()) << 5;
        x = snake[i].first * cube_size;
        y = snake[i].second * cube_size;
        st7735_rect(x, y, x + cube_size - 1, y + cube_size - 1, color);
    }

    //draw apple
    x = apple.first * cube_size;
    y = apple.second * cube_size;
    st7735_rect(x, y, x + cube_size - 1, y + cube_size - 1, appleColor);
}

void Game::move()
{
    //if the apple has not been eaten
    if (snake[0] != apple)
    {
        last = snake[snake.size()-1];
        snake.pop_back(); 
    } 
    else new_apple();

    snake.insert(snake.begin(), {snake[0].first, snake[0].second});
    snake[0].first += dir.first;
    snake[0].second += dir.second;
    
    if (snake[0].first < 0) snake[0].first = ST7735_TFTWIDTH / cube_size - 1;
    if (snake[0].second < 0) snake[0].second = ST7735_TFTWIDTH / cube_size - 1;
    if (snake[0].first >= ST7735_TFTWIDTH / cube_size) snake[0].first = 0;
    if (snake[0].second >= ST7735_TFTLENGTH / cube_size) snake[0].second = 0;
}

void Game::loss_check()
{
    for (auto cube : snake)
    {
        if(std::count(snake.begin(), snake.end(), cube) > 1)
        {
            loss_message();
            //reset the game
            init();
            return;                
        }
    }
}

void Game::loss_message()
{
    st7735_fill(RED);
    std::string message = "You lost!!!";
    std::string score = "Score: " + std::to_string(snake.size()); 
    st7735_print_str(0, 50, 2, WHITE, RED, &message);
    st7735_print_str(0, 80, 2, WHITE, RED, &score);
    ms(2000);
}

void Game::new_apple()
{
    int x, y;
    bool flag = false;
    while (!flag)
    {
        flag = true;
        x = rand() % (ST7735_TFTWIDTH / cube_size);
        y = rand() % (ST7735_TFTLENGTH / cube_size);
        for (int i = 0; i < snake.size(); i++)
        {
            if (snake[i] == std::make_pair(x, y)) flag = false;
        }
        if (snake[0].first == x || snake[0].second == y) flag = false;
    }
    apple = std::make_pair(x, y);
}

void Game::goUp()
{
    if (dir == LEFT || dir == RIGHT) dir = UP;
}

void Game::goDown()
{
    if (dir == LEFT || dir == RIGHT) dir = DOWN;
}

void Game::goLeft()
{
    if (dir == UP || dir == DOWN) dir = LEFT;
}

void Game::goRight()
{
    if (dir == UP || dir == DOWN) dir = RIGHT;
}