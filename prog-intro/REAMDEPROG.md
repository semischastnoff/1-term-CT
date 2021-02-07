
## *Prog-Intro*

### Зачет: билет `BBCode parser`

***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/bbCode)***

### Домашнее задание 13. Markdown to HTML

Модификации
 * *Базовая*
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/md2html/Md2HtmlTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/md2html/Md2HtmlTest.jar)
 * *Mark* (32-35)
    * Добавьте поддержку `~выделения цветом~`: `<mark>выделения цветом</mark>`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/md2html/Md2HtmlMarkTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/md2html/Md2HtmlMarkTest.jar)
 * *Image* (36, 37)
    * Добавьте поддержку ```![картинок](http://www.ifmo.ru/images/menu/small/p10.jpg)```:
        ```&lt;img alt='картинок' src='http://www.ifmo.ru/images/menu/small/p10.jpg'&gt;```
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/md2html/Md2HtmlImageTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/md2html/Md2HtmlImageTest.jar)
 * *Link* (38, 39)
    * Добавьте поддержку ```[ссылок с _выделением_](https://kgeorgiy.info)```:
        ```&lt;a href='https://kgeorgiy.info'>ссылок с &lt;em>выделением&lt;/em>&lt;/a>```
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/md2html/Md2HtmlLinkTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/md2html/Md2HtmlLinkTest.jar)


### Домашнее задание 12. Обработка ошибок

* ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Exceptios_Parser_hw12)***

Модификации
 * *Базовая*
    * Класс `ExpressionParser` должен реализовывать интерфейс
        [Parser](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/exceptions/Parser.java)
    * Классы `CheckedAdd`, `CheckedSubtract`, `CheckedMultiply`,
        `CheckedDivide` и `CheckedNegate` должны реализовывать интерфейс
        [TripleExpression](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/TripleExpression.java)
    * Нельзя использовать типы `long` и `double`
    * Нельзя использовать методы классов `Math` и `StrictMath`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/exceptions/ExceptionsTest.java)
 * *AbsSqrt* (32-35)
    * Дополнительно реализуйте унарные операции:
        * `abs` – модуль числа, `abs -5` равно 5;
        * `sqrt` – квадратный корень, `sqrt 24` равно 4.
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/exceptions/ExceptionsAbsSqrtTest.java)
 * *MinMax* (36, 37)
    * Реализуйте операции модификации *AbsSqrt*.
    * Дополнительно реализуйте бинарные операции (минимальный приоритет):
        * `min` – минимум, `2 min 3` равно 2;
        * `max` – максимум, `2 max 3` равно 3.
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/exceptions/ExceptionsMinMaxTest.java)
 * *GcdLcm* (38, 39)
    * Реализуйте операции модификации *AbsSqrt*.
    * Дополнительно реализуйте бинарные операции (минимальный приоритет):
        * `gcd` – НОД, `2 gcd -3` равно 1;
        * `lcm` – НОК, `2 lcm -3` равно -6.
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/exceptions/ExceptionsGcdLcmTest.java)


### Домашнее задание 11. Разбор выражений

* ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Expressions_Parser_11hw-prog/Normal)***

Модификации
 * *Базовая*
    * Класс `ExpressionParser` должен реализовывать интерфейс
        [Parser](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/parser/Parser.java)
    * Результат разбора должен реализовывать интерфейс
        [TripleExpression](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/TripleExpression.java)
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/parser/ParserTest.java)
 * *Bitwise* (32-35)
    * Дополнительно реализуйте бинарные операции:
        * `&` – побитное И, приоритет меньше чем у `+` (`6 & 1 + 2` равно `6 & (1 + 2)` равно 2);
        * `^` – побитный XOR, приоритет меньше чем у `&` (`6 ^ 1 + 2` равно `6 ^ (1 + 2)` равно 5);
        * `|` – побитное ИЛИ, приоритет меньше чем у `^` (`6 | 1 + 2` равно `6 | (1 + 2)` равно 7);
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/parser/ParserBitwiseTest.java)
 * *NotCount* (36, 37)
    * Реализуйте операции из модификации *Bitwise*.
    * Дополнительно реализуйте унарные операции (приоритет как у унарного минуса):
        * `~` – побитное отрицание, `~-5` равно 4;
        * `count` – число установленных битов, `count -5` равно 31.
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/parser/ParserNotCountTest.java)
 * *FlipLow* (38, 39)
    * Реализуйте операции из модификации *Bitwise*.
    * Дополнительно реализуйте унарные операции (приоритет как у унарного минуса):
        * `flip` – число с переставленными двоичными цифрами, `flip 12345` равно 9987, 
                   `flip -12345` равно `-470548481`;
        * `low` – минимальный установленный бит
                 (как в [lowestOneBit](https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/lang/Integer.html#lowestOneBit%28int%29)),
                 `low 123456` равно 64.
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/parser/ParserFlipLowTest.java)



### Домашнее задание 10. Выражения

* ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Expressions_10hw-prog/Normal)***

Модификации
 * *Базовая*
    * Реализуйте интерфейс [Expression](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/Expression.java)
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/ExpressionTest.java)
        * Запускать c аргументом `easy` или `hard`
 * *Triple* (32-35)
    * Дополнительно реализуйте интерфейс [TripleExpression](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/TripleExpression.java)
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/TripleExpressionTest.java)
    * ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Expressions_10hw-prog/Triple)***
 * *Double* (36, 37)
    * Дополнительно реализуйте интерфейс [DoubleExpression](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/DoubleExpression.java)
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/DoubleExpressionTest.java)
 * *DoubleTriple* (38, 39)
    * Дополнительно реализуйте интерфейсы 
      [DoubleExpression](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/DoubleExpression.java) и
      [TripleExpression](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/TripleExpression.java)
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/expression/DoubleTripleExpressionTest.java)

### Домашнее задание 9. Игра m,n,k

Модификации
 * *Матчи* (32, 33)
    * Добавьте поддержку матчей: последовательность игр до указанного числа побед
    * Стороны в матче должны меняться каждую игру
 * *Турнир* (34, 35)
    * Добавьте поддержку кругового турнира для нескольких участников из _c_ кругов
    * Выведите таблицу очков по схеме:
        * 3 очка за победу
        * 1 очко за ничью
        * 0 очков за поражение
    * ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/n%2Cm%2Ck-game_9hw-prog/src/game)***
 * *Multiplayer* (36, 37)
    * Добавьте поддержку значков `-` и `|`
    * Добавьте возможность игры для 3 и 4 игроков
 * *Ромб* (36-39)
    * Добавить поддержку доски в форме ромба (квадрата, повернутого на 45°)
 * *Дополнительные ходы* (38, 39)
    * Если в результате хода игрока на доске появляется новая последовательность
      из 4+ одинаковых символов, то он делает дополнительный ход
    * Игрок может сделать несколько дополнительных ходов подряд


### Домашнее задание 7. Разметка

Исходный код тестов:

 * [MarkdownTest.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/markup/MarkdownTest.java)
 * [AbstractTest.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/markup/AbstractTest.java)
 
 * ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Paragraph_7hw-prog/norm)***

Модификации
 * *HTML* (32, 33)
    * Дополнительно реализуйте метод `toHtml`, генерирующий HTML-разметку:
      * выделеный текст окружается тегом `em`;
      * сильно выделеный текст окружается тегом `strong`;
      * зачеркнутый текст окружается тегом `s`.
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/markup/HtmlTest.java)
 * *BBCode* (34, 35)
    * Дополнительно реализуйте метод `toBBCode`, генерирующий [BBCode](https://en.wikipedia.org/wiki/BBCode)-разметку:
      * выделеный текст окружается тегом `i`;
      * сильно выделеный текст окружается тегом `b`;
      * зачеркнутый текст окружается тегом `s`.
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/markup/BBCodeTest.java)
    * ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Paragraph_7hw-prog/mod34-bbcode)***
 * *TexList*
    * Дополнительно реализуйте метод `toTeX`, генерирующий TeX-разметку:
      * выделеный текст заключается в `\emph{` и `}`;
      * сильно выделеный текст заключается в `\textbf{` и `}`;
      * зачеркнутый текст заключается в `\textst{` и `}`.
    * Добавьте поддержку:
      * Нумерованных списков (класс `OrderedList`, окружение `enumerate`): последовательность элементов
      * Ненумерованных списков (класс `UnorderedList`, окружение `itemize`): последовательность элементов
      * Элементов списка (класс `ListItem`, тег `\item`: последовательность абзацев и списков
    * Для новых классов поддержка Markdown не требуется
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/markup/TexListTest.java)
 * *BBCodeList*
    * Сделайте модификацию *BBCode*
    * Добавьте поддержку:
      * Нумерованных списков (класс `OrderedList`, тег `list=1`): последовательность элементов
      * Ненумерованных списков (класс `UnorderedList`, тег `list`): последовательность элементов
      * Элементов списка (класс `ListItem`, открывающий тег `*`): последовательность абзацев и списков
    * Для новых классов поддержка Markdown не требуется
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/markup/BBCodeListTest.java)



### Домашнее задание 6. Подсчет слов++

Исходный код тестов:

* [WordStatIndexTest.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatIndexTest.java)
* [WordStatIndexChecker.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatIndexChecker.java)

Откомпилированные тесты: [WordStatIndexTest.jar](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/wordStat/WordStatIndexTest.jar)

* ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/WordStatIndex_6hw-prog/Normal)***

Модификации
 * *LineIndex*  (32, 33)
    * Вместо номеров вхождений во всем файле надо указывать
      `<номер строки>:<номер в строке>`
    * Класс должен иметь имя `WordStatLineIndex`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatLineIndexTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/wordStat/WordStatLineIndexTest.jar)
    * ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/WordStatIndex_6hw-prog/LineIndex)***
 * *SortedLineIndex* (34, 35)
    * В выходном файле слова должны быть упорядочены в лексикографическом порядке
    * Вместо номеров вхождений во всем файле надо указывать
      `<номер строки>:<номер в строке>`
    * Класс должен иметь имя `WordStatSortedLineIndex`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatSortedLineIndexTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/wordStat/WordStatSortedLineIndexTest.jar)
    * ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/WordStatIndex_6hw-prog/SortedLineIndex)***
 * *CountLineIndex*  (36, 37)
    * В выходном файле слова должны быть упорядочены по возрастанию числа
      вхождений, а при равном числе вхождений – по порядку первого вхождения
      во входном файле.
    * Вместо номеров вхождений во всем файле надо указывать
      `<номер строки>:<номер в строке>`
    * Класс должен иметь имя `WordStatCountLineIndex`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatCountLineIndexTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/wordStat/WordStatCountLineIndexTest.jar)
 * *CountFirstIndex*
    * В выходном файле слова должны быть упорядочены по возрастанию числа
      вхождений, а при равном числе вхождений – по порядку первого вхождения
      во входном файле.
    * Вместо номеров вхождений во всем файле надо указывать
      только первое вхождение в каждой строке
    * Класс должен иметь имя `WordStatCountFirstIndex`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatCountFirstIndexTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/wordStat/WordStatCountFirstIndexTest.jar)



### Домашнее задание 5. Свой сканнер

Исходный код тестов:

* [FastReverseTest.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/reverse/FastReverseTest.java)

* ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Scanner_5hw-prog)***

Откомпилированные тесты: [FastReverseTest.jar](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/reverse/FastReverseTest.jar)
Модификации
 * *Hex* (32, 33)
    * Во вводе и выводе используются числа в шестнадцатеричной системе счисления
    * Класс должен иметь имя `ReverseHex`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/reverse/FastReverseHexTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/reverse/FastReverseHexTest.jar)
 * *Abc* (34, 35)
    * Во вводе и выводе используются числа, записаные буквами:
      нулю соответствует буква `a`, единице – `b` и так далее
    * Класс должен иметь имя `ReverseAbc`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/reverse/FastReverseAbcTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/reverse/FastReverseAbcTest.jar)
 * *HexDec* (36, 37)
    * На вход подаются десятичные и шестнадцатеричные числа
    * Шестнадцатеричные числа имеют префикс `0x`
    * Класс должен иметь имя `ReverseHexDec`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/reverse/FastReverseHexDecTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/reverse/FastReverseHexDecTest.jar)
 * *HexAbc* (38, 39)
    * На вход подаются десятичные и шестнадцатеричные числа
    * Шестнадцатеричные числа имеют префикс `0x`
    * Десятеричные числа могут быть записаны буквами
    * Класс должен иметь имя `ReverseHexAbc`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/reverse/FastReverseHexAbcTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/reverse/FastReverseHexAbcTest.jar)


### Домашнее задание 4. Подсчет слов

Исходный код тестов:

* [WordStatInputTest.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatInputTest.java)
* [WordStatChecker.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatChecker.java)

Откомпилированные тесты: [WordStatInputTest.jar](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/wordStat/WordStatInputTest.jar)

* ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/WordStat_4hw-prog/WordStatInput%20(custom%20Scanner))***

Модификации
 * *InputPrefix* (32, 33)
    * Выходной файл должен содержать все различные префиксы длины 3
      слов встречающихся во входном файле, в порядке их появления.
      Слова длины меньшей 3 игнорируются.
    * Класс должен иметь имя `WordStatInputPrefix`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatInputPrefixTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/wordStat/WordStatInputPrefixTest.jar)
 * *InputShingles* (34, 35)
    * Выходной файл должен содержать все различные подстроки длины 3
      слов встречающихся во входном файле, в порядке их появления.
      Слова длины меньшей 3 игнорируются.
    * Класс должен иметь имя `WordStatInputShingles`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatInputShinglesTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/wordStat/WordStatInputShinglesTest.jar)
    * ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/WordStat_4hw-prog/WordStatInputShingles)***
 * *WordsPrefix* (для 36, 37)
    * Выходной файл должен содержать все различные префиксы длины 3
      слов встречающихся во входном файле, в лексикографическом порядке.
      Слова длины меньшей 3 игнорируются.
    * Класс должен иметь имя `WordStatWordsPrefix`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatWordsPrefixTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/wordStat/WordStatWordsPrefixTest.jar)
 * *CountShingles* (для 38, 39)
    * Выходной файл должен содержать все различные подстроки длины 3
      слов встречающихся во входном файле, упорядоченые по возрастанию числа
      вхождений, а при равном числе вхождений – по порядку первого вхождения
      во входном файле.
    * Класс должен иметь имя `WordStatCountShingles`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/wordStat/WordStatCountShinglesTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/wordStat/WordStatCountShinglesTest.jar)
 

### Домашнее задание 3. Реверс

Исходный код тестов:

* [ReverseTest.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/reverse/ReverseTest.java)
* [ReverseChecker.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/reverse/ReverseChecker.java)

Откомпилированные тесты: [ReverseTest.jar](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/reverse/ReverseTest.jar)
* ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Reverse_3hw-prog/Normal)***

Модификации:
 * *Max* (для 32, 33)
    * Рассмотрим входные данные как (не полностью определенную) матрицу,
      вместо каждого числа выведите максимум из чисел в его столбце и строке
    * Класс должен иметь имя `ReverseMax`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/reverse/ReverseMaxTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/reverse/ReverseMaxTest.jar)
 * *Min* (для 34, 35)
    * Рассмотрим входные данные как (не полностью определенную) матрицу,
      вместо каждого числа выведите минимум из чисел в его столбце и строке
    * Класс должен иметь имя `ReverseMin`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/reverse/ReverseMinTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/reverse/ReverseMinTest.jar)
    * ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Reverse_3hw-prog/ReverseMin)***
 * *Avg* (для 36-39)
    * Рассмотрим входные данные как (не полностью определенную) матрицу,
      вместо каждого числа выведите среднее из чисел в его столбце и строке
    * Класс должен иметь имя `ReverseAvg`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/reverse/ReverseAvgTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/reverse/ReverseAvgTest.jar)


### Домашнее задание 2. Сумма чисел

Для того, чтобы протестировать исходную программу:

 1. Скачайте откомпилированные тесты ([SumTest.jar](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/sum/SumTest.jar))
 1. Откомпилируйте `Sum.java`
 1. Проверьте, что создался `Sum.class`
 1. В каталоге, в котором находится `Sum.class` выполните команду
    ```
       java -jar <путь к SumTest.jar>
    ```
    * Например, если `SumTest.jar` находится в текущем каталоге, выполните команду
    ```
        java -jar SumTest.jar
    ```

Исходный код тестов:

* [SumTest.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/sum/SumTest.java)
* [SumChecker.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/sum/SumChecker.java)
* [Базовые классы](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/base/)
* ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Sum_2hw-prog/Nomal)***

Модификации:
 * *Long* (для 32, 33)
    * Входные данные являются 64-битными целыми числами
    * Класс должен иметь имя `SumLong`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/sum/SumLongTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/sum/SumLongTest.jar)
 * *Float* (для 34, 35)
    * ***[Решение](https://github.com/semischastnoff/1-term-KT/tree/main/prog-intro/Sum_2hw-prog/SumFloat)***
    * Входные данные являются 32-битными числами с формате с плавающей точкой
    * Класс должен иметь имя `SumFloat`
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/sum/SumFloatTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/sum/SumFloatTest.jar)
 * *LongSpace* (для 36, 37)
    * Входные данные являются 64-битными целыми числами
    * Класс должен иметь имя `SumLongSpace`
    * Числа разделяются [пробелами-разделителями](https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/lang/Character.html#SPACE_SEPARATOR)
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/sum/SumLongSpaceTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/sum/SumLongSpaceTest.jar)
 * *BigIntegerSpace* (для 38, 39)
    * Входные данные помещаются в тип [BigInteger](https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/math/BigInteger.html)
    * Класс должен иметь имя `SumBigIntegerSpace`
    * Числа разделяются [пробелами-разделителями](https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/lang/Character.html#SPACE_SEPARATOR)
    * [Исходный код тестов](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/sum/SumBigIntegerSpaceTest.java)
    * [Откомпилированные тесты](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/artifacts/sum/SumBigIntegerSpaceTest.jar)



### Домашнее задание 1. Запусти меня!

 1. Скачайте исходный код ([RunMe.java](http://www.kgeorgiy.info/git/geo/prog-intro-2020/src/branch/master/java/RunMe.java))
 1. Откомпилируйте код (должен получиться `RunMe.class`)
 1. Запустите класс `RunMe` с выданными вам аргументами командной строки
 1. Следуйте выведенной инструкции