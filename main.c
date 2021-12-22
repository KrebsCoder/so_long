#include <mlx.h>
#include <unistd.h>

int main(void)
{
        void *init;
        void *img;
        init = mlx_init();
        mlx_new_window(init, 500, 500, "teste");
        img = mlx_new_window(init, 500, 500);
        mlx_loop(init);
        return (0);
}