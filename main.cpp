#include <SFML/Graphics.hpp>
#include <iostream>
#include <Button.h>
#include <string.h>

short chart[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
bool player = false;
sf::Texture circle;
sf::Texture cross;

bool isPlayerWin() {
    return ((chart[0][0] == chart[0][1] && chart[0][1] == chart[0][2] && chart[0][0] != 0)
            || (chart[1][0] == chart[1][1] && chart[1][1] == chart[1][2] && chart[1][0] != 0)
            || (chart[2][0] == chart[2][1] && chart[2][1] == chart[2][2] && chart[2][0] != 0)
            || (chart[0][0] == chart[1][0] && chart[1][0] == chart[2][0] && chart[0][0] != 0)
            || (chart[0][1] == chart[1][1] && chart[1][1] == chart[2][1] && chart[0][1] != 0)
            || (chart[0][2] == chart[1][2] && chart[1][2] == chart[2][2] && chart[0][2] != 0)
            || (chart[0][0] == chart[1][1] && chart[1][1] == chart[2][2] && chart[0][0] != 0)
            || (chart[0][2] == chart[1][1] && chart[1][1] == chart[2][0] && chart[0][2] != 0));
}

bool isEven() {
    return (chart[0][0] != 0 && chart[0][1] != 0 && chart[0][2] != 0
            && chart[1][0] != 0 && chart[1][1] != 0 && chart[1][2] != 0
            && chart[2][0] != 0 && chart[2][1] != 0 && chart[2][2] != 0);
}

sf::Texture* getCurrentPlayerTexture() {
    if (player == true) {
        return &circle;
    } else {
        return &cross;
    }
}

int main() {
    bool stillHovering = 0;
    
    bool gameOver = false;
    sf::Cursor cursor;
    sf::RenderWindow window(sf::VideoMode(500, 660), "TicTacToe", sf::Style::Close);

    sf::Image icon;
    icon.loadFromFile("assets/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::RectangleShape currentPlayer(sf::Vector2f(120.0f, 120.0f));
    sf::RectangleShape gameoverText1(sf::Vector2f(130.0f, 130.0f));
    sf::RectangleShape gameoverText2(sf::Vector2f(130.0f, 130.0f));
    sf::RectangleShape playAgainHint(sf::Vector2f(200.0f, 25.0f));
    Button btn11(sf::Vector2f(155.0f, 145.0f), sf::Color::White);
    Button btn12(sf::Vector2f(150.0f, 145.0f), sf::Color::White);
    Button btn13(sf::Vector2f(135.0f, 145.0f), sf::Color::White);
    Button btn21(sf::Vector2f(155.0f, 150.0f), sf::Color::White);
    Button btn22(sf::Vector2f(150.0f, 150.0f), sf::Color::White);
    Button btn23(sf::Vector2f(135.0f, 150.0f), sf::Color::White);
    Button btn31(sf::Vector2f(155.0f, 145.0f), sf::Color::White);
    Button btn32(sf::Vector2f(150.0f, 145.0f), sf::Color::White);
    Button btn33(sf::Vector2f(135.0f, 145.0f), sf::Color::White);
    currentPlayer.setPosition(sf::Vector2f(203.0f, 21.0f));
    gameoverText1.setPosition(sf::Vector2f(55.0f, 15.0f));
    gameoverText2.setPosition(sf::Vector2f(333.0f, 15.0f));
    playAgainHint.setPosition(sf::Vector2f(150.0f, 146.0f));
    btn11.setPos(sf::Vector2f(25.0f, 185.0f));
    btn12.setPos(sf::Vector2f(185.0f, 185.0f));
    btn13.setPos(sf::Vector2f(340.0f, 185.0f));
    btn21.setPos(sf::Vector2f(25.0f, 335.0f));
    btn22.setPos(sf::Vector2f(185.0f, 335.0f));
    btn23.setPos(sf::Vector2f(340.0f, 335.0f));
    btn31.setPos(sf::Vector2f(25.0f, 490.0f));
    btn32.setPos(sf::Vector2f(185.0f, 490.0f));
    btn33.setPos(sf::Vector2f(340.0f, 490.0f));

    sf::Texture bgTexture;
    sf::Texture gameoverTexture1;
    sf::Texture gameoverTexture2;
    sf::Texture gameoverTexture3;
    sf::Texture gameoverTexture4;
    sf::Texture playAgainHintTexture;
    sf::Texture nothing;
    bgTexture.loadFromFile("assets/bg.png");
    circle.loadFromFile("assets/circle.png");
    cross.loadFromFile("assets/cross.png");
    gameoverTexture1.loadFromFile("assets/gameover1.png");
    gameoverTexture2.loadFromFile("assets/gameover2.png");
    gameoverTexture3.loadFromFile("assets/gameover3.png");
    gameoverTexture4.loadFromFile("assets/gameover4.png");
    playAgainHintTexture.loadFromFile("assets/playagain_hint.png");
    sf::Sprite s(bgTexture);
    currentPlayer.setTexture(&cross);
    playAgainHint.setTexture(&playAgainHintTexture);

    bgTexture.setSmooth(true);
    gameoverTexture1.setSmooth(true);
    gameoverTexture2.setSmooth(true);
    gameoverTexture3.setSmooth(true);
    gameoverTexture4.setSmooth(true);
    playAgainHintTexture.setSmooth(true);
    circle.setSmooth(true);
    cross.setSmooth(true);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left && !gameOver) {
                    if (btn11.isMouseHover(window)) {
                        if (chart[0][0] == 0) {
                            btn11.setTexture(getCurrentPlayerTexture());
                            chart[0][0] = player + 1;
                            player = !player;
                        }
                    }else if (btn12.isMouseHover(window)) {
                        if (chart[0][1] == 0) {
                            btn12.setTexture(getCurrentPlayerTexture());
                            chart[0][1] = player + 1;
                            player = !player;
                        }
                    }else if (btn13.isMouseHover(window)) {
                        if (chart[0][2] == 0) {
                            btn13.setTexture(getCurrentPlayerTexture());
                            chart[0][2] = player + 1;
                            player = !player;
                        }
                    }else if (btn21.isMouseHover(window)) {
                        if (chart[1][0] == 0) {
                            btn21.setTexture(getCurrentPlayerTexture());
                            chart[1][0] = player + 1;
                            player = !player;
                        }
                    }else if (btn22.isMouseHover(window)) {
                        if (chart[1][1] == 0) {
                            btn22.setTexture(getCurrentPlayerTexture());
                            chart[1][1] = player + 1;
                            player = !player;
                        }
                    }else if (btn23.isMouseHover(window)) {
                        if (chart[1][2] == 0) {
                            btn23.setTexture(getCurrentPlayerTexture());
                            chart[1][2] = player + 1;
                            player = !player;
                        }
                    }else if (btn31.isMouseHover(window)) {
                        if (chart[2][0] == 0) {
                            btn31.setTexture(getCurrentPlayerTexture());
                            chart[2][0] = player + 1;
                            player = !player;
                        }
                    }else if (btn32.isMouseHover(window)) {
                        if (chart[2][1] == 0) {
                            btn32.setTexture(getCurrentPlayerTexture());
                            chart[2][1] = player + 1;
                            player = !player;
                        }
                    }else if (btn33.isMouseHover(window)) {
                        if (chart[2][2] == 0) {
                            btn33.setTexture(getCurrentPlayerTexture());
                            chart[2][2] = player + 1;
                            player = !player;
                        }
                    }

                    if (isPlayerWin() || isEven()) {
                        gameOver = true;
                    }else {
                        if (player == true) {
                            currentPlayer.setTexture(&circle);
                        }else if (player == false) {
                            currentPlayer.setTexture(&cross);
                        }
                    }
                    
                }
                break;
            case sf::Event::KeyPressed:
                if (gameOver) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            chart[i][j] = 0;
                        }
                    }
                    btn11.setTexture(&nothing);
                    btn12.setTexture(&nothing);
                    btn13.setTexture(&nothing);
                    btn21.setTexture(&nothing);
                    btn22.setTexture(&nothing);
                    btn23.setTexture(&nothing);
                    btn31.setTexture(&nothing);
                    btn32.setTexture(&nothing);
                    btn33.setTexture(&nothing);
                    currentPlayer.setTexture(&cross);
                    player = false;
                    gameOver = false;
                }
                break;
            default:
                break;
            }
        }

        if (btn11.isMouseHover(window)
            || btn12.isMouseHover(window)
            || btn13.isMouseHover(window)
            || btn21.isMouseHover(window)
            || btn22.isMouseHover(window)
            || btn23.isMouseHover(window)
            || btn31.isMouseHover(window)
            || btn32.isMouseHover(window)
            || btn33.isMouseHover(window)) {
            if (cursor.loadFromSystem(sf::Cursor::Hand) && !stillHovering) {
                stillHovering = true;
                window.setMouseCursor(cursor);
            }
        } else {
            if (cursor.loadFromSystem(sf::Cursor::Arrow) && stillHovering) {
                stillHovering = false;
                window.setMouseCursor(cursor);
            }  
        }
        
        
        window.clear(sf::Color::White);
        window.draw(s);
        btn11.drawTo(window);
        btn12.drawTo(window);
        btn13.drawTo(window);
        btn21.drawTo(window);
        btn22.drawTo(window);
        btn23.drawTo(window);
        btn31.drawTo(window);
        btn32.drawTo(window);
        btn33.drawTo(window);
        window.draw(currentPlayer);
        if (isPlayerWin()) {
            gameoverText1.setTexture(&gameoverTexture1);
            gameoverText2.setTexture(&gameoverTexture2);
            window.draw(gameoverText1);
            window.draw(gameoverText2);
        }else if (isEven()) {
            gameoverText1.setTexture(&gameoverTexture3);
            gameoverText2.setTexture(&gameoverTexture4);
            window.draw(gameoverText1);
            window.draw(gameoverText2);
        }
        if (gameOver) {
            window.draw(playAgainHint);
        }
        
        
        window.display();
    }

    return 0;
}