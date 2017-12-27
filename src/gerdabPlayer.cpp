#include "gerdabPlayer.hpp"
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
      SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);
      audio_pos += len;
      audio_len -= len;
}
void GerdabPlayer::startStream()
{
    	while (!terminated){
        SDL_Delay(100);
        if(!started)
          continue;
        if(SDL_LoadWAV(wavFilePath.c_str(), &wav_spec, &wav_buffer, &wav_length) == NULL ){
          std::cout<<":()"<<std::endl;
              throw new GerdabError("Couldnt load wav file: "+wavFilePath);
        }

        wav_spec.callback = GerdabPlayer::audioCallback;
        wav_spec.userdata = NULL;

        audio_pos = wav_buffer;
        audio_len = wav_length;

        if ( SDL_OpenAudio(&wav_spec, NULL) < 0 ){
          throw new GerdabError("Couldnt open audio");
        }
        SDL_PauseAudio(0);
        while(!finished){
          if(audio_len <= 0)
            finished = true;
          if(!playing)
            SDL_PauseAudio(1);
          else
            SDL_PauseAudio(0);
          SDL_Delay(10);
        }
        SDL_CloseAudio();
        SDL_FreeWAV(wav_buffer);
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
      if (SDL_Init(SDL_INIT_AUDIO) < 0)
        throw GerdabError("Could Init SDL");
    }
void GerdabPlayer::play()
{
      playing = true;
      finished = false;
    }
void GerdabPlayer::setMusic(std::string path)
{
  playing = false;
  started = true;
  finished = true;
  wavFilePath = path;
}
void GerdabPlayer::pause()
{
  playing = false;
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
void Delay(int milis)
{
  SDL_Delay(milis);
}
