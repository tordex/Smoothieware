#ifndef _RDELTALEVELINGSTRATEGY
#define _RDELTALEVELINGSTRATEGY

#include "LevelingStrategy.h"

#define rotary_delta_strategy_checksum CHECKSUM("rdelta-calibration")

class StreamOutput;

class RotaryDeltaStrategy : public LevelingStrategy
{
public:
    RotaryDeltaStrategy(ZProbe *zprobe) : LevelingStrategy(zprobe){};
    ~RotaryDeltaStrategy(){};
    bool handleGcode(Gcode* gcode);
    bool handleConfig();

private:
    bool set_trim(float x, float y, float z, StreamOutput *stream);
    bool get_trim(float& x, float& y, float& z);
    bool calibrate_delta_endstops(Gcode *gcode);
    bool calibrate_delta_radius(Gcode *gcode);
    bool calibrate_z_offset(Gcode *gcode);
    bool probe_delta_points(Gcode *gcode);
    float findBed();

    float probe_radius;
    float initial_height;
};

#endif
