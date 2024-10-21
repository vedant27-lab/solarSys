#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawPlanet(int x, int y, int radius, int color) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(x, y, radius, radius);
}

int main() {
    int gd = DETECT, gm;
    char path[] = "C:\\TURBOC3\\BGI";
    initgraph(&gd, &gm, path);

    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int angle = 0;

    while (!kbhit()) {
        cleardevice();

        // Draw Sun
        drawPlanet(centerX, centerY, 30, YELLOW);

        // Draw Earth
        int earthX = centerX + 150 * cos(angle * M_PI / 180);
        int earthY = centerY + 150 * sin(angle * M_PI / 180);
        drawPlanet(earthX, earthY, 20, BLUE);

        // Draw Mars
        int marsX = centerX + 200 * cos((angle + 45) * M_PI / 180);
        int marsY = centerY + 200 * sin((angle + 45) * M_PI / 180);
        drawPlanet(marsX, marsY, 15, RED);

        angle += 1;
        delay(50);
    }

    closegraph();
    return 0;
}
