#include "fdf.h"


void	isometric(float *x, float *y, float *z, t_data *data) // isometric algorithm
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * cos(data->angle) - *z;
}

void parallel(float *x, float *y, float *z, t_data *data) 
{
    // Calculate the projection
    *x = *x + (*z * cos(data->angle));  // X-coordinate projection
    *y = *y + (*z * sin(data->angle));  // Y-coordinate projection
    // No change in z-coordinate for parallel projection
}

void conic(float *x, float *y, float *z, t_data *data)
{
    float projection_plane_distance = 1.0; // Distance of the projection plane from the camera
    
    // Calculate the projection
    float scale = projection_plane_distance / (*z + projection_plane_distance);
    *x = *x * scale;
    *y = *y * scale;
    // No change in z-coordinate for conic projection
}
