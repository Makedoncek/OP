

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Lab2OP
{
    class Worker 
    {
        //отримання дзвінків від користувача
        public List<PhoneBook> GetCalls()
        {
            List<PhoneBook> Calls = new List<PhoneBook>();
            string answer;
            do
            { //отримання від користувача за допомогою вводу даних та подальше утворення об'єкта класу
              //з додаванням до списку об'єктів дзвінків
                Console.WriteLine("Please enter date of a call in {dd.mm.yy} format ");
                DateOnly date = DateOnly.Parse(Console.ReadLine());
                Console.WriteLine("Please enter start time  of a call in {hh:mm}");
                TimeOnly start = TimeOnly.Parse(Console.ReadLine());
                Console.WriteLine("Please enter end time  of a call in {hh:mm}");
                TimeOnly end = TimeOnly.Parse(Console.ReadLine());
                Calls.Add(new PhoneBook(date, start, end));
                Console.WriteLine("Do you want to add one more call\n Enter your answer: Yes or No");

                answer = Console.ReadLine();
            } while (answer != "No");
            Console.WriteLine("The current calls are added to PhoneBook");
            return Calls;


        }
        //переведення отриманих дзвінків у рядок для подальшого запису у бінарний файл
        public string PhoneBookToStr(List<PhoneBook> Calls)
        {
            List<string> CallsString = new List<string>();
            foreach (PhoneBook Call in Calls)
            {
                CallsString.Add(Call.ToString());
            }
            return string.Join('\n', CallsString);
        }

        //читання з бінарного файлу
        private string ReadFromBinary(string path) 
        {
            FileStream fs = new FileStream(path, FileMode.Open);
            byte[] buffer = new byte[fs.Length];
            fs.Read(buffer, 0, buffer.Length);
            string text = System.Text.Encoding.Default.GetString(buffer);
            fs.Close();

            return text;
        }

        //виведення данних бінарного файлу
        public void PrintFile(string path)
        {
            Console.WriteLine(ReadFromBinary(path));
        }

        //запис тексту у бінарний файл
        public void AppendToBinary(string path, string text)
        {//запис у файл
            text += "\n";
            FileStream fs = new FileStream(path, FileMode.Append);
            byte[] buffer = System.Text.Encoding.Default.GetBytes(text);
            fs.Write(buffer);
            fs.Close();

        }


        //створення бінарного файлу
        public void CreatePhoneBook(string path)
        {

            FileStream fs = new FileStream(path, FileMode.Create);
            fs.Close();

        }
        //можливий перезапис або додавання дзвінків у файл
        public void AppendorCreate(string path, string path2)
        {
            Console.WriteLine("Do you want to add more calls for tax\nEnter Append or Create,else print No");
            string answer = Console.ReadLine();
            if(answer == "Append" || answer == "append")
            {
                
                List<PhoneBook> Calls = GetCalls();
                AppendToBinary(path, PhoneBookToStr(Calls));
                PrintFile(path);
                
                AppendToBinary(path2, addTax(Calls));
                PrintFile(path2);
                

                
            }
            else if(answer == "Create" || answer == "create")
            {

                List<PhoneBook>Calls = GetCalls();
                CreatePhoneBook(path);
                AppendToBinary(path, PhoneBookToStr(Calls));
                PrintFile(path);
                CreatePhoneBook(path2);
                AppendToBinary(path2, addTax(Calls));
                PrintFile(path2);
            }
          


        }


        private float GetTax(PhoneBook call) //Розрахування вартості дзвінка
        {
            if (call.end.Hour >= call.start.Hour)
            {
                return ((call.end.Hour - call.start.Hour) * 60 +
                       (call.end.Minute - call.start.Minute)) * 1.7f;
            }
            else if (22 - call.start.Hour < 22 - call.end.Hour) //Проверка на время(вечер,день)
            {
                return ((22 - call.start.Hour) * 60 +
                       (0 - call.start.Minute)) * 1.7f;
            }
            else
            {
                return 0; //Повернення у будь-якому разі
            }

        }
        //утворення рядка з розрахованою вартістю для кожного дзвінка
        public string addTax(List<PhoneBook> calls)
        {
            List<string> taxCalls = new List<string>();
            foreach (var call in calls)
            {   //перевірка на тариф дзвінка для подальшого обрахування його вартості
                if (call.start.Hour >= 9 && call.start.Hour < 18)
                {
                    taxCalls.Add($"{call.ToString()} - {GetTax(call)}");
                }
                else if ((call.start.Hour >= 7 && call.start.Hour < 9) ||
                         ((call.start.Hour >= 18 && call.start.Hour < 22)))
                {
                    taxCalls.Add($"{call.ToString()} - {GetTax(call) * 0.7f}");
                }
                else if ((call.start.Hour >= 22 && call.start.Hour < 24) ||
                     (call.start.Hour >= 0 && call.start.Hour < 7))
                {
                    taxCalls.Add($"{call.ToString()} - {0}");
                }
            }
            return string.Join('\n', taxCalls);
        }














    }

    //Перезапись файла(2 файлов) или дозапись





    class PhoneBook  //клас телефоної книги, який містить атрибути,що описують потрібні нам дані дзвінка(дата,час початку,час кінця)
    {
        public DateOnly date;
        public TimeOnly start;
        public TimeOnly end;



        public PhoneBook(DateOnly date, TimeOnly start, TimeOnly end)
        {
            this.date = date;
            this.start = start;
            this.end = end;
        }


       // метод переведення атрибутів класу у рядок для запису у файл
        public override string ToString()
        {
            return $"{date} {start}-{end}";
        }
    }
}