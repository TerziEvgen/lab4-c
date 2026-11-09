#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    int i;

    if (n < 2)
        return 0;

    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

/* Завдання 1. Варіант 83 */
void task83(void)
{
    double mass, maxMass;
    int i;

    printf("\nЗавдання 1. Найважчий предмет\n");
    printf("Введіть масу 1-го предмета: ");
    if (scanf("%lf", &maxMass) != 1)
        return;

    for (i = 2; i <= 12; i++)
    {
        printf("Введіть масу %d-го предмета: ", i);
        if (scanf("%lf", &mass) != 1)
            return;

        if (mass > maxMass)
            maxMass = mass;
    }

    printf("Маса найважчого предмета: %.2f\n", maxMass);
}

/* Завдання 2. Варіант 90 */
void task90(void)
{
    double number, sum = 0;
    int i;

    printf("\nЗавдання 2. Середнє арифметичне десяти чисел\n");

    for (i = 1; i <= 10; i++)
    {
        printf("Введіть число %d: ", i);
        if (scanf("%lf", &number) != 1)
            return;

        sum += number;
    }

    printf("Середнє арифметичне: %.2f\n", sum / 10);
}

/* Завдання 3. Варіант 109 */
void task109(void)
{
    int x, result;

    printf("\nЗавдання 3. Перевірка простих чисел\n");

    for (x = 0; x <= 15; x++)
    {
        result = x * x + x + 17;

        printf("x = %d, результат = %d - ", x, result);

        if (isPrime(result))
            printf("просте число\n");
        else
            printf("не є простим числом\n");
    }
}

/* Завдання 4. Варіант 146 */
void task146(void)
{
    int limit, n, p, found;

    printf("\nЗавдання 4. Перевірка гіпотези Гольдбаха\n");
    printf("Введіть верхню межу (не менше 52): ");

    if (scanf("%d", &limit) != 1 || limit < 52)
    {
        printf("Неправильне значення.\n");
        return;
    }

    for (n = 52; n <= limit; n += 2)
    {
        found = 0;

        for (p = 2; p <= n / 2; p++)
        {
            if (isPrime(p) && isPrime(n - p))
            {
                printf("%d = %d + %d\n", n, p, n - p);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("Для числа %d розклад не знайдено.\n", n);
    }
}

/* Завдання 5. Варіант 207 */
void task207(void)
{
    double eps, term = 1.0 / 3.0, sum = 0.0;
    int n = 1;

    printf("\nЗавдання 5. Сума членів числового ряду\n");
    printf("Введіть epsilon (додатне число): ");

    if (scanf("%lf", &eps) != 1 || eps <= 0)
    {
        printf("epsilon має бути більшим за нуль.\n");
        return;
    }

    while (fabs(term) >= eps)
    {
        sum += term;

        n++;
        term *= pow((double)(n - 1) / n, n - 1);
    }

    printf("Сума ряду: %.10f\n", sum);
}

/* Завдання 6. Варіант 18 */
void task18(void)
{
    int i;

    printf("\nЗавдання 6. Значення синуса\n");

    for (i = 2; i <= 20; i++)
        printf("sin(%d) = %.6f\n", i, sin(i));
}

/* Завдання 7. Варіант 145 */
void task145(void)
{
    int n, p, q, found;

    printf("\nЗавдання 7. Перевірка твердження Гольдбаха\n");

    for (n = 6; n <= 100; n++)
    {
        found = 0;

        for (p = 2; p <= n && !found; p++)
        {
            if (!isPrime(p))
                continue;

            for (q = p; q <= n && !found; q++)
            {
                if (!isPrime(q))
                    continue;

                if (isPrime(n - p - q) && n - p - q >= q)
                {
                    printf("%d = %d + %d + %d\n",
                           n, p, q, n - p - q);
                    found = 1;
                }
            }
        }

        if (!found)
            printf("Для числа %d розклад не знайдено.\n", n);
    }
}

/* Завдання 8. Варіант 34 */
void task34(void)
{
    int n, i;
    double x, sum = 0;

    printf("\nЗавдання 8. Обчислення суми синусів\n");
    printf("Введіть натуральне число n: ");

    if (scanf("%d", &n) != 1 || n < 1)
    {
        printf("n має бути натуральним числом.\n");
        return;
    }

    printf("Введіть дійсне число x: ");
    if (scanf("%lf", &x) != 1)
        return;

    for (i = 1; i <= n; i++)
        sum += sin(pow(x, i));

    printf("Результат: %.10f\n", sum);
}

/* Завдання 9. Варіант 251 */
void task251(void)
{
    int i;
    int x[] = {1, 2, 4, 7, 11, 16, 22};
    double a = 0.2, b = 4.0, c = -3.0, y;

    printf("\nЗавдання 9. Обчислення функції y = ax^2 + bx + c\n");
    printf(" a = 0.2, b = 4, c = -3\n");
    printf("     x          y\n");

    for (i = 0; i < 7; i++)
    {
        y = a * x[i] * x[i] + b * x[i] + c;
        printf("%6d    %10.2f\n", x[i], y);
    }
}

/* Завдання 10. Варіант 242 */
void task242(void)
{
    double a, b, h, x, y;
    int i;

    printf("\nЗавдання 10. Таблиця значень функції\n");
    printf("Введіть початок відрізка a: ");
    if (scanf("%lf", &a) != 1)
        return;

    printf("Введіть кінець відрізка b: ");
    if (scanf("%lf", &b) != 1)
        return;

    printf("Введіть крок h: ");
    if (scanf("%lf", &h) != 1 || h <= 0 || a > b)
    {
        printf("Перевірте значення a, b та h.\n");
        return;
    }

    printf("\n       x              F(x)\n");

    for (i = 0; ; i++)
    {
        x = a + i * h;

        if (x > b + 1e-10)
            break;

        y = x * x * sin(x) * sin(x) + 1;
        printf("%10.4f       %12.6f\n", x, y);
    }
}

int main(void)
{
    int choice;

    do
    {
        printf("\n========== LABORATORY WORK ==========\n");
        printf("1  - Завдання 83\n");
        printf("2  - Завдання 90\n");
        printf("3  - Завдання 109\n");
        printf("4  - Завдання 146\n");
        printf("5  - Завдання 207\n");
        printf("6  - Завдання 18\n");
        printf("7  - Завдання 145\n");
        printf("8  - Завдання 34\n");
        printf("9  - Завдання 251\n");
        printf("10 - Завдання 242\n");
        printf("0  - Вихід\n");
        printf("Оберіть завдання: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
            case 1: task83(); break;
            case 2: task90(); break;
            case 3: task109(); break;
            case 4: task146(); break;
            case 5: task207(); break;
            case 6: task18(); break;
            case 7: task145(); break;
            case 8: task34(); break;
            case 9: task251(); break;
            case 10: task242(); break;
            case 0: printf("Програму завершено.\n"); break;
            default: printf("Такого пункту меню немає.\n");
        }

    } while (choice != 0);

    return 0;
}
