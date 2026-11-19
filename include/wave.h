#ifndef WAVE_H
#define WAVE_H
#pragma once
#include "math.h"
#include "physics.h"

//velocity, pressure, stress tensor, external body forces
float navierStokes(float v, float p, float st, float ebf);

#endif
