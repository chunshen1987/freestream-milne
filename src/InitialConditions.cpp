#pragma once
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include "Parameter.h"
#define THETA_FUNCTION(X) ((double)X < (double)0 ? (double)0 : (double)1)

void initializeZero(double *density, parameters params)
{
  int DIM = params.DIM;
  for (int is = 0; is < DIM; is++)
  {
    density[is] = 0.0;
  }
}

void initializeGauss(double *density, double b, parameters params) // b is the variance ('spherically' symmetric)
{
  int DIM = params.DIM;
  int DIM_X = params.DIM_X;
  int DIM_Y = params.DIM_Y;
  int DIM_ETA = params.DIM_ETA;
  double DX = params.DX;
  double DY = params.DY;
  double DETA = params.DETA;

  double e0 = 500.0; //energy norm factor in fm^(-4) : roughly 500 MeV Temperature

  for (int is = 0; is < DIM; is++)
  {
    int ix = is / (DIM_Y * DIM_ETA);
    int iy = (is - (DIM_Y * DIM_ETA * ix))/ DIM_ETA;
    int ieta = is - (DIM_Y * DIM_ETA * ix) - (DIM_ETA * iy);

    //does it work for even number of points?
    double x = (double)ix * DX  - ((double)(DIM_X-1)) / 2.0 * DX;
    double y = (double)iy * DY  - ((double)(DIM_Y-1)) / 2.0 * DY;
    double eta = (double)ieta * DETA  - ((double)(DIM_ETA-1)) / 2.0 * DETA;

    density[is] = e0 * exp(-(1.0 / b) * ((x * x) + (y * y) + (eta * eta)));
  }
}

void initializeEllipticalGauss(double *density, double bx, double by, double beta, parameters params) // bx is the x variance etc...
{
  int DIM = params.DIM;
  int DIM_X = params.DIM_X;
  int DIM_Y = params.DIM_Y;
  int DIM_ETA = params.DIM_ETA;
  double DX = params.DX;
  double DY = params.DY;
  double DETA = params.DETA;

  double e0 = 500.0; //energy norm factor in fm^(-4) : roughly 500 MeV Temperature

  for (int is = 0; is < DIM; is++)
  {
    int ix = is / (DIM_Y * DIM_ETA);
    int iy = (is - (DIM_Y * DIM_ETA * ix))/ DIM_ETA;
    int ieta = is - (DIM_Y * DIM_ETA * ix) - (DIM_ETA * iy);

    //does it work for even number of points?
    double x = (double)ix * DX  - ((double)(DIM_X-1)) / 2.0 * DX;
    double y = (double)iy * DY  - ((double)(DIM_Y-1)) / 2.0 * DY;
    double eta = (double)ieta * DETA  - ((double)(DIM_ETA-1)) / 2.0 * DETA;

    density[is] = e0 * exp(-(1.0 / bx) * (x * x)) * exp(-(1.0 / by) * (y * y)) * exp(-(1.0 / beta) * (eta * eta));
  }
}

void initializeMCGauss(double * density, double b, parameters params)
{
  int DIM = params.DIM;
  int DIM_X = params.DIM_X;
  int DIM_Y = params.DIM_Y;
  int DIM_ETA = params.DIM_ETA;
  double DX = params.DX;
  double DY = params.DY;
  double DETA = params.DETA;

  double e0 = 500.0; //energy norm factor in fm^(-4) : roughly 500 MeV Temperature

  for (int is = 0; is < DIM; is++)
  {
    int ix = is / (DIM_Y * DIM_ETA);
    int iy = (is - (DIM_Y * DIM_ETA * ix))/ DIM_ETA;
    int ieta = is - (DIM_Y * DIM_ETA * ix) - (DIM_ETA * iy);

    //does it work for even number of points?
    double x = (double)ix * DX  - ((double)(DIM_X-1)) / 2.0 * DX;
    double y = (double)iy * DY  - ((double)(DIM_Y-1)) / 2.0 * DY;
    double eta = (double)ieta * DETA  - ((double)(DIM_ETA-1)) / 2.0 * DETA;

    density[is] = e0 * ((double)rand() / RAND_MAX) * exp(-(1.0 / b) * ((x * x) + (y * y) + (eta * eta)));
  }
}

void initializeEllipticalMCGauss(double *density, double bx, double by, double beta, parameters params) // bx is the x variance etc...
{
  int DIM = params.DIM;
  int DIM_X = params.DIM_X;
  int DIM_Y = params.DIM_Y;
  int DIM_ETA = params.DIM_ETA;
  double DX = params.DX;
  double DY = params.DY;
  double DETA = params.DETA;

  double e0 = 500.0; //energy norm factor in fm^(-4) : roughly 500 MeV Temperature

  for (int is = 0; is < DIM; is++)
  {
    int ix = is / (DIM_Y * DIM_ETA);
    int iy = (is - (DIM_Y * DIM_ETA * ix))/ DIM_ETA;
    int ieta = is - (DIM_Y * DIM_ETA * ix) - (DIM_ETA * iy);

    //does it work for even number of points?
    double x = (double)ix * DX  - ((double)(DIM_X-1)) / 2.0 * DX;
    double y = (double)iy * DY  - ((double)(DIM_Y-1)) / 2.0 * DY;
    double eta = (double)ieta * DETA  - ((double)(DIM_ETA-1)) / 2.0 * DETA;

    density[is] = e0 * ((double)rand() / RAND_MAX) * exp(-(1.0 / bx) * (x * x)) * exp(-(1.0 / by) * (y * y)) * exp(-(1.0 / beta) * (eta * eta));
  }
}

void readEnergyDensitySuperMCBlock(double *density, parameters params)
{
  int DIM = params.DIM;
  int DIM_X = params.DIM_X;
  int DIM_Y = params.DIM_Y;
  int DIM_ETA = params.DIM_ETA;
  double ETA_WIDTH = params.ETA_WIDTH;
  double ETA_FLAT = params.ETA_FLAT;
  double DETA = params.DETA;

  //first read in the transverse profile from superMC block data format
  double temp = 0.0;
  std::ifstream superMCFile;
  superMCFile.open("initial_superMC_ed/2.dat");
  if (superMCFile.is_open())
  {
    for (int ix = 0; ix < DIM_X; ix++)
    {
      for (int iy = 0; iy < DIM_Y; iy++)
      {
        superMCFile >> temp;
        for (int ieta = 0; ieta < DIM_ETA; ieta++) //copy the same value for all eta, then we will multiply by eta dependent function
        {
          int is = (DIM_Y * DIM_ETA) * ix + (DIM_ETA) * iy + ieta; //the column packed index spanning x, y, z
          density[is] = temp;
        }
      }
    }
  }

  else
  {
    printf("Could not find initial profile in initial_superMC_ed!");
  }

  superMCFile.close();

  //now multiply by an eta-dependent profile; etaWidth is the width of the eta profile
  for (int is = 0; is < DIM; is++)
  {
    int ix = is / (DIM_Y * DIM_ETA);
    int iy = (is - (DIM_Y * DIM_ETA * ix))/ DIM_ETA;
    int ieta = is - (DIM_Y * DIM_ETA * ix) - (DIM_ETA * iy);

    double eta = (double)ieta * DETA  - ((double)(DIM_ETA-1)) / 2.0 * DETA;
    //here we use a the same profile as GPU-VH (see arXiv:1608.06577v1 p. 38)
    double arg = (-1.0) * (abs(eta) - ETA_FLAT) * (abs(eta) - ETA_FLAT) / (2.0 * ETA_WIDTH * ETA_WIDTH);
    arg = arg * THETA_FUNCTION(abs(eta) - ETA_FLAT);
    density[is] = density[is] * exp(arg);
  }
}
