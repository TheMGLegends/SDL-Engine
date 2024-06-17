#include "TextureHandler.h"

std::unordered_map<Texture, SDL_Texture*> TextureHandler::textureLib;
int TextureHandler::textureCount = 0;