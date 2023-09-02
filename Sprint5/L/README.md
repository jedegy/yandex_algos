# L. Просеивание вниз

Напишите функцию, совершающую просеивание вниз в куче на максимум. Гарантируется, что порядок элементов в куче может 
быть нарушен только элементом, от которого запускается просеивание.

Функция принимает в качестве аргументов массив, в котором хранятся элементы кучи, и индекс элемента, от которого надо 
сделать просеивание вниз. Функция должна вернуть индекс, на котором элемент оказался после просеивания. Также необходимо 
изменить порядок элементов в переданном в функцию массиве.

Индексация в массиве, содержащем кучу, начинается с единицы. Таким образом, сыновья вершины на позиции `v` это `2v` и 
`2 v + 1`. 
Обратите внимание, что нулевой элемент в передаваемом массиве фиктивный, вершина кучи соответствует 1-му элементу.

![IMG](https://contest.yandex.ru/testsys/statement-image?imageId=b6fc613f7413702826048276425de73e299d78ce55cd5412c0abbc6e1ab12700)

Используйте заготовки кода для данной задачи, расположенные по ссылкам:
- [с++](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/cpp/sprint5/L)
- [Java](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/java/sprint5/L)
- [js](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/js/sprint5/L)
- [Python](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/python/sprint5/L)
- [C#](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/csharp/sprint5/L)
- [go](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/go/sprint5/L)
- [Kotlin](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/kotlin/sprint5/L)
- [Swift](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/swift/sprint5/L)

## Формат ввода

Элементы кучи — целые числа, лежащие в диапазоне от `−10^9` до `10^9`. 
Все элементы кучи уникальны. Передаваемый в функцию индекс лежит в диапазоне от 1 до размера передаваемого массива. 
В куче содержится от `1` до `10^5` элементов.