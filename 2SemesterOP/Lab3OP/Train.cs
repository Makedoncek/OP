using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3OP
{   //Класс потяг
    public class Train
    {
        
            public int Number {  get; private set; }
            public string Destination {  get; private set; }
            public TimeOnly TimeStart { get; private set; }
            


        //Конструктор об'єкта класу
            public Train(int number,string destination,TimeOnly timeStart)
            {
                Number = number;
                Destination = destination;
                TimeStart = timeStart;
            }

            
            public override string ToString()
            {
                return $"Train number - {Number} to {Destination} at {TimeStart}";
            }




        
       





    }
}
