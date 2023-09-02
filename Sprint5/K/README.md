# K. Выведи диапазон

Напишите функцию, которая будет выводить по неубыванию все ключи от `L` до `R` включительно в заданном бинарном дереве поиска.

Ключи в дереве могут повторяться. Решение должно иметь сложность `O(h + k)`, где `h` — глубина дерева, `k` — число 
элементов в ответе.

В данной задаче если в узле содержится ключ `x`, то другие ключи, равные `x`, могут быть как в правом, так и в 
левом поддереве данного узла. (Дерево строил стажёр, так что ничего страшного).

![IMG](https://contest.yandex.ru/testsys/statement-image?imageId=cb8ec256d4c7439c7c829525f0914fad9d0e34f4c6bde15cd31e4b3d0f6b9b1b)

Используйте заготовки кода для данной задачи, расположенные по ссылкам:
- [с++](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/cpp/sprint5/K)
- [Java](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/java/sprint5/K)
- [js](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/js/sprint5/K)
- [Python](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/python/sprint5/K)
- [C#](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/csharp/sprint5/K)
- [go](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/go/sprint5/K)
- [Kotlin](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/kotlin/sprint5/K)
- [Swift](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/swift/sprint5/K)

## Формат ввода

На вход функции подаётся корень дерева и искомый ключ. Число вершин в дереве не превосходит `10^5`. 
Ключи – натуральные числа, не превосходящие `10^9`. Гарантируется, что `L ≤ R`.

В итоговом решении не надо определять свою структуру / свой класс, описывающий вершину дерева.

Следуйте следующим правилам при отправке решений:
- По умолчанию выбран компилятор Make. Если вы пишете на Swift, выберите Make Swift
- Решение нужно отправлять в виде файла с расширением соответствующем вашему языку программирования.
- Для Go укажите package main.

## Формат вывода
Функция должна напечатать по неубыванию все ключи от `L` до `R` по одному в строке.