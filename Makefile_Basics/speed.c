#include "speed.h"

void 
get_speed(const float *displacement, const float *time, float *speed) { *speed   = *displacement / *time; } /* speed function prototype */
