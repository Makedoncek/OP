namespace Lab6OPSharp
{
    internal class Program
    {
        static void Main(string[] args)
        {
           Worker worker = new Worker();

            Tree tree = worker.GetTree();
            Console.WriteLine("-------------------------------------------------");
            Console.WriteLine($"Output of tree nodes:\n{tree.PreorderTraverse()}\n"); //виведення без координат

            Console.WriteLine("-------------------------------------------------");

            Console.WriteLine($"Output of tree nodes with coordinates\n(depth,branch):\n{tree.PreorderTraverseWithCoordinates()}"); //виведення з координатами

            Console.WriteLine("-------------------------------------------------");
            

            Console.WriteLine($"Amount of nodes in your tree is {tree.CountNodes()}");


        }
    }
}