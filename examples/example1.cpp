#include "../src/gerdabPlayer.hpp"
#include <string>
#include <vector>

using namespace std;


int main(int argc, char* argv[]){
  string m1 = "examples/beat.wav";
  string m2 = "examples/beat.wav";
  string m3 = "examples/beat.wav";
  // string m2 = "examples/book.wav";

  vector<string> queue;
  queue.push_back(m1);
  queue.push_back(m2);
  queue.push_back(m3);
  GerdabPlayer player;
  
  player.setQueue(queue);
  player.setRepeat(0);
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
