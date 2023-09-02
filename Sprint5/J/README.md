# J. Добавь узел

Дано BST. Надо вставить узел с заданным ключом. Ключи в дереве могут повторяться.
На вход функции подаётся корень корректного бинарного дерева поиска и ключ, который надо вставить в дерево. 
Осуществите вставку этого ключа. Если ключ уже есть в дереве, то его дубликаты уходят в правого сына. 
Таким образом вид дерева после вставки определяется однозначно. Функция должна вернуть корень дерева после вставки вершины.

Ваше решение должно работать за `O(h)`, где `h` — высота дерева.

На рисунках ниже даны два примера вставки вершин в дерево.

![IMG](https://contest.yandex.ru/testsys/statement-image?imageId=1b920b72e7d7ae066dd6dfb92fbe082e15a4e913160fc1fe1e4e285a5b0f1aff)

Используйте заготовки кода для данной задачи, расположенные по ссылкам:
- [с++](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/cpp/sprint5/J)
- [Java](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/java/sprint5/J)
- [js](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/js/sprint5/J)
- [Python](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/python/sprint5/J)
- [C#](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/csharp/sprint5/J)
- [go](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/go/sprint5/J)
- [Kotlin](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/kotlin/sprint5/J)
- [Swift](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/swift/sprint5/J)

## Формат ввода

Ключи дерева – натуральные числа, не превосходящие `10^9`. Число вершин в дереве не превосходит `10^5`.

Следуйте следующим правилам при отправке решений:
- По умолчанию выбран компилятор Make. Если вы пишете на Swift, выберите Make Swift
- Решение нужно отправлять в виде файла с расширением соответствующем вашему языку программирования.
- Для Go укажите package main.