//IC_ENERGY sets the initial condition on the energy density profile with options
// 1 : Smooth Oblate Gaussian
// 2 : Fluctuating Oblate Gaussian
// 3 : read in from data file in whitespace delimited format : x y eta epsilon(x,y,eta)
// 4 : read in from superMC block format from /initial_superMC_ed/
//IC_BARYON sets the initial baryon density profile with options
// 1 : Smooth Oblate Gaussian
// 2 : Fluctuating Oblate Gaussian
// 3 : read in from data file in whitespace delimited format : x y eta n_B(x,y,eta)
#define BARYON 1 //if true, code will freestream baryon current as well as stress tensor
#define IC_ENERGY 1
#define IC_BARYON 1
#define ETA_WIDTH 0.5f //these are the two parameters appearing in the distribution of energy density
#define ETA_FLAT 0.5f // found in GPU-VH (see arXiv:1608.06577v1 p. 38)
#define SIGMA 1.0f //the width of the gaussian distribution in (y - eta) of particle distribution function.
//Generalize this to a spacetime function?
#define SIGMA_B 1.0f //the width of the gaussian distribution in (y - eta) of baryon distribution function.
#define PI 3.141592654f //question bro?
#define DIM_X 51 //number of grid points in x direction
#define DIM_Y 51 //number of grid points in y direction
#define DIM_ETA 51 //number of grid points in eta (spacetime rapidity) direction
#define DIM (DIM_X * DIM_Y * DIM_ETA) //total number of spatial grid points
#define DIM_RAP 51 //number of grid points in momentum rapidity
#define DIM_PHIP 31 //number of grid points in phi_p momentum azimuthal angle
#define DX 0.1f //spacing of grid in x direction
#define DY 0.1f //spacing of grid in y direction
#define DETA 0.1f //spacing of grid in eta direction
#define DRAP 0.1f //spacing of grid in momentum rapidity
#define DTAU 0.5f //free streaming longitudinal proper time step size
#define TAU0 0.5f //initial longitudinal proper time
#define TAU (TAU0 + DTAU) //final matching longitudinal proper time
#define EOS_TYPE 1 // 1 : conformal EOS;  2 : Wuppertal-Budhapest parameterization, 3 : Lattice QCD Tables

//These parameters work well for the fluctuating oblate gaussian with the given widths.
/*
#define INITCOND 2
#define ETA_WIDTH 0.5f //these are the two parameters appearing in the distribution of energy density
#define ETA_FLAT 0.5f // found in GPU-VH (see arXiv:1608.06577v1 p. 38)
#define SIGMA 1.0f //the width of the gaussian distribution in (y - eta) of particle distribution function.
//Generalize this to a spacetime function?
#define PI 3.141592654f //question bro?
#define DIM_X 51 //number of grid points in x direction
#define DIM_Y 51 //number of grid points in y direction
#define DIM_ETA 31 //number of grid points in eta (spacetime rapidity) direction
#define DIM (DIM_X * DIM_Y * DIM_ETA) //total number of spatial grid points
#define DIM_RAP 51 //number of grid points in momentum rapidity
#define DIM_PHIP 51 //number of grid points in phi_p momentum azimuthal angle
#define DX 0.1f //spacing of grid in x direction
#define DY 0.1f //spacing of grid in y direction
#define DETA 0.1f //spacing of grid in eta direction
#define DRAP 0.1f //spacing of grid in momentum rapidity
#define DTAU 0.1f //free streaming longitudinal proper time step size
#define TAU0 0.1f //initial longitudinal proper time
#define TAU (TAU0 + DTAU) //final matching longitudinal proper time
#define EOS_TYPE 2 // 1 : conformal EOS;  2 : Wuppertal-Budhapest parameterization
*/
//One needs to take enough points in rapidity to integrate over the subdomain over
//which the distribution function in (y - eta) is not very small. This is because
//we are just performing a Riemann sum over a finite subdomain of rapidity rather than (-inf, inf).
