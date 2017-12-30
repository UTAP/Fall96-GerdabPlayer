#include "../src/gerdabPlayer.hpp"

int main(int argc, char* argv[]){
  GerdabPlayer player;
  player.setMusic("examples/beat.wav");

  char c;
  while (1) {
    std::cin>>c;
    if(c == 'p'){
      player.play();
      player.setNextMusic("examples/book.wav");
    }
    else if(c == 's')
      player.stop();
    else if(c == 'r')
      player.resume();
    else if(c == 'd')
      player.pause();
    else if(c == 'n')
      player.setMusic("examples/book.wav");
    else
      player.pause();
  }
}
