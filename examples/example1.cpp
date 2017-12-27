#include "../src/gerdabPlayer.hpp"
int main(int argc, char* argv[]){
  GerdabPlayer player;
  player.setMusic("examples/test.wav");
  char c;
  while (1) {
    std::cin>>c;
    std::cout<<player.getRemainingTime()<<std::endl;
    if(c == 'p')
      player.play();
    else if(c == 's')
      player.stop();
    else
      player.pause();
  }
}
