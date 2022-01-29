#include <App.hpp>
void App::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                {
                    sf::FloatRect view(0, 0, event.size.width, event.size.height);
                    window.setView(sf::View(view));
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {

                    break;
                }
                default:
                    break;
            }
        }
        window.clear();
        window.display();
    }

}
