#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define error 1e-5 //for n decimal place precision, write 1e-n+1
#define MAX 20

typedef float dt;

double g(double x)
{
    return x * log10(x) - 1.2;
}

double g_prime(int x)
{
    return log10(x) + 1 / log(10);
}

double abso(double a)
{
    return (a < 0 ? -a : a);
}

float f(float x)
{
    return 1 / (10 + x * x * x);
}

float df(float x, float y)
{
    return x + y * y;
}

void init(dt **matrix, int n)
{
    int i, j;
    double num;
    printf("Enter elements:\n");
    for (i = 0; i != n; ++i)
    {
        for (j = 0; j != n + 1; ++j)
        {
            scanf("%lf", &num);
            matrix[i][j] = (dt)num;
        }
    }
}

void swapRow(dt **matrix, int a, int b)
{
    dt *tmp = matrix[a];
    matrix[a] = matrix[b];
    matrix[b] = tmp;
}

void displayMatrix(dt **matrix, int n, int m)
{
    int isUpper = 1, isLower = 1;
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != m; ++j)
        {
            printf("%7.2f", (double)matrix[i][j]); //put -%5d for right align and no minus for left align
            if (i < j && matrix[i][j] != 0)
                isLower = 0;
            if (i > j && matrix[i][j] != 0)
                isUpper = 0;
        }
        printf("\n");
    }
}

//------------------------------------------------------------

void Quadratic()
{
    printf("Quadratic Equation:\n");
    double a, b, c, d;
    double root1, root2;
    printf("Enter a, b and c where a*x*x + b*x + c = 0: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    d = b * b - 4 * a * c;

    if (d < 0) //Imaginary roots
    {
        printf("Imaginary roots:\n");
        printf("First root = %lf + i%lf\n", -b / (double)(2 * a), sqrt(-d) / (2 * a));
        printf("Second root = %lf - i%lf\n", -b / (double)(2 * a), sqrt(-d) / (2 * a));
    }
    else //Real roots
    {
        printf("Real roots:\n");
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);

        printf("First root = %lf\n", root1);
        printf("Second root = %lf\n", root2);
    }
}

void Bisection()
{
    printf("Bisection Method:\n");
    double a, b, fa, fb;
    printf("Enter values of a and b: ");
    scanf("%lf%lf", &a, &b);
    do
    {
        fa = g(a), fb = g(b);
        if (fa * fb > 0)
        {
            printf("Invalid range.");
            return;
        }
        if (abso(fa) < error)
        {
            printf("%.10lf", a);
            return;
        }
        else if (abso(fb) < error)
        {
            printf("%.10lf", b);
            return;
        }
        else
        {
            double x = (a + b) / 2;
            if (g(x) * fa < 0)
                b = x;
            else
                a = x;
        }
    } while (1);
}

void RegulaFalsi()
{
    printf("Regula-Falsi Method:\n");
    double a, b, fa, fb;
    printf("Enter values of a and b: ");
    scanf("%lf%lf", &a, &b);
    do
    {
        fa = g(a), fb = g(b);
        if (fa * fb > 0)
        {
            printf("Invalid range.");
            return;
        }

        if (abso(fa) < error)
        {
            printf("%.10lf", a);
            return;
        }

        else if (abso(fb) < error)
        {
            printf("%.10lf", b);
            return;
        }

        else
        {
            double x = (a * fb - b * fa) / (fb - fa);
            if (g(x) * fa < 0)
                b = x;
            else
                a = x;
        }
    } while (1);
}

void NewtonRaphson()
{
    printf("Newton-Raphson Method:\n");
    float a;
    printf("Enter x0: ");
    scanf("%f", &a);
    double fa, fprime;
    do
    {
        fa = g(a), fprime = g_prime(a);
        if (fprime == 0)
        {
            printf("Invalid Number.");
            return;
        }
        if (abso(fa) < error)
        {
            printf("%.10lf", a);
            return;
        }
        else
        {
            a = a - fa / fprime;
        }
    } while (1);
}

void GaussElimination()
{
    printf("Gauss Elimination Method:\n");
    dt **matrix;
    int n, i;
    printf("Enter n (Number of Equations): ");
    scanf("%d", &n);

    matrix = (dt **)calloc(n, sizeof(dt *));
    for (i = 0; i != n; ++i)
        matrix[i] = (dt *)calloc(n + 1, sizeof(dt));
    init(matrix, n);
    for (int j = 0, piv = 0; j != n; ++j, piv = j)
    {
        while (piv < n && matrix[piv][j] == 0)
            piv++;
        if (piv >= n)
            continue;
        else if (piv != j)
            swapRow(matrix, piv, j);
        dt p = matrix[j][j];
        for (int i = j + 1; i < n; ++i)
        {
            float factor = matrix[i][j] / p;
            for (int k = j; k < n + 1; ++k)
                matrix[i][k] -= factor * matrix[j][k];
        }
    }
    printf("\nMatrix: \n");
    displayMatrix(matrix, n, n + 1);
    printf("\nSolutions: \n");
    dt *sol = (dt *)calloc(n, sizeof(dt));
    for (int i = n - 1; i >= 0; --i)
    {
        float b = matrix[i][n], coeff = matrix[i][i];
        if (b == 0 && coeff == 0)
        {
            printf("Infinite Solutions.\n");
            return;
        }
        else if (b != 0 && coeff == 0)
        {
            printf("No Solutions.\n");
            return;
        }
        sol[i] = b;
        for (int j = n - 1; j > i; --j)
            sol[i] -= sol[j] * matrix[i][j];
        sol[i] /= coeff;
    }

    for (int i = 0; i < n; ++i)
        printf("X%d = %5.2f\n", i, sol[i]);
}

void GaussJordan()
{
    printf("Gauss Jordan Method:\n");
    dt **matrix;
    int n, i;
    printf("Enter n (Number of Equations): ");
    scanf("%d", &n);

    matrix = (dt **)calloc(n, sizeof(dt *));
    for (i = 0; i != n; ++i)
        matrix[i] = (dt *)calloc(n + 1, sizeof(dt));
    init(matrix, n);
    for (int j = 0, piv = 0; j != n; ++j, piv = j)
    {
        while (piv < n && matrix[piv][j] == 0)
            piv++;
        if (piv >= n)
            continue;
        else if (piv != j)
            swapRow(matrix, piv, j);
        dt p = matrix[j][j];
        for (int i = 0; i < n; ++i)
        {
            if (i == j)
                continue;
            float factor = (float)matrix[i][j] / p;
            for (int k = j; k < n + 1; ++k)
                matrix[i][k] -= factor * matrix[j][k];
        }
    }
    printf("\nMatrix: \n");
    displayMatrix(matrix, n, n + 1);
    printf("\nSolutions: \n");
    dt *sol = (dt *)calloc(n, sizeof(dt));
    for (int i = n - 1; i >= 0; --i)
    {
        float b = matrix[i][n], coeff = matrix[i][i];
        if (b == 0 && coeff == 0)
        {
            printf("Infinite Solutions.\n");
            return;
        }
        else if (b != 0 && coeff == 0)
        {
            printf("No Solutions.\n");
            return;
        }
        sol[i] = b / coeff;
    }

    for (int i = 0; i < n; ++i)
        printf("X%d = %5.2f\n", i, sol[i]);
}

void NewtonForwardDiff()
{
    printf("Newton's Forward Difference Method:\n");
    int n, i, j;
    float *x, **y, xPredict, yPredict, h, u, mult;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    y = (float **)calloc(n, sizeof(float *));
    x = (float *)calloc(n, sizeof(float));
    for (i = 0; i < n; ++i)
    {
        y[i] = (float *)calloc(n - i, sizeof(float));
        printf("Enter x%d and y%d: ", i, i);
        scanf("%f%f", x + i, y[0] + i);
    }

    //calculating the forward differences
    for (i = 1; i < n; ++i)
        for (j = 0; j < n - i; ++j)
            y[i][j] = y[i - 1][j + 1] - y[i - 1][j];

    printf("\nEnter the x for which you want the y: ");
    scanf("%f", &xPredict);

    h = x[1] - x[0]; //step size
    mult = u = (xPredict - x[0]) / h;

    yPredict = y[0][0];
    for (i = 1; i < n; ++i)
    {
        yPredict += mult * y[i][0];
        mult *= (u - i) / (i + 1);
    }
    printf("\ny(%.2f) = %.4f", xPredict, yPredict);
}

void NewtonBackwardDiff()
{
    printf("Newton's Backward Difference Method:\n");
    int n, i, j;
    float *x, **y, xPredict, yPredict, h, u, mult;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    y = (float **)calloc(n, sizeof(float *));
    x = (float *)calloc(n, sizeof(float));
    for (i = 0; i < n; ++i)
    {
        y[i] = (float *)calloc(n - i, sizeof(float));
        printf("Enter x%d and y%d: ", i, i);
        scanf("%f%f", x + i, y[0] + i);
    }

    //calculating the backward differences
    for (i = 1; i < n; ++i)
        for (j = 0; j < n - i; ++j)
            y[i][j] = y[i - 1][j + 1] - y[i - 1][j];

    printf("\nEnter the x for which you want the y: ");
    scanf("%f", &xPredict);

    h = x[1] - x[0]; //step size
    mult = u = (xPredict - x[n - 1]) / h;

    yPredict = y[0][n - 1];
    printf("%5.2f", yPredict);
    for (i = 1; i < n; ++i)
    {
        yPredict += mult * y[i][n - i - 1];
        mult *= (u + i) / (i + 1);
    }
    printf("\ny(%.2f) = %.4f", xPredict, yPredict);
}

void Lagrange()
{
    printf("Lagrange's Method:\n");
    int n, i, j;
    float x[MAX], y[MAX], xPredict, yPredict = 0, nr, dr;

    printf("Enter the no. of terms: ");
    scanf("%d", &n);

    //Input x and y
    for (i = 0; i < n; ++i)
    {
        printf("Enter x%d and y%d: ", i, i);
        scanf("%f%f", x + i, y + i);
    }

    printf("\nEnter the x for which you want the y: ");
    scanf("%f", &xPredict);

    for (i = 0; i < n; ++i)
    {
        nr = dr = 1;
        for (j = 0; j < n; ++j)
        {
            if (j != i)
            {
                nr *= xPredict - x[j];
                dr *= x[i] - x[j];
            }
        }
        yPredict += (nr / dr) * y[i];
    }

    printf("\ny(%.2f) = %.4f", xPredict, yPredict);
}

void Trapezoidal()
{
    printf("Trapezoidal Method:\n");
    float a, b, h, result;
    int i, n;

    printf("Enter lower limit (a): ");
    scanf("%f", &a);
    printf("Enter upper limit (b): ");
    scanf("%f", &b);
    printf("Enter no. of subintervals (n): ");
    scanf("%d", &n);

    h = (b - a) / n;
    result = f(a) + f(b);
    for (i = 1; i < n; ++i)
        result += 2 * f(a + i * h);
    result *= h / 2;

    printf("Result = %7.6f", result);
}

void Simpson1_3()
{
    printf("Simpson's 1/3 Method:\n");
    float a, b, h, result;
    int i, n;

    printf("Enter lower limit (a): ");
    scanf("%f", &a);
    printf("Enter upper limit (b): ");
    scanf("%f", &b);
    printf("Enter no. of subintervals (n): ");
    scanf("%d", &n);
    while (n % 2)
    {
        printf("n must be even. Enter again: ");
        scanf("%d", &n);
    }

    h = (b - a) / n;
    result = f(a) + f(b);
    for (i = 1; i < n; ++i)
    {
        if (i % 2) //true when i is odd
            result += 4 * f(a + i * h);
        else
            result += 2 * f(a + i * h);
    }
    result *= h / 3;

    printf("\n\nResult = %7.6f", result);
}

void Simpson3_8()
{
    printf("Simpson's 3/8 Method:\n");
    float a, b, h, result;
    int i, n;

    printf("Enter lower limit (a): ");
    scanf("%f", &a);
    printf("Enter upper limit (b): ");
    scanf("%f", &b);
    printf("Enter no. of subintervals (n): ");
    scanf("%d", &n);
    while (n % 3)
    {
        printf("n must be multiple of 3. Enter again: ");
        scanf("%d", &n);
    }

    h = (b - a) / n;
    result = f(a) + f(b);
    for (i = 1; i < n; ++i)
    {
        if (i % 3 == 0) //true when i multiple of 3
            result += 2 * f(a + i * h);
        else
            result += 3 * f(a + i * h);
    }
    result *= 3 * h / 8;
    printf("\n\nResult = %7.6f", result);
}

void Euler()
{
    printf("Euler's Method:\n");
    float x, h, xPredict, yPredict;
    int i, n;
    printf("Enter x0 ad y0: ");
    scanf("%f%f", &x, &yPredict);
    printf("Enter x for which y is needed: ");
    scanf("%f", &xPredict);
    printf("Enter no. of subintervals: ");
    scanf("%d", &n);

    h = (xPredict - x) / n;
    for (i = 0; i < n; ++i)
        yPredict += h * df(x + i * h, yPredict);

    printf("\ny(%.2f) = %7.5f", xPredict, yPredict);
}

void RungeKutta()
{
    printf("Runge-Kutta Method:\n");
    float x, h, xPredict, yPredict, k1, k2, k3, k4;
    int i, n;
    printf("Enter x0 ad y0: ");
    scanf("%f%f", &x, &yPredict);
    printf("Enter x for which y is needed: ");
    scanf("%f", &xPredict);
    printf("Enter no. of subintervals: ");
    scanf("%d", &n);

    h = (xPredict - x) / n;
    for (i = 0; i < n; ++i)
    {
        x += i * h;
        k1 = h * df(x, yPredict);
        k2 = h * df(x + h / 2, yPredict + k1 / 2);
        k3 = h * df(x + h / 2, yPredict + k2 / 2);
        k4 = h * df(x + h, yPredict + k3);

        yPredict += (k1 + 2 * (k2 + k3) + k4) / 6;
        printf("\ny(%.2f) = %7.5f", x + h, yPredict);
    }
}

int main()
{
    int op;
    printf("\n\t\tSCIENTIFIC CALCULATOR");
    void (*fp[14])(void) = {Quadratic, Bisection, RegulaFalsi, NewtonRaphson, GaussElimination,
                            GaussJordan, NewtonForwardDiff, NewtonBackwardDiff, Lagrange, Trapezoidal, Simpson1_3, Simpson3_8, Euler, RungeKutta};

    do
    {
        printf("\n\n");
        printf("1 -> Quadratic Equation\n");
        printf("2 -> Bisection Method\n");
        printf("3 -> Regula-Falsi Method\n");
        printf("4 -> Newton-Raphson Method\n");
        printf("5 -> Gauss Elimination\n");
        printf("6 -> Gauss Jordan\n");
        printf("7 -> Newton's Forward Difference\n");
        printf("8 -> Newton's Backward Difference\n");
        printf("9 -> Lagrange's Method\n");
        printf("10 -> Trapezoidal Method\n");
        printf("11 -> Simpson's 1/3 Method\n");
        printf("12 -> Simpson's 3/8 Method\n");
        printf("13 -> Euler's Method\n");
        printf("14 -> Runge-Kutta Method\n");
        printf("0 -> Exit\n");
        printf("\nEnter: ");
        scanf("%d", &op);

        if (!op)
            break;
        else if (op < 1 || op > 14)
            printf("Invalid Input.\n");
        else
        {
            printf("\n\n");
            fp[op - 1]();
        }
    } while (op);
}

//     switch (op)
//     {
//     case 1:
//         Quadratic();
//         break;
//     case 2:
//         Bisection();
//         break;
//     case 3:
//         RegulaFalsi();
//         break;
//     case 4:
//         NewtonRaphson();
//         break;
//     case 5:
//         GaussElimination();
//         break;
//     case 6:
//         GaussJordan();
//         break;
//     case 7:
//         NewtonForwardDiff();
//         break;
//     case 8:
//         NewtonBackwardDiff();
//         break;
//     case 9:
//         Lagrange();
//         break;
//     case 10:
//         Trapezoidal();
//         break;
//     case 11:
//         Simpson1_3();
//         break;
//     case 12:
//         Simpson3_8();
//         break;
//     case 13:
//         Euler();
//         break;
//     case 14:
//         RungeKutta();
//         break;
//     case 0:
//         break;
//     default:
//         printf("Invalid Input.");
//     }