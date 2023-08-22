#include "fdf.h"

void	isometric(float *x, float *y, float *z, t_data *data) // isometric algorithm
{
	*x = (*x - *y) * cos(data->angle);  // 
	*y = (*x + *y) * cos(data->angle) - *z;
}

void parallel(float *x, float *y, float *z, t_data *data) 
{
    *x = *x + (*z * cos(data->angle));
    *y = *y + (*z * sin(data->angle));
}

void conic(float *x, float *y, float *z, t_data *data)
{
    float projection_plane_distance;

    projection_plane_distance = 1.0;
    float scale = projection_plane_distance / (*z + projection_plane_distance);
    *x = *x * scale;
    *y = *y * scale;
}
