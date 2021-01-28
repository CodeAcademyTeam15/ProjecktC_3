Екип № 15 – Димитър Ангелов, Калина Кърнева, Венцислав Костадинов

Втора редакция на:
•	Задание на екип № 4 – Мартин Иванов, Антон Петков, Николай Стоянов
•	Първа редакция от екип № 2 – Джулия Василева, Милена Желязкова

Описание на заданието: /*задачата с хотела*/
Трябва да направите софтуер за заявки на хотел. Хотелът има два типа стаи - Луксозна, с цена 180 лв. на нощ,
Стандартна -120 лв. на нощ. Туристическият данък е 6%.Направете програма, която калкулира очаквана себестойност за клиентите
в зависимост от брой нощувки и стаи, и я отпечатва на екрана. Валидността на офертата е 14 дни.
Продължение 1:
•	Ако клиентът заяви повече от 5 нощувки, независимо в какви и колко стаи, получава 15% отстъпка от цената.
Продължение 2:
•	Ако клиентът направи оборот без данък повече от 700 лв за нощувки общо може да избира, дали да получи 15% отстъпка или
да получи спа процедура за 100 лв.
•	След като клиентът направи своя избор, трябва да отпечатате цялото предложение на екран.
Продължение 3:
•	Ако клиентът заяви нощувки за повече от 1000 лв. общо, може да избира между:
•	20% отстъпка
•	Спа процедура на стойност 200 лв.
•	2 Безплатни вечери за семейството
След като клиентът заяви своя избор, трябва да отпечатате финалната оферта на екран.

Екипната работа протече в две срещи в Zoom. В първата обсъдихме оригиналния код, предложените промени при първата редакция и 
дали те са удачни и промените, които ние искаме и да предложим. Втората среща се състоя от демонстрация на оптимизациите, 
които всеки един от нас е направил и  обединяването им в един общ код. Паралелно с това кореспондирахме в Slack, а кода
синхронизирахме в Github. 

Взехме единодушно решение, че след първата редакция програмата е по-бавна за изпълнение, дава грешки при въвеждането 
на определени данни и би била по-трудоемка за оптимизация, отколкото в оригиналния й вид. Съответно промените, 
които ние предлагаме, са предимно на база първоначалния вид на програмата и се състоят в:
•	Преместване на кода от main функцията в отделни функции;
•	Деклариране на глобалните променливи и константи и намаляване на броя им в сравнение с тези от първата редакция; 
•	Добавка на меню, което разширява възможностите за избор на клиента – брой нощувки в различни по вид стаи;
•	Подобрение в скоростта на изпълнение на програмата в сравнение с първата редакция.