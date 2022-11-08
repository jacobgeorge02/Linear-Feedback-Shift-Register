#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"

void transform(sf::Image &, FibLFSR *);

int main(int argc, char *argv[])
{
    sf::Image original;
    sf::Image encodedImage;

    if (!original.loadFromFile(argv[1]))
    {
        std::cout << "Could not load original properly" << std::endl;
        return 1;
    }

    FibLFSR Shift(argv[3]);

    if (!encodedImage.loadFromFile(argv[1]))
    {
        std::cout << "Could not load encoded image properly" << std::endl;
        return 1;
    }

    transform(encodedImage, &Shift);
    encodedImage.saveToFile(argv[2]);

    // printing to multiple windows

    sf::Texture decodedTexture;
    sf::Texture encodedTexture;

    decodedTexture.loadFromImage(original);
    encodedTexture.loadFromImage(encodedImage);

    sf::Sprite decodedSprite;
    decodedSprite.setTexture(decodedTexture);

    sf::Sprite encodedSprite;
    encodedSprite.setTexture(encodedTexture);

    sf::RenderWindow window1(sf::VideoMode(355, 265), "Original Window");
    sf::RenderWindow window2(sf::VideoMode(355, 265), "Encoded Window");

    while (window1.isOpen() && window2.isOpen())
    {
        sf::Event event;

        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window1.close();
        }

        while (window2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window2.close();
        }

        window1.clear();
        window1.draw(decodedSprite);
        window1.display();
        window2.clear();
        window2.draw(encodedSprite);
        window2.display();
    }

    return 0;
}

void transform(sf::Image &transformedImage, FibLFSR *initialSeed)
{
    sf::Vector2u size = transformedImage.getSize();
    sf::Color pixel;

    for (int x = 0; x < size.x; x++)
    {
        for (int y = 0; y < size.y; y++)
        {
            pixel = transformedImage.getPixel(x, y);            // get a pixel
            pixel.r = 255 - pixel.r ^ initialSeed->generate(8); // xor the red, green and blue pixels together
            pixel.g = 255 - pixel.g ^ initialSeed->generate(8);
            pixel.b = 255 - pixel.b ^ initialSeed->generate(8);
            transformedImage.setPixel(x, y, pixel); // set the new pixel to the transformed images
        }
    }
}
