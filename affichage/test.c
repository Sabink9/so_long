#include <mlx.h>
#include <stdlib.h>
#include <X11/keysym.h>   // pour XK_Escape
#include <X11/X.h>        // pour le bouton de fermeture

#define WIDTH 800
#define HEIGHT 600

int	handle_key(int key, void *mlx)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(mlx, mlx
		exit(0);
	}
	return (0);
}

int	handle_close(void *mlx)
{
	mlx_destroy_window(mlx, mlx);
	exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (1);

	win = mlx_new_window(mlx, WIDTH, HEIGHT, "so_long - fenêtre test");
	if (!win)
		return (1);

	// Gère la touche Échap
	mlx_key_hook(win, handle_key, mlx);

	// Gère le clic sur la croix
	mlx_hook(win, 17, 0, handle_close, mlx);

	mlx_loop(mlx);
	return (0);
}