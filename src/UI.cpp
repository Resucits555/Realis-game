#include "general.h"

sf::Texture mainTexture("../data/UI/mainTexture.png");

UIObject bottom{ sf::Sprite(mainTexture) };
const position saveUL = { 13, 928 }, saveBR = { 55, 971 };

UIObject mainWindow{ sf::Sprite(mainTexture), false };


static bool DetectTouch(position mousePos, position upleft, position bottomright) {
    if (mousePos.x > upleft.x && mousePos.x < bottomright.x &&
        mousePos.y > upleft.y && mousePos.y < bottomright.y)
        return true;
    else return false;
}



void ProcessUI(position mousePos) {
    std::cout << mousePos.x << ", " << mousePos.y << '\n';

    if (DetectTouch(mousePos, saveUL, saveBR))
        mainWindow.active = true;
}