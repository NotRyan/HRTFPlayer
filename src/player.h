#ifndef PLAYER_H
#define PLAYER_H

#include <bass.h>
#include "sofa.h"

class Player {
public:
    Player();
    ~Player();
    void open(const std::string &filename);
    void open_hrtf(const std::string &filename);
    void play();
    void pause();
    void stop();
    void set_source(float x, float y, float z);
private:
    enum {
        SAMPLE_RATE = 44100
    };
    SOFA *sofa;
    HSTREAM handle;
    float x, y, z;
    static bool inited;
    static void init();
    static void CALLBACK DSP(HDSP, DWORD, void *buffer, DWORD length, void *user);
    void DSP(void *buffer, DWORD length);
};

#endif // PLAYER_H