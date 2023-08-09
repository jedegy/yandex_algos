# B. Ловкость рук

Гоша и Тимофей нашли необычный тренажёр для скоростной печати и хотят освоить его.

Тренажёр представляет собой поле из клавиш `4 × 4`, в котором на каждом раунде появляется конфигурация цифр и точек. 
На клавише написана либо точка, либо цифра от `1` до `9`.

В момент времени `t` игрок должен одновременно нажать на все клавиши, на которых написана цифра `t`. Гоша и Тимофей могут 
нажать в один момент времени на `k` клавиш каждый. Если в момент времени `t` были нажаты все нужные клавиши, то игроки 
получают `1` балл.

Найдите число баллов, которое смогут заработать Гоша и Тимофей, если будут нажимать на клавиши вдвоём.

![IMG](https://contest.yandex.ru/testsys/statement-image?imageId=cb3cdeef693f05abf245a66df9e312d48c7c2501e5307354ef9722bb8b9a2e5f)

## Формат ввода

В первой строке дано целое число `k (1 ≤ k ≤ 5)`.
В четырёх следующих строках задан вид тренажёра — по 4 символа в каждой строке. Каждый символ — либо точка, 
либо цифра от `1` до `9`. Символы одной строки идут подряд и не разделены пробелами.

## Формат вывода

Выведите единственное число –— максимальное количество баллов, которое смогут набрать Гоша и Тимофей.

### Пример 1

<table>
  <thead>
     <tr>
        <th>Ввод</th>
        <th>Вывод</th>
     </tr>
  </thead>
  <tbody>
     <tr>
        <td>
            3<br>
            1231<br>
            2..2<br>
            2..2<br>
            2..2<br>
        </td>
        <td>
            2<br>
            <br>
            <br>
            <br>
            <br>
        </td>
     </tr>
  </tbody>
</table>

### Пример 2

<table>
  <thead>
     <tr>
        <th>Ввод</th>
        <th>Вывод</th>
     </tr>
  </thead>
  <tbody>
     <tr>
        <td>
            4<br>
            1111<br>
            9999<br>
            1111<br>
            9911<br>
        </td>
        <td>
            1<br>
            <br>
            <br>
            <br>
            <br>
        </td>
     </tr>
  </tbody>
</table>