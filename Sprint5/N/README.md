# N. Разбиение дерева

Дано бинарное дерево поиска, в котором хранятся целые числа. От этого дерева надо отделить `k` самых маленьких элементов.
Реализуйте функцию, которая принимает корень дерева и число `k`, а возвращает два BST — в первом `k` наименьших элементов 
из исходного дерева, а во втором — оставшиеся вершины BST. В вершинах дерева уже записаны корректные размеры 
поддеревьев (точное название поля смотрите в заготовках кода). После разбиения размеры должны остаться корректными — 
вам придётся пересчитывать их на ходу. Ваше решение должно иметь асимптотику `O(h)`, где `h` — высота исходного дерева.

Используйте заготовки кода для данной задачи, расположенные по ссылкам:
- [с++](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/cpp/sprint5/N)
- [Java](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/java/sprint5/N)
- [js](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/js/sprint5/N)
- [Python](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/python/sprint5/N)
- [C#](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/csharp/sprint5/N)
- [go](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/go/sprint5/N)
- [Kotlin](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/kotlin/sprint5/N)
- [Swift](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/swift/sprint5/N)

## Формат ввода

Числа, записанные в вершинах дерева, лежат в диапазоне от `0` до `10^9`. Дерево не содержит одинаковых ключей.

Число вершин в дереве не превосходит `10^5`.