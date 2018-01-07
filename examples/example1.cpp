#include "../src/gerdabPlayer.hpp"
#include <string>
#include <vector>

using namespace std;


int main(int argc, char* argv[]){
  string m1 = "examples/beat.wav";
  string m2 = "examples/beat.wav";
  // string m1 = "examples/book.wav";
  // string m2 = "examples/book.wav";
  string m3 = "examples/book.wav";
  string m4 = "examples/book.wav";
  // string m2 = "examples/book.wav";

  vector<string> queue;
  queue.push_back(m1);
  queue.push_back(m2);
  queue.push_back(m3);
  queue.push_back(m4);
  GerdabPlayer player;

  player.setQueue(queue);
  player.setRepeat(1);

  char c;
  while (1) {
    std::cin>>c;
    if(c == 'p'){
      player.play();
    }
    else if(c == 's')
      player.stop();
    else if(c == 'r')
      player.resume();
    else if(c == 'd')
      player.pause();
    else if(c == 'n')
      player.next();
    else if(c == 'l')
      player.previous();
    else
      player.pause();
  }
}
