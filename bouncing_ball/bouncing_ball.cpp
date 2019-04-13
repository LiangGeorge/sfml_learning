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
    srand(time(NULL));
    delta_y = float(rand() % 5);
    delta_x = float(rand() % 5);

    while (window.isOpen()){
      sf::Event event;
      while(window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
          window.close();
        }
      }
      int distance_traveled;
      sf::Vector2f position = circle0.getPosition();
      if (position.x > 1024 - radius * 2 && delta_x > 0){
        delta_x *= -1;
      }
      if (position.x < 0 && delta_x < 0){
          delta_x *= -1;
      }
      if (position.y < 0 && delta_y < 0){
        delta_y *= -1;
      }
      if (position.y > 576 - radius * 2 && delta_y > 0){
        delta_y *= -1;
      }
      //printf("%f",position.x);
      startx += delta_x;
      starty += delta_y;
      circle0.setPosition(startx,starty);

      srand(time(NULL));
      delta_y = float(rand() % 5);
      delta_x = float(rand() % 5);

      window.clear();
      window.draw(circle0);
      window.display();
  }
  return 0;
}
