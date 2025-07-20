/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:51:02 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/20 17:51:20 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "includes/so_long.h"

int	main(void)
{
	t_img img;
	
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "LittlePoney\n"); 
	img.img_back = mlx_xpm_file_to_image(img.mlx, "imgs/castle.xpm", &img.img_width, &img.img_height);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img_back, 0, 0);
	mlx_loop(img.mlx);
}




#include <stdio.h>
#include <X11/keysym.h>
#include "minilibx-linux/mlx.h"

int	handle_key(int keycode, void *param)
{
	(void)param;
	printf("Keycode :%d\n", keycode);
	return (0);
}

int	main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "Test");
	mlx_key_hook(win, handle_key, NULL);
	mlx_loop(mlx);	
	return (0);
} */