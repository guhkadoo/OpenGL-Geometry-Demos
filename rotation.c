#include <stdio.h>
#include <math.h>
#include <unistd.h>
#define HEIGHT 50
#define WIDTH 50

struct Point {
    double x, y;
};

void printGrid(struct Point p) {
    //if(p.x < 0 || p.x >= WIDTH || p.y < 0 || p.y >= HEIGHT) return;

    for(int i=HEIGHT-1; i>=0; i--) {
        for(int j=0; j<WIDTH; j++) {
            if(j == p.x + WIDTH/2 && i == p.y + HEIGHT/2)
                printf("\033[0;31m*\033[0m");
            else if(i == WIDTH/2)
                putchar('-');
            else if(j == HEIGHT/2)
                putchar('|');
            else
                putchar(' ');
        }
        printf("\n");
    }
}

void movePoint(struct Point start, struct Point end, int steps) {
    struct Point current;
    int dx = end.x - start.x, dy = end.y - start.y;

    for(int i=0; i <= steps; i++) {
        current.x = start.x + i*dx/steps;
        current.y = start.y + i*dy/steps;
        printf("\033[H\033[J");
        printGrid(current);
        usleep(100000);
    }
}

struct Point rotatePoint(double angle, struct Point p) {
    struct Point p_return;
    angle = angle * M_PI/180.0;
    // Applying the rotation matrix
    p_return.x = cos(angle) * p.x - sin(angle) * p.y;
    p_return.y = sin(angle) * p.x + cos(angle) * p.y;

    return p_return;
}

int main(int argc, char *argv[]) {

    struct Point p_inicial;
    scanf("%lf%lf", &p_inicial.x, &p_inicial.y);
    struct Point p_final = rotatePoint(90, p_inicial);
    movePoint(p_inicial, p_final, 10);
    printf("Ponto inicial: (%.2lf, %.2lf)\n", p_inicial.x, p_inicial.y);
    printf("Ponto final: (%.2lf, %.2lf)\n", p_final.x, p_final.y);
    
    return 0;
}
