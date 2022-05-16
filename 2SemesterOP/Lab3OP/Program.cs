// суть ООП - инкапсуляция, старт ООП, 4(перегрузка), 5(наследование, полиморфизм)
//сделать клас который будет с ним работать
//

namespace Lab3OP;


    class Program
    {

        static void Main(string[] args)
        {
            Worker worker = new Worker();
            Train[] trains = worker.Generator();
            Train[] DiapasonTrains=worker.GetTrainsDiapason(trains, worker.GetDiapason());
            Console.Clear();
            Console.WriteLine("----------------------------------------\nAll trains");
            worker.PrintArray(trains);
            Console.WriteLine("----------------------------------------\nTrains in Diapason");
            worker.PrintArray(DiapasonTrains);





        }


    }
