#ifndef _SRC_EVOLUTIONDATASTRUCT_H_
#define _SRC_EVOLUTIONDATASTRUCT_H_

typedef struct {
    float eta;
    float sd, ed, pressure, temperature;
    float ux, uy, ueta;
} fluidCell_ideal;


typedef struct {
   float ed, sd, temperature, pressure;
   float vx, vy, vz;
   float pi[4][4];
   float bulkPi;
} fluidCell;

#endif  // _SRC_EVOLUTIONDATASTRUCT_H_
