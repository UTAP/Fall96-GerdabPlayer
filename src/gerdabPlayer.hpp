#include "sdlHeaders.hpp"
#include <iostream>
#include <string>

void Delay(int milis);
class GerdabPlayer
{
  public:
    void play();
    void setMusic(std::string path);
    void pause();
    void resume();
    void stop();
    int getRemainingTime();
  private:
    Mix_Music *music;
};

class GerdabError{
private:
  std::string message;
public:
  GerdabError();
  GerdabError(std::string errorMessage);
  std::string getMessage();
};
