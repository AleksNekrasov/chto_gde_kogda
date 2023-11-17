// chto_gde_kogda.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>

void game(std::ifstream& question_stream, std::ifstream& answer_stream,std::string answer, std::string true_answer, int &experts ,int &wiewers,bool* baraban,int sector,int &flag,std::string file_question,std::string file_answer)
{
    question_stream.open(file_question);
    if (!question_stream.is_open())
    {
        std::cerr << "Error!!";
    }
    else
    {
        std::cout << " Attention! Question: ";
        char ch;
        while (question_stream.get(ch))   // пока поток передается в чар
        {
            std::cout << ch;              // чар на экран, символ за символом
        }
        question_stream.close();

        std::cout << "\n Your answer: ";
        std::cin >> answer;

        answer_stream.open(file_answer);
        if (!answer_stream.is_open())
        {
            std::cerr << "Error!";
        }
        else
        {
            answer_stream >> true_answer;
        }
        answer_stream.close();

        if (answer == true_answer)
        {
            experts++;                    // если ответ верный - знатокам +1
        }
        else
        {
            wiewers++;                    // если ответ неверный - телезрителям +1
        }
        baraban[sector] = false;
        flag++;
    }
}

int main()
{
    int experts = 0;                  // счетчик знатоков
    int wiewers = 0;                  // счетчик телезрителей 
    int sector = 1;                   // сектор барабана- волчка
    int flag = 0;                     // счетчик цикла
    int* ptr = &flag;
    int offset = 0;                   // вводимое смещение волчка
    std::string answer;               // ответ пользователя
    std::string true_answer;          // правильный ответ
    std::ifstream question_stream;    // поток-вопрос
    std::ifstream answer_stream;      // поток-ответ
    std::string file_question = "";   // путь к файлу - вопросу
    std::string file_answer = "";     // путь к файлу - ответу
    bool baraban[13];                 // сам волчок-барабан с 13 секторами
    for (int i = 0; i < 13; i++)
    {
        baraban[i] = true;
    }

    while (flag < 13)
    {
        std::cout << "Enter offset: ";
        std::cin >> offset;
        sector = (sector + offset) % 13;

        while (!baraban[sector])       // поиск еще не игравшего вопроса
        {
            sector++;
            if (sector == 13)
            {
                sector = 0;
            }
        }

        switch(sector)
        {
        case 0:
            file_question = "C:\\Users\\user\\Desktop\\w13.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a13.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 1:
            file_question = "C:\\Users\\user\\Desktop\\w1.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a1.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 2:
            file_question = "C:\\Users\\user\\Desktop\\w2.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a2.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 3:
            file_question = "C:\\Users\\user\\Desktop\\w3.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a3.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 4:
            file_question = "C:\\Users\\user\\Desktop\\w4.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a4.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 5:
            file_question = "C:\\Users\\user\\Desktop\\w5.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a5.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 6:
            file_question = "C:\\Users\\user\\Desktop\\w6.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a6.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 7:
            file_question = "C:\\Users\\user\\Desktop\\w7.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a7.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 8:
            file_question = "C:\\Users\\user\\Desktop\\w8.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a8.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 9:
            file_question = "C:\\Users\\user\\Desktop\\w9.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a9.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 10:
            file_question = "C:\\Users\\user\\Desktop\\w10.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a10.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 11:
            file_question = "C:\\Users\\user\\Desktop\\w11.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a11.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector, flag, file_question, file_answer);
            break;
        case 12:
            file_question = "C:\\Users\\user\\Desktop\\w12.txt";
            file_answer = "C:\\Users\\user\\Desktop\\a12.txt";
            game(question_stream, answer_stream, answer, true_answer, experts, wiewers, baraban, sector,flag, file_question, file_answer);
            break;
        }
    }
    if (experts > wiewers) std::cout << "EXPERTS WIN!!";
    else std::cout << "WIEWERS WIN!!";

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
