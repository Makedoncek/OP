using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Lab2OP
{
    class Program
    {



        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to GetTax app");
            //адреси бінарних файлів для створення та їх обробки
            string path = "Phone.dat";
            string path2 = "bills.dat";

            Worker worker = new Worker();
            Console.WriteLine("File creating\n---------------------------------------------");
            worker.CreatePhoneBook(path);
            Console.WriteLine("Enter information about your calls");
            List<PhoneBook> Calls =  worker.GetCalls();
            worker.AppendToBinary(path, worker.PhoneBookToStr(Calls));
            Console.WriteLine("You entered your calls\n Thanks!");
            Console.WriteLine("Your file with calls information:");
            worker.PrintFile(path);
            
            worker.CreatePhoneBook(path2);
            worker.AppendToBinary(path2, worker.addTax(Calls));
            worker.PrintFile(path2);
            Console.ReadKey();
            Console.Clear();
            worker.AppendorCreate(path,path2);
            
            Console.WriteLine("This is your bills for your phone calls");

            Console.WriteLine("Thank for using our service");





        }

    }
}


//Дозапись или перезапись - выбор
//Нахождение цены - в один файл день + время, во второй тоже самое + цена. 