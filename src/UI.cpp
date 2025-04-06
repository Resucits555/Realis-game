#include <fstream>
#include "general.h"


sf::Texture mainTexture("../data/UI/mainTexture.png");

UIObject bottom{ sf::Sprite(mainTexture) };
const position saveSelectUL = { 13, 928 }, saveSelectBR = { 55, 971 };
const position saveUL = { 69, 926 }, saveBR = { 958, 967 };

UIObject bigWindow{ sf::Sprite(mainTexture), false };

position mousePos;


static bool DetectTouch(position upleft, position bottomright) {
    if (mousePos.x > upleft.x && mousePos.x < bottomright.x &&
        mousePos.y > upleft.y && mousePos.y < bottomright.y)
        return true;
    else return false;
}



void ProcessUI(position mousePosition) {
    mousePos = mousePosition;
    std::cout << mousePos.x << ", " << mousePos.y << '\n';

    if (DetectTouch(saveSelectUL, saveSelectBR))
        bigWindow.active = true;
    /*if (DetectTouch(saveUL, saveBR)) {
        bigWindow.active = true;
        std::ofstream newSave;
        newSave.open("../data/saves/newSave.txt", std::ios::binary);

        if (!newSave.is_open()) {
            std::cerr << "Unable to open file";
            window.close();
            return;
        }
        
        
        newSave.close();
    }*/
}