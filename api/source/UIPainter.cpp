#include "UIPainter.hpp"
#include "SDL.h"

UIPainter::UIPainter() {
    SDL_Init(SDL_INIT_EVENTS);
}

void UIPainter::showMessage(const std::string& message) const {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Message", message.c_str() , NULL);
}
