# COFFEEBOX
The main idea of the project is to develop menu control system for coffee machine.

## Description
*Some project description*

## ToDo
- **Interface**
  + [x] change the menu width by 64 characters.  
  *We decided to make width up to 40 symbols.*
  + [x] уменьшить уже имеющееся количество надписей Byn во всевозможных меню.  
  + [x] в начале главного меню сразу отображать информацию об оставшихся стаканчиках и балансе пользователя.  
  + [x] Надо убрать предупреждение о малом количестве стаканов.  
  + [x] В сервисном меню можно сразу же отображать информацию об всей наличности в аппарате и количестве оставшихся стаканчиков.
  + [x] Изменить сообщение, которое выдаёт программа в результате неверного ввода PIN-кода более 3х раз. Примерное содержание: "Автомат заблокирован. Причина: слишком много попыток ввода пароля. Для снятия блокировки свяжитесь с нашим менеджером по тел.: +375 (29) 197-15-64".
  + [ ] Refactor menu with sugar adding. To make better UI.
  + [ ] Refactor service menu: delete "show left glasses" option & "show available proceeds" option.
  + [ ] Refactor service menu: delete . after BYN;
  + [ ] Service menu -> "add glasses" option -> write message with more details, why we can't fill our coffee machine with more than 700 glasses.
- **Program logic**
  + [x] слишном высокие цены - уменьшить. 
  + [x] В меню с ценами выровнять цены в аккуратный столбик.
  + [x] Должна быть возмножность ввести неверный пароль до 2 раз, после чего можно выйти в главное меню без каких-либо последствий и продолжить заказывать кофе. После выхода из меню ввода PIN-кода количество использованных попыток сохраняется.
  + [x] Убрать вывод на экран количества попыток ввода PIN-кода.
  + [x] Доработать функцию очистки дисплея, чтобы удалялись пустые строки перед каждым выводом на экран?

**All will be fine!**
