#include "fdf.h"

void	zoom(float *x1, float *y1, float *x2, float *y2, t_data *data)
{
	// --zoom-- (30)    // default    	   zoomed
	*x1 *= data->zoom;	// 10         ->    300
	*x2 *= data->zoom;	// 10         ->    300
	*y1 *= data->zoom;	// 100        ->    3000
	*y2 *= data->zoom;	// 200        ->    3000
}

void	set_indexes(float *x1, float *y1, float *x2, float *y2, t_data *data)
{
	*x1 += data->shiftx;
	*y1 += data->shifty;
	*x2 += data->shiftx;
	*y2 += data->shifty;
}

void	zoom_z(float *z1, float *z2, t_data *data)
{
	*z1 *= data->z_zoom;
	*z2 *= data->z_zoom;
}