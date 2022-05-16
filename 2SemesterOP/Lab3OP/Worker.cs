using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3OP
{
    public class Worker
    {


        //Створення потягів та запис їх у масив
        public Train[] Generator()
        {

            Console.WriteLine("Please enter amount of trains do you want:");
            int amount = Convert.ToInt32(Console.ReadLine());
            Train[] trains = new Train[amount];
            Random random = new Random();
            for (int i = 0; i < amount; i++)
            {
                int number = random.Next(1111, 10000);
                Console.WriteLine("Enter destination of your train");
                string destination = Console.ReadLine()!;
                Console.WriteLine("Enter time of start train run in format HH:MM");
                TimeOnly start = TimeOnly.Parse(Console.ReadLine()!);
                trains[i] = new Train(number, destination, start);


            }
            return trains;

        }

        //Отримання введення діапазону годину від користувача
        public (TimeOnly start, TimeOnly end) GetDiapason()
        {
            Console.WriteLine("Enter starttime of your diapason in HH:MM format");
            TimeOnly start = TimeOnly.Parse((Console.ReadLine()!));
            Console.WriteLine("Enter endtime of your diapason in HH:MM format");
            TimeOnly end = TimeOnly.Parse(Console.ReadLine()!);
            return (start, end);
        }
        
        //Виведення масиву
        public void PrintArray(Train[]trains)
        {
            foreach(Train train in trains)
            {
                Console.WriteLine(train.ToString());
            }
        }
        //Перевірка на діапазон годин
        public bool CheckDiapason(Train train, (TimeOnly start, TimeOnly end) Diapason)
        {//22 - 7 6 6<22 6

            if (Diapason.start < Diapason.end)
            {

                return train.TimeStart >= Diapason.start && train.TimeStart <= Diapason.end;

            }

            else // 20<=19 && 20>=23  6     19  - 7        6>=19 && 
            {

                if (train.TimeStart >= Diapason.start) return true; 
                else if (train.TimeStart <= Diapason.end) return true;
                else return false;
            }

            


        }
        //Перевірка потягу щодо належності до часового проміжку  та запис при належності у масив
        public Train[] GetTrainsDiapason(Train[] trains, (TimeOnly start, TimeOnly end) Diapason)
        {

            List<Train> trainsDiapason = new List<Train>();
            foreach (Train train in trains)
            {
                if (CheckDiapason(train, Diapason))
                {
                    trainsDiapason.Add(train);
                }
            }
            return trainsDiapason.ToArray();
        }
    }
}