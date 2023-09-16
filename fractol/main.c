#include <mlx.h>

#include <stdlib.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

typedef struct s_data {
    void *mlx;
    void *win;
    void *win1;
} t_data;

void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); // Determine the number of steps

    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;
    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++) {
        mlx_pixel_put(data->mlx, data->win, x, y, color);
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    t_data data;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "MiniLibX Line Drawing");
    // data.win1 = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "MiniLibX Line Drawing");
    // Set the color to green (0x00FF00 in hexadecimal)
    int green = 0xFFFF;

    // Draw a line from (100, 100) to (300, 300)
    draw_line(&data, 100, 100, 200, 200, green);

    mlx_loop(data.mlx);
    return 0;
}
