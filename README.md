Завдання: Реалізувати бібліотеку оптимізації багатовимірних функцій за допомогою генетичних алгоритмів.

Опис: Бібліотека повинна отримувати на вхід функцію для оптимізації, параметри ГА (розмір популяції, ймовірність мутацій тощо)
та шукати її мінімум.

Багатовимірні функції  та їх мінімум

На перший погляд здається, що можна просто розв’язати цю систему алгебраїчних рівнянь і знайти екстремум функції. Але цей шлях приводить до екстремуму тільки у випадку гладкої квадратичної функції. 

В інших випадках внаслідок великого інтервалу пошуку та поганого початкового наближення, а також кривизни поверхні f(x,y) ми можемо не отримати розв’язку системи алгебраїчних рівнянь. Тому найчастіше використовуються ітераційні методи пошуку, коли ми наближаємось до точки мінімуму поступовими кроками, виконуючи на кожному кроці одні і ті ж дії – ітерації.

Генетичні алгоритми — це процедури пошуку, засновані на механізмах природного відбору і спадкоємства. У них використовується еволюційний принцип виживання найбільш пристосованих особин. 

1.обробляють не значення параметрів самого завдання, а їх закодовану форму;

2.здійснюють пошук рішення виходячи не з єдиної точки, а з їх деякої популяції;

3.використовують тільки цільову функцію, а не її похідні або іншу додаткову інфор3.мацію;

4.застосовують імовірнісні, а не детерміновані правила вибору.

Використання мінімуму інформації про завдання і рандомізація операцій приводять у результаті до стійкості генетичних алгоритмів і до їх переваги над іншими широко вживаними технологіями.

На відміну від більшості алгоритмів оптимізації, генетичні алгоритми не використовують похідні для пошуку мінімумів. Однією з найбільш значущих переваг генетичних алгоритмів є їх здатність знаходити глобальний мінімум, не зациклюючись на локальних мінімумах. Випадковість відіграє істотну роль у структурі генетичних алгоритмів, і це головна причина, по якій генетичні алгоритми продовжують шукати простір пошуку.

Що ми вже зробили?

Знайшли багато корисної літератури і зрозуміли принцип роботи генетичних алгоритмів
Реалізували один генетичний алгоритм на С++, який шукає мінімум функції
Обговорювали, які методи розпаралелювання ми можемо використати у написаному послідовному алгоритмі

Що ми плануємо робити далі?

Вдосконалення ГА:
реалізувати стадії відбору, парування, злиття і мутації різними способами (рулеткове колесо, найпристосованіша частина і тд)
протестувати різні критерії припинення і обрати найкращий


Вдосконалення розпаралелення:
розпаралелити наш теперішній код
реалізувати розпаралелення іншим способом


організувати наявний код в бібліотеку, написати документацію та тести до неї

