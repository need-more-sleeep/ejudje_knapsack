# ejudje_knapsack
## Рюкзак
Решите задачу о рюкзаке приближенно. Алгоритм должен быть
инкапсулирован.
### Формат ввода
Данные подаются на стандартный поток ввода. Пустые строки игнорируются.
Первая строка содержит дробное число от 0 до 1 — коэффициент
приближения. 0 — решение должно совпасть с оптимальным, 0.1 — отличается
не более чем на 10% и т.д.
Вторая строка содержит целое неотрицательное число — максимальную массу
предметов, которую выдержит рюкзак.
Каждая последующая содержит два целых неотрицательных числа: массу
предмета и его стоимость.
### Формат вывода
Первая строка содержит два числа: суммарную массу предметов и их
суммарную стоимость.
В последующих строках записаны номера предметов, которые были помещены
в рюкзак. Порядок не важен.
Результат работы программы выводится в стандартный поток вывода.
### Пример
#### Ввод:
0.001
165
23 92
31 57
29 49
44 68
53 60
38 43
63 67
85 84
89 87
82 72
#### Вывод:
165 309
1
2
3
4
