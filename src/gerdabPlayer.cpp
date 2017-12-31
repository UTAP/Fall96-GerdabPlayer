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


GerdabPlayer::GerdabPlayer(){
  Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
  index = 0;
  repeat = 0;
}

Mix_Music* GerdabPlayer::music;
bool GerdabPlayer::repeat;
int GerdabPlayer::index;
std::vector<std::string> GerdabPlayer::queue;
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

void GerdabPlayer::goToNext(){
  GerdabPlayer::stop();
  index++;
  if(index >= queue.size()){
    if(repeat){
      index = 0;
    }else{
      queue.clear();
      return;
    }
  }
  GerdabPlayer::setMusic(queue[index]);
  GerdabPlayer::play();
}

void musicFinishCallback(){
  GerdabPlayer::goToNext();
}

void GerdabPlayer::play()
{

    if(queue.size() != 0){
      cout<<queue[index]<<endl;
      music = Mix_LoadMUS(queue[index].c_str());
      Mix_PlayMusic(music, 1);
      Mix_HookMusicFinished(musicFinishCallback);
    }

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

void GerdabPlayer::setRepeat(bool _repeat)
{ 
  repeat = _repeat;
}
void GerdabPlayer::setQueue(std::vector<std::string> _queue)
{
  queue = _queue;
}

