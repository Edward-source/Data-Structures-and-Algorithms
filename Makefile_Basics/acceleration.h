#ifndef __ACCELERATION_H__
#define __ACCELERATION_H__

void 
get_acceleration(const float *speed,       /* velocity */
                 const float *time,        /* Time */
                 float       *acceleration /* Acceleration*/
               );

#endif // __ACCELERATION_H__