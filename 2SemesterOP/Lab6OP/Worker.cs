using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6OPSharp
{
    internal class Worker
    { 
        public Tree GetTree() // Метод створення дерева
        {

            Tree tree = RootCreating(); 

            tree = AddNodes(tree);

            return tree;
        }



         private Tree RootCreating()  // Отримання кореню дерева
        {
            Console.Write("Enter value for the root of tree - ");
            int valueRoot = Convert.ToInt32(Console.ReadLine());

            Tree tree = new Tree(valueRoot);
            return tree;
        }


        private Tree AddNodes(Tree tree) // Додавання вершин до дерева
        {
            
            int[] values = GetValuesForTreeNodes();
            
            foreach(int value in values)
            {
                tree.Insert(value);
            }

            return tree;
        }


        private int[] GetValuesForTreeNodes() // Отримання значень вершин дерева
        {
            Console.Write("Please enter amount of nodes you want add to your tree - ");

            int amount = Convert.ToInt32(Console.ReadLine());

            Random random = new Random();

            int[] values = new int[amount];

            for (int i = 0; i < amount; i++)
            {
                values[i] = random.Next(-100,101); 

            }
            return values;


        }







    }
}
