# B. Чётные и нечётные числа

Представьте себе онлайн-игру для поездки в метро: игрок нажимает на кнопку, и на экране появляются три случайных числа. 
Если все три числа оказываются одной чётности, игрок выигрывает.

Напишите программу, которая по трём числам определяет, выиграл игрок или нет.

## Формат ввода

В первой строке записаны три случайных целых числа `a`, `b` и `c`. Числа не превосходят `10^9` по модулю.

## Формат вывода

Выведите `«WIN»`, если игрок выиграл, и `«FAIL»` в противном случае.

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
        <td>1 2 -3</td>
        <td>FAIL</td>
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
        <td>7 11 7</td>
        <td>WIN</td>
     </tr>
  </tbody>
</table>

### Пример 3

<table class="tests">
  <thead>
     <tr>
        <th>Ввод</th>
        <th>Вывод</th>
     </tr>
  </thead>
  <tbody>
     <tr>
        <td>6 -2 0</td>
        <td>WIN</td>
     </tr>
  </tbody>
</table>