#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

/*
* do zrobienia póŸniej. generator du¿ej iloœci obiektów przy kliknienciu
* 
std::vector<sf::CircleShape> shape_vector_generator(int n) {
    std::vector<sf::CircleShape> sh_vec;
    sf::CircleShape circle;

    for (int i = 0; i < n; i++) {
        sh_vec.push_back()
    }

    return sh_vec;
}

*/
int main()
{
    #define WW  1800
    #define WH  1200
    #define font_size 18

    sf::RenderWindow window(sf::VideoMode(WW,WH), "SFML works!");
    
    sf::Font inconsolata_font;

    if (!inconsolata_font.loadFromFile("inconsolata.ttf"))
        {
        std::cout << "nie znaleziono czcionki! \n";
        }

    sf::RectangleShape text_rect;
    text_rect.setSize(sf::Vector2f(WW-6, font_size+8));
    text_rect.setPosition(sf::Vector2f(2, WH - 34));
    text_rect.setOutlineThickness(2);
    text_rect.setOutlineColor(sf::Color::Blue);
    text_rect.setFillColor(sf::Color::Black);


    sf::Text mouse_text_l;
    sf::Text mouse_text_m;
    sf::Text mouse_text_r;
    mouse_text_l.setFont(inconsolata_font);
    mouse_text_l.setString("Start!");
    mouse_text_l.setCharacterSize(font_size);
    mouse_text_l.setFillColor(sf::Color::White);
    mouse_text_l.setPosition(sf::Vector2f(10, WH - font_size -12));
    
    mouse_text_r.setFont(inconsolata_font);
    mouse_text_r.setString("Start!");
    mouse_text_r.setCharacterSize(font_size);
    mouse_text_r.setFillColor(sf::Color::Red);
    mouse_text_r.setPosition(sf::Vector2f(2*(WW/3)+10, WH - font_size - 12));

    mouse_text_m.setFont(inconsolata_font);
    mouse_text_m.setString("Start!");
    mouse_text_m.setCharacterSize(font_size);
    mouse_text_m.setFillColor(sf::Color::Red);
    mouse_text_m.setPosition(sf::Vector2f(WW/3+10, WH - font_size - 12));

    std::string mouse_string;

    sf::CircleShape shape(5.f);
    shape.setFillColor(sf::Color::Green);

    std::vector<sf::CircleShape> shape_vector;


    

// Main processing loop


    while (window.isOpen())
    {
        sf::Event event;
        
        //events pooling
        while (window.pollEvent(event))
        {
            switch (event.type){
            
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    //std::cout << "Nacisnieto: " << event.key.code << " \n";
                    mouse_string = "Nacisnieto:" + std::to_string(event.key.code);
                    mouse_text_m.setString(mouse_string);
                    break;

                case sf::Event::KeyReleased:
                    //std::cout << "Puszczono: " << event.key.code << " \n";
                    mouse_string = " Puszczono:" + std::to_string(event.key.code);
                    mouse_text_m.setString(mouse_string);
                    break;


                case sf::Event::MouseButtonPressed:
                    //std::cout << "kliknieto mysz: " << event.mouseButton.button << " w lokalizacji: x=" << event.mouseButton.x << " , y=" << event.mouseButton.y << "\n";
                    mouse_string = "Klikniecie. BTN= "+std::to_string(event.mouseButton.button) + " x="+ std::to_string(event.mouseButton.x) 
                                    +" y=" + std::to_string(event.mouseButton.y);
                    mouse_text_r.setString(mouse_string);

                    shape.setPosition(event.mouseButton.x, event.mouseButton.y);
                    shape_vector.push_back(shape);


                    break;

                case sf::Event::MouseButtonReleased:
                    //std::cout << "puszczono mysz: " << event.mouseButton.button << " w lokalizacji: x=" << event.mouseButton.x << " , y=" << event.mouseButton.y << "\n";
                    mouse_string = " Puszczono. BTN= " + std::to_string(event.mouseButton.button) + " x=" + std::to_string(event.mouseButton.x)
                        + " y=" + std::to_string(event.mouseButton.y);
                    mouse_text_r.setString(mouse_string);
                    break;

                case sf::Event::MouseMoved:
                    //std::cout << "ruszono mysz w lokalizacji: x=" << event.mouseMove.x << " , y=" << event.mouseMove.y << "\n";
                    mouse_string = "Pozycja myszy: x=" + std::to_string(event.mouseMove.x) + " , y=" + std::to_string(event.mouseMove.y);
                    mouse_text_l.setString(mouse_string);
                    break;

            }

        }

        window.clear();
        
        for (sf::CircleShape s : shape_vector) {
            window.draw(s);
        }
                      
        window.draw(text_rect);
        window.draw(mouse_text_l);
        window.draw(mouse_text_m);
        window.draw(mouse_text_r);
        
        
        
        window.display();
    }

    return 0;
}