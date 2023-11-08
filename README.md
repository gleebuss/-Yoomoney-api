
# API Yoomoney C++

Это неофициальная библиотека С++ [YooMoney](https://yoomoney.ru/) API


## Установка

1)Для сборки нужен [cmake](https://cmake.org/).

2)Требуется установить [vcpkg](https://vcpkg.io/en/).

3)Требуется установить библиотку [cpr](https://github.com/libcpr/cpr).

```bash
vcpkg install cpr
```

4)Для сборки документации нужен [Doxygen](https://www.doxygen.nl/).
## Запуск
Для того, чтобы собрать проект нужно:

1)Перейти в корень проекта и ввести команду.

```bash
cmake -B build -S .
```

2)Если вы используете Windows, то окрыть powershell с правами администратора.
```bash
cd build
cmake --build . --target install #скачать бибилотеку
cmake --build . --target documentation #построить документацию
```

Если вы используете macOS, то окрыть терминал
```bash
cd build
sudo cmake --build . --target install #скачать бибилотеку
cmake --build . --target documentation #построить документацию
```
3)После этих команд вы сможете пользоваться бибилотекой.
## Использование
Пример можно увидеть [тут](https://github.com/gleebuss/Example)

