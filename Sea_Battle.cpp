#include "Header.h"


int Sea_Battle()
{
	setlocale(LC_ALL, "rus");
	
	const int size = 10;

	int bot_arr[size][size];        //инициализировали массив для бота

	int human_arr[size][size];     //поле игрока
	
	int cordinat_a = 0;          //координаты
	int cordinat_b = 0;         //координаты
	short numan_ship = 10;       //корабли игрока
	short bot_ship = 10;        //корабли бота
	short switch_shot = 0;     //переключатель
	short New_End = 0;        // Перезапуск или выход из игры
	short switch_game = 0;   //переключатель режима расстановки кораблей

	// выводим и заполняем массив нолями

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			human_arr[i][j] = 0; // вводим начальное значение 
		}
	}
	//-------Режим расстановки кораблей-----------
	cout << "\t Расстановка кораблей: \n ";
	cout << "\t 1 - Авто \n ";
	cout << "\t 2 - Игрок \n ";
	cin >> switch_game;
	if (switch_game==1)
		auto_ship(human_arr, 10, 10);//передаем массив в функцию //---Ставим корабли
	if (switch_game==2)
	{ 
	for (int a = 0; a < size; a++)  //позволяет вводит значания в массив координат . поаторяет ввод 10 кораблей, 10 раз
	{ 
		cout << "введите координаты своих кораблей всего 10 \n ";
		cout << "Вертикаль - A \n";
		cin >> cordinat_a;
		cout << "Горизонталь - Б \n";
		cin >> cordinat_b;
		human_arr[cordinat_a][cordinat_b] = 1;
	}
	cout << "\x1b[34m Поле игрока" << endl;
	//-------------выводим  поле игрока-------------
	for (int g = 0; g < 10; g++)  // выводим координату Б
	{
		cout << "\tБ-" << g;
	}
	cout << "\n";
	for (int i = 0; i < size; i++)  //выводим массив для просмотра
	{
			cout << "A-"<< i;
		
		for (int j = 0; j < size; j++)
		{
			cout << "\t" << human_arr[i][j];
		}
		cout << "\n" << endl;
	}
	cout << "Кораблей на плаву - " << numan_ship << endl;
	cout << "\x1b[0m" << endl;
	}

	//-------------Бот поле противника-----------
	cout << "\x1b[31m Поле врага"  << endl;
		for (int i = 0; i < size; i++) // заполняем массив бота ноликами
		{
			for (int j = 0; j < size; j++)
			{
				bot_arr[i][j] = 0;
			}
		}

		rand_arr(bot_arr, 10, 10); //передаем массив в функцию //---Ставим корабли

		cout << "\x1b[34m"  << endl;
		//----------- Режим боя --------------------
		cout << " Режим боя - нажмите _1" << endl;
		
		cin >> switch_shot;
		cout << " Режим боя" << endl;
		for(int cycle_shot = 0; cycle_shot < switch_shot;)
		{ 
		if (switch_shot == 1)
		{
			cout << " Введите координаты для залпа\n ";
			cout << " Вертикаль - A \n";
			cin >> cordinat_a;
			cout << " Горизонталь - Б \n";
			cin >> cordinat_b;
			cout << "\x1b[31m";
			bot_arr[cordinat_a][cordinat_b] == 1 ? bot_arr[cordinat_a][cordinat_b] = 2 : bot_arr[cordinat_a][cordinat_b] = 3; //использовал тернарный оператор //сравнивает координаты и значения в них если есть корабль 1 то ставит 2 - потопил если нет то 3
			bot_arr[cordinat_a][cordinat_b] == 2 ? bot_ship -= 1 : bot_ship + 0; //минусуем потопленные корабли бота для условия победы или поражения
			Batle_Bot(bot_arr, 10, 10);//передаем массив в функцию

			cout << "\n \x1b[0m" << endl;
			bot_arr[cordinat_a][cordinat_b] == 2 ? switch_shot = 1 : switch_shot = 2;//если switch_shot = 2 то бот стреляет снова иначе ход переходит игроку
		}
		if (switch_shot == 2)
		{ 
			cout << "\x1b[31m Враг атакует!!!\x1b[34m\n ";
			cordinat_a = rand() % 10; // случайные координаты для выстрела
			cordinat_b = rand() % 10; // случайные координаты для выстрела
			human_arr[cordinat_a][cordinat_b] == 1 ? human_arr[cordinat_a][cordinat_b] = 2 : human_arr[cordinat_a][cordinat_b] = 3; //сравнивает координаты и значения в них если есть корабль 1 то ставит 2 - потопил если нет то 3
			human_arr[cordinat_a][cordinat_b] == 2 ? numan_ship -= 1 : numan_ship + 0; //минусуем потопленные корабли игрока для условия победы или поражения
			Batle_Human(human_arr, 10, 10);//передаем массив в функцию
		
			human_arr[cordinat_a][cordinat_b] == 2 ? switch_shot = 2 : switch_shot = 1;//если switch_shot = 2 то бот стреляет снова иначе ход переходит игроку
			
			cout << "\n \x1b[0m" << endl;
		}
		if (numan_ship == 0)
		{
	        cout << "\t\t Ваш флот потоплен\a \n " << endl; //тут все понятно 
		    cout << "\t\tИгрок проиграл\a\n " << endl;
			cout << "\t\tСобрать новый флот - 1\n " << endl;
			cout << "\t\t Выйти из игры - 2\n " << endl;
			cin >> New_End;
			if (New_End == 1)
				cout << Sea_Battle();
			if (New_End == 2)
				 exit(0);
		}
		if (bot_ship == 0)
		{
			cout << " \a\t\tВражеский Флот потоплен \n " << endl;//тут все понятно 
		    cout << " \t\tИгрок победил\n " << endl;
			cout << " \t\tНовая битва - 1\n " << endl;
			cout << " \t\tВыйти из игры - 2\n " << endl;
			cin >> New_End;
			if(New_End == 1)
				cout << Sea_Battle();
			if (New_End == 2)
				 exit(0);
		}
		}
		return 0;	
}


