#include "gerdabPlayer.hpp"
#include <iostream>

using namespace std;
Uint32 GerdabPlayer::audio_len = 0;
Uint8* GerdabPlayer::audio_pos;
GerdabError::GerdabError(){}
GerdabError::GerdabError(std::string errorMessage){
    message = errorMessage;
  }
std::string GerdabError::getMessage()
{
    return message;
  }
void GerdabPlayer::audioCallback(void *userdata, Uint8 *stream, int len)
{
      if (audio_len ==0)
        return;
      len = ( len > audio_len ? audio_len : len );
      // SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);
      

      audio_pos += len;
      audio_len -= len;
}
void GerdabPlayer::startStream()
{
    	while (!terminated){
        while(!finished){
        }
        // Mix_FreeMusic(music);
      }
    }
GerdabPlayer::GerdabPlayer()
{
      playing = false;
      finished = false;
      terminated = false;
      started = false;
      stream = new std::thread(&GerdabPlayer::startStream, this);
      wavFilePath = "";
}

void GerdabPlayer::play()
{
    playing = true;
    finished = false;
    Mix_PlayMusic(music, 1);
}

void GerdabPlayer::setMusic(std::string path)
{
  playing = false;
  started = true;
  finished = true;
  wavFilePath = path;
  Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
  music = Mix_LoadMUS(path.c_str());
}
void GerdabPlayer::pause()
{
  playing = false;
  Mix_PauseMusic();
}
void GerdabPlayer::stop()
{
  playing = false;
  finished = true;
  started = false;
}
int GerdabPlayer::getRemainingTime()
{
  return (int) audio_len;
}
void GerdabPlayer::terminate(){
  terminated = true;
  finished = true;
}
GerdabPlayer::~GerdabPlayer(){
  terminate();
  if(stream){
    if(stream->joinable())
      stream->detach();
  }
}
