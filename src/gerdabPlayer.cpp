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

Mix_Music* GerdabPlayer::music;
std::string GerdabPlayer::nextMusic;
void GerdabPlayer::resume()
{
    Mix_ResumeMusic();
}
void GerdabPlayer::setNextMusic(std::string path)
{
    nextMusic = path;
}

void GerdabPlayer::goToNext(){
  GerdabPlayer::stop();
  GerdabPlayer::setMusic(GerdabPlayer::nextMusic);
  GerdabPlayer::play();
}

void musicFinishCallback(){
  GerdabPlayer::goToNext();
}

void GerdabPlayer::play()
{
    Mix_PlayMusic(music, 1);
    Mix_HookMusicFinished(musicFinishCallback);
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
