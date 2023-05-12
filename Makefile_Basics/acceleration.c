#include "acceleration.h"

void 
get_acceleration(const float *speed,       /* __________ Input  : velocity     m/s   _____________ */
                 const float *time,        /* __________ Input  : Time         sec   ____________  */
                 float       *acceleration /* __________ Output : Acceleration m/s2  _____________ */
               ){ *acceleration  = *speed / *time; }
