#include "gerdabPlayer.hpp"
#include <iostream>

using namespace std;

GerdabError::GerdabError(){}

GerdabError::GerdabError(std::string errorMessage){
    message = errorMessage;
  }
std::string GerdabError::getMessage()
{
    return message;
  }

void GerdabPlayer::resume()
{
    Mix_ResumeMusic();
}

void GerdabPlayer::play()
{
    Mix_PlayMusic(music, 1);
}

void GerdabPlayer::setMusic(std::string path)
{
  Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
  music = Mix_LoadMUS(path.c_str());
}
void GerdabPlayer::pause()
{
  Mix_PauseMusic();
}
void GerdabPlayer::stop()
{
  Mix_HaltMusic();
}

int GerdabPlayer::getRemainingTime()
{
  return 0;
}