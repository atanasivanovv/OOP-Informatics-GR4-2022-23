## Task 1

Да се дефинира клас MyMoney, за откриване на депозит с определена парична сума, върху която се начислява лихва. Класът трябва да съдържа име на депозиращия, парична сума, период от време (в години) и лихва. Направете метод за пресмятането на лихвата спрямо годините и процента ликвидност, както и метод за показване на информациятата в класа. Да се направят set-ъри и get-ъри.

## Task 2

Да се дефинира клас BankAccount, определящ банкова сметка на клиент, съдържаща: име на клиент (символен низ с дължина 20 символа),номер на банковата сметка(символен низ с дължина до 10 знака), който задължително започва с "BG" и налична сума на клиент (реално число). Класът да притежава методи чрез които:

- да създава банкова сметка на клиент
- да извежда на екрана данните
- да внася и тегли пари (така да се направи, че ако се опитваме да изтеглим повече пари от наличните да дава грешка).
- Да се направят и сетъри и гетъри за упражнение.

## Task 3

Да се направи клас Ticket, определящ билет за автобус, съдържаща: място на потегляне, място на пристигане (символни низове не по - дълги от 30 символа), година на издаване (цяло число) и цена (реално число). Да се инициализират:

- **методи за създаване на билет (конструктори)**
- **методи за получаване на достъп до данните на някой билет (гетъри)**
- **методи мутатори на данните на билета (сетъри)**
- **метод за извеждане на екрана данните на билета**
- **метод за за форматиране на данните, които са символни низове, т.е ако името на дестинацията ни е написано така sOfIa след извикване на метода да бъде променено на Sofia**

## Task 4

Имате да изградите система за обработка на текущата информация в магазин за анаболни продукти.
Имате клас Product, който описва в себе си:

- Име на стоката
- срок на годност (в дни)
- процент мазнини (ако няма => 0%)
- дали е хранителна стока или не

Реализирайте клас Store, в който да включите:

- общ брой текущи стоки
- стоките в магазина
- текущ оборот на магазина

Напишете функции, които да представляват:

- Конструктури за двата класа
- Сетъри и гетъри за съответните полета (член - променливи)
- функция за продажба на продукт
- за търсене на продукт по име
- изчисляване загубите от развалени стоки
