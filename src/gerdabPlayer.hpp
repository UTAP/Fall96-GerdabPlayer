#include "sdlHeaders.hpp"
#include <iostream>
#include <string>

void Delay(int milis);
class GerdabPlayer
{
  public:
    static void play();
    static void setMusic(std::string path);
    static void pause();
    static void resume();
    static void stop();
    static void setNextMusic(std::string path);
    friend void musicFinishCallback();
    static std::string nextMusic;
  private:
    static Mix_Music *music;
    static void goToNext();
};

class GerdabError{
private:
  std::string message;
public:
  GerdabError();
  GerdabError(std::string errorMessage);
  std::string getMessage();
};
