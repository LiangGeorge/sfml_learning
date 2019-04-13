#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cmath>
int main(){
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1024, 576), "Experimental",sf::Style::Default,settings);
    float radius = 50;
    sf::CircleShape circle0(50,50);
    sf::Clock clock;
    circle0.setFillColor(sf::Color::Blue);
    float gravity;
    gravity = 2.0;
    float startx;
    float starty;
    startx = 200;
    starty = 200;
    float last_pos;
    last_pos = 200;
    int move_units;
    move_units = 25;
    float delta_y = 0.5;

    //clock.restart();
    while (window.isOpen()){
      clock.restart();
      sf::Event event;
      while(window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
          window.close();
        }
      }
      int distance_traveled;
      //sf::Time elapsed_time = clock.getElapsedTime();
      //int delta_y = move_units * elapsed_time.asSeconds();
      sf::Vector2i localPosition = sf::Mouse::getPosition(window);
      //circle0.setPosition(localPosition.x - 100,localPosition.y - 100);
      printf("%f \n",circle0.getPosition().y);
      if (circle0.getPosition().y > 576 - radius * 2 && delta_y > 0){
        clock.restart();
        delta_y *= -1;
        //elapsed_time = clock.getElapsedTime();
      }
      else if (circle0.getPosition().y < 0 && delta_y < 0){
        clock.restart();
        delta_y *= -1;
        //elapsed_time = clock.getElapsedTime();
      }
      last_pos += delta_y;
      //starty += delta_y;
      circle0.setPosition(startx,last_pos);
      window.clear();
      window.draw(circle0);
      window.display();
  }
  return 0;
}
