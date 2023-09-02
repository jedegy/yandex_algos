# M. Просеивание вверх

Напишите функцию, совершающую просеивание вверх в куче на максимум. Гарантируется, что порядок элементов в куче может 
быть нарушен только элементом, от которого запускается просеивание.

Функция принимает в качестве аргументов массив, в котором хранятся элементы кучи, и индекс элемента, от которого надо 
сделать просеивание вверх. Функция должна вернуть индекс, на котором элемент оказался после просеивания. 
Также необходимо изменить порядок элементов в переданном в функцию массиве.

Индексация в массиве, содержащем кучу, начинается с единицы. Таким образом, сыновья вершины на позиции `v` это `2v` и 
`2 v + 1`. 
Обратите внимание, что нулевой элемент в передаваемом массиве фиктивный, вершина кучи соответствует 1-му элементу.

![IMG](https://contest.yandex.ru/testsys/statement-image?imageId=b08ae22c8e37a6121895276bffe825fd8602bfb4cf0f96428c5375ae585734de)

Используйте заготовки кода для данной задачи, расположенные по ссылкам:
- [с++](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/cpp/sprint5/M)
- [Java](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/java/sprint5/M)
- [js](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/js/sprint5/M)
- [Python](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/python/sprint5/M)
- [C#](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/csharp/sprint5/M)
- [go](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/go/sprint5/M)
- [Kotlin](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/kotlin/sprint5/M)
- [Swift](https://github.com/Yandex-Practicum/algorithms-templates/tree/main/swift/sprint5/M)

## Формат ввода

Элементы кучи — целые числа, лежащие в диапазоне от `−10^9` до `10^9`. 
Все элементы кучи уникальны. Передаваемый в функцию индекс лежит в диапазоне от 1 до размера передаваемого массива. 
В куче содержится от `1` до `10^5` элементов.