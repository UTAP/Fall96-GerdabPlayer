#include "../src/gerdabPlayer.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

int main(int argc, char* argv[]){
  GerdabPlayer player;
  player.setMusic("examples/beat.wav");
  // Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
  // Mix_PlayMusic(music, 1);
  // Mix_Music *music = Mix_LoadMUS("examples/beat.wav");

  // while(1){}
  char c;
  while (1) {
    std::cin>>c;
    // std::cout<<player.getRemainingTime()<<std::endl;
    if(c == 'p')
      player.play();
    else if(c == 's')
      player.stop();
    else
      player.pause();
  }
}
