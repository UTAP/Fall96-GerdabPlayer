#include "sdlHeaders.hpp"
#include <thread>
#include <iostream>
#include <string>

void Delay(int milis);
class GerdabPlayer
{
  public:
    GerdabPlayer();
    void play();
    void setMusic(std::string path);
    void pause();
    void stop();
    void terminate();
    int getRemainingTime();
    ~GerdabPlayer();
  private:
    bool playing;
    bool finished;
    bool terminated;
    bool started;
    std::thread* stream;
    std::string wavFilePath;
    static Uint8 *audio_pos;
    static Uint32 audio_len;
    Uint32 wav_length;
    Uint8 *wav_buffer;
    SDL_AudioSpec wav_spec;
  protected:
    static void audioCallback(void *userdata, Uint8 *stream, int len);
    void startStream();
};

class GerdabError{
private:
  std::string message;
public:
  GerdabError();
  GerdabError(std::string errorMessage);
  std::string getMessage();
};
