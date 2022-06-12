using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6OPSharp
{
   
       

    public class Node  //Класс вершини
    {
        public Node(int value) // Конструктор вершини та онулення вершин нащадків
        {
            Value = value;
            Left = Right = null;
        }

        public int Value { get; }  //Властивість значення вершини
        
        //Гілки вершини
        public Node? Left { get; set; }
        public Node? Right { get; set; }

        public override string ToString() => $"[{Value}]"; //Переведення значення вершини у строку
    }






}
