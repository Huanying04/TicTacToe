#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button{
    public:
        Button(){}

        Button(sf::Vector2f size, sf::Color color) {
            btn.setSize(size);
            btn.setFillColor(color);
        }

        void setColor(sf::Color color) {
            btn.setFillColor(color);
        }

        void setTexture(const sf::Texture* texture) {
            btn.setTexture(texture, true);
        }

        void setPos(sf::Vector2f pos) {
            btn.setPosition(pos);
        }

        void drawTo(sf::RenderWindow& window) {
            window.draw(btn);
        }

        bool isMouseHover(sf::RenderWindow& window) {
            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;
            
            int btnPosX = btn.getPosition().x;
            int btnPosY = btn.getPosition().y;

            int btnWidthEndX = btn.getPosition().x + btn.getLocalBounds().width;
            int btnHeightEndY = btn.getPosition().y + btn.getLocalBounds().height;

            return (mouseX < btnWidthEndX && mouseX > btnPosX && mouseY < btnHeightEndY && mouseY > btnPosY);
        }
    private:
        sf::RectangleShape btn;
};