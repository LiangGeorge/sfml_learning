#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cmath>
#include <time.h>

int main(){
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1024, 576), "Experimental",sf::Style::Default,settings);
    int radius = 50;
    sf::CircleShape circle0(radius,50);
    circle0.setFillColor(sf::Color::Blue);
    float startx;
    float starty;
    startx = 200;
    starty = 200;
    float delta_y;
    float delta_x;
    delta_y = 0.7;
    delta_x = 0.8;

    while (window.isOpen()){
      sf::Event event;
      while(window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
          window.close();
        }
      }
      //Check the ball's current position to save it. This makes comparison a bit more readable
      sf::Vector2f position = circle0.getPosition();
      //The ball's position is actually describing its top left corner
      if (position.x > 1024 - radius * 2 && delta_x > 0){
        delta_x *= -1;
        circle0.setFillColor(sf::Color::Blue);
      } //Create bounds for right side of screen
      if (position.x < 0 && delta_x < 0){
          delta_x *= -1;
          circle0.setFillColor(sf::Color::Red);
      } //Create bounds for left side of screen
      if (position.y < 0 && delta_y < 0){
        delta_y *= -1;
        circle0.setFillColor(sf::Color::Green);
      } //Create bounds for top side of screen
      if (position.y > 576 - radius * 2 && delta_y > 0){
        delta_y *= -1;
        circle0.setFillColor(sf::Color::Yellow);
      } //Create bounds for bottom side of screen
      //printf("%f",position.x);
      startx += delta_x;
      starty += delta_y;
      //Alter our ball's position based on change
      circle0.setPosition(startx,starty);

      window.clear();
      window.draw(circle0);
      window.display();
  }
  return 0;
}
