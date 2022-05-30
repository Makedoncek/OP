﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5OpSharp
{
    internal class Point //Клас точки
    {
        public double X { get; set; }
        public double Y { get; set; }

       

        public Point(double x=0, double y=0)
        {
            X = x;
            Y = y;
        }
        
        public override string ToString()
        {
            return $"({this.X},{this.Y})";

        }
    }
}
