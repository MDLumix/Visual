#include <SFML/Graphics.hpp>
#include <iostream>
#include<cmath>


struct Vec2d {
    float x, y, mag, angle;

    
};

struct Arrow {
    sf::ConvexShape bar;
    sf::ConvexShape head;

};



Arrow Draw_Arrow(Vec2d vec, float width, float lenght) {

    sf::ConvexShape bar;
    
    bar.setPointCount(4);
    bar.setPoint(0, sf::Vector2f(-width,   0));
    bar.setPoint(1, sf::Vector2f(-width, lenght));
    bar.setPoint(2, sf::Vector2f(width, lenght));
    bar.setPoint(3, sf::Vector2f(width,   0));
    bar.rotate(vec.angle);
    bar.move(vec.x, vec.y);

    sf::ConvexShape head;
    head.setPointCount(3);
    head.setPoint(0, sf::Vector2f(-width*5, lenght));
    head.setPoint(1, sf::Vector2f(  0, float(lenght+0.2*lenght)));
    head.setPoint(2, sf::Vector2f( width*5, lenght));
    head.rotate(vec.angle);
    head.move(vec.x, vec.y);

    Arrow arrow2;
    arrow2.bar  = bar;
    arrow2.head = head;


    return arrow2;
}










int main()
{
    float WW = 1200;
    float WH = 1200;
    sf::RenderWindow window(sf::VideoMode(int(WW), int(WH)), "SFML works!");
    
    int const nx = 50;
    int const dx = int(1200 / nx);
    int const ny = 50;
    int const dy = int(1200 / ny);
    std::vector<std::vector<Arrow>> arrow_array(nx,std::vector<Arrow>(ny));

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            Vec2d v1;
            v1.x = float(i * dx);
            v1.y = float(j * dy);
            v1.angle = 360 * std::sin(float(10*i*3.14/180)) * std::cos(float(10*j*3.14/180));
            //std::cout << v1.angle<<" ";
            arrow_array[i][j] = Draw_Arrow(v1,1,20);
        }
    }



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        window.clear();
        
     
        for (int i = 0; i < nx; i++) {
            for (int j = 0; j < ny; j++) {
                window.draw(arrow_array[i][j].bar);
                window.draw(arrow_array[i][j].head);
            }
        }

                   
        //Arrow arrow1 = Draw_Arrow(400,400,30,1,20);
        //window.draw(arrow1.bar);
        //window.draw(arrow1.head);
        
        window.display();
    }

    return 0;
}